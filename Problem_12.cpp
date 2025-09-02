/*Program to take input of a user name and minutes spent talking on the 
telephone and print a telephone bill which billing criteria is as follows 
i) First 150 minutes is free of cost 
ii) Next 250 calls (151-400 minute) are charged at the rate of 1 
   TK/minute 
iii) And all calls after 400 minutes, are charged at the rate of 
    2/minute 
Make sure you implement the idea using user-defined function. */

#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
double telephoneBill(double minutes){
    double bill=0.0;
    if(minutes<=150){
        bill=0.0;
    }
    else if(minutes>150 && minutes<=400){
        bill=(minutes-150)*1;
    }
    else{
        bill=250*1+(minutes-400)*2;
    }
    return bill;
}
int main(){
    int choice=1;
    while(choice==1){
        string first,last;
        cout<<"Enter your first name and last name: ";
        cin>>first>>last;
        double minutes;
        cout<<"Enter the minutes spent talking on the telephone: ";
        cin>>minutes;
        cout<<"Mr./Ms. "<<first<<" "<<last<<endl;
        cout<<fixed<<setprecision(2);
        cout<<"Your telephone bill is:"<<telephoneBill(minutes)<<"Tk."<<endl;
        cout << "Do you want to calculate telephone bill for a different person? (1=yes, 0=no): ";
       cin>>choice;
    }
   return 0;
}