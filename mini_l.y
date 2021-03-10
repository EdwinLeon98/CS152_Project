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
 int tmp2=0;
 int temp=0;
%}

%union{
  double dval;
  int ival;
  char* str;
  
  struct VarStruct {
	char* name;
	char* tokentype;
	char* ret_name;
  } var_struct;

  struct ExprStruct {
	char* name;
	int value;
	char* tokentype;
	char* ret_name;
	char* next;
  } expr_struct;

  struct RelExprStruct {
	char* ret_name;
  } relexpr_struct;

  struct CompStruct {
	char* name;
  } comp_struct;
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
%token<expr_struct> NUMBER;
%type<expr_struct> term1;
%type<expr_struct> term;
%type<expr_struct> multexpr;
%type<expr_struct> expression;
%type<relexpr_struct> relexpr2;
%type<comp_struct> comp;


%%
prog_start:	functions														{printf("prog_start -> functions\n");}
			;

functions:	%empty															{printf("functions -> epsilon\n");}
			| function functions                                          	{printf("functions -> function functions\n");}
			;

function:	FUNCTION IDENT SEMICOLON BEGIN_PARAMS funcparams			    { char c[] = "func "; strcat(c, $2); strcat(c, "\n"); strcpy(code[tmp2], c); tmp2++;}
			| FUNCTION IDENT SEMICOLON BEGIN_PARAMS error			    	{ tmp--; printf("Syntax error at line %d: expecting \"declaration or endparams\"\n", errors[tmp]);}
			| FUNCTION IDENT SEMICOLON error funcparams			    		{ tmp--; printf("Syntax error at line %d: expecting \"beginparams\"\n", errors[tmp]);}
			| FUNCTION IDENT error BEGIN_PARAMS funcparams		    		{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]);}
			| FUNCTION error SEMICOLON BEGIN_PARAMS funcparams				{ tmp--; printf("Syntax error at line %d: expecting \"identifier\"\n", errors[tmp]);}
			;

funcparams: declaration SEMICOLON funcparams                            	{ printf("funcparams -> declaration SEMICOLON funcparams\n");}
            | END_PARAMS BEGIN_LOCALS funclocals                        	{ printf("funcparams -> END_PARAMS BEGIN_LOCALS funclocals\n");}
			| declaration error funcparams									{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]);}
			| END_PARAMS error funclocals									{ tmp--; printf("Syntax error at line %d: expecting \"beginlocals\"\n", errors[tmp]);}
			| END_PARAMS BEGIN_LOCALS error BEGIN_BODY funcbody				{ tmp--; printf("Syntax error at line %d: expecting \"declaration or endlocals\"\n", errors[tmp]);}
            ;

funclocals: declaration SEMICOLON funclocals                            	{ printf("funclocals -> declaration SEMICOLON funclocals\n");}
            | END_LOCALS BEGIN_BODY funcbody                            	{ printf("funclocals -> END_LOCALS BEGIN_BODY funcbody\n");}
			| declaration error funclocals									{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]);}
			| END_LOCALS error funcbody										{ tmp--; printf("Syntax error at line %d: expecting \"beginbody\"\n", errors[tmp]);}
            ;

funcbody:   statement SEMICOLON END_BODY                                	{ printf("funcbody -> statement SEMICOLON END_BODY\n");}
            | statement SEMICOLON funcbody                             		{ printf("funcbody -> statement SEMICOLON statement\n");}
			| statement SEMICOLON error										{ tmp--; printf("Syntax error at line %d: expecting \"statement or endbody\"\n", errors[tmp]);}
			| statement error funcbody										{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]);}
			| error SEMICOLON END_BODY										{ tmp--; printf("Syntax error at line %d: expecting \"statement\"\n", errors[tmp]);}
			| statement error END_BODY										{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]);}
			;

declaration:  IDENT COMMA declaration										{ char c[] = ". "; strcat(c, $1); strcat(c, "\n"); strcpy(code[tmp2], c); tmp2++;}
            | IDENT COLON array												{ char c[] = ". "; strcat(c, $1); strcat(c, "\n"); strcpy(code[tmp2], c); tmp2++;}
			| IDENT error													{ tmp--; printf("Syntax error at line %d: invalid declaration\n", errors[tmp]);}
			| error															{ tmp--; printf("Syntax error at line %d: expecting \"identifier, endparams, or endlocals\"\n", errors[tmp]);}
            ;

