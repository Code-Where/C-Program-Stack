#include<stdio.h>

int isFull(int stack[], int size, int top){
    if (top == size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(int stack[], int top){
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int push(int stack[], int size, int val, int top){
    if(isFull(stack, size, top))
    {
        return -1;
    }
    top++;
    stack[top] = val;
    return top;
    
}
int pop(int stack[], int top){
    if (isEmpty(stack, top))
    {
        return -1;
    }
    top--;
    return top;
}
int peek(int stack[], int top){
    if (isEmpty(stack, top))
    {
        return -1;
    }
    return top;
}

int main(){
    int push(int[], int, int, int);
    int pop(int[], int);
    int peek(int[], int);
    int stack[5], i = -1, val, ind;
    char choose;
    do
    {
        printf("Press 1: Push\tPress 2: Pop\tPress 3: Peek\tPress 4: Exit\t\n");
        choose = getch();
        if (choose == '1')
        {
            printf("Enter Value \n");
            scanf("%d", &val);
            ind = push(stack, 5, val, i);
            if(ind != -1){
                i = ind;
                printf("%d pushed Successfully\n",val);
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
                printf("Top Element of Stack is %d\n", stack[ind]);
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