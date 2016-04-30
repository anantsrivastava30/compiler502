/*=========================================================================
TEAM : Team 31, Team Flash, Very Fast Much Wow.

Members : Anant Srivastava
		  Bharat Singh
		  Wenbo Tian
		  Vidyaabharathi Vasudevan

Build Using : FLEX(2.6.0), BISON (GNU 3.0.4), C;		  

References : Compiler Construction using Flex and Bison,
						Anthony A. Aaby,
			 		email :	aabyan@wwc.edu
			 	  version of Feburary 25,2004.
	OPEN PUBLIC LISCENCE : https://opencontent.org/openpub
=========================================================================*/

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

void gen_code_def( enum code_ops operation,char *sym,  char *arg )
{ code[code_offset].op = operation;
  char *outFile = malloc(10);
  strcpy(outFile, sym);
  strcat(outFile, "%");
  strcat(outFile, arg);
  code[code_offset++].name = outFile;
}

void gen_code_bool_str( enum code_ops operation, char *arg )
{
  code[code_offset].op = operation;
  code[code_offset++].name = arg;
}

void gen_fun(enum code_ops operation, char *arg)
{
  code[code_offset].op = operation;
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
	else if (strcmp(op_name[(int) code[i].op],"def") == 0 ){
		fprintf(fp,"%3ld: %-10s %3s\n",i,op_name[(int) code[i].op], code[i].name );
		i++;
	}
	else if( strcmp(op_name[(int) code[i].op],"ld_str") == 0 ) {
		fprintf(fp,"%3ld: %-10s %3s\n",i,op_name[(int) code[i].op], code[i].name );
		i++;
	}
	else if( strcmp(op_name[(int) code[i].op],"fun_init") == 0 ) {
		fprintf(fp,"%3ld: %-10s %3s\n",i,op_name[(int) code[i].op], code[i].name );
		i++;
	}
	else if( strcmp(op_name[(int) code[i].op],"call") == 0) {
		fprintf(fp,"%3ld: %-10s %3s\n",i,op_name[(int) code[i].op], code[i].name );
		i++;
	}
	else if( strcmp(op_name[(int) code[i].op],"ld_var") == 0 || strcmp(op_name[(int) code[i].op],"addstk") == 0 || strcmp(op_name[(int) code[i].op],"remstk") == 0) {
		fprintf(fp,"%3ld: %-10s %3s\n",i,op_name[(int) code[i].op], code[i].name );
		i++;
	}
	else if( strcmp(op_name[(int) code[i].op],"arg") == 0 || strcmp(op_name[(int) code[i].op],"store") == 0) {
		fprintf(fp,"%3ld: %-10s %3s\n",i,op_name[(int) code[i].op], code[i].name );
		i++;
	}
	else if( strcmp(op_name[(int) code[i].op],"para_int") == 0 || strcmp(op_name[(int) code[i].op],"para_bool") == 0 || strcmp(op_name[(int) code[i].op],"para_str") == 0) {
		fprintf(fp,"%3ld: %-10s %3s\n",i,op_name[(int) code[i].op], code[i].name );
		i++;
	}
	else if( strcmp(op_name[(int) code[i].op],"read_int") == 0 || strcmp(op_name[(int) code[i].op],"read_bool") == 0 || strcmp(op_name[(int) code[i].op],"read_str") == 0) {
		fprintf(fp,"%3ld: %-10s %3s\n",i,op_name[(int) code[i].op], code[i].name );
		i++;
	}
	else if( strcmp(op_name[(int) code[i].op],"in_int") == 0 || strcmp(op_name[(int) code[i].op],"in_bool") == 0 || strcmp(op_name[(int) code[i].op],"in_str") == 0) {
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
