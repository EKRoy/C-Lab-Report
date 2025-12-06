#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "\nEnter the order of matrix: ";
    cin >> n;
    double a[100][101];
    cout << "\nEnter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            if (j == i + n)
            {
                a[i][j] = 1;
            }
            else
                a[i][j] = 0;
        }
    }
    // pivot
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (abs(a[i][i]) < abs(a[k][i]))
            {
                for (int j = 0; j < 2 * n; j++)
                {
                    swap(a[i][j], a[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = a[k][i] / a[i][i];
                for (int j = 0; j < 2 * n; j++)
                {
                    a[k][j] = a[k][j] - factor * a[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        double temp = a[i][i];
        if (temp < 1e-9)
        {
            cout << "Does not exists" << endl;
            return 0;
        }
        for (int j = 0; j < 2 * n; j++)
        {
            a[i][j] =a[i][j]/ temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
