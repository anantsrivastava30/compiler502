/***************************************************************************
					Scanner for the Simple language
***************************************************************************/
%{
/*=========================================================================
				C-libraries and Token definitions
=========================================================================*/
#include <string.h>			/* for strdup */
/*#include <stdlib.h> */	/* for atoi */
#include "flash.tab.h" 	/* for token definitions and yylval */
%}
/*=========================================================================
							TOKEN Definitions
=========================================================================*/
DIGIT	[0-9]
ID		[a-z][a-z0-9]*
BOOL	[t][r][u][e]|[f][a][l][s][e]
/*=========================================================================
	REGULAR EXPRESSIONS defining the tokens for the Simple language
=========================================================================*/
%%
":="		{ return(ASSGNOP); 	}
{DIGIT}+ 	{ yylval.intval = atoi( yytext );
			  return(NUMBER);	}
{BOOL}+ 	{ yylval.boolval = (char *) strdup(yytext);
			  return(BOOLEAN);	}			  
do			{ return(DO);		}
else		{ return(ELSE);		}
end			{ return(END);		}
fi			{ return(FI);		}
if			{ return(IF);		}
in			{ return(IN);		}
integer 	{ return(INTEGER); 	}
boolean		{ return(BOOLE);	}
let			{ return(LET);		}
read		{ return(READ);		}
skip		{ return(SKIP);		}
then		{ return(THEN);		}
while		{ return(WHILE);	}
write		{ return(WRITE);	}
{ID}		{ yylval.id = (char *) strdup(yytext);
			  return(IDENTIFIER);}
[ \t\n]+ /* eat up whitespace */
.			{ return(yytext[0]);}
%%
int yywrap(void){}
/************************** End Scanner File *****************************/
