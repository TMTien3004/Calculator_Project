#include <stdio.h>
#define max 100

void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

// Input the size of the matrix
void input_SqMat(int (*mat)[max], int &row, int &column)
{
    printf("Length of row: ");
    scanf("%d", &row);

    printf("\nLength of column: ");
    scanf("%d", &column);
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
}

// Printing out the matrix
void output_SqMat(int (*mat)[max], int &row, int &column)
{
    printf("Resulting matrix:\n\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

// Locating the pivot points
void Pivot_Points(int (*mat)[max], int &row, int &column)
{
    printf("Locations of the pivot points:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (mat[i][j] != 0)
            {
                printf("Column: %d, Row: %d, Num: %d\n", i, j, mat[i][j]);
                break;
            }
        }
    }
    
}

// Gauss-Jordan Elimination (Bring the matrix to reduced row echelon form)
void Reduced_Row_Echelon_Form(int (*mat)[max], int &row, int &column)
{
    int k, i, j;
    float multiplier;
    for (k = 0; k < column; k++)
    {
        for (i = 0; i < row; i++)
        {
            if (i != k)
            {
                multiplier = mat[i][k] / mat[k][k];
                for (j = 0; j < column + 1; j++)
                {
                    mat[i][j] = mat[i][j] - mat[k][j] * multiplier;
                }
            }
        }
    }
    printf("\n\n");
}

// Incomplete
void Soltuion(int (*mat)[max], int &row, int &column)
{
    float solution;
    if (mat[row - 1][column] == 0)
    {
        printf("There are Infinite number of Solutions!\n");
    }
}

int main()
{
    int mat[max][max];
    int row, column, num;

    input_SqMat(mat, row, column);
    printf("-------------------- RESULTS ---------------------\n\n");
    Pivot_Points(mat, row, column);
    Reduced_Row_Echelon_Form(mat, row, column);
    output_SqMat(mat, row, column);
    //Soltuion(mat, row, column);
}
