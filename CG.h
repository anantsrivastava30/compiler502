/***************************************************************************
								Code Generator
***************************************************************************/
/*-------------------------------------------------------------------------
								Data Segment
-------------------------------------------------------------------------*/
int data_offset = 0;	/* Initial offset */
int data_location()		/* Reserves a data location */
{
	return data_offset++;
}
/*-------------------------------------------------------------------------
								Code Segment
-------------------------------------------------------------------------*/
int code_offset = 0;	/* Initial offset */
int gen_label()			/* Returns current offset */
{
	return code_offset;
} 	
int reserve_loc()		/* Reserves a code location */
{
return code_offset++;
} 
						/* Generates code at current location */
void gen_code( enum code_ops operation, int arg )
{ code[code_offset].op = operation;
  code[code_offset++].arg = arg;
}

void gen_code_bool( enum code_ops operation, char *arg )
{ code[code_offset].op = operation;
  code[code_offset++].name = arg;
}

			/* Generates code at a reserved location	*/
void back_patch( int addr, enum code_ops operation, int arg )
{
code[addr].op = operation;
code[addr].arg = arg;
}
/*-------------------------------------------------------------------------
Print Code to stdio
-------------------------------------------------------------------------*/
void print_code( FILE *fp )
{
	int i = 0;
	while (i < code_offset) {
	if( strcmp(op_name[(int) code[i].op],"ld_bol") == 0 ) {
	fprintf(fp,"%3ld: %-10s %3s\n",i,op_name[(int) code[i].op], code[i].name );
		i++;		
		}
	else {
	fprintf(fp,"%3ld: %-10s%4ld\n",i,op_name[(int) code[i].op], code[i].arg );
		i++;
		}
	}
}
/************************** End Code Generator **************************/
