/*Program to take input of the name an of third year student of Applied 
Mathematics, RU and marks obtained in all courses including LAB and viva, 
and print the overall GPA in year three following the standard grading 
criteria of Applied Mathematics. */

#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
double markToGpa(double marks){
    if(marks>=80) return 4;
    else if(marks>=75) return 3.75;
    else if(marks>=70) return 3.5;
    else if(marks>=65) return 3.25;
    else if(marks>=60) return 3;
    else if(marks>=55) return 2.75;
    else if(marks>=50) return 2.5;
    else if(marks>=45) return 2.25;
    else if(marks>=40) return 2;
    else return 0;
}
double markToGpa2(double marks){
    if(marks>=40) return 4;
    else if(marks>=38) return 3.75;
    else if(marks>=35) return 3.5;
    else if(marks>=33) return 3.25;
    else if(marks>=30) return 3;
    else if(marks>=28) return 2.75;
    else if(marks>=25) return 2.5;
    else if(marks>=23) return 2.25;
    else if(marks>=20) return 2;
    else return 0;
}
int main(){
    int choice=1;
    while(choice==1){
        string first,last;
        cout<<"Enter the student first and last name: ";
        cin>>first>>last;
        long long  roll;
        cout<<"Enter the roll number: ";
        cin>>roll;
        double marks,sum=0,M320,M321;
        double ar[12];
        //we will get the marks of 9 course.Without lab and viva
        for(int i=1;i<=9;i++){
            cout<<"Enter marks obtained A.Math-30"<<i<<": ";
            cin>>marks;
            ar[i]=markToGpa(marks)*4;
            sum+=ar[i];
        }
        cout<<"Enter marks obtained in the course A.Math-320: ";
        cin>>M320;
        ar[10]=markToGpa(M320)*4;
        sum+=ar[10];
        // Now we will take input of viva course 321
        //the full mark for this course is 50
        // this course has 2 credits
         cout<<"Enter marks obtained in the course A.Math-321(out of 50): ";
        cin>>M321;
        ar[11]=markToGpa2(M321)*2;
        sum+=ar[11];
        /*According to Applied Mathematics department if you fail in A.Math-320 then you fail*/
        if(M321<20){
            cout<<"Mr./Ms. "<<first<<" "<<last<<endl;
            cout<<"Your CGPA =0.0"<<endl;
            cout<<"Sorry! you are fail."<<endl;
        }
        else{
            //Another rule ,if you fail in more than two course then you fail.
            int count=0;
            for(int i=1;i<=11;i++){
                if(ar[i]==0) count++;
            }
            if(count>2) {
                cout<<"Mr./Ms. "<<first<<" "<<last<<endl;
                cout<<"Your CGPA =0.0"<<endl;
               cout<<"Sorry! you are fail."<<endl;
            }
            else{
               cout<<"Mr./Ms. "<<first<<" "<<last<<endl;
                cout<<"Your CGPA is: "<<sum/42<<endl;;
                cout<<"Congratulation! You pass"<<endl;
            }
        }
        cout << "Do you want to calculate the CGPA for a different person? (1=yes, 0=no): ";
       cin>>choice;
    }
   return 0;
}