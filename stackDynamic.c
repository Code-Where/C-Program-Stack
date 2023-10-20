#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct Node *next;
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

int *push(Node **top, int val)
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

int *peek(Node *top)
{
    if (isEmpty(top))
    {
        return NULL;
    }

    return &(top->data);
}

int main()
{
    Node *top = NULL;
    int *val, valid, value;

    char choose;
    do
    {
        printf("Press 1: Push\tPress 2: Pop\tPress 3: Peek\tPress 4: Exit\t\n");
        choose = getch();
        if (choose == '1')
        {
            printf("Enter Value \n");
            scanf("%d", &value);
            val = push(&top, value);
            if (val == NULL)
            {
                printf("Stack is Full\n");
            }
            else
            {
                printf("%d pushed Successfully\n", *val);
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
            // val = peek(top);
            if (val == NULL)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Top Element of Stack is %d\n", *peek(top));
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