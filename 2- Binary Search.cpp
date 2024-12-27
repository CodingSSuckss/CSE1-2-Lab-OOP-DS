#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int x){
  int low = 0,high = n-1;

  while(low<=high)
  {
    int mid = (high+low)/2;

    if(arr[mid]== x) return mid;
    else if(arr[mid] > x)
    {
        high = mid-1;
    }
    else low = mid+1;
  }

  return -1;
}

int main()
{
  cout<<"How many numbers: ";
  int n;  cin >> n;

  cout<<"Enter Numbers: ";
  int arr[n];
  for(int i=0; i<n; i++)  cin >> arr[i];

  sort(arr,arr+n);

  cout<<"Enter TestCases: ";
  int t;  cin >> t;
  while(t--)
  {
     cout<<"Which number to find?: ";
     int x;  cin >> x;

     int indx = binarySearch(arr,n,x);

     if(indx == -1) cout<<"This value is not present in the array!"<<endl<<endl;
     else cout<<"index: "<<indx<<endl<<endl;

  }

  return 0;
}
