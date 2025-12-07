#include <bits/stdc++.h>
using namespace std;
struct Point // user-defined data type,group different types of variables under one name
{
    double x, y;
};
class PointSet
{
private:
    int n;
    Point arr[1000];
    double mn, mx;

public:
    double distance(Point &a, Point &b)
    {
        return sqrt(((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
    }
    void read()
    {
        cout << "Enter the number of points" << endl;
        cin >> n;
        if (n < 2)
        {
            cout << "Please enter the points at least two" << endl;
            exit(0);
        }
        cout << "Please make sure all the points are distinct.\n";
        cout << "Enter the points(x,y)" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].x >> arr[i].y;
        }
        mn = 1e18;
        mx = 1e-18;
    }
    void calculate()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double d = distance(arr[i], arr[j]);
                cout << "\nThe distance between the points (" << arr[i].x << "," << arr[i].y << ") and ("
                     << arr[j].x << "," << arr[j].y << ") is: ";
                cout << d << endl;
                if (d < mn)
                    mn = d;
                if (d > mx)
                    mx = d;
            }
        }
    }
    void print()
    {
        cout << "Shortest Distance: " << mn << endl;
        cout << "Longest distance: " << mx << endl;
    }
};
int main()
{
    cout << fixed << setprecision(3) << endl;
    PointSet P;
    P.read();
    P.calculate();
    P.print();
    return 0;
}