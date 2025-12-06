// Determinant using Row-Elementary Operations with vector
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    int n;
    cout << "\nEnter the dimension of the matrix: ";
    cin >> n;
    double a[100][100];
    cout << "\nEnter the elements of the matrix row-wise:\n";
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
            if (abs(a[i][i]) < abs(a[k][i]))
            {
                for (int j = 0; j < n; j++)
                {
                    swap(a[i][j], a[k][j]);
                    determinant = determinant * -1;
                }
            }
        }
    }

    cout << "\nThe matrix after Pivotisation is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    // Gaussian elimination to upper triangular matrix
    for (int i = 0; i < n - 1; i++)
    {
        if (fabs(a[i][i]) < 1e-9)
        {
            cout << "Zero pivot encountered! Determinant is 0.\n";
            return 0;
        }
        for (int k = i + 1; k < n; k++)
        {
            double factor = a[k][i] / a[i][i];
            for (int j = 0; j < n; j++)
                a[k][j] -= factor * a[i][j];
        }
    }

    cout << "\nThe matrix after Gaussian Elimination is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(10) << a[i][j];
        cout << "\n";
    }

    // Calculate determinant from diagonal
    for (int i = 0; i < n; i++)
        determinant *= a[i][i];

    cout << "\nThe required determinant is: " << determinant << "\n";
    return 0;
}
