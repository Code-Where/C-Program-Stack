
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node
{
    char str[25];
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

char* push(Node **top, char val[])
{
    Node *nn;
    nn = (Node *)malloc(sizeof(Node));
    if (isFull(nn))
    {
        return NULL;
    }
    strcpy(nn->str, val);
    nn->next = *top;
    *top = nn;
    return &(nn->str);
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

char* peek(Node *top)
{
    if (isEmpty(top))
    {
        return NULL;
    }

    return &(top->str);
}

int main()
{
    Node *top = NULL;
    char *val, value[25];
    int valid;

    char choose;
    do
    {
        printf("Press 1: Push\tPress 2: Pop\tPress 3: Peek\tPress 4: Exit\t\n");
        choose = getch();
        if (choose == '1')
        {
            printf("Enter String \n");
            gets(value);
            val = push(&top, value);
            if (val == NULL)
            {
                printf("Stack is Full\n");
            }
            else
            {
                printf("%s pushed Successfully\n", val);
            }
        }
        else if (choose == '2')
        {
            valid = pop(&top);
            if (valid)
            {
                printf("Poped Successfully\n");
            }
            else
            {
                printf("Stack is Empty\n");
            }
        }
        else if (choose == '3')
        {
            if (peek(top) == NULL)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Top Element of Stack is %s\n", peek(top));
            }
        }
        else if (choose == '4')
        {
            printf("Exiting From The Program\n");
        }
        else
            printf("Invalid Choice\n");

    } while (choose != '4');

    while(top != NULL){
        pop(&top);
    }

    return 0;
}