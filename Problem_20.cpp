/*write an OOP to find the roots of a general quadratic equation. */
#include <bits/stdc++.h>
using namespace std;
class Quadratic
{
public:
    double a, b, c;
    void input()
    {
        cout << "Enter the coefficient of a,b,c ";
        cin >> a >> b >> c;
    }
    void calculate()
    {
        if (a == 0)
        {
            cout << "This is not a Quadratic equation(a==0)" << endl;
            return;
        }
        double dist = b * b - 4 * a * c;
        if (dist > 0)
        {
            double root1 = (-b + sqrt(dist)) / (2 * a);
            double root2 = (-b - sqrt(dist)) / (2 * a);
            cout << "Roots are real and different." << endl;
            cout << "Root1=" << root1 << endl;
            cout << "Root2=" << root2 << endl;
        }
        else if (dist == 0)
        {
            double root = -b / (2 * a);
            cout << "Roots are real and same." << endl;
            cout << "Root1=Root2 = " << root << endl;
        }
        else
        {
            double realPart = -b / (2 * a);
            double img = sqrt(-dist) / (2 * a);
            cout << "Roots are complex and different." << endl;
            cout << "Root1= " << realPart << "+ " << img << "i" << endl;
            cout << "Root2= " << realPart << "- " << img << "i" << endl;
        }
    }
};
int main()
{
    Quadratic Q;
    Q.input();
    Q.calculate();
    return 0;
}
