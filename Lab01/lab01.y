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
%start input
%token MULT DIV PLUS MINUS EQUAL L_PAREN R_PAREN END
%token <dval> NUMBER
%type <dval> exp
%left PLUS MINUS
%left MULT DIV
%nonassoc UMINUS


%% 
program:	
			| function program            {printf("program -> function program\n");}
			;

function:		exp EQUAL END         { printf("line -> exp EQUAL END"); printf("\t%f\n", $1);}
			;

exp:		NUMBER                { printf("exp -> NUMBER\n"); $$ = $1; }
			| exp PLUS exp        { printf("exp -> exp PLUS exp\n"); $$ = $1 + $3; }
			| exp MINUS exp       { printf("exp -> exp MINUS exp\n"); $$ = $1 - $3; }
			| exp MULT exp        { printf("exp -> exp MULT exp\n"); $$ = $1 * $3; }
			| exp DIV exp         { printf("exp -> exp DIV exp\n"); if ($3==0) yyerror("divide by zero\n"); else $$ = $1 / $3; }
			| MINUS exp %prec UMINUS { printf("exp -> MINUS exp prec UMINUS\n"); $$ = -$2; }
			| L_PAREN exp R_PAREN { printf("exp -> L_PAREN exp R_PAREN\n"); $$ = $2; }
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