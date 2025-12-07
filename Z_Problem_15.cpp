#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the order of matrix: ";
    cin >> n;

    double a[100][200]; // augmented matrix [A|I]
    double orig[100][100];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            orig[i][j] = a[i][j];
        }

    // Form augmented matrix [A | I]
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            if (j == i + n)
            {
                a[i][j] = 1;
            }
            else
                a[i][j] = 0;
        }
    }
    // Gauss-Jordan elimination with partial pivoting
    for (int i = 0; i < n; i++)
    {
        // Partial pivoting for column i
        int pivot_row = i;
        for (int k = i + 1; k < n; k++)
            if (fabs(a[k][i]) > fabs(a[pivot_row][i]))
                pivot_row = k;

        if (fabs(a[pivot_row][i]) < 1e-12)
        {
            cout << "Inverse does not exist.\n";
            return 0;
        }

        // Swap rows if needed
        if (pivot_row != i)
            for (int j = 0; j < 2 * n; j++)
                swap(a[i][j], a[pivot_row][j]);

        // Make pivot = 1
        double temp = a[i][i];
        for (int j = 0; j < 2 * n; j++)
            a[i][j] /= temp;

        // Eliminate other rows
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = a[k][i] / a[i][i];
                for (int j = 0; j < 2 * n; j++)
                    a[k][j] -= factor * a[i][j];
            }
        }
    }

    // Print inverse matrix
    cout << "\nThe inverse matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "\nA * A^-1 = Identity matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double sum = 0;
            for (int k = 0; k < n; k++)
                sum += orig[i][k] * a[k][j + n]; // original * inverse
            if (fabs(sum) < 1e-9)
                sum = 0; // treat tiny floating-point errors as 0
            cout << fixed << setprecision(6) << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
//  3           this matrix create runtime error for my first code
//  0 0 3
//  4 0 6
//  6 4 0