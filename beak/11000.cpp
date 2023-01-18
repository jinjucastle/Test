#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main()
{
    long long N;
    cin>>N;
    vector<pair<long long,long long>>a(N);
    priority_queue<int, vector<int>,greater<int>>A;
    int count=1;
    
    for(int i=0;i<N;i++)
    {
        
        cin>>a[i].first>>a[i].second;
        
    }
    sort(a.begin(),a.end());
     A.push(a[0].second);
    for(int i=1;i<N;i++)
    {
        if(A.top()<=a[i].first)
        {
            A.pop();
            A.push(a[i].second);
        }
        else 
            A.push(a[i].second);
    }
    cout<<A.size()<<endl;

}