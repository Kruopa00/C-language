#include <stdio.h>

int main()
{
    int number;
    printf("\nHello, this program will print number that you written\n");
    printf("and says its even or not\n");

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("%d %s", number, ((number % 2 == 0) ? ("even\n") : ("not even\n")));
    return 0;
}