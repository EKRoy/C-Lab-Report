//Solve suppressed cubic equations(x^3-2x-5) or transcendental functions by using 
// bisection & Newton-Raphson method
#include<iostream>
#include<cmath>
#include <iomanip>
#define t 0.00001
using namespace std;
double f(double x){
    return pow(x,3)-2*x-5;
}
double ff(double x){
    return 3*pow(x,2)-2;
}
void BisectionMethod(double a,double b){
    if(f(a)*f(b)>=0){
        cout<<"There is no roots between the given interval"<<endl;
        return;
    }
     double c=(a+b)/2;
    if(f(c)==0){
         cout<<"The root of the equation between the given interval is"<<c<<endl;
    }
    else{
        while(fabs(a-b)>=t){
            if(fabs(f(c))<t) break;
            if(f(a)*f(c)<0) b=c;
            else a=c;
            c=(a+b)/2;
        }
        cout<<"According to Bisection Method "<<endl;
        cout<<"The root of the equation between the given interval is:"<<c<<endl;
    }
}
void NewtonRapshon(double x1){
    double x0=0;
    int i=1;
    cout<<"According to Newton Rapshon"<<endl;
    while(fabs(x1-x0)>=t){
        x0=x1;
        if(ff(x0)==0){
            cout<<"Mathematical Error"<<endl;
            return;
        }
        x1=x0-f(x0)/ff(x0);
        cout<<"At step- "<<i<<"x= "<<x1<<endl;
        i++;
    }
    cout<<"The root of the function is: "<<x1<<endl;
    cout<<"Iteration number is "<<i-1<<endl;
}
int main(){
    int y=1;
    while(y--){
        double a,b,d;
        cout<<"Enter the initial interval [a,b] for Bisection Method"<<endl;
        cin>>a>>b;
        cout<<"Enter the initial guess for NewTon_Raphson Method"<<endl;
        cin>>d;
        BisectionMethod(a,b);
        NewtonRapshon(d);
        cout << "Do you want to put new values? (1=yes, 0=no): ";
        cin>>y;
    }
   return 0;
}