//Solve cubic general cubic equation by using Cardano's Method
#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#include <complex> 
using namespace std;
void solveCubic(double a,double b,double c,double d){
    if(a==0){
        cout<<"This is not a cubic equation."<<endl;
        return;
    }
    double p=(3*a*c-b*b)/(3*a*a);
    double q=(2*b*b*b-9*a*b*c+27*a*a*d)/(27*a*a*a);
    double delta=q*q/4+p*p*p/27;
    double r=-b/(3*a);
    if(delta>0){
        double u=cbrt(-q/2+sqrt(delta));
        double v=cbrt(-q/2-sqrt(delta));
        double real=u+v+r;
        cout<<"One real root and two complex coonjugate roots."<<endl;
        cout<<"Root 1:"<<real<<endl;
        cout<<"Root 2:"<<-(u+v)/2+r<<" + "<<sqrt(3)/2*(u-v)<<"i"<<endl;
        cout<<"Root 3:"<<-(u+v)/2+r<<" - "<<sqrt(3)/2*(u-v)<<"i"<<endl;
    }
    else if(delta==0){
        double u=cbrt(-q/2);
        cout<<"One real root and two repeated root."<<endl;
        cout<<"Root 1:"<<2*u+r<<endl;
        cout<<"Root 2:"<<-u+r<<endl;
        cout<<"Root 3:"<<-u+r<<endl;
    }
    else{
        double rho=sqrt(-p*p*p/27);
        double theta=acos(-q/(2*rho));
        double factor=2*cbrt(rho);
        cout<<"The real roots."<<endl;
        double r1=factor*cos(theta/3)+r;
        double r2=factor*cos((theta+2*M_PI)/3)+r;
        double r3=factor*cos((theta+4*M_PI)/3)+r;
        cout<<"Root 1:"<<r1<<endl;
        cout<<"Root 2:"<<r2<<endl;
        cout<<"Root 3:"<<r3<<endl;
    }
}
int main(){
    int y=1;
    while(y--){
        double a,b,c,d;
        cout<<"Enter the values of the coefficients a, b, c, and d:"<<endl;
       cin>>a>>b>>c>>d;
       solveCubic(a,b,c,d);
       cout << "Do you want to put new values? (1=yes, 0=no): ";
       cin>>y;
    }
   return 0;
}