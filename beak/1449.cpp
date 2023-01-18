#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int N,L;
    cin>>N>>L;
    vector<int> a;
    int count=1;
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
   
    int top=a[0];
    for(int i=1;i<a.size();i++)
    {
        if(a[i]-top+1>L){
        count++;
        top=a[i];
        }
    }
    cout<<count<<endl;
}