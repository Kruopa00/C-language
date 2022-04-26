#include <stdio.h>
#include <stdlib.h>

int highest_denominator(int a, int b);
int least_multiple(int a, int b);

int main()
{
    int a, b, c;
    int hcf, lcm;
    fprintf(stderr, "Hello, this program will show the highest common denominator\n");
    fprintf(stderr, "and least common multiple.\n");
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

    lcm = least_multiple(a, least_multiple(b, c));
    hcf = highest_denominator(a, highest_denominator(b, c));

    fprintf(stderr, "HCF: %d\n", hcf);
    fprintf(stderr, "LCM: %d\n", lcm);
    fprintf(stderr, "Thank you and good luck! :)\n");
    return 0;
}

int least_multiple(int a, int b)
{
    int temp = a;

    while(1){
        if (temp % b == 0 && temp % a == 0)
            break;
        temp++;
    }

    return temp;
}

int highest_denominator(int a, int b)
{
    int gcd = 0;
    for(int i = 1; i <= a && i <= b; ++i){
        // Checks if i is factor of both integers
        if(a % i == 0 && b % i == 0)
            gcd = i;
    }

    return gcd;
}