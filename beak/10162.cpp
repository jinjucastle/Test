#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int a;
    int b,c,d;
    cin>>a;
    if(a%10!=0) cout<<-1<<endl;
    else
    {
        b=a/300;
        c=(a%300)/60;
        d=((a%300)%60)/10;
        cout<<b<<" "<<c<<" "<<d<<endl;
    }
}