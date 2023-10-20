#include <stdio.h>

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

void infixToPostfix(char infix[], char postfix[]){
    int i = -1, j = 0, ind = 0;
    char stack[30];
    int push(char[], int, char, int);
    int pop(char[], int);
    int peek(char[], int);
    while (infix[j])
    {
        if (isOperand(infix[j]))
        {
            postfix[ind++] = infix[j];
        }
        else if(isOperator(infix[j]))
        {
            while(i != -1 && precedence(stack[peek(stack, i)]) >= precedence(infix[j]))
            {
                postfix[ind++] = stack[peek(stack, i)];
                i = pop(stack, i);
            }
            i = push(stack, 30, infix[j], i);
        }
        else if(infix[j] == '(')
        {
            i = push(stack, 30, infix[j], i);
        }
        else if(infix[j] == ')'){
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
}

int main()
{
    char infix[30], postfix[30];
    printf("Enter an Infix Expression\n");
    gets(infix);
    
    infixToPostfix(infix, postfix);
  
    printf("Postfix Expression: %s", postfix);
}