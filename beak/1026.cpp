#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int N;
    cin>>N;

    vector<int>a(N);
    vector<int>b(N);
    vector<int>c(N,0);
    

    for(int i=0;i<N;i++)
        cin>>a[i];
     for(int i=0;i<N;i++)
        cin>>b[i];


    sort(a.begin(),a.end());

    int time,count=0,index;
   
    for( int j=0;j<N;j++)
    {
        time=0;    
        index=0;
        for(int i=0;i<N;i++)
        {
            if(time<b[i]&&c[i]==0){
                time=b[i];
                index=i;
            }
        }
        count+=a[j]*time;
        c[index]=1;
    }
    cout<<count<<endl;
}