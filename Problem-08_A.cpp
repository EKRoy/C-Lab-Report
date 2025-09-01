/*Program to sort an array of numbers in ascending and descending order.
Write codes for without user defined function.*/
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main(){
   int choice=1;
   while(choice==1){
    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;
    int ar[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    //Ascending Order
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ar[i]>ar[j]){
                int temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
    cout<<"The ascender order is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    //Desending Order
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
           if(ar[i]<ar[j]){
                int temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
    cout<<"The descending order is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    cout << "Do you want to put new values? (1=yes, 0=no): ";
    cin>>choice;
   }
   return 0;
}