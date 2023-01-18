#include<iostream>

using namespace std;

int main()
{
    int N,b,c,d,f;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        b=a/25;
        c=(a%25)/10;
        d=((a%25)%10)/5;
        f=(((a%25)%10)%5);
        
        cout<<b<<" "<<c<<" "<<d<<" "<<f<<endl;
    }


}