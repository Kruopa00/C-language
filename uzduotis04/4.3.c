#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    fprintf(stderr, "Hello, this program will show the answer (if there is) of \n");
    fprintf(stderr, "number that are bigger than 0 and remaining 1 by dividing by c.\n");
    fprintf(stderr, "Now, please enter three numbers.\n");

    if (scanf("%d %d %d", &a, &b, &c) == 3) {   
        if (a >= 0 && b >= 0 && c >= 0){
            printf("Input without mistakes.\n"); 
        }
        else 
        {
            printf("Wrong input, goodbye.\n");
            exit(1);
        }
    }
    else {
        printf("Wrong input, goodbye.\n");
        exit(1);
    }

    if (a == 0 && b == 1){
        int num = 0;
        for (int i = 2; i <= c; ++i){
            num = a + b;
            a = b;
            b = num;
        }
        
        fprintf(stderr, "It`s Fibonacci number: %d", num);
        fprintf(stderr, "Thank you and good luck! :) \n");
        return 0;
    }

    int Array[c];

    Array[0] = a;
    Array[1] = b;

    for (int i = 2; i <= c; ++i)
        Array[i] = Array[i - 1] + Array [i - 2];

    fprintf(stderr, "This F%d number: %d\n", c, Array[c]);
    fprintf(stderr, "Thank you and good luck! :)\n");
    return 0;
}