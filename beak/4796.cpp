#include<iostream>

using namespace std;

int main()
{
    int L, P, V;
    int count;
    int a = 0;
    while (1)
    {

        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            break;
        count = (V / P) * L + min(L, V % P);
        cout << "Case " << ++a << ": " << count << endl;
       
    }
    return 0;
}
