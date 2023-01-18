#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<string> A(N);
    vector<int>B(26);
    
    int total=0;
    for(int i=0;i<N;i++)
        cin>>A[i];

    for(int i=0;i<N;i++)
    {
        int seat=1;
        for(int j=A[i].size()-1;j>=0;j--)
        {
                int test=A[i][j]-'A';
                    B[test]+=seat;
                    seat*=10;  
        }
    }
        sort(B.begin(),B.end(),greater<int>());
        int num=9;
        
        
        for(int k=0;k<B.size();k++)
        {
            if(B[k]==0)break;
            total+=B[k]*num;
            num--;
        }

   
    cout<<total<<endl;

}