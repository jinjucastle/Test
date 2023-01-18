#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int a, coin = 0, b = 1000,d;

    vector<int>c = { 500,100,50,10,5,1 };
    cin >> a;

    a = b - a;
    while (a > 0) {
        for (int i = 0; i < c.size(); i++)
        {
            if (a >= c[i])
            {
                d = a / c[i];
                a %= c[i];

                coin += d;
            }
            else
                continue;
        }
    }
    cout << coin;
}