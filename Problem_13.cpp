/*Program to take input of the name an of third year student of Applied
Mathematics, RU and marks obtained in all courses including LAB and viva,
and print the overall GPA in year three following the standard grading
criteria of Applied Mathematics. */
#include <iostream>
using namespace std;
double markToGpa(double marks)
{
    if (marks >= 80)
        return 4;
    else if (marks >= 75)
        return 3.75;
    else if (marks >= 70)
        return 3.5;
    else if (marks >= 65)
        return 3.25;
    else if (marks >= 60)
        return 3;
    else if (marks >= 55)
        return 2.75;
    else if (marks >= 50)
        return 2.5;
    else if (marks >= 45)
        return 2.25;
    else if (marks >= 40)
        return 2;
    else
        return 0;
}
int main()
{
    string first, last;
    cout << "Enter the student first and last name: ";
    cin >> first >> last;
    long long roll;
    cout << "Enter the roll number: ";
    cin >> roll;
    double marks, sum = 0, M320, M321;
    double ar[11];
    for (int i = 0; i <= 8; i++)
    {
        cout << "Enter marks obtained A.Math-30" << i + 1 << ": ";
        cin >> marks;
        ar[i] = markToGpa(marks) * 4;
        sum = sum + ar[i];
    }
    cout << "Enter marks obtained in the course A.Math-320: ";
    cin >> M320;
    ar[9] = markToGpa(M320) * 4;
    sum = sum + ar[9];

    cout << "Enter marks obtained in the course A.Math-321(out of 50): ";
    cin >> M321;
    ar[10] = markToGpa(2 * M321) * 2;
    sum = sum + ar[10];

    if (M320 < 40 || M321 < 20)
    {
        cout << first << " " << last << endl;
        cout << "Your CGPA =0.0" << endl;
        cout << "Sorry! you are fail." << endl;
    }
    else
    {
        int fail_count = 0;
        for (int i = 0; i <= 10; i++)
        {
            if (ar[i] == 0)
                fail_count = fail_count + 1;
        }
        if (fail_count > 2)
        {
            cout << first << " " << last << endl;
            cout << "Your CGPA =0.0" << endl;
            cout << "Sorry! you are fail." << endl;
        }
        else
        {
            cout << first << " " << last << endl;
            cout << "Your CGPA is: " << sum / 42 << endl;
            ;
            cout << "Congratulation! You are passed" << endl;
        }
    }

    return 0;
}
