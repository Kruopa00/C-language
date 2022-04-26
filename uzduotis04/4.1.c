#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double determinant;
    fprintf(stderr, "Hello, this program will show the answer (if there is) of function.\n");
    fprintf(stderr, "Now, please enter three numbers.\n");

    fscanf(stdin, "%lf %lf %lf", &a, &b, &c);

    determinant = (b*b) - (4 * a * c);

    if (determinant < 0){
        fprintf(stderr, "There is no solution with this numbers.\n");
    }

    else if (determinant == 0) {
        double x1 = (-b) / (2 * a);
        fprintf(stderr, "There is one solution: %.2lf\n", x1);
    }
    else {
        determinant = sqrt(determinant);
        double x1 = ((-b) + determinant) / (2 * a);
        double x2 = ((-b) - determinant) / (2 * a);

        fprintf(stderr, "There are two solutions: %.2lf and %.2lf\n", x1, x2);
    }

    fprintf(stderr, "Thank you for your attention. :) \n");
    return 0;
}