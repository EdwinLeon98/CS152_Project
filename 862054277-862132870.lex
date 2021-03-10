/*** Definition Section ***/
%{
#include "y.tab.h"
int currLine = 1, currPos = 1;
int identCnt = 0;
int errLine = 1;
%}
  
/*** Rule Section ***/
%%

function				    { currPos += yyleng; return FUNCTION;} //Function keyword
beginparams				    { currPos += yyleng; return BEGIN_PARAMS;} //Beginparams keyword
endparams				    { currPos += yyleng; return END_PARAMS;} //Endparams keyword
beginlocals 			    { currPos += yyleng; return BEGIN_LOCALS;} //Beginlocals keyword
endlocals 			        { currPos += yyleng; return END_LOCALS;} //Endlocals keyword
beginbody			        { currPos += yyleng; return BEGIN_BODY;} //Beginbody keyword
endbody			            { currPos += yyleng; return END_BODY;} //Endbody keyword
integer 			        { currPos += yyleng; return INTEGER;} //Integer keyword
array 			            { currPos += yyleng; return ARRAY;} //Array keyword
of 			                { currPos += yyleng; return OF;} //Of keyword
if 			                { currPos += yyleng; return IF;} //If keyword
then 			            { currPos += yyleng; return THEN;} //Then keyword
endif 			            { currPos += yyleng; return ENDIF;} //Endif keyword
else 			            { currPos += yyleng; return ELSE;} //Else keyword
while 			            { currPos += yyleng; return WHILE;} //While keyword
do 			                { currPos += yyleng; return DO;} //Do keyword
beginloop 			        { currPos += yyleng; return BEGINLOOP;} //Beginloop keyword
endloop 			        { currPos += yyleng; return ENDLOOP;} //Endloop keyword
break 			            { currPos += yyleng; return BREAK;} //Break keyword
read 			            { currPos += yyleng; return READ;} //Read keyword
write 			            { currPos += yyleng; return WRITE;} //Write keyword
and 			            { currPos += yyleng; return AND;} //And keyword
or 			                { currPos += yyleng; return OR;} //Or keyword
not 			            { currPos += yyleng; return NOT;} //Not keyword
true 			            { currPos += yyleng; return TRUE;} //True keyword
false 			            { currPos += yyleng; return FALSE;} //False keyword
return 			            { currPos += yyleng; return RETURN;} //Return keyword

{} // Arithmetic Ops
-				    { currPos += yyleng; return SUB;} //Subtraction
\+				    { currPos += yyleng; return ADD;} //Addition
\*				    { currPos += yyleng; return MULT;} //Multiplication
\/				    { currPos += yyleng; return DIV;} //Division
\%				    { currPos += yyleng; return MOD;} //Modulus

{} // Comparison Ops
==				    { currPos += yyleng; return EQ;} //Is equal to
\<\>				{ currPos += yyleng; return NEQ;} //Not equal to
\<				    { currPos += yyleng; return LT;} //Less than
\>				    { currPos += yyleng; return GT;} //Greater than
\<=				    { currPos += yyleng; return LTE;} //Less than or equal to
\>=				    { currPos += yyleng; return GTE;} //Greater than or equal to

{} // Numbers and Identifiers
[0-9]+ 				                    { currPos += yyleng; yylval.expr_struct.name = strdup(yytext); char* c; yylval.expr_struct.value = strtol(yytext, &c, 10); yylval.expr_struct.tokentype = "number"; return NUMBER;} //number
[a-zA-Z]([a-zA-Z0-9_]+[a-zA-Z0-9]+)?    { identCnt++; currPos += yyleng; yylval.var_struct.name = strdup(yytext); yylval.str = strdup(yytext); yylval.var_struct.tokentype = "variable"; return IDENT;}  //identifier
[0-9]+[a-zA-Z_]+([a-zA-Z0-9]+)?         {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter", currLine, currPos, yytext); return 0;}  //invalid identifier #1
[a-zA-Z]([a-zA-Z0-9_]+?)_+              {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore", currLine, currPos, yytext); return 0;}  //invalid identifier #2

{} // Special Symbols
;				    { currPos += yyleng; return SEMICOLON;} //Semicolon symbol
:				    { currPos += yyleng; return COLON;} //Colon symbol
,				    { currPos += yyleng; return COMMA;} //Comma symbol
\(				    { currPos += yyleng; return L_PAREN;} //Left parenthesis symbol
\)				    { currPos += yyleng; return R_PAREN;} //Right parenthesis symbol
\[				    { currPos += yyleng; return L_SQUARE_BRACKET;} //Left bracket symbol
\]				    { currPos += yyleng; return R_SQUARE_BRACKET;} //Right bracket symbol
:=				    { currPos += yyleng; return ASSIGN;} //Assignment symbol

{} // Comments and Whitespaces - not to be outputted
##(.+)?                {currPos += yyleng;}
[ \t]                  {currPos += yyleng;}
\n                     {currLine++; currPos = 1;}
.                      {errLine = currLine; printf("Error at line %d, column %d: unrecognized symbol \"%s\" ", currLine, currPos, yytext); return 0;} //unrecognized symbol

%%