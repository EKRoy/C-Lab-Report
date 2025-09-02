/*write an OOP to find the roots of a general quadratic equation. */
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
class QuadraticEquation{
    private:
        double a,b,c;
    //constructor
    public:
        QuadraticEquation(double coeffA, double coeffB, double coeffC) {
        a = coeffA;
        b = coeffB;
        c = coeffC;
    }
    void findRoots(){
        if(a==0){
            cout<<"This is not a Quadratic equation(a==0)"<<endl;
            return;
        }
        double dist=b*b-4*a*c;
        if(dist>0){
            double root1=(-b+sqrt(dist))/(2*a);
            double root2=(-b-sqrt(dist))/(2*a);
            cout<<"Roots are real and different."<<endl;
            cout<<"Root1="<<root1<<endl;
            cout<<"Root2="<<root2<<endl;
        }
        else if(dist==0){
            double root=-b/(2*a);
            cout<<"Roots are real and same."<<endl;
             cout<<"Root1=Root2 = "<<root<<endl;
        }
        else{
            double realPart=-b/(2*a);
            double img=sqrt(-dist)/(2*a);
            cout<<"Roots are complex and different."<<endl;
            cout<<"Root1= "<<realPart<<"+ "<<img<<"i"<<endl;
            cout<<"Root1= "<<realPart<<"- "<<img<<"i"<<endl;

        }
    }
};
int main(){
    cout<<fixed<<setprecision(2);
    int choice=1;
    while(choice==1){
        double a,b,c;
        cout<<"Enter the coefficients of a,b,c: ";
        cin>>a>>b>>c;
        QuadraticEquation Q(a,b,c);
        Q.findRoots();
        cout << "Do you want to calculate another quadratic equation? (1=yes, 0=no): ";
        cin>>choice;
    }
   return 0;
}