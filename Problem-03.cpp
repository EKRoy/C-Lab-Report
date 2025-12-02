/*Calculate the value of sinx  using its series for some
   given 𝑥 using WHILE or DO WHILE condition. */
#include <iostream>
#include <cmath>
using namespace std;
void sinFunction(double x,int n){
    n=n-1;
    x=x*(3.1416/180);
    double sum=x;
    double fact=1;
    int i=1;
    while(i<=n){
        fact=fact*(2*i+1)*(2*i);
        sum=sum+(pow(-1,i)*pow(x,2*i+1))/fact;
        i=i+1;
    }
    cout<<"summation:"<<sum<<endl;
}
int main()
{
    int n;
    double x;
    cout << "Enter the value of n:" << endl;
    cin >> n;
    cout << "Enter the value of x (in degree.):" << endl;
    cin >> x;
    sinFunction(x, n);
    return 0;
}
