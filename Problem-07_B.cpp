/*Program to find the factorial of any given number.  Write codes for both
with and without user defined function. */

#include <iostream>
using namespace std;
void factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    cout << "The factorial of the given number is: " << fact << endl;
}
int main()
{
    int n;
    cout << "Enter the positive number: ";
    cin >> n;
    factorial(n);
    return 0;
}
