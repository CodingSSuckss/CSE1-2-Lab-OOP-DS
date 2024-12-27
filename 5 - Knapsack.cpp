#include<bits/stdc++.h>
using namespace std;

int knapsack(int n,int s,int v[],int w[])
{
    //base case
    if(n==0 || s==0) return 0;

    if(w[n-1] <= s)
    {
        int op1 = knapsack(n-1,s-w[n-1],v,w)+v[n-1];
        int op2 = knapsack(n-1,s,v,w);

        return max(op1,op2);
    }
    else{
        return knapsack(n-1,s,v,w);
    }
}


int main()
{
  cout<<"Enter Array Size: ";
  int n;  cin >> n;

  cout<<endl<<endl<<"Enetr Values: ";
  int v[n];  for(int i=0; i<n; i++)  cin >> v[i];

  cout<<endl<<"Enetr Weights: ";
  int w[n]; for(int i=0; i<n; i++) cin >> w[i];

  cout<<endl<<"Knapsack Size: ";
  int s; cin >> s;


  cout<<endl<<knapsack(n,s,v,w)<<endl;


  return 0;
}
