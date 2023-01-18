#include<iostream>
#include<string>

using namespace std;
int main(){
    string a;
    cin>>a;

    int total=a.length();

    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='=')
            {
                if(a[i-1]=='z')
                {
                    total--;
                    if(a[i-2]=='d')
                        total--;
                }
                if(a[i-1]=='s'||a[i-1]=='c')
                    total--;
            }
        if(a[i]=='j')
        {
            if(a[i-1]=='n'||a[i-1]=='l')
                total--;
        }
        if(a[i]=='-')
        {
            if(a[i-1]=='c'||a[i-1]=='d')
                total--;
        }
    }
    cout<<total<<endl;
}