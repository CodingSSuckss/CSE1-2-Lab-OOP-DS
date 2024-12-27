#include<bits/stdc++.h>
using namespace std;

int lcs(string a,int n,string b,int m)
{
    //base case
    if(n==0 || m==0) return 0;

    if(a[n-1] == b[m-1])
    {
        return lcs(a,n-1,b,m-1)+1;
    }
    else
    {
        int ans1 = lcs(a,n,b,m-1);
        int ans2 = lcs(a,n-1,b,m);

        return max(ans1,ans2);
    }
}

int main()
{
    string a,b; cin >> a >> b;

    cout<<lcs(a,a.size(),b,b.size())<<endl;

    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;

  return 0;
}

