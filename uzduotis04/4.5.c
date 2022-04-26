#include <stdio.h>
#include <stdlib.h>
int main()
{
    double a, num;
    double max = 0, min = 0, sum = 0;
    double average = 0;
    fprintf(stderr, "Hello, this program will ask you how much numbers you want to write\n");
    fprintf(stderr, "and will calculate average, sum, biggest and smallest number.\n");
    fprintf(stderr, "Now, please enter how much numbers you will want to write: \n");

    if (scanf("%lf", &a) == 1 && a > 0) {   
        fprintf(stderr, "Now enter %.0lf numbers:\n", a);
        
        if (scanf ("%lf", &num) == 1) {
            max = num;
            min = num;
            sum = num;
        }
        else {
            printf("Wrong input, goodbye.\n");
            exit(1);
        }

        for (int i = 1; i < a; ++i) {
            if (scanf("%lf", &num) == 1){
                sum += num;
                if (num > max)
                    max = num;
                if (num < min)
                    min = num;
            }
            
            else {
                printf("Wrong input, goodbye.\n");
                exit(1);
            }
        }

    }
    else {
        printf("Wrong input, goodbye.\n");
        exit(1);
    }

    average = sum / a;

    fprintf(stderr, "Sum: %.2f\n", sum);
    fprintf(stderr, "Average: %.2f\n", average);
    fprintf(stderr, "Biggest: %.2f\n", max);
    fprintf(stderr, "Smallest: %.2f\n", min);
    fprintf(stderr, "Thank you and good luck! :)\n");
    return 0;
}
