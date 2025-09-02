/*Write an Object-Oriented Program (OOP) to find the smallest and largest 
distance between any two points taken from a randomly given set of 𝑛 
points.*/
#include <iostream>
#include <cmath>
using namespace std;
class MinMax {
public:
    // Function to compute Euclidean distance
    double distance(double x1, double y1, double x2, double y2) {
        return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
    }

    void getDistances() {
        int n;
        cout << "Enter the number of points to be entered: ";
        cin >> n;
        if (n < 2) {
            cout << "There should be at least two points.\n";
            exit(0);
        }
        cout << "Please make sure all the points are distinct.\n";
        int totalPairs = n*(n-1)/2;
        double points[n][2]; 
        cout << "Enter the points (x y) row-wise:\n";
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        double mx=-1e18,mn=1e18;
        // Calculate distances
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                double x1 = points[i][0];
                double y1 = points[i][1];
                double x2 = points[j][0];
                double y2 = points[j][1];

                cout << "\nThe distance between the points (" << x1 << "," << y1 << ") and ("
                     << x2 << "," << y2 << ") is: ";

                double k=distance(x1, y1, x2, y2);
                if(k>mx) mx=k;
                if(k<mn) mn=k;
                cout << k << endl;
            }
        }

        cout << "\nThe smallest distance is: " << mn << endl;
        cout << "The largest distance is: " << mx << endl;
    }
};

int main() {
    int choice=1;
    while(choice==1){
        MinMax obj;
        obj.getDistances();
         cout << "Do you want to calculate another testcase? (1=yes, 0=no): ";
        cin>>choice;
    }
    return 0;
}
