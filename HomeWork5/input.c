#include <stdio.h>

int main()
{
    char input[50];
    fgets(input, 50, stdin);
    printf("%s", input);
    return 0;
}
