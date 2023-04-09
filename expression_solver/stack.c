#include"structures.c"
#include"lex.yy.c"

struct evalue stack[1024];
int stack_top = 0;

int push_stack(struct evalue *exp_val)
{
    stack[stack_top].dtype = exp_val->dtype;
    stack[stack_top].value = exp_val->value;
    stack_top++;
}

struct evalue* pop_stack()
{
    stack_top--;
    return(&stack[stack_top]);
}


void push_longval_stack(long lval)
{
    struct evalue int_val;
    int_val.dtype = INTEGER;
    long *tmp = (long*)malloc(sizeof(long));
    *tmp = lval;
    int_val.value = (void *)tmp;
    push_stack(&int_val);
}

void push_double_stack(double dbval)
{
    struct evalue float_val;
    float_val.dtype = FLOAT;
    double *tmp = (double*)malloc(sizeof(double));
    *tmp = dbval;
    float_val.value = (void *)tmp;
    push_stack(&float_val);
}

void push_operator_stack(char op)
{
    struct evalue char_val;
    char_val.dtype = OPERATOR;
    char *tmp = (char*)malloc(sizeof(char));
    *tmp = op;
    char_val.value = (void *)tmp;
    push_stack(&char_val);
}


void print_stack()
{
    printf("\nstack:");
    for(int i=0;i<stack_top;i++)
    {
        if(stack[i].dtype==INTEGER)
        {
            printf("%ld ",*(long*)(stack[i].value));
        }
        else if(stack[i].dtype==FLOAT)
        {
            printf("%lf ",*(double*)(stack[i].value));
        }
        else if(stack[i].dtype==OPERATOR)
        {
            printf("%c ",*(char*)(stack[i].value));
        }
    }
    printf("\n");
}