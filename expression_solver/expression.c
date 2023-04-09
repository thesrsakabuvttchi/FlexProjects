#include "stack.c"


struct evalue expression[2048];
int exp_top = 0;

int push_exp(struct evalue *exp_val)
{
    expression[exp_top].dtype = exp_val->dtype;
    expression[exp_top].value = exp_val->value;
    exp_top++;
}

struct evalue* pop_exp()
{
    exp_top--;
    return(&expression[exp_top]);
}


void push_longval_exp(long lval)
{
    struct evalue int_val;
    int_val.dtype = INTEGER;
    long *tmp = (long*)malloc(sizeof(long));
    *tmp = lval;
    int_val.value = (void *)tmp;
    push_exp
(&int_val);
}

void push_double_exp(double dbval)
{
    struct evalue float_val;
    float_val.dtype = FLOAT;
    double *tmp = (double*)malloc(sizeof(double));
    *tmp = dbval;
    float_val.value = (void *)tmp;
    push_exp
(&float_val);
}

void push_operator_exp(char op)
{
    struct evalue char_val;
    char_val.dtype = OPERATOR;
    char *tmp = (char*)malloc(sizeof(char));
    *tmp = op;
    char_val.value = (void *)tmp;
    push_exp
(&char_val);
}


void print_exp()
{
    printf("\nExp:");
    for(int i=0;i<exp_top;i++)
    {
        if(expression[i].dtype==INTEGER)
        {
            printf("%ld ",*(long*)(expression[i].value));
        }
        else if(expression[i].dtype==FLOAT)
        {
            printf("%lf ",*(double*)(expression[i].value));
        }
        else if(expression[i].dtype==OPERATOR)
        {
            printf("%c ",*(char*)(expression[i].value));
        }
    }
    printf("\n");
}