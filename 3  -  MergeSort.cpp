#include<bits/stdc++.h>
using namespace std;

void merged(int arr[],int si,int mid,int ei)
{
    int* tmp = new int[ei-si+1];

    int p1=si,p2=mid+1,x=0;

    while(p1<=mid && p2<=ei)
    {
       if(arr[p1]<=arr[p2])
       {
           tmp[x++] = arr[p1++];
       }
       else
       {
           tmp[x++] = arr[p2++];
       }
    }

    while(p1 <= mid)
    {
        tmp[x++] = arr[p1++];
    }

    while(p2 <= ei)
    {
        tmp[x++] = arr[p2++];
    }

    //copying elements to main array

    for(int i=si,x=0; i<=ei;i++,x++)
    {
        arr[i] = tmp[x];
    }

    delete[] tmp;
}

void divide(int arr[],int si,int ei)
{
    //base case
    if(si >= ei) return;

    int mid = si+(ei-si)/2;

    divide(arr,si,mid);
    divide(arr,mid+1,ei);

    merged(arr,si,mid,ei);
}


int main()
{
  int n;  cin >> n;
  int arr[n]; for(int i=0; i<n; i++) cin >> arr[i];

  divide(arr,0,n-1);
  cout<<endl<<"After Sorting: "<<endl;
  for(int i=0; i<n; i++)
  {
      cout<<arr[i]<<" ";
  }

  return 0;
}

