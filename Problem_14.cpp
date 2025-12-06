/*Program to find the dominant eigenvalue and corresponding eigenvector of
a given non-diagonal square matrix. */

#include <bits/stdc++.h>
#define t 0.00001
using namespace std;
int main()
{
    cout << fixed << setprecision(4);
    int n;
    cout << "Enter the order of the matrix: ";
    cin >> n;
    double A[n][n];
    double v[n], c[n];
    cout << "Enter the elements of the matrix row-wise:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "Enter the initial guess for the eigenvector:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    double k = v[0]; // Initial guess for eigenvalue
    double y;
    do
    {
        y = k;
        // Compute c = A * v
        for (int i = 0; i < n; i++)
        {
            c[i] = 0;
            for (int j = 0; j < n; j++)
            {
                c[i] = c[i] + A[i][j] * v[j];
            }
        }

        // Estimate the eigenvalue as the max absolute value of c
        k = abs(c[0]);
        for (int i = 1; i < n; i++)
        {
            if (abs(c[i]) > k)
            {
                k = abs(c[i]);
            }
        }
        // Normalize to get the next eigenvector
        for (int i = 0; i < n; i++)
            v[i] = c[i] / k;

    } while (abs(k - y) >= t);

    cout << "\nThe largest Eigenvalue is: " << k << "\n";
    cout << "The corresponding Eigenvector is:\n";
    for (int i = 0; i < n; i++)
        cout << v[i] << "\n";

    return 0;
}
