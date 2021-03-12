%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 extern int errLine;
 FILE * yyin;
 int yylex(void);
 int errors[1000];
 int errInd=0;
 int tmp=0;
 char code[10000][254];
 int top=0;
 int tmp2=0;
 int temp=0;
 int label=0;
 int param=0;
 int inLoop=0;
 char declared[10000][50];
 int d1=0;
 extern char defined[10000][100];
 int d2=0;
 char called[10000][50];
 int calls[10000];
 int call=0;
 int fCnt=0;
 char hasMain=0;
 char error=0;
 char arrNames[10000][254];
 int arr=0;
 char varNames[10000][254];
 int varInd=0;
%}

%union{
  double dval;
  int ival;
  char* str;
  
  struct VarStruct {
	char* name;
	char* tokentype;
	char* ret_name;
	char type[20];
	char ind_name[100];
  } var_struct;

  struct ArrayStruct {
	char* name;
	int size;
  } arr_struct;

  struct Declaration {
	  int start;
	  char type[20];
	  int size;
  } decl_struct;

  struct ReadWrite {
	  int start;
  } rw_struct;

  struct ExprStruct {
	char* name;
	int value;
	char* tokentype;
	char ret_name[80];
	char* next;
	int start;
	char type[20];
  } expr_struct;

  struct RelExprStruct {
	char ret_name[80];
	int start;
	char inner[50];
	char type[10];
	int done;
	int end;
	int outside;
	int stateStrt;
  } relexpr_struct;

  struct CompStruct {
	char* name;
  } comp_struct;

  struct StatementStruct {
	char* IR[254];
	int stateStrt;
	char ret_name[80];
  } statement_struct;

  struct FuncStruct {
	  char name[80];
	  int start;
	  char* IR[254];
  } func_struct;
}

%error-verbose
%start prog_start
%token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN EQ NEQ LT GT LTE GTE SUB ADD MULT DIV MOD
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP BREAK READ WRITE AND OR NOT TRUE FALSE RETURN
%token <ival> INTEGER
%token <str> IDENT
%left ADD SUB
%left MULT DIV
%type<var_struct> var;
%type<decl_struct> declaration1;
%type<decl_struct> declaration2;
%token<expr_struct> NUMBER;
%type<expr_struct> term2;
%type<expr_struct> term1;
%type<expr_struct> term;
%type<rw_struct> rfunc;
%type<rw_struct> wfunc;
%type<expr_struct> multexpr;
%type<expr_struct> expression;
%type<relexpr_struct> relexpr2;
%type<relexpr_struct> relexpr;
%type<relexpr_struct> relandexpr;
%type<relexpr_struct> boolexpr;
%type<relexpr_struct> TRUE;
%type<relexpr_struct> FALSE;
%type<relexpr_struct> while;
%type<relexpr_struct> dowhile;
%type<relexpr_struct> if;
%type<comp_struct> comp;
%type<statement_struct> statement;
%type<func_struct> function
%type<func_struct> functions
%type<func_struct> prog_start


%%
prog_start:	functions														{  }
			;

functions:	%empty															{  }
			| function functions                                          	{  }
			;

