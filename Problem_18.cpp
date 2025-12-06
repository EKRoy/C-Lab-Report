\/*Program to solve a system of 𝑛 linear equations by using Cramer’s rule. */
#include<bits/stdc++.h>
using namespace std;

double det(double matrix[][100] ,int n)
{
    double determinant = 1.0;
    //pivot
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (abs(matrix[i][i]) < abs(matrix[k][i]))
            {
                for (int j = 0; j < n; j++)
                {
                    swap(matrix[i][j],matrix[k][j]);
                }
                determinant *= -1;
            }
        }
    }
    //gauss
    for (int i = 0; i < n; i++)
    {
        for (int k= i + 1; k < n; k++)
        {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = 0; j < n; j++)
            {
                matrix[k][j] =matrix[k][j]- factor * matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        determinant *= matrix[i][i];
    }

    return determinant;
}

int main()
{
    int n;
    cout << fixed << setprecision(2);
    cout << "Enter the n of the matrix :";
    cin >> n;
    double matrix[100][100], rhs[100], modifiedMatrix[100][100], solution[n], tempMatrix[100][100];

    cout << "Enter the elements of the matrix row-wise\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the elements of the RHS vector\n";
    for (int i = 0; i < n; i++)
    {
        cin >> rhs[i];
    } 
    // Copy the original matrix to a temp matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tempMatrix[i][j] = matrix[i][j];
        }
    }

    if (det(matrix,n) <=1e-9)
    {
        cout << "The system doesn't have a unique solution\n";
    }
    else
    {
        for (int i =  0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                    {
                        modifiedMatrix[j][k] = rhs[j];
                    } 
                    else
                    {
                        modifiedMatrix[j][k] = tempMatrix[j][k];
                    }
                }
            }
            solution[i] = det(modifiedMatrix, n) / det(matrix,n);
        }

        cout << "\nThe required solution is:\n";
        for (int i = 0; i < n; i++)
        {
            cout << solution[i] << endl;
        }
    }

    return 0;
}
