#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
const int wait = 1000;
int main()
{
    int num = 0;
    int n;
    cin >> n;
    vector<int>d(wait);
    for (int i = 0; i < n ;i++)
    {
        cin >>d[i];
    }

   sort(d.begin(), d.begin()+n);
   
   vector<int>a(n);
   for (int i = 0; i < n; i++)
   {
       if (i == 0)
           a[i] = d[i];
       else
           a[i] = a[i - 1] + d[i];
       
       num += a[i];
   }
      
   
   cout << num;
}