function:	FUNCTION IDENT SEMICOLON BEGIN_PARAMS funcparams				{ 	char c[] = "func ";
																				strcat(c, $2);
																				strcat(c, "\n");
																				strcpy($$.name, c);
																				tmp2++;
																				strcpy(defined[d2], $2);
																				if(strcmp(defined[d2], "main") == 0) hasMain = 1;
																				d2++;

																			  	for(int i = 0; i < call; i++) {
																					char found = 0;
																					for(int j = 0; j < d2; j++) {
																						if(strcmp(defined[j], called[i]) == 0) {
																							found = 1;
																							j = d2;
																						}
																					}
																					if(!found) {
																						printf("Error line %d: function \"%s\" called before definition.\n", calls[i], called[i]);
																						error = 1;
																					}
																			  	}

																				if(fCnt > 0) {
																					for(int i = 10000; i > top; i--) {
																						strcpy(code[i], code[i-1]);
																					}
																					strcpy(code[top], "endfunc\n\n");

																					for(int i = 10000; i > top+1; i--) {
																						strcpy(code[i], code[i-1]);
																					}
																					strcpy(code[top+1], $$.name);
																				}
																				else {
																					for(int i = 10000; i > top; i--) {
																						strcpy(code[i], code[i-1]);
																					}
																					strcpy(code[top], $$.name);
																				}
																				for(int i = top; i < 10000; i++) {
																					strcpy(declared[i], "");
																					strcpy(called[i], "");
																				}
																				d1 = 0;
																				call = 0;
																				top = tmp2;
																				fCnt++;
																			}
			| FUNCTION IDENT SEMICOLON BEGIN_PARAMS error			    	{ tmp--; printf("Syntax error at line %d: expecting \"declaration or endparams\"\n", errors[tmp]); }
			| FUNCTION IDENT SEMICOLON error funcparams			    		{ tmp--; printf("Syntax error at line %d: expecting \"beginparams\"\n", errors[tmp]); }
			| FUNCTION IDENT error BEGIN_PARAMS funcparams		    		{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
			| FUNCTION error SEMICOLON BEGIN_PARAMS funcparams				{ tmp--; printf("Syntax error at line %d: expecting \"identifier\"\n", errors[tmp]); }
			;

funcparams: declaration1 SEMICOLON funcparams                            	{  }
            | END_PARAMS BEGIN_LOCALS funclocals                        	{  }
			| declaration1 error funcparams									{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
			| END_PARAMS error funclocals									{ tmp--; printf("Syntax error at line %d: expecting \"beginlocals\"\n", errors[tmp]); }
			| END_PARAMS BEGIN_LOCALS error BEGIN_BODY funcbody				{ tmp--; printf("Syntax error at line %d: expecting \"declaration or endlocals\"\n", errors[tmp]); }
            ;

funclocals: declaration2 SEMICOLON funclocals                            	{  }
            | END_LOCALS BEGIN_BODY funcbody                            	{  }
			| declaration2 error funclocals									{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
			| END_LOCALS error funcbody										{ tmp--; printf("Syntax error at line %d: expecting \"beginbody\"\n", errors[tmp]); }
            ;

funcbody:   statement SEMICOLON END_BODY                                	{  }
            | statement SEMICOLON funcbody                             		{  }
			| statement SEMICOLON error										{ tmp--; printf("Syntax error at line %d: expecting \"statement or endbody\"\n", errors[tmp]); }
			| statement error funcbody										{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
			| error SEMICOLON END_BODY										{ tmp--; printf("Syntax error at line %d: expecting \"statement\"\n", errors[tmp]); }
			| statement error END_BODY										{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
			;

declaration1:  IDENT COMMA declaration1										{ 	
																				for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], $1) == 0) {
																						printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, $1);
																						error = 1;
																					}
																				}
																				if((strcmp($1, "true") == 0) || (strcmp($1, "false") == 0)) {
																					printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, $1);
																					error = 1;
																				}
																				strcpy(declared[d1], $1);
																				d1++;
																				
																				for(int i = tmp2; i > $3.start; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				if(strcmp($3.type, "var") == 0) {
																					char c[200];
																					sprintf(c, ". %s\n", $1);
																					strcpy(code[$3.start], c);
																					strcpy(varNames[varInd], $1);
																					varInd++;
																				}
																				else if(strcmp($3.type, "array") == 0) {
																					char c[200];
																			  		sprintf(c, ".[] %s, %d\n", $1, $3.size);
																					strcpy(code[$3.start], c);
																					strcpy(arrNames[arr], $1);
																			  		arr++;
																				}
																				$$.start = $3.start;
																				strcpy($$.type, $3.type);
																				$$.size = $3.size;
																			  	tmp2++;
																			}
			| IDENT COLON INTEGER											{	for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], $1) == 0) {
																						printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, $1);
																						error = 1;
																					}
																				}

																				if((strcmp($1, "true") == 0) || (strcmp($1, "false") == 0)) {
																					printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, $1);
																					error = 1;
																				}

																				strcpy(declared[d1], $1);
																				d1++;

																				strcpy(varNames[varInd], $1);
																				varInd++;
																				
																				char c[200];
																				sprintf(c, ". %s\n", $1);
																				strcpy(code[tmp2], c);
																				$$.start = tmp2;
																				strcpy($$.type, "var");
																				tmp2++;

																				char c1[200];
																				sprintf(c1, "= %s, $%d\n", $1, param);
																				strcpy(code[tmp2], c1);
																				strcpy($$.type, "var");
																				tmp2++;
																			}
			| IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER		{ 	for(int i = 0; i < d1; i++) {
																								if(strcmp(declared[i], $1) == 0) {
																									printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, $1);
																									error = 1;
																								}
																							}

																							if((strcmp($1, "true") == 0) || (strcmp($1, "false") == 0)) {
																								printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, $1);
																								error = 1;
																							}

																							if($5.value <= 0) {
																								printf("Error line %d: symbol \"%s\" has array index less than or equal to zero.\n", currLine, $1);
																								error = 1;
																							}

																							strcpy(declared[d1], $1);
																							d1++;

																							strcpy(arrNames[arr], $1);
																			  				arr++;
																							
																							char c[200];
																			  			  	sprintf(c, ".[] %s, %d\n", $1, $5.value);
																			  			  	strcpy(code[tmp2], c);
																							$$.start = tmp2;
																							strcpy($$.type, "array");
																							$$.size = $5.value;
																			  			  	tmp2++;
																						}
			| IDENT error													{ tmp--; printf("Syntax error at line %d: invalid declaration\n", errors[tmp]); }
			| error															{ tmp--; printf("Syntax error at line %d: expecting \"identifier, endparams, or endlocals\"\n", errors[tmp]); }
            ;

