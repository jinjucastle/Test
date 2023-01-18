#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
const int max2=300000;
int main()
{
    int N,K;
    
    cin>>N>>K;
    vector<pair<int,int>>a(N);
    int P[max2];
    priority_queue<int,vector<int>,less<int>>c;
    
    for(int i=0;i<N;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<K;i++)
    {
        cin>>P[i];
    }

    sort(a.begin(),a.end());
    sort(P,P+K);
    long long sum=0;
    int index=0;
    for(int i=0;i<K;i++)
    {
        while(index<N&&P[i]>=a[index].first)
        {
            c.push(a[index].second);
            index++;
        }
        if(!c.empty())
        {
            sum+=c.top();
            c.pop();

        }

    }
    cout<<sum<<endl;

}