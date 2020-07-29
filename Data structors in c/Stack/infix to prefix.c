#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int top;
    unsigned int capacity;
    char *arr;
};

struct Stack *createStack(int);
void push(struct Stack *, char);
char pop(struct Stack *);
char peek(struct Stack *);
int isEmpty(struct Stack *);
int isFull(struct Stack *);
void clear(struct Stack *);

void swap(char *string1, char *string2);
int priority(char);
char *infixToPrefix(char *expression)
{
    int n = strlen(expression);
    struct Stack *stack = createStack(n);
    char *prefix_notation = (char *)malloc((n + 1) * sizeof(char));
    register int i = 0, j = n - 1;
    while (i <= j)
    {
        swap(&expression[i], &expression[j]);
        i++;
        j--;
    }
    j = i = 0;
    while (i < n)
    {
        if (priority(expression[i]) == 0)
        {
            prefix_notation[j] = expression[i];
            j++;
        }

        else
        {
            if (expression[i] == ')')
                push(stack, expression[i]);
            else if (expression[i] == '(')
            {
                while ((isEmpty(stack) == 0) && peek(stack) != ')')
                {
                    prefix_notation[j] = pop(stack);
                    j++;
                }
                pop(stack);
            }
            else
            {
                while ((isEmpty(stack) == 0) && (priority(peek(stack)) > priority(expression[i])) && (peek(stack) != ')'))
                {
                    prefix_notation[j] = pop(stack);
                    j++;
                }
                push(stack, expression[i]);
            }
        }
        i++;
    }
    while (isEmpty(stack) == 0)
    {
        prefix_notation[j] = pop(stack);
        j++;
    }
    prefix_notation[n] = NULL;
    i = 0;
    j = n - 1;
    while (i <= j)
    {
        swap(&prefix_notation[i], &prefix_notation[j]);
        i++;
        j--;
    }
    free(stack);
    return prefix_notation;
}

int main()
{
    char string[] = "A+B*C";
    char *s = infixToPrefix(string);
    printf("So now prefix expression is = %s\n", s);
    free(s);
    return 0;
}

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(struct Stack *stack, char value)
{
    stack->arr[++stack->top] = value;
}

int isEmpty(struct Stack *stack)
{
    if (stack->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack *stack)
{
    if (stack->top == stack->capacity - 1)
        return 1;
    return 0;
}

char pop(struct Stack *stack)
{
    return stack->arr[stack->top--];
}

char peek(struct Stack *stack)
{
    return stack->arr[stack->top];
}

void clear(struct Stack *stack)
{
    free(stack->arr);
    free(stack);
}
void swap(char *string1, char *string2)
{
    char s = *string1;
    *string1 = *string2;
    *string2 = s;
}

int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '^')
        return 3;
    else if (op == '(' || op == ')')
        return 4;
    return 0;
}