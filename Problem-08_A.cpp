/*Program to sort an array of numbers in ascending and descending order.
Write codes for without user defined function.*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    int ar[n];
    cout << "Enter the elements of the array :" << endl;
    //Assending Order
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] > ar[j])
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    cout << "The ascender order is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    //desending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] < ar[j])
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    cout << "The descending order is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;

    return 0;
}
