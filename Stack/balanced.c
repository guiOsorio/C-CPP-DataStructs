// check if operation is balanced (in terms of (), {} and []), using a stack

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;
void Push(int x);
void Pop();
int Top();
void Print();

int main()
{
    // ask user for input
    char input[50];
    printf("Input: ");
    scanf("%s", input);
    // loop to check every parentheses in the input
    for(int i = 0; i < strlen(input); i++)
    {
        // if opening character is presented, push it to the top of the stack
        if(input[i] == '(' || input[i] == '[' || input[i] == '{')
        {
            Push(input[i]);
        }
        // if closing character is presented, check if the top of the stack corresponds to its opening
        // parentheses
        else if(input[i] == ')')
        {
            if(A[top] == '(') // if they correspond, remove opening character from the stack
            {
                Pop();
            }
            else
            {
                return printf("Invalid - %c does not correspond to last opening character\n", input[i]); // if they do not correspond, the input is invalid
            }
        }
        // square brackets
        else if(input[i] == ']')
        {
            if(A[top] == '[')
            {
                Pop();
            }
            else
            {
                return printf("Invalid - %c does not correspond to last opening character\n", input[i]);
            }
        }
        // curly brackets
        else if(input[i] == '}')
        {
            if(A[top] == '{')
            {
                Pop();
            }
            else
            {
                return printf("Invalid - %c does not correspond to last opening character\n", input[i]);
            }
        }
    }
    // if the top of the stack is empty, the input is invalid
    if( A[top] != '(' && A[top] != '{' && A[top] != '[')
    {
        return printf("Valid\n");
    }
    // if the top of the stack is not empty, the input is invalid because an opening character was not closed
    else
    {
        return printf("Invalid - a closing character was not provided\n");
    }
}


void Push(int x)
{
    if(top == MAX_SIZE -1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    A[++top] = x;
}
void Pop()
{
    if(top == -1)
    {
        printf("Error: no element to pop\n");
        return;
    }
    top--;
}
int Top()
{
    return A[top];
}
void Print()
{
    printf("Stack: ");
    for(int i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
