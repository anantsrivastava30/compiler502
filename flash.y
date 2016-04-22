%{/*************************************************************************
Compiler for the Simple language
***************************************************************************/
/*=========================================================================
C Libraries, Symbol Table, Code Generator & other C code
=========================================================================*/
#include <stdio.h>
/* For I/O																*/
#include <stdlib.h>

/* For malloc here and in symbol table									*/
#include <string.h>
/* For strcmp in symbol table											*/
#include "ST.h"
/* Symbol Table															*/
#include "SM.h"
/* Stack Machine														*/
#include "CG.h"
/* Code Generator														*/
#define YYDEBUG 1
/* For Debugging														*/
int errors;
/* Error Count*/
/*-------------------------------------------------------------------------
				The following support backpatching
-------------------------------------------------------------------------*/
struct lbs
/* Labels for data, if and while*/
{
	int for_goto;
	int for_jmp_false;
};
struct lbs * newlblrec() /*      Allocate space for the labels			*/
{
	return (struct lbs *) malloc(sizeof(struct lbs));
}
/*-------------------------------------------------------------------------
				Install identifier & check if previously defined.
-------------------------------------------------------------------------*/
install ( char *sym_name ,int type)
{
	symrec *s;
	s = getsym (sym_name);
	if (s == 0)
		s = putsym (sym_name,type);
	else { errors++;
		printf( "%s is already defined\n", sym_name );
	}
}
/*-------------------------------------------------------------------------
				If identifier is defined, generate code
-------------------------------------------------------------------------*/
context_check( enum code_ops operation, char *sym_name ,int type)
{   symrec *identifier;
	identifier = getsym( sym_name );
	if ( identifier == 0 ) { 
		errors++;
		printf( "%s", sym_name );
		printf( "%s\n", " is an undeclared identifier" );
		}
	else if (type != -1 && identifier->type != type) {
		printf( "%s", sym_name );
		printf( "%s\n", " type error!" );
		}
	else gen_code( operation, identifier->offset );
}
/*=========================================================================
							SEMANTIC RECORDS
=========================================================================*/
%}
%union semrec							/* The Semantic Records*/
{
int	intval;								/* Integer value */
char *id;								/* Identifiers	*/
struct lbs *lbls;						/* For backpatching	*/
char *boolval;						
}
/*=========================================================================
								TOKENS
=========================================================================*/
%start program
%token <boolval> BOOLEAN					/* Simple boolean */
%token <intval> NUMBER					/* Simple integer */
%token <id> IDENTIFIER								/* Simple identifier */
%token <lbls> IF WHILE								/* For backpatching labels */
%token SKIP THEN ELSE FI DO END
%token INTEGER READ WRITE LET IN BOOLE
%token ASSGNOP
/*=========================================================================
							OPERATOR PRECEDENCE
=========================================================================*/
%left '-' '+'
%left '*' '/'
%right '^'
/*=========================================================================
					GRAMMAR RULES for the Simple language
=========================================================================*/
%%
program : 	LET
				declaration
			IN	{	gen_code( DATA, data_location() - 1 );				}
				commands
			END {	gen_code( HALT, 0 ); YYACCEPT;						}
;
declaration : /* empty*/
	| declaration declarations
;	
declarations : SKIP
	| INTEGER id_seqi IDENTIFIER ';' {	install( $3 , 1);					}
	| BOOLE id_seqb IDENTIFIER ';' {	install( $3 , 0);					}
;
id_seqi : /* empty */
	| id_seqi IDENTIFIER ',' {	install( $2 , 1);							}
;
id_seqb : /* empty */
	| id_seqb IDENTIFIER ',' {	install( $2 , 0);							}
;
commands : /* empty */
	| commands command ';'
;
command : SKIP
	| READ IDENTIFIER {    context_check( READ_INT, $2 , 1);				}
	| READ '#' IDENTIFIER {    context_check( READ_BOL, $3 , 0);			}
	| WRITE exp_int {	gen_code( WRITE_INT, 1 );							}
	| WRITE '#' exp_bol {	gen_code( WRITE_BOL, 0 );						}
	| IDENTIFIER ASSGNOP exp_int { context_check( STORE, $1 , 1);   		}
	| IDENTIFIER ASSGNOP exp_bol { context_check( STORE, $1 , 0);   		}	
	| IF exp_int	{	$1 = (struct lbs *) newlblrec();
					$1->for_jmp_false = reserve_loc(); 					}
	  THEN commands	{ $1->for_goto = reserve_loc(); 					}
	  ELSE			{ back_patch( $1->for_jmp_false,
							JMP_FALSE,
							gen_label() ); 								}

		commands
	  FI		{ back_patch( $1->for_goto, GOTO, gen_label() ); 		}	
	| WHILE		{ $1 = (struct lbs *) newlblrec();
				  $1->for_goto = gen_label(); 							}


		exp_int		{ $1->for_jmp_false = reserve_loc();					}

	DO
		commands
	END			{ gen_code( GOTO, $1->for_goto );
				  back_patch( $1->for_jmp_false,
						JMP_FALSE,
						gen_label() );									}
	| IF exp_bol	{	$1 = (struct lbs *) newlblrec();
					$1->for_jmp_false = reserve_loc(); 					}
	  THEN commands	{ $1->for_goto = reserve_loc(); 					}
	  ELSE			{ back_patch( $1->for_jmp_false,
							JMP_FALSE,
							gen_label() ); 								}

		commands
	  FI		{ back_patch( $1->for_goto, GOTO, gen_label() ); 		}	
	| WHILE		{ $1 = (struct lbs *) newlblrec();
				  $1->for_goto = gen_label(); 							}


		exp_bol		{ $1->for_jmp_false = reserve_loc();					}

	DO
		commands
	END			{ gen_code( GOTO, $1->for_goto );
				  back_patch( $1->for_jmp_false,
						JMP_FALSE,
						gen_label() );									}
;
exp_int : NUMBER		{ gen_code( LD_INT, $1 );							}
	| IDENTIFIER	{ context_check( LD_VAR, $1 , -1);						}
	| exp_int '<' exp_int	{ gen_code( LT, 0 );								}
	| exp_int '=' exp_int	{ gen_code( EQ, 0 );								}
	| exp_int '>' exp_int	{ gen_code( GT, 0 );								}
	| exp_int '+' exp_int	{ gen_code( ADD, 0 );								}
	| exp_int '-' exp_int	{ gen_code( SUB, 0 );								}
	| exp_int '*' exp_int	{ gen_code( MULT, 0 );								}
	| exp_int '/' exp_int	{ gen_code( DIV, 0 );								}
	| exp_int '^' exp_int	{ gen_code( PWR, 0 );								}
	| '(' exp_int ')'
;
exp_bol :  BOOLEAN		{ gen_code_bool( LD_BOL, $1 );							}
	| IDENTIFIER	{ context_check( LD_VAR, $1 ,-1);						}
;
%%
/*=========================================================================
MAIN
=========================================================================*/
main( int argc, char *argv[] )
{   extern FILE *yyin;
	++argv; --argc;
	yyin = fopen( argv[0], "r" );
	
	/*yydebug = 1;*/
	errors = 0;
	yyparse ();
	printf ( "Parse Completed\n" );
	if ( errors == 0 )
	{	 
		FILE *fp = fopen("mc.txt","w+");
		print_code (fp);
		fclose(fp);
	}
}
/*=========================================================================
YYERROR
=========================================================================*/
yyerror ( char *s ) /* Called by yyparse on error */
{
errors++;
printf ("%s\n", s);
}
/**************************** End Grammar File ***************************/
