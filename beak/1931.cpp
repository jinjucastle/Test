#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;




int main(){

    int N,begin,end;

    vector<pair<int,int>>a;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>begin>>end;
        a.push_back(make_pair(end,begin));

    }
    sort(a.begin(),a.end());
    int p=a[0].first;
    int count =1;
    for(int i=1;i<N;i++)
    {
        if(p<=a[i].second)
        {
        count++;
        p=a[i].first;
        }
    }

        cout<<count;
}