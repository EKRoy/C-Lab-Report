/*Program to find the dominant eigenvalue and corresponding eigenvector of 
a given non-diagonal square matrix. */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    cout << fixed << setprecision(4);
    int n;
    cout << "Enter the order of the matrix: ";
    cin >> n;
    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), c(n);
    cout << "Enter the elements of the matrix row-wise:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter the initial guess for the eigenvector:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    double eps;
    cout << "Enter the desired accuracy: ";
    cin >> eps;

    double k = b[0]; // Initial guess for eigenvalue
    double y;
    do {
        y = k;
        // Compute c = A * b
        for (int i = 0; i < n; i++) {
            c[i] = 0;
            for (int j = 0; j < n; j++)
                c[i] += A[i][j] * b[j];
        }

        // Estimate the eigenvalue as the max absolute value of c
        k = abs(c[0]);
        for (int i = 1; i < n; i++)
            if (abs(c[i]) > k)
                k = abs(c[i]);

        // Normalize to get the next eigenvector
        for (int i = 0; i < n; i++)
            b[i] = c[i] / k;

    } while (abs(k - y) >= eps);

    cout << "\nThe largest Eigenvalue is: " << k << "\n";
    cout << "The corresponding Eigenvector is:\n";
    for (int i = 0; i < n; i++)
        cout << b[i] << "\n";

    return 0;
}
