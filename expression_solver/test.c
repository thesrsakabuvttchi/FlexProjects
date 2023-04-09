#include"expression.c"
#include<math.h>

void stack_operations()
{
    if(stack_top==0 || operator=='(' || operator=='^')
    {
        push_operator_stack(operator);
    }
    else if(operator=='*' || operator=='/')
    {
        while(stack_top!=0 && *(char *)stack[stack_top-1].value=='^')
        {
            struct evalue *tmp_val = pop_stack();
            push_exp(tmp_val);
        }
        push_operator_stack(operator);
    }
    else if(operator=='+' || operator=='-')
    {
        while(stack_top!=0 && (*(char *)stack[stack_top-1].value=='^' ||\
        *(char *)stack[stack_top-1].value=='*' || \
        *(char *)stack[stack_top-1].value=='/'))
        {
            struct evalue *tmp_val = pop_stack();
            push_exp(tmp_val);
        }
        push_operator_stack(operator);
    }
    else if(operator==')')
    {
        while(*(char *)stack[stack_top-1].value!='(')
        {
            struct evalue *tmp_val = pop_stack();
            push_exp(tmp_val);
        }
        pop_stack();
    }
}

int main(int argc, char *argv[])
{
    int retval;
    if(argc>=2)
    {
        yyin = fopen(argv[1], "r");
    }
    while(retval=yylex())
    {
        if(retval==INTEGER)
        {
            push_longval_exp(longval);
        }
        else if(retval==FLOAT)
        {
            push_double_exp(dval);
        }
        else if(retval==OPERATOR)
        {
            stack_operations();
        }
        else if(retval==NEWLINE)
        {
            // printf("Newline");
        }
        else if(retval==SPACER)
        {
            // printf("Spacer");
        }
        else if(retval==UNDEF)
        {
             
        }
        // print_exp();
    }

    while(stack_top!=0)
    {
        struct evalue *tmp_val = pop_stack();
        push_exp(tmp_val);
    }

    for(int i=0;i<exp_top;i++)
    {
        if(expression[i].dtype!=OPERATOR)
        {
            push_stack(&expression[i]);
        }
        else
        {
            double daccumulator = 0;  
            double tmpval1,tmpval2;

            if(stack[stack_top-1].dtype==INTEGER)
            {
                tmpval1 = (double)*((long*)stack[stack_top-1].value);
                stack[stack_top-1].value = &tmpval1;
            }
            if(stack[stack_top-2].dtype==INTEGER)
            {
                tmpval2 = (double)*((long*)stack[stack_top-2].value);
                stack[stack_top-2].value = &tmpval2;
            }

            if(*((char*)expression[i].value)=='+')
            {
                daccumulator = *((double*)stack[stack_top-1].value)+*((double*)stack[stack_top-2].value);
            }
            else if(*((char*)expression[i].value)=='-')
            {
                daccumulator = *((double*)stack[stack_top-2].value)-*((double*)stack[stack_top-1].value);
            }
            else if(*((char*)expression[i].value)=='*')
            {
                daccumulator = *((double*)stack[stack_top-1].value) * *((double*)stack[stack_top-2].value);
            }
            else if(*((char*)expression[i].value)=='/')
            {
                daccumulator = *((double*)stack[stack_top-2].value) /(*((double*)stack[stack_top-1].value));
            }
            else if(*((char*)expression[i].value)=='^')
            {
                daccumulator = pow(*((double*)stack[stack_top-2].value),(*((double*)stack[stack_top-1].value)));
            }     
            pop_stack();
            pop_stack();
            push_double_stack(daccumulator);       

        }
    }
    printf("%lf\n", *(double *)pop_stack()->value);
    fclose(yyin);
}