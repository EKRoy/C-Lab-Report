/*Program to find the largest and smallest number that can be formed using
digits of a given number. Write codes for without user
defined function. */
#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter the number: ";
    cin >> s;
    int n = s.length();
    //largest number
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] < s[j])
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    cout << "The largest number is: " << s << endl;
    //smallest number
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] > s[j])
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    cout << "The smallest number is: " << s << endl;
    return 0;
}
