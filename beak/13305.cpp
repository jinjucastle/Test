#include<iostream>
#include<vector>

using namespace std;

int dis[100000];
int a[100000];

int main(){
    
    int N;
    long long G;
    cin>>N;
   
    long long sum=0;
    
    for(int i=1;i<N;i++)
        cin>>dis[i];
    for(int i=0;i<N;i++)
        cin>>a[i];

    G=a[0];
    sum=G*dis[1];

    for(int i=1;i<N;i++)
    {
        if(G>a[i])
        {
            G=a[i];
            sum+=G*dis[i+1];
        }
        else
        
            sum+=G*dis[i+1];
    } 
    cout<<sum<<endl;
}