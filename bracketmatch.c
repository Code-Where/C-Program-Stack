#include<stdio.h>

int push(char stack[], int size, int val, int i){
    if (i == size-1)
    {
        return -1;
    }
    i++;
    stack[i] = val;
    return i;
    
}
int pop(char stack[], int i){
    if (i == -1)
    {
        return -2;
    }
    i--;
    return i;
}
int main(){
    int push(char[], int, int, int);
    int pop(char[], int);
    char exp[30], stack[30];
    int i = -1, ind, j;
    printf("Enter Expresstion Containing {}\n");
    gets(exp);
    for (j = 0; exp[j] != '\0'; j++)
    {
        if (exp[j] == '{')
        {
            i = push(stack, 30, exp[j], i);       
        }
        if(exp[j] == '}')
        {
            ind = pop(stack, i);
            if (ind == -2)
            {
                printf("Brackets are not matching\n");
                break;
            }
            else{
                i = ind;
            }
        }
    }
    if (i == -1 && exp[j] != '}')
    {
        printf("Brackets are Matching\n");
    }
    else if (i > -1)
    {
        printf("Brackets are not Matching");
    }
}