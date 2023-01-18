#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string a;
    
    cin>>a;

    sort(a.begin(),a.end(),greater<>());
    int sum=0;
    if(a[a.length()-1]!='0')
        cout<<-1<<endl;
    else{
    for(auto d:a)
        sum+=d-'0';
    if(sum%3==0)
        cout<<a<<endl;
    else 
        cout<<-1<<endl;
    }
}