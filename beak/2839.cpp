#include<iostream>
using namespace std;

int main()
{
    int kg,a,b;
    cin>>kg;
    a=0;
  while(kg>=0)
  {
    if(kg%5==0)
    {
        a+=(kg/5);
        cout<<a<<endl;
        return 0;
    }
    kg-=3;
    a++;

  }
  cout<<-1<<endl;
    return 0;
}