#include<iostream>
#include<vector>

const int Max=100;
using namespace std;

int check[Max];
int Plug[Max];

int main()
{
    int N,K,sum=0;
    cin>>N>>K;
    
    for(int i=0;i<K;i++)
    cin>>Plug[i];

    for(int i=0;i<K;i++)
    {
        bool plugcheck=false;
        for(int j=0;j<N;j++)
        {
            if(check[j]==Plug[i])
            {
            plugcheck=true;
            break;
            }
        }
        if(plugcheck)
            continue;
        for(int j=0;j<N;j++)
        {
            if(check[j]==0)
            {
            check[j]=Plug[i];
            plugcheck=true;
            }
        }
        if(plugcheck)
            continue;

        int index=-1;
        int last_plug=-1;
        for(int j=0;j<N;j++)
        {
            int tmp=0;
            for(int q=0;q<K;q++)
            {
                if(Plug[q]==check[j])
                {
                    break;
                }
                tmp++;
            }
            if(tmp>last_plug)
            {
                last_plug=tmp;
                index=j;
            }
        }
        check[index]=Plug[i];
        sum++;
    }
    cout<<sum<<endl;
}