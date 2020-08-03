#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef stackLL
#define stackLL .h
struct Node_Stack
{
    void *data;
    struct Node_Stack *next;
};
struct stack
{
    struct Node_Stack *top;
    size_t memSize;
};
typedef struct stack Stack;

int isEmpty_Stack(Stack *stack)
{
    return (stack->top == NULL) ? 1 : 0;
}
void clear_Stack(Stack *stack)
{
    struct Node_Stack *temp = stack->top;
    struct Node_Stack *tail = NULL;
    while (temp)
    {
        tail = temp;
        if (!temp)
            break;
        temp = temp->next;
        free(tail->data);
        free(tail);
    }
    stack->top = NULL;
    stack->memSize = 0;
}
void createStack(Stack *stack, size_t memSize)
{
    stack->top = NULL;
    stack->memSize = memSize;
}
void display_Stack(Stack *stack)
{
    printf("=================================\n");
    printf("%16s\n", "Displaying Stack");
    int data;
    struct Node_Stack *temp = stack->top;
    while (temp)
    {
        memcpy(&data, temp->data, stack->memSize);
        printf("%d - ", data);
        temp = temp->next;
    }
    printf("\n=================================\n");
}
void push_Stack(Stack *stack, void *value)
{
    struct Node_Stack *newNode = (struct Node_Stack *)malloc(sizeof(struct Node_Stack));
    newNode->data = malloc(stack->memSize);
    if (!newNode)
    {
        printf("Out of Memory\n");
        free(newNode);
        return;
    }
    memcpy(newNode->data, value, stack->memSize);
    newNode->next = stack->top;
    stack->top = newNode;
}
void peek_Stack(Stack *stack, void *value)
{
    if (stack->top)
    {
        memcpy(value, stack->top->data, stack->memSize);
    }
}
void pop_Stack(Stack *stack, void *data)
{
    if (isEmpty_Stack(stack))
    {
        printf("Stack Underflow\n");
        return;
    }
    struct Node_Stack *p = stack->top;
    memcpy(data, p->data, stack->memSize);
    stack->top = p->next;
    p->next = NULL;
    free(p->data);
    free(p);
}
#endif