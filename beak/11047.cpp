#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N,k,coin=0;
    int a; 
    cin>>N>>k;
    vector<int>num(N);

    for(int i=0;i<N;i++)
    {
        cin>>num[i];
    }
    while(k>=0)
    for(int i=0;i<N; i++)
    {
        if(num[i]>k)
         {   k%=num[i-1];
            a=k/num[i-1];
            coin+=a;
         }


    }
    cout<<coin;
}