declaration2:  IDENT COMMA declaration2										{ 	for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], $1) == 0) {
																						printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, $1);
																						error = 1;
																					}
																				}

																				if((strcmp($1, "true") == 0) || (strcmp($1, "false") == 0)) {
																					printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, $1);
																					error = 1;
																				}

																				strcpy(declared[d1], $1);
																				d1++;
																				
																				for(int i = tmp2; i > $3.start; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				if(strcmp($3.type, "var") == 0) {
																					char c[200];
																					sprintf(c, ". %s\n", $1);
																					strcpy(code[$3.start], c);
																					strcpy(varNames[varInd], $1);
																					varInd++;
																				}
																				else if(strcmp($3.type, "array") == 0) {
																					char c[200];
																			  		sprintf(c, ".[] %s, %d\n", $1, $3.size);
																					strcpy(code[$3.start], c);
																					strcpy(arrNames[arr], $1);
																			  		arr++;
																				}
																				$$.start = $3.start;
																				strcpy($$.type, $3.type);
																				$$.size = $3.size;
																			  	tmp2++;
																			}
			| IDENT COLON INTEGER											{	for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], $1) == 0) {
																						printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, $1);
																						error = 1;
																					}
																				}

																				if((strcmp($1, "true") == 0) || (strcmp($1, "false") == 0)) {
																					printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, $1);
																					error = 1;
																				}

																				strcpy(declared[d1], $1);
																				d1++;

																				strcpy(varNames[varInd], $1);
																				varInd++;
																				
																				char c[200];
																				sprintf(c, ". %s\n", $1);
																				strcpy(code[tmp2], c);
																				$$.start = tmp2;
																				strcpy($$.type, "var");
																				tmp2++;
																			}
			| IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER		{ 	for(int i = 0; i < d1; i++) {
																								if(strcmp(declared[i], $1) == 0) {
																									printf("Error line %d: symbol \"%s\" is already defined.\n", currLine, $1);
																									error = 1;
																								}
																							}

																							if((strcmp($1, "true") == 0) || (strcmp($1, "false") == 0)) {
																								printf("Error line %d: symbol \"%s\" is a reserved keyword and cannot be used to declare variables.\n", currLine, $1);
																								error = 1;
																							}

																							if($5.value <= 0) {
																								printf("Error line %d: symbol \"%s\" has array index less than or equal to zero.\n", currLine, $1);
																								error = 1;
																							}

																							strcpy(declared[d1], $1);
																							d1++;

																							strcpy(arrNames[arr], $1);
																			  				arr++;
																							
																							char c[200];
																			  			  	sprintf(c, ".[] %s, %d\n", $1, $5.value);
																			  			  	strcpy(code[tmp2], c);
																							$$.start = tmp2;
																							strcpy($$.type, "array");
																							$$.size = $5.value;
																			  			  	tmp2++;
																						}
			| IDENT error													{ tmp--; printf("Syntax error at line %d: invalid declaration\n", errors[tmp]); }
			| error															{ tmp--; printf("Syntax error at line %d: expecting \"identifier, endparams, or endlocals\"\n", errors[tmp]); }
            ;

