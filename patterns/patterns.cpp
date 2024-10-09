#include <bits/stdc++.h>
using namespace std;

/*
****
****
****
****
*/
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
 *
 **
 ***
 ****
 */
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
1
12
123
*/
void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }
        cout << endl;
    }
}

/*
1
22
333
4444
*/
void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1;
        }
        cout << endl;
    }
}

/*
****
***
**
*
*/
void pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
1234
123
12
1
*/
void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << j + 1;
        }
        cout << endl;
    }
}

/*
 *    [2 1 2]  space star space
 ***   [1 3 1]  for spaces: n - i - 1
 *****  [0 5 0]  for stars: 2 * i + 1
 */
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

/*
*****
***
*
*/
void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * (n - i) - 1; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
 *
 **
 ***
 **
 *
 */
void pattern10(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int stars;
        if (i < n)
        {
            stars = i + 1;
        }
        else
        {
            stars = 2 * n - i - 1;
        }
        for (int j = 0; j < stars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
1
01
101
0101
10101
*/
void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = 1;
        if (i % 2 == 0)
            start = 1; // for even row start is 1
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
    cout << endl;
}

/*
1      1
12    21
123  321
12344321
*/
void pattern12(int n)
{
    int space = 2 * (n - 1);
    for (int i = 0; i < n; i++)
    {
        // numbers
        for (int j = 0; j < i; j++)
        {
            cout << j;
        }
        // spaces
        for (int k = 0; k < space; k++)
        {
            cout << " ";
        }
        // numbers
        for (int l = i; l > 0; l--)
        {
            cout << l;
        }
        cout << endl;
        space -= 2;
    }
}

/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/
void pattern19(int n)
{
    int initial = 0;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < (n - i); j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < initial; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (n - i); j++)
        {
            cout << "*";
        }
        initial += 2;
        cout << endl;
    }
    initial = 2 * n - 2;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < initial; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
        initial -= 2;
    }
    cout << endl; 
}

/*

*/
void pattern21(int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == (n - 1) || j == (n - 1))
            {
                cout << "*"; 
            }
            else cout << " ";
        }
        cout << endl; 
    }
    cout << endl; 
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) // run for given times
    {
        int n;
        cin >> n;
        pattern21(n); // call the function
    }
}