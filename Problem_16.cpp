// Determinant using Row-Elementary Operations with vector
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    int n;
    cout << "Enter the dimension of the matrix: " << endl;
    cin >> n;
    double a[100][100];
    cout << "Enter the elements of the matrix row-wise:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    double determinant = 1;

    // Pivotisation: make leading element the largest by absolute value
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(a[i][i]) < fabs(a[k][i]))
            {
                for (int j = 0; j < n; j++)
                {
                    swap(a[i][j], a[k][j]);
                }
                determinant = determinant * -1;
            }
        }
    }

    // Gaussian elimination to upper triangular matrix
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            double factor = a[k][i] / a[i][i];
            for (int j = 0; j < n; j++)
                a[k][j] = a[k][j] - factor * a[i][j];
        }
    }

    // Calculate determinant from diagonal
    for (int i = 0; i < n; i++)
    {
        determinant = determinant * a[i][i];
    }

    cout << "\nThe required determinant is: " << determinant << endl;
    return 0;
}