statement:  var ASSIGN expression											{ char c1[200];
																			  if(strcmp($1.type, "var") == 0) {
																				sprintf(c1, "= %s, %s\n", $1.name, $3.ret_name);
																				strcpy(code[tmp2], c1);
																			  }
																			  else if(strcmp($1.type, "array") == 0) {
																				  sprintf(c1, "[]= %s, %s, %s\n", $1.name, $1.ind_name, $3.ret_name);
																				  strcpy(code[tmp2], c1);
																			  }
																			  $$.stateStrt = $3.start;
																			  tmp2++;
																			}
        	| IF boolexpr THEN if 											{ if($4.done) {
																				
																				char c0[200];
																				sprintf(c0, ": __label__%d\n", label+1);
																				strcpy(code[$4.outside], c0);

																				for(int i = tmp2; i > $2.end; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				tmp2++;
																				for(int i = tmp2; i > $2.end; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				tmp2++;
																				for(int i = tmp2; i > $2.end; i--) {
																					strcpy(code[i], code[i-1]);
																				}

																				inLoop -= 1;

																				char c1[200];
																				sprintf(c1, "?:= __label__%d, %s\n", label, $2.ret_name);
																				strcpy(code[$2.end], c1);
																				tmp2++;

																				char c2[200];
																				sprintf(c2, ":= __label__%d\n", label+1);
																				strcpy(code[$2.end+1], c2);
																				tmp2++;

																				char c3[200];
																				sprintf(c3, ": __label__%d\n", label);
																				strcpy(code[$2.end+2], c3);
																				tmp2++;
																				label+=2;
																			  }
																			  $$.stateStrt = $2.start;

																			}
	    	| WHILE boolexpr BEGINLOOP while								{  if(strcmp($2.type, "nested") && $4.done) {
																				for(int i = tmp2; i > $2.end; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				tmp2++;
																				for(int i = tmp2; i > $2.end; i--) {
																					strcpy(code[i], code[i-1]);
																				}
																				tmp2++;
																				for(int i = tmp2; i > $2.end; i--) {
																					strcpy(code[i], code[i-1]);
																				}

																				inLoop -= 1;

																				char c1[200];
																				sprintf(c1, "?:= __label__%d, %s\n", label, $2.ret_name);
																				strcpy(code[$2.end], c1);
																				tmp2++;

																				char c2[200];
																				sprintf(c2, ":= __label__%d\n", label+1);
																				strcpy(code[$2.end+1], c2);
																				tmp2++;

																				char c3[200];
																				sprintf(c3, ": __label__%d\n", label);
																				strcpy(code[$2.end+2], c3);
																				tmp2++;
																				label+=2;
																			  }

																			  char c1[200];
																			  sprintf(c1, ":= __label__%d\n", label);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, ": __label__%d\n", label-1);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[200];
																			  sprintf(c3, ": __label__%d\n", label);
																			  tmp2++;

																			  for(int i = tmp2; i > $2.start; i--) {
																				  strcpy(code[i], code[i-1]);
																			  }
																			  strcpy(code[$2.start], c3);
																			  tmp2++;
																			  label++;
																			}
        	| DO BEGINLOOP dowhile											{ if($3.done) {

																				for(int i = tmp2; i > $3.stateStrt; i--) {
																					strcpy(code[i], code[i-1]);
																				}

																				char c3[200];
																				sprintf(c3, ": __label__%d\n", label);
																				strcpy(code[$3.stateStrt], c3);
																				tmp2++;

																				for(int i = $3.start; i <= $3.end; i++) {
																					strcpy(code[tmp2], code[i]);
																					tmp2++;
																				}

																				char c1[200];
																				sprintf(c1, "?:= __label__%d, %s\n", label, $3.ret_name);
																				strcpy(code[tmp2-1], c1);
																				tmp2++;

																				inLoop -= 1;
																				label++;
																			  }
																			}
	    	| READ rfunc													{  }
	    	| WRITE wfunc													{  }
			| READ var														{ char c1[200];
																			  sprintf(c1, ".< %s\n", $2.name);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			}
	    	| WRITE var														{ char c1[200];
																			  sprintf(c1, ".> %s\n", $2.name);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			}
	    	| BREAK															{ if(!inLoop) {
																				printf("Error line %d: break statement not within a loop.\n", currLine);
																				error = 1;
																			  }
																			}
	    	| RETURN expression												{ char c1[200];
																			  sprintf(c1, "ret __temp__%d\n", temp-1);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			}
			| var error	expression											{ tmp--; printf("Syntax error at line %d: expecting \":=\"\n", errors[tmp]); }
			| var ASSIGN error ADD expression								{ tmp--; printf("Syntax error at line %d: expecting \"expression\"\n", errors[tmp]); }
			| var ASSIGN error SUB expression								{ tmp--; printf("Syntax error at line %d: expecting \"expression\"\n", errors[tmp]); }
			| IF boolexpr error if											{ tmp--; printf("Syntax error at line %d: expecting \"then\"\n", errors[tmp]); }
			| WHILE boolexpr error while									{ tmp--; printf("Syntax error at line %d: expecting \"beginloop\"\n", errors[tmp]); }
			| WHILE boolexpr BEGINLOOP error statement						{ tmp--; printf("Syntax error at line %d: \"invalid statement\"\n", errors[tmp]); }
			| WHILE boolexpr BEGINLOOP error ENDLOOP						{ tmp--; printf("Syntax error at line %d: \"invalid statement\"\n", errors[tmp]); }
			| DO error dowhile												{ tmp--; printf("Syntax error at line %d: expecting \"beginloop\"\n", errors[tmp]); }
			| READ error													{ tmp--; printf("Syntax error at line %d: \"invalid read\"\n", errors[tmp]); }
			| WRITE error													{ tmp--; printf("Syntax error at line %d: \"invalid write\"\n", errors[tmp]); }
			| RETURN error													{ tmp--; printf("Syntax error at line %d: expecting \"return expression\"\n", errors[tmp]); }
			| WHILE error boolexpr											{ tmp--; printf("Syntax error at line %d: expecting \"while loop condition\"\n", errors[tmp]); }
        	;

if:   		statement SEMICOLON if											{ $$.done = $3.done; $$.outside = $3.outside; $$.stateStrt = $1.stateStrt; }
	    	| ELSE statement SEMICOLON if									{  }
	    	| ENDIF															{ $$.done = 1;
																			  $$.outside = tmp2;
																			  tmp2++;
																		    }
			| statement error if											{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
			| error															{ tmp--; printf("Syntax error at line %d: expecting \"else or endif\"\n", errors[tmp]); }
	    	;

while:  	statement SEMICOLON while										{ $$.done = $3.done; }
	    	| ENDLOOP														{ $$.done = 1; inLoop += 1; }
			| statement error while											{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
			| statement SEMICOLON error statement							{ tmp--; printf("Syntax error at line %d: expecting \"statement or endloop\"\n", errors[tmp]); }
			| statement SEMICOLON error	ENDLOOP								{ tmp--; printf("Syntax error at line %d: expecting \"statement or endloop\"\n", errors[tmp]); }
	    	;

dowhile:	 statement SEMICOLON dowhile									{ $$.done = $3.done; $$.stateStrt = $1.stateStrt; strcpy($$.ret_name, $3.ret_name); }
	    	| ENDLOOP WHILE boolexpr										{ $$.done = 1; inLoop += 1; strcpy($$.ret_name, $3.ret_name); $$.start = $3.start; $$.end = $3.end; }
			| statement error												{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]); }
			| error															{ tmp--; printf("Syntax error at line %d: expecting \"statement or endloop\"\n", errors[tmp]); }
			| ENDLOOP error													{ tmp--; printf("Syntax error at line %d: expecting \"while\"\n", errors[tmp]); }
			| ENDLOOP WHILE error											{ tmp--; printf("Syntax error at line %d: expecting \"boolean expression\"\n", errors[tmp]); }
	    	;

rfunc:     var COMMA rfunc												{ 	for(int i = tmp2; i > $3.start; i--) {
																					strcpy(code[i], code[i-1]);
																			  	}
																				char c[] = ".< ";
																			  	strcat(c, $1.name);
																			  	strcat(c, "\n");
																			  	strcpy(code[$3.start], c);
																			  	tmp2++;
																			}
			| var COMMA var													{ char c1[200];
																			  sprintf(c1, ".< %s\n", $1.name);
																			  strcpy(code[tmp2], c1);
																			  $$.start = tmp2;
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, ".< %s\n", $3.name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			}
			| var COMMA error												{ tmp--; printf("Syntax error at line %d: expecting \"var\"\n", errors[tmp]); }
 	    	;

wfunc:     var COMMA wfunc												{ 	for(int i = tmp2; i > $3.start; i--) {
																				strcpy(code[i], code[i-1]);
																			}
																			char c[] = ".> ";
																			strcat(c, $1.name);
																			strcat(c, "\n");
																			strcpy(code[$3.start], c);
																			tmp2++;
																			}
			| var COMMA var													{ char c1[200];
																			  sprintf(c1, ".> %s\n", $1.name);
																			  strcpy(code[tmp2], c1);
																			  $$.start = tmp2;
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, ".> %s\n", $3.name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			}
			| var COMMA error												{ tmp--; printf("Syntax error at line %d: expecting \"var\"\n", errors[tmp]); }
 	    	;

boolexpr:   relandexpr														{ $$.start = $1.start; $$.end = tmp2; }
	    	| relandexpr OR boolexpr										{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "|| __temp__%d, %s, %s\n", temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			  $$.start = $1.start;
																			  $$.end = tmp2;
																			}
	    	;

relandexpr: relexpr															{ strcpy($$.type, $1.type); $$.start = $1.start; $$.end = tmp2; }
	    	| relexpr AND relandexpr										{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "&& __temp__%d, %s, %s\n", temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			  $$.start = $1.start;
																			  $$.end = tmp2;
																			}
	    	;

relexpr:    NOT relexpr2													{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			  
																			  char c2[200];
																			  sprintf(c2, "! __temp__%d, %s\n", temp, $2.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);

																			  temp++;
																			  strcpy($$.type, $2.type);
																			  $$.start = $2.start;
																			  $$.end = tmp2;
																			}
	    	| relexpr2														{ strcpy($$.type, $1.type); $$.start = $1.start; $$.end = tmp2; }
	    	;

relexpr2:   expression comp expression										{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "%s __temp__%d, %s, %s\n", $2.name, temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			  $$.start = $1.start;
																			  $$.end = tmp2;
																			}
	    	| TRUE															{ $$.start = tmp2;
																			  char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "= __temp__%d, %d\n", temp, 1);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			}
	    	| FALSE															{ $$.start = tmp2;
																			  char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "= __temp__%d, %d\n", temp, 0);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			}
	    	| L_PAREN boolexpr R_PAREN										{ strcpy($$.ret_name, $2.ret_name); strcpy($$.type, "nested"); $$.start = $2.start; }
			| expression error												{ tmp--; printf("Syntax error at line %d: expecting \"comparison operator\"\n", errors[tmp]); }
	    	;

