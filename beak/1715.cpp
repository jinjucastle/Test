#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
    int N,num,first=0,sum;
    cin>>N;
    priority_queue<int ,vector<int>,greater<int>>a;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        a.push(num);
    }
    while(a.size()>1){
        int b=a.top();
        a.pop();
        int c= a.top();
        a.pop();

        sum=b+c;
        first+=sum;
        a.push(sum);
    }
    cout<<first<<endl;
}