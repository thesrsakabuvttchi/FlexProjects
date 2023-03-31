#include"lex.yy.c"

int main(int argc, char *argv[])
{
    int retval;
    if(argc>=2)
    {
        yyin = fopen("Testfile.txt", "r");
    }
    while(retval=yylex())
    {
        if(retval==word)
        {
            // printf("Word(%s)\n", spt);
        }
        if(retval==newline)
        {
            // printf("Newline detected\n");
            // printf("Word count is: %d\n",count);
        }
    }
    fclose(yyin);
    printf("Final word count is:%d\n",count);
}