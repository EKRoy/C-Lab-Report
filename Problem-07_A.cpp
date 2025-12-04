/*Program to find the factorial of any given number.  Write codes for 
 without user defined function. */

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the positive number: ";
    cin >> n;
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << "The factorial of the given number is: " << fact << endl;
    return 0;
}
