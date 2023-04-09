%{
    #include <stdio.h>
    long longval;
    double dval;
    char operator;
    enum type  {
        EFILE,
        INTEGER,
        FLOAT,
        OPERATOR,
        NEWLINE,
        SPACER,
        UNDEF
    };
%}

%option noyywrap

%%
[0-9]+  {
    sscanf(yytext,"%ld",&longval);
    return(INTEGER);
    }
[0-9]+\.[0-9]*  {
    sscanf(yytext,"%lf",&dval);
    return(FLOAT);
    }
[-\+/*\^\(\)] {
    sscanf(yytext,"%c",&operator);
    return(OPERATOR);
}
\n {
    return(NEWLINE);
}
[ \t]* {
    return(SPACER);
}
<<EOF>> {
    return(EFILE);
}
.   {
    /*No Action*/
}
%%
