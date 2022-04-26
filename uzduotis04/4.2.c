#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    fprintf(stderr, "Hello, this program will show the answer (if there is) of interval (a;b]\n");
    fprintf(stderr, "number that are bigger than 0 and remaining 1 by dividing by c.\n");
    fprintf(stderr, "Now, please enter three numbers.\n");

    fscanf(stdin, "%lf %lf %lf", &a, &b, &c);

    for (int i = a; i <= b; i++){
        if(i % (int)c == 1 && c > 0 && i > 0)
            fprintf(stderr, "%d\n", i);
    }

    fprintf(stderr, "Thank you and good luck! :)\n");
    return 0;
}