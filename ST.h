/***************************************************************************
							Symbol Table Module
***************************************************************************/
/*=========================================================================
								DECLARATIONS
=========================================================================*/

/*=========================================================================
								DECLARATIONS
=========================================================================*/
/* OPERATIONS: Internal Representation */
enum code_ops { HALT, STORE, JMP_FALSE, GOTO,
				DATA, LD_INT, LD_VAR, LD_BOL, LD_STR,
				FUN_INIT, FUN_EN, POP, FUN_CALL,
				PARA_INT, PARA_BOOL, PARA_STR, ARG,
				READ_INT, WRITE_INT,
				READ_BOL, WRITE_BOL,
				READ_STR, WRITE_STR,
				LT, EQ, GT, ADD, SUB, MULT, DIV, PWR, DEF, ADD_STR,
				ADDSTK, REMSTK,
				GTEQ, LTEQ,
				AND, OR};
			
/* OPERATIONS: External Representation */

char *op_name[] = {"halt", "store", "jmp_false", "goto",
					"data", "ld_int", "ld_var", "ld_bol", "ld_str",
					"fun_init", "fun_end", "pop","call",
					"para_int", "para_bol", "para_str", "arg",
					"in_int", "out_int",
					"in_bol", "out_bol",
					"in_str", "out_str",
					"lt", "eq", "gt", "add", "sub", "mult", "div", "pwr", "def", "add_str",
					"addstk", "remstk",
					"gteq", "lteq",
					"and", "or"};


/*-------------------------------------------------------------------------
								Code
-------------------------------------------------------------------------*/					
struct instruction
{
	enum code_ops op;
	int arg;
	char * name;
};

/* CODE Array */

struct instruction code[999];

/* RUN-TIME Stack */

int stack[999];

/*-------------------------------------------------------------------------
							SYMBOL TABLE RECORD
-------------------------------------------------------------------------*/
struct symrec
{
	char *name; /* name of symbol */
	int offset; /* data offset */
	int type;  /*	1:integer 0:boolean, 2:string, 3:function 4:Stack*/
	struct symrec *next; /* link field */
	int block_offset;	/* block structure */
};
typedef struct symrec symrec;

/*-------------------------------------------------------------------------
								SYMBOL TABLE ENTRY
-------------------------------------------------------------------------*/
symrec *identifier;

/*-------------------------------------------------------------------------
							SYMBOL TABLE
					Implementation: a chain of records.
------------------------------------------------------------------------*/
symrec *sym_table = (symrec *)0; /* The pointer to the Symbol Table */

/*========================================================================
Operations: Putsym, Getsym
========================================================================*/

symrec * putsym (char *sym_name, int type, int block)
{
	symrec *ptr;
	ptr = (symrec *) malloc (sizeof(symrec));
	ptr->name = (char *) malloc (strlen(sym_name)+1);
	ptr->type = type;
	ptr->block_offset = block;
	strcpy (ptr->name,sym_name);
	ptr->offset = data_location();
	ptr->next = (struct symrec *)sym_table;
	sym_table = ptr;
	return ptr;
}
symrec * getsym (char *sym_name)
{
	symrec *ptr;
	for ( ptr = sym_table;
		ptr != (symrec *) 0;
		ptr = (symrec *)ptr->next )
		if (strcmp (ptr->name,sym_name) == 0)
			return ptr;
	return 0;
}
/************************** End Symbol Table **************************/
