#include<iostream>

using namespace std;

int main()
{
    long long count=0;
    int num=1;
    long long S;
    int cur=0;
    scanf("%d",&S);
    while(1)
    {
        count+=num;
       cur++;
        if(count>S)
        {
            cur--;
            break;
    } 
        num++;
    }
    printf("%d",cur);
    return 0;
}