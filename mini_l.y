%{
 #include <stdio.h>
 #include <stdlib.h>
 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 FILE * yyin;
 int yylex(void);
%}

%union{
  double dval;
  int ival;
  char* str;
}

%error-verbose
%start program
%token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN EQ NEQ LT GT LTE GTE SUB ADD MULT DIV MOD
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP BREAK READ WRITE AND OR NOT TRUE FALSE RETURN
%token <dval> NUMBER
%token <ival> INTEGER
%token <str> IDENT
%left ADD SUB
%left MULT DIV


%%
program:	%empty															{printf("program -> epsilon\n");}
			| function program                                          	{printf("program -> function program\n");}
			;

function:	FUNCTION IDENT SEMICOLON BEGIN_PARAMS funcparams			    { printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS\n"); free($2);}
			| FUNCTION IDENT SEMICOLON BEGIN_PARAMS error			    	{ printf("Syntax error at line %d: expecting \"declaration or endparams\"\n", currLine); return 0;}
			| FUNCTION IDENT SEMICOLON error			    				{ printf("Syntax error at line %d: expecting \"beginparams\"\n", currLine); return 0;}
			| FUNCTION IDENT error			    							{ printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
			| FUNCTION error			    								{ printf("Syntax error at line %d: expecting \"identifier\"\n", currLine); return 0;}
			;

funcparams: declaration SEMICOLON funcparams                            	{ printf("funcparams -> declaration SEMICOLON funcparams\n");}
            | END_PARAMS BEGIN_LOCALS funclocals                        	{ printf("funcparams -> END_PARAMS BEGIN_LOCALS funclocals\n");}
			| declaration error												{ printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
			| END_PARAMS error												{ printf("Syntax error at line %d: expecting \"beginlocals\"\n", currLine); return 0;}
			| END_PARAMS BEGIN_LOCALS error									{ printf("Syntax error at line %d: expecting \"declaration or endlocals\"\n", currLine); return 0;}
            ;

funclocals: declaration SEMICOLON funclocals                            	{ printf("funclocals -> declaration SEMICOLON funclocals\n");}
            | END_LOCALS BEGIN_BODY funcbody                            	{ printf("funclocals -> END_LOCALS BEGIN_BODY funcbody\n");}
			| declaration error												{ printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
			| END_LOCALS error												{ printf("Syntax error at line %d: expecting \"beginbody\"\n", currLine); return 0;}
            ;

funcbody:   statement SEMICOLON END_BODY                                	{ printf("funcbody -> statement SEMICOLON END_BODY\n");}
            | statement SEMICOLON funcbody                             		{ printf("funcbody -> statement SEMICOLON statement\n");}
			| statement SEMICOLON error										{ printf("Syntax error at line %d: expecting \"statement or endbody\"\n", currLine); return 0;}
			| statement error												{ printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
			;

declaration:  IDENT COMMA declaration										{ printf("declaration -> IDENT COMMA declaration\n"); free($1);}
            | IDENT COLON array												{ printf("declaration -> IDENT COLON array\n"); free($1);}
			| IDENT error													{ printf("Syntax error at line %d: invalid declaration\n", currLine); return 0;}
			| error															{ printf("Syntax error at line %d: expecting \"identifier, endparams, or endlocals\"\n", currLine); return 0;}
            ;

array: 	    INTEGER															{ printf("array -> INTEGER\n");}
            | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER		{ printf("array -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
            ;

statement:  var ASSIGN expression											{ printf("statement -> var ASSIGN expression\n");}
        	| IF boolexpr THEN if 											{ printf("statement -> IF boolexpr THEN if\n");}
	    	| WHILE boolexpr BEGINLOOP while								{ printf("statement -> WHILE boolexpr BEGINLOOP while\n");}
        	| DO BEGINLOOP dowhile											{ printf("statement -> DO BEGINLOOP dowhile\n");}
	    	| READ rwfunc													{ printf("statement -> READ rwfunc\n");}
	    	| WRITE rwfunc													{ printf("statement -> WRITE rwfunc\n");}
			| READ var														{ printf("statement -> READ var\n");}
	    	| WRITE var														{ printf("statement -> WRITE var\n");}
	    	| BREAK															{ printf("statement -> BREAK\n");}
	    	| RETURN expression												{ printf("statement -> RETURN expression\n");}
			| var error														{ printf("Syntax error at line %d: expecting \":=\"\n", currLine); return 0;}
			| var ASSIGN error												{ printf("Syntax error at line %d: expecting \"expression\"\n", currLine); return 0;}
			| IF boolexpr error												{ printf("Syntax error at line %d: expecting \"then\"\n", currLine); return 0;}
			| WHILE boolexpr error											{ printf("Syntax error at line %d: expecting \"beginloop\"\n", currLine); return 0;}
			| WHILE boolexpr BEGINLOOP error								{ printf("Syntax error at line %d: \"invalid statement\"\n", currLine); return 0;}
			| DO error														{ printf("Syntax error at line %d: expecting \"beginloop\"\n", currLine); return 0;}
			| READ error													{ printf("Syntax error at line %d: \"invalid read\"\n", currLine); return 0;}
			| WRITE error													{ printf("Syntax error at line %d: \"invalid write\"\n", currLine); return 0;}
			| RETURN error													{ printf("Syntax error at line %d: expecting \"return expression\"\n", currLine); return 0;}
			| WHILE error													{ printf("Syntax error at line %d: expecting \"while loop condition\"\n", currLine); return 0;}
        	;

if:   		statement SEMICOLON if											{ printf("if -> statement SEMICOLON if\n");}
	    	| ELSE statement SEMICOLON if									{ printf("if -> ELSE statement SEMICOLON if\n");}
	    	| ENDIF															{ printf("if -> ENDIF\n");}
			| statement error												{ printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
			| error															{ printf("Syntax error at line %d: expecting \"else or endif\"\n", currLine); return 0;}
	    	;

while:  	statement SEMICOLON while										{ printf("while -> statement SEMICOLON while\n");}
	    	| ENDLOOP														{ printf("while -> ENDLOOP\n");}
			| statement error												{ printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
			| statement SEMICOLON error										{ printf("Syntax error at line %d: expecting \"statement or endloop\"\n", currLine); return 0;}
	    	;

dowhile:	 statement SEMICOLON dowhile									{ printf("dowhile -> statement SEMICOLON dowhile\n");}
	    	| ENDLOOP WHILE boolexpr										{ printf("dowhile -> ENDLOOP WHILE boolexpr\n");}
			| statement error												{ printf("Syntax error at line %d: expecting \";\"\n", currLine); return 0;}
			| error															{ printf("Syntax error at line %d: expecting \"endloop\"\n", currLine); return 0;}
			| ENDLOOP error													{ printf("Syntax error at line %d: expecting \"while\"\n", currLine); return 0;}
			| ENDLOOP WHILE error											{ printf("Syntax error at line %d: expecting \"boolean expression\"\n", currLine); return 0;}
	    	;

rwfunc:     var COMMA rwfunc												{ printf("rwfunc -> var COMMA rwfunc\n");}
			| var COMMA var													{ printf("rwfunc -> var COMMA rwfunc\n");}
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

relexpr:    NOT relexpr2													{ printf("relexpr -> NOT relexpr2\n");}
	    	| relexpr2														{ printf("relexpr -> relexpr2\n");}
	    	;

relexpr2:   expression comp expression										{ printf("relexpr2 -> expression comp expression\n");}
	    	| TRUE															{ printf("relexpr2 -> TRUE\n");}
	    	| FALSE															{ printf("relexpr2 -> FALSE\n");}
	    	| L_PAREN boolexpr R_PAREN										{ printf("relexpr2 -> L_PAREN boolexpr R_PAREN\n");}
			| expression error												{ printf("Syntax error at line %d: expecting \"comparison operator\"\n", currLine); return 0;}
	    	;

comp: 	    EQ																{ printf("comp -> EQ\n");}
	    	| NEQ															{ printf("comp -> NEQ\n");}
	    	| LT															{ printf("comp -> LT\n");}
	    	| GT															{ printf("comp -> GT\n");}
	    	| LTE															{ printf("comp -> LTE\n");}
        	| GTE															{ printf("comp -> GTE\n");}
			| error															{ printf("Syntax error at line %d: expecting \"comparison operator\"\n", currLine); return 0;}
	    	;

expression: multexpr														{ printf("expression -> multexpr\n");}
	    	| multexpr ADD expression										{ printf("expression -> multexpr ADD expression\n");}
			| multexpr SUB expression										{ printf("expression -> multexpr SUB expression\n");}
	    	;

multexpr: 	term															{ printf("multexpr -> term\n");}
			| term MULT multexpr											{ printf("multexpr -> term MULT multexpr\n");}
			| term DIV multexpr												{ printf("multexpr -> term DIV multexpr\n");}
			| term MOD multexpr												{ printf("multexpr -> term MOD multexpr\n");}
			;

term:	    term1															{ printf("term -> term1\n");}
	 		| SUB term1														{ printf("term -> SUB term1\n");}
            | term2															{ printf("term -> term2\n");}
	    	;									

term1: 	    var																{ printf("term1 -> var\n");}
	    	| NUMBER														{ printf("term1 -> NUMBER\n");}
	    	| L_PAREN expression R_PAREN									{ printf("term1 -> L_PAREN expression R_PAREN\n");}
	 		;

term2:      IDENT L_PAREN term3 R_PAREN										{ printf("term2 -> IDENT L_PAREN term3 R_PAREN\n"); free($1);}
	    	;

term3:	    %empty															{printf("program -> epsilon\n");}
	    	| expression													{ printf("term3 -> expression\n");}
	    	| expression COMMA term3										{ printf("term3 -> expression COMMA term3\n");}
	    	; 

var: 		IDENT															{ printf("var -> IDENT %s\n", $1); free($1);}
	    	| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET			{ printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n"); free($1);}
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
   return 0;
}

void yyerror(const char *msg) {
	
	printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
