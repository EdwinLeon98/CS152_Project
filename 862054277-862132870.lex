/*** Definition Section ***/
%{
int currLine = 1, currPos = 1;
int identCnt = 0;
%}
  
/*** Rule Section ***/
%%
{} // Keywords
function				    {printf("FUNCTION\n"); currPos += yyleng; return FUNCTION;} //Function keyword
beginparams				    {printf("BEGIN_PARAMS\n"); currPos += yyleng; return BEGIN_PARAMS;} //Beginparams keyword
endparams				    {printf("END_PARAMS\n"); currPos += yyleng; return END_PARAMS;} //Endparams keyword
beginlocals 			    {printf("BEGIN_LOCALS\n"); currPos += yyleng; return BEGIN_LOCALS;} //Beginlocals keyword
endlocals 			        {printf("END_LOCALS\n"); currPos += yyleng; return END_LOCALS;} //Endlocals keyword
beginbody			        {printf("BEGIN_BODY\n"); currPos += yyleng; return BEGIN_BODY;} //Beginbody keyword
endbody			            {printf("END_BODY\n"); currPos += yyleng; return END_BODY;} //Endbody keyword
integer 			        {printf("INTEGER\n"); currPos += yyleng; return INTEGER;} //Integer keyword
array 			            {printf("ARRAY\n"); currPos += yyleng; return ARRAY;} //Array keyword
of 			                {printf("OF\n"); currPos += yyleng; return OF;} //Of keyword
if 			                {printf("IF\n"); currPos += yyleng; return IF;} //If keyword
then 			            {printf("THEN\n"); currPos += yyleng; return THEN;} //Then keyword
endif 			            {printf("ENDIF\n"); currPos += yyleng; return ENDIF;} //Endif keyword
else 			            {printf("ELSE\n"); currPos += yyleng; return ELSE;} //Else keyword
while 			            {printf("WHILE\n"); currPos += yyleng; return WHILE;} //While keyword
do 			                {printf("DO\n"); currPos += yyleng; return DO;} //Do keyword
beginloop 			        {printf("BEGINLOOP\n"); currPos += yyleng; return BEGINLOOP;} //Beginloop keyword
endloop 			        {printf("ENDLOOP\n"); currPos += yyleng; return ENDLOOP;} //Endloop keyword
break 			            {printf("BREAK\n"); currPos += yyleng; return BREAK;} //Break keyword
read 			            {printf("READ\n"); currPos += yyleng; return READ;} //Read keyword
write 			            {printf("WRITE\n"); currPos += yyleng; return WRITE;} //Write keyword
and 			            {printf("AND\n"); currPos += yyleng; return AND;} //And keyword
or 			                {printf("OR\n"); currPos += yyleng; return OR;} //Or keyword
not 			            {printf("NOT\n"); currPos += yyleng; return NOT;} //Not keyword
true 			            {printf("TRUE\n"); currPos += yyleng; return TRUE;} //True keyword
false 			            {printf("FALSE\n"); currPos += yyleng; return FALSE;} //False keyword
return 			            {printf("RETURN\n"); currPos += yyleng; return RETURN;} //Return keyword

{} // Arithmetic Ops
-				    {printf("SUB\n"); currPos += yyleng; return SUB;} //Subtraction
\+				    {printf("ADD\n"); currPos += yyleng; return ADD;} //Addition
\*				    {printf("MULT\n"); currPos += yyleng; return MULT;} //Multiplication
\/				    {printf("DIV\n"); currPos += yyleng; return DIV;} //Division
\%				    {printf("MOD\n"); currPos += yyleng; return MOD;} //Modulus

{} // Comparison Ops
==				    {printf("EQ\n"); currPos += yyleng; return EQ;} //Is equal to
\<\>				{printf("NEQ\n"); currPos += yyleng; return NEQ;} //Not equal to
\<				    {printf("LT\n"); currPos += yyleng; return LT;} //Less than
\>				    {printf("GT\n"); currPos += yyleng; return GT;} //Greater than
\<=				    {printf("LTE\n"); currPos += yyleng; return LTE;} //Less than or equal to
\>=				    {printf("GTE\n"); currPos += yyleng; return GTE;} //Greater than or equal to

{} // Numbers and Identifiers
[0-9]+ 				                    {printf("NUMBER %s\n", yytext); currPos += yyleng; return NUMBER;} //number
[a-zA-Z]([a-zA-Z0-9_]+[a-zA-Z0-9]+)?    {printf("IDENT %s\n", yytext); identCnt++; currPos += yyleng; return IDENT;}  //identifier
[0-9]+[a-zA-Z_]+([a-zA-Z0-9]+)?          {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter", currLine, currPos, yytext); return 0;}  //invalid identifier #1
[a-zA-Z]([a-zA-Z0-9_]+?)_+              {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore", currLine, currPos, yytext); return 0;}  //invalid identifier #2

{} // Special Symbols
;				    {printf("SEMICOLON\n"); currPos += yyleng; return SEMICOLON;} //Semicolon symbol
:				    {printf("COLON\n"); currPos += yyleng; return COLON;} //Colon symbol
,				    {printf("COMMA\n"); currPos += yyleng; return COMMA;} //Comma symbol
\(				    {printf("L_PAREN\n"); currPos += yyleng; return L_PAREN;} //Left parenthesis symbol
\)				    {printf("R_PAREN\n"); currPos += yyleng; return R_PAREN;} //Right parenthesis symbol
\[				    {printf("L_SQUARE_BRACKET\n"); currPos += yyleng; return L_SQUARE_BRACKET;} //Left bracket symbol
\]				    {printf("R_SQUARE_BRACKET\n"); currPos += yyleng; return R_SQUARE_BRACKET;} //Right bracket symbol
:=				    {printf("ASSIGN\n"); currPos += yyleng; return ASSIGN;} //Assignment symbol

{} // Comments and Whitespaces - not to be outputted
##(.+)?                {currPos += yyleng;}
[ \t]                  {currPos += yyleng;}
\n                     {currLine++; currPos = 1;}
.                      {printf("Error at line %d, column %d: unrecognized symbol \"%s\" ", currLine, currPos, yytext); return 0;} //unrecognized symbol
%%
  
/*** Code Section ***/
int yywrap() {}
int main(int argc, char ** argv) {
    if(argc >= 2) {
        yyin = fopen(argv[1], "r");
        if(yyin == NULL) yyin = stdin;
    }
    else yyin = stdin;
    
    yylex();
  
return 0;
}