comp: 	    EQ																{ $$.name = "=="; }
	    	| NEQ															{ $$.name = "!="; }
	    	| LT															{ $$.name = "<"; }
	    	| GT															{ $$.name = ">"; }
	    	| LTE															{ $$.name = "<="; }
        	| GTE															{ $$.name = ">="; }
			| error															{ tmp--; printf("Syntax error at line %d: expecting \"comparison operator\"\n", errors[tmp]); }
	    	;

expression: multexpr														{ strcpy($$.ret_name, $1.ret_name); strcpy($$.type, $1.type); }
	    	| multexpr ADD expression										{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "+ __temp__%d, %s, %s\n", temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			  $$.start = $1.start;
																			}
			| multexpr SUB expression										{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "- __temp__%d, %s, %s\n", temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			  $$.start = $1.start;
																			}
	    	;

multexpr: 	term															{ strcpy($$.ret_name, $1.ret_name); strcpy($$.type, $1.type); }
			| term MULT multexpr											{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "* __temp__%d, %s, %s\n", temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			  $$.start = $1.start;
																			}
			| term DIV multexpr												{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "/ __temp__%d, %s, %s\n", temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			  $$.start = $1.start;
																			}
			| term MOD multexpr												{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "\% __temp__%d, %s, %s\n", temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp++;
																			  $$.start = $1.start;
																			}
			;

