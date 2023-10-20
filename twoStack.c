#include <stdio.h>
#include <conio.h>

int push1(int stack[], int val, int top, int top2)
{
    if (top + 1 == top2)
    {
        return -1;
    }
    top++;
    stack[top] = val;
    return top;
}

int push2(int stack[], int val, int top, int top2)
{
    if (top + 1 == top2)
    {
        return -1;
    }
    top2--;
    stack[top2] = val;
    return top2;
}

int pop1(int stack[], int top)
{
    if (top == -1)
    {
        return -2;
    }
    top--;
    return top;
}
int pop2(int stack[], int top, int size)
{
    if (top == size)
    {
        return -1;
    }
    top++;
    return top;
}
int peek(int stack[], int top, int size)
{
    if (top == -1 || top == size)
    {
        return -1;
    }
    return top;
}

int main()
{
    int push(int[], int, int, int);
    int pop(int[], int);
    int peek(int[], int, int);
    int stack[6], i1 = -1, i2 = 6, val, ind;
    char choose, num;
    do
    {
        printf("Press 1: Push\tPress 2: Pop\tPress 3: Peek\tPress 4: Exit\t\n");
        choose = getch();
        if (choose == '1' || choose == '2' || choose == '3')
        {
            printf("Enter Stack Number: (1 or 2)\n");
            num = getch();
        }

        if (choose == '1')
        {
            printf("Enter Value \n");
            scanf("%d", &val);
            if (num == '1')
            {
                ind = push1(stack, val, i1, i2);
                if (ind != -1)
                {
                    i1 = ind;
                    printf("%d pushed to Stack 1 Successfully\n", val);
                }
                else
                {
                    printf("Stack 1 is Full\n");
                }
            }
            else
            {
                ind = push2(stack, val, i1, i2);
                if (ind != -1)
                {
                    i2 = ind;
                    printf("%d pushed to Stack 2 Successfully\n", val);
                }
                else
                {
                    printf("Stack 2 is Full\n");
                }
            }
        }
        else if (choose == '2')
        {
            if (num == '1')
            {
                ind = pop1(stack, i1);
                if (ind != -2)
                {
                    i1 = ind;
                    printf("Poped from stack 1 Successfully\n");
                }
                else
                {
                    printf("Stack 1 is Empty\n");
                }
            }
            else
            {
                ind = pop2(stack, i2, 6);
                if (ind != -1)
                {
                    i2 = ind;
                    printf("Poped from stack 2 Successfully\n");
                }
                else
                {
                    printf("Stack 2 is Empty\n");
                }
            }
        }
        else if (choose == '3')
        {
            if (num == '1')
            {
                ind = peek(stack, i1, 6);
            }
            else
            {
                ind = peek(stack, i2, 6);
            }
            if (ind != -1)
            {
                printf("Top Element of Stack %c is %d\n", num, stack[ind]);
            }
            else
            {
                printf("Stack %c is Empty\n", num);
            }
        }
        else if (choose == '4')
        {
            printf("Exiting From The Program\n");
        }
        else
            printf("Invalid Choice\n");

    } while (choose != '4');
}