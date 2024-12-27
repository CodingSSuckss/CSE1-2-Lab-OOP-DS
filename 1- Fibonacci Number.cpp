#include<bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;

ll fib(ll n){
    //base case
    if(n==0 || n==1) return 1;

    return fib(n-1)+fib(n-2);
}

int main()
{
  cout<<"Enetr a number: ";
  int n;  cin >> n;

  cout<<n<<"'th number of fibonacci series is: "<<fib(n-1)<<endl;
  return 0;
}
