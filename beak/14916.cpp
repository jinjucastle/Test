
#include<iostream>

using namespace std;

int main()
{
    int N, a, b;
    int sum = 0;
    cin >> N;
    a = N / 5;
    if (N % 5 == 0)
    {
        cout << a;
        return 0;
    }
    while (a >= 0)
    {
        int result = (N-(a*5)) % 2;
        b = (N - (a * 5)) / 2;
        if (result == 0)
        {
            cout << a + b;
            return 0;
        }
        a--;
    }
    cout << -1;
}
