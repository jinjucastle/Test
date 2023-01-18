#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
    int N,sum;
    cin>>N;
    vector<int>A(N);

    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    sort(A.begin(),A.end());
     if (A[0] != 1)

          cout << 1 << "\n";
    else{
    sum=1;
    for(int i=1;i<N;i++)
    {
        if(sum+1<A[i])
            break;

        sum+=A[i];
    }
    cout<<sum+1<<endl;
}
}