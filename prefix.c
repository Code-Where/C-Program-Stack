#include <stdio.h>
#include<stdlib.h>
int push(char stack[], int size, char val, int i)
{
    if (i == size - 1)
    {
        return -1;
    }
    i++;
    stack[i] = val;
    return i;
}
int pop(char stack[], int i)
{
    if (i == -1)
    {
        return -2;
    }
    i--;
    return i;
}
int peek(char stack[], int i)
{
    if (i == -1)
    {
        return -1;
    }
    return i;
}

void strrev(char src[], char dest[]){
    int i = -1, j = 0;
    char stack[30];
    for (j = 0; src[j]; j++)
    {
        i = push(stack, 30, src[j], i);
    }
    for (j = 0; src[j]; j++)
    {
        dest[j] = stack[peek(stack, i)];
        i = pop(stack, i);
    }
    dest[j] = '\0';
}

int isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int isOperand(char c){
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infixToPrefix(char infix[], char prefix[]){
    int i = -1, j = 0, ind = 0;
    
    int push(char[], int, char, int);
    int pop(char[], int);
    int peek(char[], int);
    
    char *invInf = (char*)malloc(sizeof(char)*30);
    char *postfix = (char*)malloc(sizeof(char)*30);
    char *stack = (char*)malloc(sizeof(char)*30);

    strrev(infix, invInf);

    while (invInf[j])
    {
        if (isOperand(invInf[j]))
        {
            postfix[ind++] = invInf[j];
        }
        else if(isOperator(invInf[j]))
        {
            while(i != -1 && precedence(stack[peek(stack, i)]) > precedence(invInf[j]))
            {
                postfix[ind++] = stack[peek(stack, i)];
                i = pop(stack, i);
            }
            i = push(stack, 30, invInf[j], i);
        }
        else if(invInf[j] == '(')
        {
            i = push(stack, 30, invInf[j], i);
        }
        else if(invInf[j] == ')'){
            while (i != -1 && stack[peek(stack, i)] != '(')
            {
                postfix[ind++] = stack[peek(stack, i)];
                i = pop(stack, i);
            }
            i = pop(stack, i);
        }
        j++;
    }

    while (i != -1)
    {
        postfix[ind++] = stack[peek(stack, i)];
        i = pop(stack, i);
    }
    postfix[ind] = '\0';
    strrev(postfix, prefix);
    free(invInf);
    free(postfix);
}

int main()
{
    char infix[30], prefix[30];
    printf("Enter an Infix Expression\n");
    gets(infix);
    
    infixToPrefix(infix, prefix);
  
    printf("Prefix Expression: %s", prefix);
}