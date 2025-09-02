/*Program to solve a system of 𝑛 linear equations by using Cramer’s rule. */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double det(int n, double matrix[100][100]) {
    double temp[100][100];
    // Copy the matrix so original is not modified
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matrix[i][j];
        }
    }

    double determinant = 1.0;

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (abs(temp[i][i]) < abs(temp[k][i])) {
                for (int j = 0; j < n; j++) {
                    double swap = temp[i][j];
                    temp[i][j] = temp[k][j];
                    temp[k][j] = swap;
                }
                determinant *= -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = 0; k < n; k++) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        determinant *= temp[i][i];
    }

    return determinant;
}

int main() {
    int n;
    cout<<fixed<<setprecision(2);
    cout << "Enter the n of the matrix :";
    cin >> n;
    double matrix[100][100], rhs[100], modifiedMatrix[100][100], solution[n], tempMatrix[100][100];

    cout << "Enter the elements of the matrix row-wise\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the elements of the RHS vector\n";
    for (int i = 0; i < n; i++) {
        cin >> rhs[i];
    }
    // Copy the original matrix to a temp matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempMatrix[i][j] = matrix[i][j];
        }
    }

    if (det(n, matrix) == 0) {
        cout << "The system doesn't have a unique solution\n";
        exit(0);
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k != i) {
                        modifiedMatrix[j][k] = tempMatrix[j][k];
                    } else {
                        modifiedMatrix[j][k] = rhs[j];
                    }
                }
            }
            solution[i] = det(n, modifiedMatrix) / det(n, matrix);
        }

        cout << "\nThe required solution is:\n";
        for (int i = 0; i < n; i++) {
            cout << solution[i] << endl;
        }
    }

    return 0;
}
