#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
    int sum = 0, tmp=0;
    char a[51];
    bool check=false;
    cin >> a;

    for (int i = 0; i <=strlen(a); i++)
    {
        if (a[i] == '+' || a[i] == '-' || i==strlen(a))
        {
            if (!check) {
                sum += tmp;
                tmp = 0;
            }
            else
            {
                sum -= tmp;
                tmp = 0;
            }
            if (a[i] == '-') check = true;
         }

        else
        {
            tmp *= 10;
            tmp += a[i] - '0';
        }
    }
    cout << sum;
}