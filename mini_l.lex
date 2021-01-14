/*** Definition Section ***/
%{
int currLine = 1, currPos = 1;
int identCnt = 0;
%}
  
/*** Rule Section ***/
%%
[a-zA-Z][a-zA-Z0-9_]+[a-zA-Z0-9]+   {identCnt++; currPos += yyleng;}  //identifier
[0-9][a-zA-Z0-9_]+[a-zA-Z0-9]+        {printf("Invalid Character: %s at Line %d and Position %d\n", yytext, currLine, currPos); return 0;}  //invalid identifier #1
[a-zA-Z][a-zA-Z0-9_]+_+             {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore", currLine, currPos, yytext); return 0;}  //invalid identifier #2
\n                                  {currLine++; currPos = 1;}
%%
  
/*** Code Section ***/
int yywrap(){}
int main(){
  
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
  
return 0;
}