array: 	    INTEGER															{ printf("array -> INTEGER\n");}
            | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER		{ printf("array -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
            ;

statement:  var ASSIGN expression											{ char c1[254];
																			  sprintf(c1, "= %s, %s\n", $1.name, $3.ret_name);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;
																			}
        	| IF boolexpr THEN if 											{ printf("statement -> IF boolexpr THEN if\n");}
	    	| WHILE boolexpr BEGINLOOP while								{ printf("statement -> WHILE boolexpr BEGINLOOP while\n");}
        	| DO BEGINLOOP dowhile											{ printf("statement -> DO BEGINLOOP dowhile\n");}
	    	| READ rwfunc													{ printf("statement -> READ rwfunc\n");}
	    	| WRITE rwfunc													{ printf("statement -> WRITE rwfunc\n");}
			| READ var														{ printf("statement -> READ var\n");}
	    	| WRITE var														{ printf("statement -> WRITE var\n");}
	    	| BREAK															{ printf("statement -> BREAK\n");}
	    	| RETURN expression												{ printf("statement -> RETURN expression\n");}
			| var error	expression											{ tmp--; printf("Syntax error at line %d: expecting \":=\"\n", errors[tmp]);}
			| var ASSIGN error ADD expression								{ tmp--; printf("Syntax error at line %d: expecting \"expression\"\n", errors[tmp]);}
			| var ASSIGN error SUB expression								{ tmp--; printf("Syntax error at line %d: expecting \"expression\"\n", errors[tmp]);}
			| IF boolexpr error if											{ tmp--; printf("Syntax error at line %d: expecting \"then\"\n", errors[tmp]);}
			| WHILE boolexpr error while									{ tmp--; printf("Syntax error at line %d: expecting \"beginloop\"\n", errors[tmp]);}
			| WHILE boolexpr BEGINLOOP error statement						{ tmp--; printf("Syntax error at line %d: \"invalid statement\"\n", errors[tmp]);}
			| WHILE boolexpr BEGINLOOP error ENDLOOP						{ tmp--; printf("Syntax error at line %d: \"invalid statement\"\n", errors[tmp]);}
			| DO error dowhile												{ tmp--; printf("Syntax error at line %d: expecting \"beginloop\"\n", errors[tmp]);}
			| READ error													{ tmp--; printf("Syntax error at line %d: \"invalid read\"\n", errors[tmp]);}
			| WRITE error													{ tmp--; printf("Syntax error at line %d: \"invalid write\"\n", errors[tmp]);}
			| RETURN error													{ tmp--; printf("Syntax error at line %d: expecting \"return expression\"\n", errors[tmp]);}
			| WHILE error boolexpr2											{ tmp--; printf("Syntax error at line %d: expecting \"while loop condition\"\n", errors[tmp]);}
        	;

if:   		statement SEMICOLON if											{ printf("if -> statement SEMICOLON if\n");}
	    	| ELSE statement SEMICOLON if									{ printf("if -> ELSE statement SEMICOLON if\n");}
	    	| ENDIF															{ printf("if -> ENDIF\n");}
			| statement error if											{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]);}
			| error															{ tmp--; printf("Syntax error at line %d: expecting \"else or endif\"\n", errors[tmp]);}
	    	;

while:  	statement SEMICOLON while										{ printf("while -> statement SEMICOLON while\n");}
	    	| ENDLOOP														{ printf("while -> ENDLOOP\n");}
			| statement error while											{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]);}
			| statement SEMICOLON error statement							{ tmp--; printf("Syntax error at line %d: expecting \"statement or endloop\"\n", errors[tmp]);}
			| statement SEMICOLON error	ENDLOOP								{ tmp--; printf("Syntax error at line %d: expecting \"statement or endloop\"\n", errors[tmp]);}
	    	;

dowhile:	 statement SEMICOLON dowhile									{ printf("dowhile -> statement SEMICOLON dowhile\n");}
	    	| ENDLOOP WHILE boolexpr										{ printf("dowhile -> ENDLOOP WHILE boolexpr\n");}
			| statement error												{ tmp--; printf("Syntax error at line %d: expecting \";\"\n", errors[tmp]);}
			| error															{ tmp--; printf("Syntax error at line %d: expecting \"statement or endloop\"\n", errors[tmp]);}
			| ENDLOOP error													{ tmp--; printf("Syntax error at line %d: expecting \"while\"\n", errors[tmp]);}
			| ENDLOOP WHILE error											{ tmp--; printf("Syntax error at line %d: expecting \"boolean expression\"\n", errors[tmp]);}
	    	;

