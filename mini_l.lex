/*** Definition Section ***/
%{
int currLine = 1, currPos = 1;
int identCnt = 0;
%}
  
/*** Rule Section ***/
%%
{} // Keywords
function				    {printf("FUNCTION\n"); currPos += yyleng;} //Function keyword
beginparams				    {printf("BEGIN_PARAMS\n"); currPos += yyleng;} //Beginparams keyword
endparams				    {printf("END_PARAMS\n"); currPos += yyleng;} //Endparams keyword
beginlocals 			    {printf("BEGIN_LOCALS\n"); currPos += yyleng;} //Beginlocals keyword
endlocals 			        {printf("END_LOCALS\n"); currPos += yyleng;} //Endlocals keyword
beginbody			        {printf("BEGIN_BODY\n"); currPos += yyleng;} //Beginbody keyword
endbody			            {printf("END_BODY\n"); currPos += yyleng;} //Endbody keyword
integer 			        {printf("INTEGER\n"); currPos += yyleng;} //Integer keyword
array 			            {printf("ARRAY\n"); currPos += yyleng;} //Array keyword
of 			                {printf("OF\n"); currPos += yyleng;} //Of keyword
if 			                {printf("IF\n"); currPos += yyleng;} //If keyword
then 			            {printf("THEN\n"); currPos += yyleng;} //Then keyword
endif 			            {printf("ENDIF\n"); currPos += yyleng;} //Endif keyword
else 			            {printf("ELSE\n"); currPos += yyleng;} //Else keyword
while 			            {printf("WHILE\n"); currPos += yyleng;} //While keyword
do 			                {printf("DO\n"); currPos += yyleng;} //Do keyword
beginloop 			        {printf("BEGINLOOP\n"); currPos += yyleng;} //Beginloop keyword
endloop 			        {printf("ENDLOOP\n"); currPos += yyleng;} //Endloop keyword
break 			            {printf("BREAK\n"); currPos += yyleng;} //Break keyword
read 			            {printf("READ\n"); currPos += yyleng;} //Read keyword
write 			            {printf("WRITE\n"); currPos += yyleng;} //Write keyword
and 			            {printf("AND\n"); currPos += yyleng;} //And keyword
or 			                {printf("OR\n"); currPos += yyleng;} //Or keyword
not 			            {printf("NOT\n"); currPos += yyleng;} //Not keyword
true 			            {printf("TRUE\n"); currPos += yyleng;} //True keyword
false 			            {printf("FALSE\n"); currPos += yyleng;} //False keyword
return 			            {printf("RETURN\n"); currPos += yyleng;} //Return keyword

{} // Arithmetic Ops
-				    {printf("SUB\n"); currPos += yyleng;} //Subtraction
\+				    {printf("ADD\n"); currPos += yyleng;} //Addition
\*				    {printf("MULT\n"); currPos += yyleng;} //Multiplication
\/				    {printf("DIV\n"); currPos += yyleng;} //Division
\%				    {printf("MOD\n"); currPos += yyleng;} //Modulus

{} // Comparison Ops
==				    {printf("EQ\n"); currPos += yyleng;} //Is equal to
\<\>				    {printf("NEQ\n"); currPos += yyleng;} //Not equal to
\<				    {printf("LT\n"); currPos += yyleng;} //Less than
\>				    {printf("GT\n"); currPos += yyleng;} //Greater than
\<=				    {printf("LTE\n"); currPos += yyleng;} //Less than or equal to
\>=				    {printf("GTE\n"); currPos += yyleng;} //Greater than or equal to

{} // Numbers and Identifiers
[0-9]+ 				        {printf("NUMBER %s\n", yytext); currPos += yyleng;} //number
[a-zA-Z]([a-zA-Z0-9_]+[a-zA-Z0-9]+)?   {printf("IDENT %s\n", yytext); identCnt++; currPos += yyleng;}  //identifier
[0-9][a-zA-Z0-9_]+[a-zA-Z0-9]+      {printf("Invalid Character: %s at Line %d and Position %d\n", yytext, currLine, currPos); return 0;}  //invalid identifier #1
[a-zA-Z][a-zA-Z0-9_]+_+             {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore", currLine, currPos, yytext); return 0;}  //invalid identifier #2

{} // Special Symbols
;				    {printf("SEMICOLON\n"); currPos += yyleng;} //Semicolon symbol
:				    {printf("COLON\n"); currPos += yyleng;} //Colon symbol
,				    {printf("COMMA\n"); currPos += yyleng;} //Comma symbol
\(				    {printf("L_PAREN\n"); currPos += yyleng;} //Left parenthesis symbol
\)				    {printf("R_PAREN\n"); currPos += yyleng;} //Right parenthesis symbol
\[				    {printf("L_SQUARE_BRACKET\n"); currPos += yyleng;} //Left bracket symbol
\]				    {printf("R_SQUARE_BRACKET\n"); currPos += yyleng;} //Right bracket symbol
:=				    {printf("ASSIGN\n"); currPos += yyleng;} //Assignment symbol

{} // Comments and Whitespaces - not to be outputted
##(.+)?                {currPos += yyleng;}
[ \t]               {currPos += yyleng;}
\n                                  {currLine++; currPos = 1;}
.                   {printf("Error at line %d, column %d: unrecognized symbol \"%s\" ", currLine, currPos, yytext); return 0;} //unrecognized symbol
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
