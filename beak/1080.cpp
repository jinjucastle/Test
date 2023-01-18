#include<iostream>


using namespace std;
const int Max=50;
char mat1[Max][Max];
char mat2[Max][Max];


void reverse(int x,int y)
{
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(mat1[i][j]==0)

                mat1[i][j]=1;
            else 
                mat1[i][j]=0;
        }
    }
}





int main()
{
    int N,M;
    cin>>N>>M;
    int count=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
           cin>>mat1[i][j];
        }
    }
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
           cin>>mat2[i][j];
        }
    }
      for(int i=0;i<N-2;i++)
    {
        for(int j=0;j<M-2;j++)
        {
            if(mat1[i][j]!=mat2[i][j])
                reverse(i,j);
                count++;
        }
        }
    bool flag=false;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat1[i][j]!=mat2[i][j])
                flag=true;

        }
    }
    if(flag)cout<<-1<<endl;
    else cout<<count<<endl;




}