rwfunc:     var COMMA rwfunc												{ printf("rwfunc -> var COMMA rwfunc\n");}
			| var COMMA var													{ printf("rwfunc -> var COMMA rwfunc\n");}
			| var COMMA error												{ tmp--; printf("Syntax error at line %d: expecting \"var\"\n", errors[tmp]);}
 	    	;

boolexpr:   relandexpr														{ printf("boolexpr -> relandexpr\n");}
	    	| relandexpr boolexpr2											{ printf("boolexpr -> relandexpr boolexpr2\n");}
	    	;

boolexpr2:  OR relandexpr boolexpr2											{ printf("boolexpr2 -> OR relandexpr boolexpr2\n");}
	    	| OR relandexpr													{ printf("boolexpr2 -> OR relandexpr\n");}
	    	;

relandexpr: relexpr															{ printf("relandexpr -> relexpr\n");}
	    	| relexpr relandexpr2											{ printf("relandexpr -> relexpr relandexpr2\n");}
	    	;

relandexpr2: AND relexpr relandexpr2										{ printf("relandexpr2 -> AND relexpr relandexpr2\n");}
	    	| AND relexpr													{ printf("relandexpr2 -> AND relexpr\n");}
	    	;

relexpr:    NOT relexpr2													{  }
	    	| relexpr2														{  }
	    	;

relexpr2:   expression comp expression										{ char c1[254];
																			  sprintf(c1, ". __temp%d__\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[254];
																			  sprintf(c2, "%s __temp%d__, %s, %s\n", $2.name, temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[20];
																			  sprintf(c3, "__temp%d__", temp);
																			  $$.ret_name = c3;
																			  temp++;
																			}
	    	| TRUE															{  }
	    	| FALSE															{  }
	    	| L_PAREN boolexpr R_PAREN										{  }
			| expression error												{ tmp--; printf("Syntax error at line %d: expecting \"comparison operator\"\n", errors[tmp]);}
	    	;

comp: 	    EQ																{ $$.name = "=="; }
	    	| NEQ															{ $$.name = "<>"; }
	    	| LT															{ $$.name = "<"; }
	    	| GT															{ $$.name = ">"; }
	    	| LTE															{ $$.name = "<="; }
        	| GTE															{ $$.name = ">="; }
			| error															{ tmp--; printf("Syntax error at line %d: expecting \"comparison operator\"\n", errors[tmp]);}
	    	;

expression: multexpr														{  }
	    	| multexpr ADD expression										{  }
			| multexpr SUB expression										{  }
	    	;

multexpr: 	term															{  }
			| term MULT multexpr											{  }
			| term DIV multexpr												{ char c1[254];
																			  sprintf(c1, ". __temp%d__\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[254];
																			  sprintf(c2, "/ __temp%d__, %s, %s\n", temp, $1.ret_name, $3.ret_name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;
																			  
																			  char c3[20];
																			  sprintf(c3, "__temp%d__", temp);
																			  $$.ret_name = c3;
																			  temp++;
																			}
			| term MOD multexpr												{ }
			;

term:	    term1															{  }
	 		| SUB term1														{ }
            | term2															{ }
	    	;								

term1: 	    var																{ char c1[254];
																			  sprintf(c1, ". __temp%d__\n", temp);
																			  strcpy(code[tmp2], c1);
																			  tmp2++;

																			  char c2[254];
																			  sprintf(c2, "= __temp%d__, %s\n", temp, $1.name);
																			  strcpy(code[tmp2], c2);
																			  tmp2++;

																			  char c3[20];
																			  sprintf(c3, "__temp%d__", temp);
																			  $$.ret_name = strdup(c3);
																			  temp++;
																			}
	    	| NUMBER														{ $$.name = $1.name; $$.value = $1.value; }
	    	| L_PAREN expression R_PAREN									{ }
	 		;

term2:      IDENT L_PAREN term3 R_PAREN										{ }
	    	;

term3:	    %empty															{ }
	    	| expression													{ }
	    	| expression COMMA term3										{ }
	    	; 

var: 		IDENT															{  }
	    	| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET			{ char c[] = "=[] "; strcat(c, $1); strcat(c, "\n"); strcpy(code[tmp2], c); tmp2++;}
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
   for(int i = 0; i < 10000; i++) {
   	  printf(code[i]);
   }
   return 0;
}

void yyerror(const char *msg) {
	// errLine = currLine;
	errors[tmp] = currLine;
	tmp++;
	printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
