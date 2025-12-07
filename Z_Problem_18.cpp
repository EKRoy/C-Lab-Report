#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double det(int n, double matrix[100][100])
{
    double temp[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = matrix[i][j];

    double determinant = 1;

    for (int i = 0; i < n; i++)
    {
        int pivot_row = i;
        for (int k = i + 1; k < n; k++)
            if (fabs(temp[k][i]) > fabs(temp[pivot_row][i]))
                pivot_row = k;

        if (fabs(temp[pivot_row][i]) < 1e-12)
            return 0;

        if (pivot_row != i)
        {
            for (int j = 0; j < n; j++)
                swap(temp[i][j], temp[pivot_row][j]);
            determinant *= -1;
        }

        for (int k = i + 1; k < n; k++)
        {
            double factor = temp[k][i] / temp[i][i];
            for (int j = i; j < n; j++)
                temp[k][j] -= factor * temp[i][j];
        }

        determinant *= temp[i][i];
    }

    return determinant;
}

int main()
{
    int n;
    cout << fixed << setprecision(3);
    cout << "Enter the n of the matrix : ";
    cin >> n;

    double matrix[100][100], rhs[100];
    double modifiedMatrix[100][100], solution[100];

    cout << "Enter the elements of the matrix row-wise\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    cout << "Enter the elements of the RHS vector\n";
    for (int i = 0; i < n; i++)
        cin >> rhs[i];

    double D = det(n, matrix);
    if (D == 0)
    {
        cout << "The system doesn't have a unique solution\n";
        return 0;
    }

    for (int col = 0; col < n; col++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                modifiedMatrix[i][j] = matrix[i][j];

        for (int i = 0; i < n; i++)
            modifiedMatrix[i][col] = rhs[i];

        solution[col] = det(n, modifiedMatrix) / D;
    }

    cout << "\nThe required solution is:\n";
    for (int i = 0; i < n; i++)
        cout << solution[i] << endl;

    return 0;
}
