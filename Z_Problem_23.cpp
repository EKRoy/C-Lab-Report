/*Write an OOP to solve a system of 𝑛 linear equations by using Gauss’s
Elimination method.*/
// OOP to solve a nxn Linear system
#include <bits/stdc++.h>
using namespace std;
class GaussElimination
{
private:
    double a[100][101];
    double x[100];
    int n;

public:
    GaussElimination()
    { // constructor
        cout << fixed << setprecision(3);
        cout << "Enter the number of equation" << endl;
        cin >> n;
        cout << "Enter the argument matrix row-wise(include RHS)" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                cin >> a[i][j];
            }
        }
    }
    void printMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    void pivotisation()
    {
        for (int i = 0; i < n; i++)
        {
            // Partial pivoting: find the row with the largest absolute value in column i
            int pivot_row = i;
            for (int k = i + 1; k < n; k++)
                if (fabs(a[k][i]) > fabs(a[pivot_row][i]))
                    pivot_row = k;

            // cout << "pivot: " << pivot_row << endl;
            // If pivot is zero, determinant is zero
            if (fabs(a[pivot_row][i]) < 1e-12)
            {
                cout << "\nThe system is inconsistent\n";
                exit(0);
            }

            // Swap rows if needed
            if (pivot_row != i)
            {
                for (int j = 0; j < n + 1; j++)
                    swap(a[i][j], a[pivot_row][j]);
            }

            // Eliminate lower rows
            for (int k = i + 1; k < n; k++)
            {
                double factor = a[k][i] / a[i][i];
                for (int j = i; j < n + 1; j++)
                    a[k][j] -= factor * a[i][j];
            }
        }
    }
    void backSubstitution()
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (fabs(a[i][i]) < 1e-12)
            {
                cout << "The system is inconsistent" << endl;
                exit(0);
            }
            x[i] = a[i][n];
            for (int j = i + 1; j < n; j++)
            {
                x[i] -= a[i][j] * x[j];
            }
            x[i] /= a[i][i];
        }
    }
    void solve()
    {
        pivotisation();
        cout << "After Elimination:" << endl;
        printMatrix();
        backSubstitution();
        cout << "Solution: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "x" << "[" << i << "]= " << x[i] << endl;
        }
    }
};
int main()
{
    GaussElimination obj;
    obj.solve();
    return 0;
}
//  3            this matrix create runtime error for my first code
// 0 0 3 10
// 4 0 6 20
// 6 4 0 30