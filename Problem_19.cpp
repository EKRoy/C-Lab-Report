/*Write an Object-Oriented Program (OOP) to find the smallest and largest
distance between any two points taken from a randomly given set of 𝑛
points.*/
#include<bits/stdc++.h>
using namespace std;
class MinMax
{
public:
    double distance(double x1, double y1, double x2, double y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    void calculate()
    {
        int n;
        cout << "Enter the number of points: ";
        cin >> n;
        if (n < 2)
        {
            cout << "At least two points.\n";
            return;
        }
        double points[n][2];
        cout << "Enter the points (x y) row-wise:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> points[i][0] >> points[i][1];
        }
        double mx = -1e18, mn = 1e18;

        for (int i = 0; i < n; i++)
        {
            double x1 = points[i][0];
            double y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                double x2 = points[j][0];
                double y2 = points[j][1];

                double k = distance(x1, y1, x2, y2);
                // cout << "\nThe distance between the points "<< x1 << "," << y1 << "and "
                //      << x2 << "," << y2 << " is: " << k << endl;

                if (k > mx)
                    mx = k;
                if (k < mn)
                    mn = k;
            }
        }

        cout << "The smallest distance is: " << mn << endl;
        cout << "The largest distance is: " << mx << endl;
    }
};

int main()
{
    MinMax obj;
    obj.calculate();
    return 0;
}
