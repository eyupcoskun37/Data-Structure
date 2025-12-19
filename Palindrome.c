#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char str[100];
    int i, len, flag = 1;

    printf("Kelime giriniz: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len / 2; i++)
        push(str[i]);

    if (len % 2 != 0)
        i++;

    for (; i < len; i++)
    {
        if (str[i] != pop())
        {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Palindrome degil\n");

    return 0;
}
