#include <bits/stdc++.h>
using namespace std;

int main()
{
    // takes an input of age and shows if adult or not

    // int age;
    // cin >> age;
    // if (age >= 18)
    // {
    //     cout << "Person is Adult";
    // }
    // else{
    //     cout << "Person is not Adult" << endl;
    // }

    // grade system:

    // int marks;
    // cin >> marks;

    // if (marks < 25)
    // {
    //     cout << "Grade: F";
    // }
    // else if (marks <= 44)
    // {
    //     cout << "Grade: E";
    // }
    // else if (marks <= 49)
    // {
    //     cout << "Grade: D";
    // }
    // else if (marks <= 59)
    // {
    //     cout << "Grade: C";
    // }
    // else if (marks <= 79)
    // {
    //     cout << "Grade: B";
    // }
    // else
    // {
    //     cout << "Grade: A";
    // }


    int personage; 
    cin >> personage; 

    if (personage < 18)
    {
        cout << "NOT Eligible for JOB"; 
    } else {
        if (personage >= 18)
        {
            cout << "Eligible for JOB"; 
        }
        else if (personage >= 55 && personage <= 57)
        {
            cout << "Eligible for JOB but retirement soon";
        }
        else if (personage > 57)
        {
            cout << "Time for retirement"; 
        }
        
    }
    
}