#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,k,first,second;
    cin>>n;
    while(n--)
    {
        cin>>k;
        vector<pair<int,int>>a;
        for(int i=0;i<k;i++)
        {
            cin>>first>>second;
            a.push_back({first,second});
        }
        sort(a.begin(),a.end());
        int count=0;
        int check=1;

        for(int i=1;i<k;i++)
        {
            if(a[count].second>a[i].second){
                check++;
                count=i;
            }
        }
        cout<<check<<endl;
    }
    
}