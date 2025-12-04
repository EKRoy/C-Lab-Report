/*Calculate the value of log⁡(1+𝑥) using its series for some
given 𝑥 using WHILE or DO WHILE condition. */

#include <iostream>
#include <cmath>
using namespace std;
void logFunction(double x, int n)
{
    if (x >= 1)
    {
        cout << "Not valid ,Enter x<1" << endl;
        return;
    }
    double y = 1 + x;
    double v = (y - 1) / (y + 1);
    double sum = 0;
    int i = 1;
    while (i <= 2 * n)
    {
        sum = sum + pow(v, i) / i;
        i = i + 2;
    }
    cout << "The actual value of log(1+x) using standard library is: " << log10(y) << endl;
    cout << "The approximate value of log(1+" << x << ")= " << 2 * sum / log(10) << endl;
    double error = abs(log10(y) - 2 * sum / log(10));
    cout << "Error= " << error << endl;
}
int main()
{
    int n;
    double x;
    cout << "Enter the number of term(n>0): " << endl;
    cin >> n;
    cout << "Enter the value of x(x>=0) for log(1+y) series: " << endl;
    cin >> x;
    logFunction(x, n);

    return 0;
}
