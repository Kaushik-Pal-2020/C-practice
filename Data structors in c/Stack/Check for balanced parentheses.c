#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node
{
    char data;
    struct Node *next;
};
void push(struct Node **, char);
char pop(struct Node **);
int isEmpty(struct Node *);
char peek(struct Node*);
bool balancedParenthesis(char *s)
{
    register unsigned int i = 0;
    struct Node *top = NULL;
    while(s[i])
    {
        if(s[i] == '{' ||s[i] == '('||s[i] == '[')
            push(&top, s[i]);
            
        else if(s[i] == '}' ||s[i] == ']'||s[i] == ')')
        {   
            if(isEmpty(top) == 0){

                if(s[i] == '}' && peek(top)=='{')
                    pop(&top);
                else if(s[i] == ')' && peek(top)=='(')
                    pop(&top);
                else if(s[i] == ']' && peek(top)=='[')
                    pop(&top);
                else
                    return false;
            }
            else
                return false;
            
        }
        i++;
    } 
    if(isEmpty(top))
        return true;
    while(isEmpty(top)!=0)
        pop(&top);
    free(top);
    return false;
}
int main()
{
    char s[] = "[(])";
    printf("is %s is balanced  = %d\n",s,balancedParenthesis(s));
    return 0;
}
char peek(struct Node *top)
{
    return top->data;
}
int isEmpty(struct Node *top)
{
    return (top == NULL) ? 1 : 0;
}
void push(struct Node **top, char value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}
char pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow\n");
        return 'x';
    }
    struct Node *p = *top;
    char data = p->data;
    *top = p->next;
    p->next = NULL;
    free(p);
    return data;
}