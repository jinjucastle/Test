#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a.begin(),a.end(),greater<int>());
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=max(sum,a[i]*(i+1));
    }
    cout<<sum;
}