term:	    term1															{ strcpy($$.ret_name, $1.ret_name); strcpy($$.type, $1.type); }
	 		| SUB term1														{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c4[200];
																			  sprintf(c4, ". __temp__%d\n", temp+1);
																			  strcpy(code[tmp2], c4);
																			  tmp2++;

																			  char c5[200];
																			  sprintf(c5, "= __temp__%d, %d\n", temp+1, 0);
																			  strcpy(code[tmp2], c5);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "- __temp__%d, __temp__%d, %s\n", temp, temp+1, $2.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  temp+=2;
																			  $$.start = $2.start;
																			  strcpy($$.type, $2.type);
																			}
            | term2															{ strcpy($$.ret_name, $1.ret_name); strcpy($$.type, $1.type); }
	    	;								

term1: 	    var																{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  $$.start = tmp2;
																			  tmp2++;
																			  
																			  if(strcmp($1.type, "var") == 0) { 
																				char c2[200];
																				sprintf(c2, "= __temp__%d, %s\n", temp, $1.name);
																				strcpy(code[tmp2], c2);
																				tmp2++;
																			  }
																			  else if(strcmp($1.type, "array") == 0) { 
																				char c2[200];
																				sprintf(c2, "=[] __temp__%d, %s, %s\n", temp, $1.name, $1.ind_name);
																				strcpy(code[tmp2], c2);
																				tmp2++;
																			  }

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  strcpy($$.type, $1.type);
																			  temp++;
																			}
	    	| NUMBER														{ char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "= __temp__%d, %s\n", temp, $1.name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  $$.value = $1.value;
																			  temp++;
																			}
	    	| L_PAREN expression R_PAREN									{ strcpy($$.ret_name, $2.ret_name); }
	 		;

