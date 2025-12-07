#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the dimension of the matrix: ";
    cin >> n;

    double a[100][100]; // using fixed-size array
    cout << "Enter the elements row-wise:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    double determinant = 1;

    for (int i = 0; i < n; i++)
    {
        // Partial pivoting: find the row with the largest absolute value in column i
        int pivot_row = i;
        for (int k = i + 1; k < n; k++)
            if (fabs(a[k][i]) > fabs(a[pivot_row][i]))
                pivot_row = k;

        // cout << "pivot: " << pivot_row << endl;
        // If pivot is zero, determinant is zero
        if (fabs(a[pivot_row][i]) < 1e-12)
        {
            determinant = 0;
            break;
        }

        // Swap rows if needed
        if (pivot_row != i)
        {
            for (int j = 0; j < n; j++)
                swap(a[i][j], a[pivot_row][j]);
            determinant *= -1; // row swap changes sign
        }

        // Eliminate lower rows
        for (int k = i + 1; k < n; k++)
        {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j < n; j++)
                a[k][j] -= factor * a[i][j];
        }
        determinant *= a[i][i];
    }

    cout << "\nThe determinant is: " << determinant << endl;
    return 0;
}
//  3           this matrix create runtime error for my first code
//  0 0 3
//  4 0 6
//  6 4 0