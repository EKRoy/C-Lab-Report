/*Write an OOP to read a matrix, display the sum of its diagonal elements,
lower-diagonal elements and upper-diagonal elements. */
#include <bits/stdc++.h>
using namespace std;
class matrix
{
public:
    int mat[100][100];
    int n;
    void input()
    {
        cout << "Enter the value of n: ";
        cin >> n;
        cout << "Enter the elements of Matrix row_wise: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
    }
    void calculate()
    {
        double diagSum = 0, lowerSum = 0, upperSum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    diagSum = diagSum + mat[i][j];
                }
                else if (i > j)
                {
                    lowerSum = lowerSum + mat[i][j];
                }
                else
                    upperSum = upperSum + mat[i][j];
            }
        }
        cout << "Sum of main diagonal elements: " << diagSum << endl;
        cout << "Sum of lower diagonal elements: " << lowerSum << endl;
        cout << "Sum of upper diagonal elements: " << upperSum << endl;
    }
};
int main()
{
    matrix M;
    M.input();
    M.calculate();
    return 0;
}
