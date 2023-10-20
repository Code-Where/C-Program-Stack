#include<stdio.h>
#include<conio.h>
int isFull(int size, int top){
    if (top == size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(int top){
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int push(char stack[5][10], int size, char val[10], int top){
    int i;
    if(isFull(size, top))
    {
        return -1;
    }
    top++;
    for(i = 0; val[i]; i++)
    {
        stack[top][i] = val[i];
    }
    stack[top][i] = val[i];
    return top;
    
}
int pop(char stack[5][10], int top){
    if (isEmpty(top))
    {
        return -1;
    }
    top--;
    return top;
}
int peek(char stack[5][10], int top){
    if (isEmpty(top))
    {
        return -1;
    }
    return top;
}

int main(){
    char stack[5][10], val[10];
    int i = -1, ind;
    char choose;
    do
    {
        printf("Press 1: Push\tPress 2: Pop\tPress 3: Peek\tPress 4: Exit\t\n");
        choose = getch();
        if (choose == '1')
        {
            printf("Enter String Value \n");
            gets(val);
            ind = push(stack, 5, val, i);
            if(ind != -1){
                i = ind;
                printf("%s pushed Successfully\n", val);
            }
            else{
                printf("Stack is Full\n");
            }
        }
        else if(choose == '2')
        {
            ind = pop(stack, i);
            if(ind != -1){
                i = ind;
                printf("Poped Successfully\n");
            }
            else{
                printf("Stack is Empty\n");
            }
        }
        else if(choose == '3')
        {
            ind = peek(stack, i);
            if(ind != -1){
                printf("Top Element of Stack is %s\n", stack[ind]);
            }
            else{
                printf("Stack is Empty\n");
            }
        }
        else if(choose == '4')
        {
            printf("Exiting From The Program\n");
        }
        else
            printf("Invalid Choice\n");
        
    } while (choose != '4');
    
}