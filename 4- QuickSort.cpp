#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low, int high){
   int pivot = arr[high];

   int i = -1;
   for(int j=0; j<high; j++)
   {
       if(arr[j]<pivot)
       {
         i++;
         int tmp = arr[i];
         arr[i] = arr[j];
         arr[j] = tmp;
       }
   }

   i++;
   int tmp = arr[i];
   arr[i] =  pivot;
   arr[high] = tmp;

   return i;
}

void quickSort(int arr[],int low,int high){
    if(low >= high) return;

    int pivot_indx = partition(arr,low,high); //its return the index of pivot after positioning it to its correct position

    quickSort(arr,low,pivot_indx-1);
    quickSort(arr,pivot_indx+1,high);

}

int main()
{
  cout<<"EnterSize: ";
  int n;  cin >> n;

  cout<<"Enter Elements: ";
  int arr[n];
  for(int i=0; i<n; i++) cin >> arr[i];

  quickSort(arr,0,n-1);

  cout<<endl<<"Sorted Array: "<<endl<<endl;;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}

