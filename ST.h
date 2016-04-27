/***************************************************************************
							Symbol Table Module
***************************************************************************/
/*=========================================================================
								DECLARATIONS
=========================================================================*/

/*-------------------------------------------------------------------------
							SYMBOL TABLE RECORD
-------------------------------------------------------------------------*/
struct symrec
{
	char *name; /* name of symbol */
	int offset; /* data offset */
	int type;  /*	0:integer 1:boolean, 2:string, 3:function 4:Stack*/
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
