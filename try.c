#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *stackA)
{
    if (stackA->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *stackA)
{
    if (stackA->top == stackA->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *stackA, char val)
{
    if (isFull(stackA))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        stackA->top++;
        stackA->arr[stackA->top] = val;
    }
}

char pop(struct stack *stackA)
{
    if (isEmpty(stackA))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    else
    {
        char val = stackA->arr[stackA->top];
        stackA->top--;
        return val;
    }
}

char stackTop(struct stack *stackA)
{
    return stackA->arr[stackA->top];
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *stackA;
    stackA->size = 100;
    stackA->top = -1;
    stackA->arr = (char *)malloc(stackA->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(stackA, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(stackA))
            {
                return 0;
            }
            popped_ch = pop(stackA);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(stackA))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // Write Expression here ------------
    //                                  |
    char *exp = "{[[(a+b]]}"; //<----------

    if (parenthesisMatch(exp))
    {
        printf("\nbalanced\n");
    }
    else
    {
        printf("\nnot balanced\n");
    }
    return 0;
}
