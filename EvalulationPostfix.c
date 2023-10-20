#include <stdio.h>
#include <stdlib.h>

struct node
{
    float data;
    struct node *next;
};
typedef struct node Node;

int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

float *push(Node **top, float val)
{
    Node *nn;
    nn = (Node *)malloc(sizeof(Node));
    if (isFull(nn))
    {
        return NULL;
    }
    nn->data = val;
    nn->next = *top;
    *top = nn;
    return &(nn->data);
}

int pop(Node **top)
{
    Node *temp;
    if (isEmpty(*top))
    {
        return 0;
    }
    temp = *top;
    (*top) = temp->next;
    free(temp);
    return 1;
}

float *peek(Node *top)
{
    if (isEmpty(top))
    {
        return NULL;
    }

    return &(top->data);
}

int isOperand(char ch){
    return (ch >= '0' && ch <= '9');
}
int isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int chtoint(char ch){
    return (ch-'0');
}

float eval(char opr, float op1, float op2){
    if(opr == '+')
        return (op1+op2);
    else if (opr == '-')
        return (op1-op2);
    else if(opr == '*')
        return (op1*op2);
    else if (opr == '/')
        return (op1/op2);
    return 0;
}

float postfixEval(char expression[]){
    Node *top = NULL;
    int j = 0;
    while(expression[j] != '\0')
    {
        if(isOperand(expression[j]))
        {
            push(&top, chtoint(expression[j]));
        }
        else if(isOperator(expression[j]))
        {
            float a = *(peek(top->next));
            float b = *(peek(top));
            pop(&top);
            pop(&top);
            push(&top, eval(expression[j], a, b));
        } 
        j++;      
    }
    j = *(peek(top));
    free(top);
    return j;
}

int main(){
    char exp[30];

    printf("Enter an Infix Expression\n");
    gets(exp);

    printf("Evaluated Postfix Expression is : %f", postfixEval(exp));
}