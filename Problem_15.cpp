/*Program to find the inverse of a given square matrix using row-elementary 
 operations. */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cout.precision(4);
    cout.setf(ios::fixed);
    int i, j, k, n;
    float a[100][200];
    a:
    cout << "\nEnter the order of matrix: ";
    cin >> n;

    cout << "\nEnter the elements:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    // Form an augmented matrix by adding identity matrix
    for (i = 0; i < n; i++)
        for (j = n; j < 2 * n; j++)
            if (j == i + n)
                a[i][j] = 1;

    // Pivotisation to make the matrix diagonally dominant
    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (abs(a[i][i]) < abs(a[k][i]))
                for (j = 0; j < 2 * n; j++) {
                    float temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }

    cout << "\nAugmented Matrix after pivotization:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2 * n; j++)
            cout << a[i][j] << "    ";
        cout << endl;
    }

    // Convert left matrix to identity
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            if (k != i) {
                float temp = a[k][i] / a[i][i];
                for (j = 0; j < 2 * n; j++)
                    a[k][j] -= temp * a[i][j];
            }
        }
    }

    // Divide every row by its leading entry
    for (i = 0; i < n; i++) {
        float temp = a[i][i];
        if (temp == 0) {
            cout << "\nThe given matrix doesn't have an inverse\n";
            exit(0);
        }
        for (j = 0; j < 2 * n; j++)
            a[i][j] /= temp;
    }

    cout << "\nThe required inverse matrix is:\n";
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    int si;
    cout << "\nDo you want to calculate for a different matrix?\n";
    cout << "If yes press 1, else 0: ";
    cin >> si;
    if (si == 1)
        goto a;

    return 0;
}
