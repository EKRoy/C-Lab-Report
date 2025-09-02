/*Write an OOP to solve a system of 𝑛 linear equations by using Gauss’s 
Elimination method.*/
// OOP to solve a nxn Linear system
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

class GaussianElimination {
private:
    int n;  
    vector<vector<double>> augmentedMat; 

public:
    GaussianElimination(int size) : n(size), augmentedMat(size, vector<double>(size + 1)) {}

    void inputMatrix() {
        cout << "Enter the coefficients of the augmented matrix (including RHS) row by row:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                cin >> augmentedMat[i][j];
            }
        }
    }

    vector<double> solve() {
        for (int i = 0; i < n; ++i) {
            if (fabs(augmentedMat[i][i]) < 1e-9) {
                for (int k = i + 1; k < n; ++k) {
                    if (fabs(augmentedMat[k][i]) > 1e-9) {
                        swap(augmentedMat[i], augmentedMat[k]);
                        break;
                    }
                }
            }

            double pivot = augmentedMat[i][i];
            for (int j = 0; j <= n; ++j) {
                augmentedMat[i][j] /= pivot;
            }

            for (int k = i + 1; k < n; ++k) {
                double factor = augmentedMat[k][i];
                for (int j = 0; j <= n; ++j) {
                    augmentedMat[k][j] -= factor * augmentedMat[i][j];
                }
            }
        }

        vector<double> solution(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            solution[i] = augmentedMat[i][n];
            for (int j = i + 1; j < n; ++j) {
                solution[i] -= augmentedMat[i][j] * solution[j];
            }
        }

        return solution;
    }

    void displayMatrix() {
        cout << "Augmented Matrix:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                cout << setw(10) << augmentedMat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    GaussianElimination solver(n);
    solver.inputMatrix();

    cout << "\nInitial Augmented Matrix:\n";
    solver.displayMatrix();

    vector<double> solution = solver.solve();

    cout << "\nSolution:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
