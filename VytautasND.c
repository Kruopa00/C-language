// Vytautas, program created on 2021-10-04, was first released without errors on 2021-10-06, edited on 2021-10-24.
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main() {

    int number;
    char c;

	printf("Hello, this program will find a positive prime number. \n");
	printf("If its not prime number will find a nearest prime number. \n");
	printf("If you want to done program, just write 0 and press enter. \n");

    printf("Now enter a positive integer (please double check what your written): ");

    while(1)
    {
        if(scanf("%d%c", &number, &c) != 2 || number < 0 || !isspace(c))				// cheking its valid, or not.
        {
            while(!isspace(getchar()));
            if (number < 0){
					printf("%d is invalid symbol, please enter a positive integer. \n", number);
					continue;
				}
            else if (number == 0)
                break;
            else
            {
                printf("%c is invalid symbol, please check and try again. \n", c);
                continue;
            }
        }

		else if(number > 1215752191){
			printf("God damm it, number its too big, why you need it? Please write normal number... \n");
			continue;
		}
        
        else if(number == 0)
            break;

        else
        {
            int flag = 0; 		// using flag to mark number it is prime or not..
            for (int i = 2; i <= sqrt(number); ++i) 
            {
                // condition for non-prime
                if (number % i == 0) 
                {
                    flag = 1;
                    break;
                }
            }

            if (number == 1)
                printf("1 is neither prime nor composite. \n");

            else 
            {
                if (flag == 0)
                    printf("%d is a prime number. \n", number);
                else
                {
                    printf("%d is not a prime number. ", number);
                    
					while(1){
                        int temp = number;
                        int temp_neg = number;
                        int k = 0;  		// temporary number, to count how much quotient number has, if has 2 its prime number.
                        
						while(1)			// searching nearest bigger number.
                        {
                            temp++;
                            for(int i = 1; i <= temp; i++)
                            {    if ((temp % i) == 0)
                                   k++;
                            }
                            if (k == 2)
                                break;
                            else k = 0;
                        }

                        k = 0;

                        while(1){			// searching nearest lowest number.
                            temp_neg--;
                            for(int i = 1; i <= temp_neg; i++)
                            {
                                if ((temp_neg % i) == 0)
                                    k++;
                            }
                            if (k == 2)
                                break;
                            else k = 0;
                        }

						// cheking nearest prime number or numbers.
                        if((number - temp_neg) == (temp - number))				
                        {
                            printf("Nearest prime numbers: %d %d.", temp_neg, temp);
                            break;
                        }

                        else if((number - temp_neg) > (temp - number))
                        {
                            printf("Nearest prime number: %d.", temp);
                            break;
                        }
                        else
                        {
                            printf("Nearest prime number: %d.", temp_neg);
                            break;
                        }
                    }                    
                    printf("\n");
                    continue;    
                }
                    
            }
        }
    }

    printf("Thank you, come again. (Saying in Apu from the Simpsons style) \n");

    return 0;
}