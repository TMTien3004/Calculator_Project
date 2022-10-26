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
    printf("\n");
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

// Gaussian Elimination (Bring the matrix to reduced row echelon form)
void Gaussian_Elimination(int (*mat)[max], int &row, int &column)
{
    int lead = 0; 
    while (lead < row) {
        float div, mult;
        // for each row ...
        for (int r = 0; r < row; r++) 
        { 
            /* calculate divisor and multiplier */
            div = mat[lead][lead];
            mult = mat[r][lead] / mat[lead][lead];
            
            // for each column ...
            for (int c = 0; c < column; c++) 
            { 
                if (r == lead)
                    mat[r][c] /= div;               // make pivot = 1
                else
                    mat[r][c] -= mat[lead][c] * mult;  // make other = 0
            }
        }
        lead++;
    }
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
    printf("-------------------- RESULTS ---------------------\n");
    Gaussian_Elimination(mat, row, column);
    Pivot_Points(mat, row, column);
    output_SqMat(mat, row, column);
    //Soltuion(mat, row, column);
}
