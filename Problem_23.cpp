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
            for (int k = i + 1; k < n; k++)
            {
                if (fabs(a[i][i]) < fabs(a[k][i]))
                {
                    for (int j = 0; j < n + 1; j++)
                    {
                        swap(a[i][j], a[k][j]);
                    }
                }
            }
        }
    }
    void elimination()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                if (fabs(a[i][i]) < 1e-12)
                {
                    cout << "The system is inconsistent" << endl;
                    exit(0);
                }
                double factor = a[k][i] / a[i][i];
                for (int j = 0; j < n + 1; j++)
                {
                    a[k][j] -= factor * a[i][j];
                }
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
        cout << "After Pivotisation: " << endl;
        printMatrix();
        elimination();
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
