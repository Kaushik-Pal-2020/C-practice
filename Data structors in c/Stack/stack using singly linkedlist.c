#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **, int);
int pop(struct Node **);
void display(struct Node *);
int isEmpty(struct Node *);

int main()
{
    struct Node *stack = NULL;
    push(&stack, 10);
    printf("%d\n", isEmpty(stack));
    push(&stack, 20);
    push(&stack, 30);
    display(stack);
    for (int i = 0; i < 4; i++)
        printf("%d\n", pop(&stack));
    printf("%d\n", isEmpty(stack));
    return 0;
}
int isEmpty(struct Node *top)
{
    return (top == NULL) ? 1 : -1;
}
void display(struct Node *top)
{
    printf("=================================\n");
    char *empty = "-> !stack is empty!", *arrow = "->";
    while (top)
    {
        printf("%d %s", top->data, (top->next == NULL) ? empty : arrow);
        top = top->next;
    }

    printf("\n=================================\n");
}
void push(struct Node **top, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}
int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow\n");
        return -999;
    }
    struct Node *p = *top;
    int data = p->data;
    *top = p->next;
    p->next = NULL;
    free(p);
    return data;
}