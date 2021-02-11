/* calculator. */
%{
 #include <stdio.h>
 #include <stdlib.h>
 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 FILE * yyin;
%}

%union{
  double dval;
  int ival;
}

%error-verbose
%start program
%token IDENT SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN EQ NEQ LT GT LTE GTE SUB ADD MULT DIV MOD
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP BREAK READ WRITE AND OR NOT TRUE FALSE RETURN
%token <dval> NUMBER
%token <ival> INTEGER
%left PLUS MINUS
%left MULT DIV
%nonassoc UMINUS


%% 
program:	/* epsilon */
			| function program                                          {printf("program -> function program\n");}
			;

function:	FUNCTION IDENT SEMICOLON BEGIN_PARAMS funcparams            { printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS");}
			;

funcparams: declaration SEMICOLON funcparams                            { printf("funcparams -> declaration SEMICOLON funcparams");}
            | END_PARAMS BEGIN_LOCALS funclocals                        { printf("funcparams -> END_PARAMS BEGIN_LOCALS funclocals");}
            ;

funclocals: declaration SEMICOLON funclocals                            { printf("funclocals -> declaration SEMICOLON funclocals");}
            | END_LOCALS BEGIN_BODY funcbody                            { printf("funclocals -> END_LOCALS BEGIN_BODY funcbody");}
            ;

funcbody: statement SEMICOLON END_BODY                                  { printf("funcbody -> statement SEMICOLON END_BODY");}
            | statement SEMICOLON statement                             { printf("funcbody -> statement SEMICOLON statement");}                         

declaration: funcident
            ;

funcident: IDENT COMMA funcident
            | IDENT COLON array
            ;

array: INTEGER
            | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
            ;

statement: var ASSIGN expression
            | if | while | dowhile | read | write | break | RETURN expression
            ;



exp:		NUMBER                { printf("exp -> NUMBER\n");}
			| exp PLUS exp        { printf("exp -> exp PLUS exp\n");}
			| exp MINUS exp       { printf("exp -> exp MINUS exp\n");}
			| exp MULT exp        { printf("exp -> exp MULT exp\n");}
			| exp DIV exp         { printf("exp -> exp DIV exp\n");}
			| MINUS exp %prec UMINUS { printf("exp -> MINUS exp prec UMINUS\n");}
			| L_PAREN exp R_PAREN { printf("exp -> L_PAREN exp R_PAREN\n");}
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
   return 0;
}

void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}