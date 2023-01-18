#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
int N;

int one=0,zero=0;
vector<int>p;
vector<int>O;
cin>>N;
while(N--)
{
    int K;
    cin>>K;
    if(K==1)
        one++;
    else if(K>1)
        p.push_back(K);
    else if(K<0)
        O.push_back(K);
    else
        zero++;
}
sort(p.begin(),p.end(),greater<int>());
sort(O.begin(),O.end());


if(p.size()%2==1)p.push_back(1);

if(O.size()%2==1)O.push_back(zero>0?0:1);
int awn=0;
for(int i=0;i<p.size();i+=2)
{
    awn+=p[i]*p[i+1];
}
for(int i=0;i<O.size();i+=2)
awn+=O[i]*O[i+1];

awn=awn+one;
cout<<awn;
}