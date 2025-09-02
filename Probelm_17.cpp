/*Program to solve a system of 𝑛 linear equations by using Gauss’s 
Elimination method. */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printMatrix(float a[][101], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << setw(12) << a[i][j];
        }
        cout << "\n";
    }
}

void pivotisation(float a[][101], int n) {
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[i][i]) < fabs(a[k][i])) {
                for (int j = 0; j <= n; j++) {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
    }
}

void gaussElimination(float a[][101], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            double factor = a[k][i] / a[i][i];
            for (int j = 0; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }
}

void backSubstitution(float a[][101], float x[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (a[i][i] == 0) {
            cout << "\nThe system is inconsistent\n";
            exit(0);
        } else {
            x[i] = a[i][n];
            for (int j = i + 1; j < n; j++) {
                x[i] -= a[i][j] * x[j];
            }
            x[i] /= a[i][i];
        }
    }
}

int main() {
    int n;
    cout << fixed << setprecision(4);
    cout << "Enter the number of equations: ";
    cin >> n;
    float a[100][101], x[100];

    cout << "\nEnter the elements of the augmented matrix row-wise:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    pivotisation(a, n);
    cout << "\nMatrix after Pivotisation:\n";
    printMatrix(a, n);
    gaussElimination(a, n);
    cout << "\nMatrix after Gauss Elimination:\n";
    printMatrix(a, n);
    backSubstitution(a, x, n);
    cout << "\nThe values of the variables are:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << x[i] << "\n";
    }

    return 0;
}
