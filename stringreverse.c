#include<stdio.h>
#include<stdlib.h>
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
int peek(char stack[], int i){
    if (i == -1)
    {
        return -1;
    }
    return i;
}

void strrev(char src[], char dest[]){
    int push(char[], int, int, int);
    int pop(char[], int);
    int peek(char[], int);
    char *stack = (char*)malloc(sizeof(char)*30);
    int i = -1, j;
    for (j = 0; src[j] != '\0'; j++)
    {
        i = push(stack, 30, src[j], i);
    }
    for (j = 0; src[j] != '\0'; j++)
    {
        dest[j] = stack[peek(stack, i)];
        i = pop(stack, i);
    }
    dest[j] = '\0';
    free(stack);
}

int main(){
    char str[30], rev[30];

    printf("Enter String \n");
    gets(str);
    strrev(str, rev);
    printf("Reverse of String: %s", rev);
    return 0;
}