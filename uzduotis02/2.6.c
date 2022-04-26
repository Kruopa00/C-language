#include <stdio.h>

void max(int x, int y, int z);
void min(int x, int  y, int z);

int main(){

    int minmax;

	int x, y, z;

    printf("Hello, this program will show biggest or smallest number \n");
    printf("from your three numbers. If you want to find biggest number enter 1 and press enter.\n");
    printf("If you want to find smallest number, enter 0 and press enter.\n");

    while (scanf("%d", &minmax) != 1 || (minmax != 0 && minmax != 1) || getchar() != '\n')
    {
		while (getchar() != '\n');

		printf("Wrong input! Enter only a number\n");
		printf("Try again: ");
    }
    
    printf("Now enter three numbers:\n");

	printf("Enter the X value: ");
	while (scanf("%d", &x) != 1 || getchar() != '\n'){
		while (getchar() != '\n');

		printf("Wrong input! Enter only a number\n");
		printf("Try again: ");
	}

	printf("Enter the Y value: ");
	while (scanf("%d", &y) != 1 || getchar() != '\n'){
		while (getchar() != '\n');

		printf("Wrong input! Enter only a number\n");
		printf("Try again: ");
	}

	printf("Enter the Z value: ");
	while (scanf("%d", &z) != 1 || getchar() != '\n'){
		while (getchar() != '\n');
		
		printf("Wrong input! Enter only a number\n");
		printf("Try again: ");
	}

    (minmax == 1) ? (max(x, y, z)) : (min (x, y, z));

    printf("Program compiled succesfully, bye!\n");

	return 0;
}

void max(int x, int  y, int z){
	int  temp = x;
	(temp < y) && (temp = y);
	(temp < z) && (temp = z);

    printf("\nBiggest number = %d\n", temp);
}

void min(int x, int  y, int z){
	int  temp = x;
	(temp > y) && (temp = y);
	(temp > z) && (temp = z);
	
    printf("\nSmallest number = %d\n", temp);
}