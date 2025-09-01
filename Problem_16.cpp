// Determinant using Row-Elementary Operations with vector
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n; 
    cout.precision(2);      
    cout.setf(ios::fixed);

    cout << "\nEnter the dimension of the matrix: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n));
    double determinant = 1.0;

    cout << "\nEnter the elements of the matrix row-wise:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    // Pivotisation: make leading element the largest by absolute value
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (abs(a[i][i]) < abs(a[k][i])) {
                swap(a[i], a[k]);      
                determinant *= -1;   
            }
        }
    }

    cout << "\nThe matrix after Pivotisation is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(10) << a[i][j];
        cout << "\n";
    }

    // Gaussian elimination to upper triangular matrix
    for (int i = 0; i < n - 1; i++) {
        if (fabs(a[i][i]) < 1e-9) {
            cout << "Zero pivot encountered! Determinant is 0.\n";
            return 0;
        }
        for (int k = i + 1; k < n; k++) {
            double factor = a[k][i] / a[i][i];
            for (int j = 0; j < n; j++)
                a[k][j] -= factor * a[i][j];
        }
    }

    cout << "\nThe matrix after Gaussian Elimination is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(10) << a[i][j];
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
        determinant *= a[i][i];

    cout << "\nThe required determinant is: " << determinant << "\n";
    return 0;
}
