#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;
    printf("\nHello, this program will ask you to write three numbers\n");
    printf("and solve two math problems.\n");

    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("First math problem answer: %f\n", (x + 4 * y + pow(z, 3)));
    printf("Second math problem answer: %f\n", ((x + sqrt(y)) * (pow(z, 4) - ((z > 0) ? (z) : (z * -1)) + 46.3 ) ));
    return 0;
}