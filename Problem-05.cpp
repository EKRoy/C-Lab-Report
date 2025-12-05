/*Calculate the value of log⁡(1+𝑥) using its series for some
given 𝑥 using WHILE or DO WHILE condition. */
#include <iostream>
#include <cmath>
using namespace std;
void logFunction(double x, int n)
{
    if (x <= -1 || x > 1)
    {
        cout << "Series does not converge for this x. Please enter -1 < x <= 1." << endl;
    }
    else
    {
        double sum = 0;
        int i = 1;
        while (i <= n)
        {
            sum += pow(-1, i + 1) * pow(x, i) / i;
            i = i + 1;
        }
        cout << "The approximate value of log(1+x)= " << sum << endl;
    }
}
int main()
{
    int n;
    double x;
    cout << "Enter the number of term(n>0): " << endl;
    cin >> n;
    cout << "Enter the value of x(x>=0) for log(1+x) series: " << endl;
    cin >> x;
    logFunction(x, n);

    return 0;
}
