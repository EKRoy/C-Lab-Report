#include <bits/stdc++.h>
using namespace std;
class Matrix
{
public:
    int n;
    double a[100][100];
    void input()
    {
        cout << "Enter the order of matrix: ";
        cin >> n;
        cout << "Enter the elements:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        // Append identity matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j < 2 * n; j++)
            {
                if (j == i + n)
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }
    }

    void pivot()
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                if (fabs(a[i][i]) < fabs(a[k][i]))
                {
                    for (int j = 0; j < 2 * n; j++)
                    {
                        swap(a[i][j], a[k][j]);
                    }
                }
            }
        }
    }

    void inverse()
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    double factor = a[k][i] / a[i][i];
                    for (int j = 0; j < 2 * n; j++)
                    {
                        a[k][j] -= factor * a[i][j];
                    }
                }
            }
        }

        // Normalize diagonal to 1
        for (int i = 0; i < n; i++)
        {
            double temp = a[i][i];
            if (fabs(temp) < 1e-9)
            {
                cout << "Inverse does NOT exist (singular matrix)\n";
                return;
            }
            for (int j = 0; j < 2 * n; j++)
            {
                a[i][j] /= temp;
            }
        }
        cout << "\nInverse Matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j < 2 * n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix M;
    M.input();
    M.pivot();
    M.inverse();
    return 0;
}
