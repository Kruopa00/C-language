// LSP numeris: 2110582, el. paštas: krupaviciusvy@gmail.com, 2 užduotis, 1 variantas
#include <stdio.h>

void formMatrix(int arr[], int n, int mat[n][n]);
void getMatrix(int arr[], int n);
void printMatrix(int n, int mat[n][n]);
int validNumber();

int main() {

    int n; 

    printf("Write N: ");

    n = validNumber();
    while(1){

        if (n <= 0)
        {
            printf("Matrix number cant be negative, please try again: ");
            n = validNumber();
            continue;
        }
        else 
        {
            int mat[n][n];
            int arr[n];
            getMatrix(arr, n);
            formMatrix(arr, n, mat);
            printMatrix(n, mat);
            break;
        }
    }

    return 0;
}

void formMatrix(int arr[], int n, int mat[n][n])
{
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int index = 0;

    while(1)
    {
        if (left > right)
            break;

        for (int i = left; i <= right; ++i)
            mat[top][i] = arr[index++];
        top++;

        if(top > bottom)
            break;

        for (int i = top; i <= bottom; ++i)
            mat[i][right] = arr[index++];
        right--;

        if(left > right)
            break;
        
        for (int i = right; i >= left; --i)
            mat[bottom][i] = arr[index++];
        bottom--;

        if(top > bottom)
            break;

        for (int i = bottom; i >= top; --i)
            mat[i][left] = arr[index++];
        left++;
    }
}

void printMatrix(int n, int mat[n][n])
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void getMatrix(int arr[], int n)
{
    for (int i = 0; i < n*n; ++i)
        arr[i] = i + 1;
}

int validNumber()
{
    int n;
    while(1)
        {
            if ((scanf("%d", &n) == 1) && (getchar() == '\n'))
            {
                return n;
                break;
            }
            else
            {
                while (getchar() != '\n');
                printf("Invalid symbol, please check and try again: \n");
                continue;
            }
        }
}