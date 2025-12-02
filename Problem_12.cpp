/*Program to take input of a user name and minutes spent talking on the
telephone and print a telephone bill which billing criteria is as follows
i) First 150 minutes is free of cost
ii) Next 250 calls (151-400 minute) are charged at the rate of 1
   TK/minute
iii) And all calls after 400 minutes, are charged at the rate of
    2/minute
Make sure you implement the idea using user-defined function. */

#include <iostream>
using namespace std;
void telephoneBill(double minutes)
{
    double bill;
    if (minutes <= 150)
    {
        bill = 0.0;
    }
    else if (minutes <= 400)
    {
        bill = 0 + (minutes - 150) * 1;
    }
    else
    {
        bill = 0 + 250 * 1 + (minutes - 400) * 2;
    }
    cout << "Your telephone bill is:" << bill << "Tk." << endl;
}
int main()
{
    string first, last;
    cout << "\nEnter your first name and last name: ";
    cin >> first >> last;
    double minutes;
    cout << "Enter the minutes spent talking on the telephone: ";
    cin >> minutes;
    cout << first << " " << last << endl;
    telephoneBill(minutes);
    return 0;
}