term2:      IDENT L_PAREN term3 R_PAREN										{ strcpy(called[call], $1);
																			  calls[call] = currLine;
																			  call++;
																			  char c1[200];
																			  sprintf(c1, ". __temp__%d\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[200];
																			  sprintf(c2, "call %s, __temp__%d\n", $1, temp);
																			  strcpy(code[tmp2], c2);

																			  char c3[50];
																			  sprintf(c3, "__temp__%d", temp);
																			  strcpy($$.ret_name, c3);
																			  tmp2++;
																			  temp++;
																			}
	    	;

term3:	    %empty															{  }
	    	| expression													{ char c1[200];
																			  sprintf(c1, "param %s\n", $1.ret_name);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			}
	    	| expression COMMA term3										{  }
	    	; 

var: 		IDENT															{ strcpy($$.type, "var");
																			  char found = 0;
																			  for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], $1) == 0) {
																						found = 1;
																					}
																			  }

																			  if(!found) {
																				  printf("Error line %d: used variable \"%s\" was not previously declared.\n", currLine, $1);
																				  error = 1;
																			  }

																			  for(int i = 0; i < arr; i++) {
																					if(strcmp(arrNames[i], $1) == 0) {
																						printf("Error line %d: used array variable \"%s\" without specifying index.\n", currLine, $1);
																				  		error = 1;
																					}
																			  }
																			}
	    	| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET			{ strcpy($$.type, "array");
																			  strcpy($$.ind_name, $3.ret_name);
																			  char found = 0;
																			  for(int i = 0; i < d1; i++) {
																					if(strcmp(declared[i], $1) == 0) {
																						found = 1;
																					}
																			  }
																			  if(!found) {
																				  printf("Error line %d: used variable \"%s\" was not previously declared.\n", currLine, $1);
																				  error = 1;
																			  }

																			  for(int i = 0; i < varInd; i++) {
																					if(strcmp(varNames[i], $1) == 0) {
																						printf("Error line %d: specified array index for symbol \"%s\" which is a non-array variable.\n", currLine, $1);
																				  		error = 1;
																					}
																			  }
																			}
     		;
%%

int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   fclose(yyin);
   if(!hasMain) {
	   printf("Error: no main function definition is given.\n");
	   return 0;
   }
   else if(error) return 0;

   FILE *fp;
   fp = fopen("mil_code.mil", "w+");

   for(int i = 0; i < 10000; i++) {
	   fprintf(fp, code[i]);
   }
   fprintf(fp, "endfunc\n\n");
   fclose(fp);

   return 0;
}

void yyerror(const char *msg) {
	// errLine = currLine;
	errors[tmp] = currLine;
	tmp++;
	printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
