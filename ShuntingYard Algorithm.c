#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack yapısı
typedef struct
{
    char items[MAX][20];
    int top;
} Stack;

void push(Stack *s, char *item)
{
    if (s->top < MAX - 1)
    {
        strcpy(s->items[++s->top], item);
    }
}

char *pop(Stack *s)
{
    if (s->top >= 0)
        return s->items[s->top--];
    return NULL;
}

char *peek(Stack *s)
{
    if (s->top >= 0)
        return s->items[s->top];
    return NULL;
}

// Operatör kontrolü
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Öncelik değerleri
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    }
    return 0;
}

// ^ sağdan birleşimli (right-associative)
int isRightAssociative(char op)
{
    return op == '^';
}

// Shunting-yard algoritması
void shuntingYard(char *expression, char output[MAX][20], int *outSize)
{
    Stack stack;
    stack.top = -1;

    char token[20];
    int pos = 0, outCount = 0;

    for (int i = 0; expression[i] != '\0'; i++)
    {

        if (isdigit(expression[i]))
        {
            token[pos++] = expression[i];

            if (!isdigit(expression[i + 1]))
            {
                token[pos] = '\0';
                pos = 0;
                strcpy(output[outCount++], token);
            }
        }
        else if (isOperator(expression[i]))
        {

            char op = expression[i];
            char *top = peek(&stack);

            while (top && isOperator(top[0]) &&
                   ((precedence(op) <= precedence(top[0]) && !isRightAssociative(op)) ||
                    (precedence(op) < precedence(top[0]) && isRightAssociative(op))))
            {
                strcpy(output[outCount++], pop(&stack));
                top = peek(&stack);
            }

            token[0] = op;
            token[1] = '\0';
            push(&stack, token);
        }
        else if (expression[i] == '(')
        {
            token[0] = '(';
            token[1] = '\0';
            push(&stack, token);
        }
        else if (expression[i] == ')')
        {

            while (peek(&stack) && peek(&stack)[0] != '(')
            {
                strcpy(output[outCount++], pop(&stack));
            }

            pop(&stack); // '(' atılır
        }
    }

    while (stack.top >= 0)
    {
        strcpy(output[outCount++], pop(&stack));
    }

    *outSize = outCount;
}

int main()
{
    char expr[100];
    char output[MAX][20];
    int outSize;

    printf("Infix ifade gir (bosluksuz): ");
    scanf("%s", expr);

    shuntingYard(expr, output, &outSize);

    printf("Postfix (RPN): ");
    for (int i = 0; i < outSize; i++)
    {
        printf("%s ", output[i]);
    }

    printf("\n");
    return 0;
}
