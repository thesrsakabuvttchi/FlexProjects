%{
    #include <stdio.h>
    #include <string.h>
    int count = 0;
    char *spt = NULL;
    enum token_type {eof,word,newline};
%}

%option noyywrap

%%
[^ \t\n]+ {

    free(spt);
    spt = (char*) malloc(yyleng*sizeof(char));
    strcpy(spt,yytext);

    count++;

    return(word);
    }
\n {
    return(newline);
}
<<EOF>> {
    return(eof);
}
. {
    free(spt);
    spt = (char*) malloc(yyleng*sizeof(char));
    strcpy(spt,yytext);}
%%
