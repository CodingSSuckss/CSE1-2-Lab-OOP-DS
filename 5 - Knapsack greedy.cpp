#include<bits/stdc++.h>
#define pb push_back
using namespace std;

bool sortByProfitWeightRatio(pair<int,int>a , pair<int ,int>b){
    return (double)a.first/a.second > (double)b.first/b.second;
}

int main()
{
    vector<pair<int,int>>v;
    cout<<"Enter Profit and Weight: "<<endl;
    int p,w;
    while(cin>>p && cin >> w)
    {
        if(p==-1 && w==-1) break;
        v.pb({p,w});
    }

    sort(v.begin(),v.end(),sortByProfitWeightRatio);

    cout<<"Enetr Maximum Capacity: ";
    double c;  cin >> c;
    double ans = 0;
    for(auto x: v)
    {
       if(c >= x.second)
       {
           ans += x.first;
           c -= x.second;
       }
       else
       {
           ans += c*((double)x.first/x.second);
           break;
       }
    }
    cout<<endl<<"Maximum Profit: "<<ans<<endl<<endl;
    return 0;
}
