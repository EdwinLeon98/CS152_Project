/*** Definition Section ***/
%{
int currLine = 1, currPos = 1;
int intCount = 0;
int opCount = 0;
int parCount = 0;
int eqCount = 0;
%}
  
/*** Rule Section ***/
%%
[0-9]+ {printf("%s", yytext); intCount++; currPos += yyleng;}
\+     {printf(" + "); opCount++; currPos++;}
-      {printf(" - "); opCount++; currPos++;}
\*     {printf(" * "); opCount++; currPos++;}
\/     {printf(" / "); opCount++; currPos++;}
\(     {printf("("); parCount++; currPos++;}
\)     {printf(")"); parCount++; currPos++;}
=      {printf(" =\n"); eqCount++; currPos++;}
\n     {currLine++; currPos = 1; printf("%d) ", currLine);}
[ \t]+ {currPos += yyleng;}
.      {printf("Invalid Character: %s at Line %d and Position %d\n", yytext, currLine, currPos); return 0;}
%%
  
/*** Code Section ***/
int yywrap(){}
int main(){
    printf("1) ");
  
// Explanation: 
// yywrap() - wraps the above rule section
/* yyin - takes the file pointer
          which contains the input*/
/* yylex() - this is the main flex function
          which runs the Rule Section*/
// yytext is the text in the buffer
  
// Uncomment the lines below
// to take input from file
// FILE *fp;
// char filename[50];
// printf("Enter the filename: \n");
// scanf("%s",filename);
// fp = fopen(filename,"r");
// yyin = fp;
  
yylex();
printf("\nNumber of Integers - %d\n", intCount);
printf("\nNumber of Operators - %d\n", opCount);
printf("\nNumber of Parenthesis - %d\n", parCount);
printf("\nNumber of Equals - %d\n", eqCount);
  
return 0;
}