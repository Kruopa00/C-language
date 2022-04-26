#include <stdio.h>
#include <stdlib.h>

int main()
{
    fprintf(stderr, "Hello, this program will find number with most digits.\n");
    fprintf(stderr, "Now, please enter a number: ");
    
    int n;
    int big = 0, digits = 0, maxDigits = 0;
    int temp;
    while(1)
    {
        if(scanf("%d", &n) == 1){
            if (n < 0){
                fprintf(stderr, "Number with most digits: %d", big);
                fprintf(stderr, "Thank you and good luck! :)\n");
                return 0;
            }

            temp = n;
            while(n){     
                n /= 10;
                digits++;
            }

            if(digits > maxDigits){
                big = temp;
                maxDigits = digits;                
            }

            digits = 0;
        }
        else {
            printf("Wrong input, goodbye.\n");
            exit(1);
        }
    }
}