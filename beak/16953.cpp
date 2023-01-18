#include<iostream>

using namespace std;

int main()
{
    int a, b;
    int count =0;
    cin >> a >> b;

    while (1)
    {
        if (b < a)
        {
            cout << -1 << endl;
            break;
        }
        if (b == a)
        {
            count++;
            cout << count << endl;
            break;
        }

        if (b % 2 == 0)
        {
            b /= 2;
           
        }
        else if (b % 10== 1)
        {
            b--;
            b /= 10;
           
        }
        else
        {
            cout << -1 << endl;
            break;
        } 
        count++;
    }
}