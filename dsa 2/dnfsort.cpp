//dnf sort
#include<bits/stdc++.h>
using namespace std;
void dnfsort(int arr[],int size)
{
  int low=0,mid=0,high=size-1,k;
  while(mid<=high)
  {
    if(arr[mid]==0)
    {
      k = arr[mid];
      arr[mid] = arr[low];
      arr[low] = k;
      mid++; low++;
    }
    else if(arr[mid]==1)
    {
      mid++;
    }
    else if(arr[mid]==2)
    {
      k = arr[mid];
      arr[mid] = arr[high];
      arr[high] = k;
      high--;
    }
  }
}
int main()
{
  int arr[] = {1,2,1,0,0,2,0,1,0,2};
  int size = sizeof(arr)/sizeof(arr[0]);
  dnfsort(arr,size);
  for(int i=0;i<size;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}