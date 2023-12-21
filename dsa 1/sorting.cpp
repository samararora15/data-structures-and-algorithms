//sorting techniques
//mergesort and quicksort works on divide and conquerer technique having complexity nlogn
#include<bits/stdc++.h>
using namespace std;

int partitionn(int arr[],int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            int k = arr[i];
            arr[i] = arr[j];
            arr[j] = k;
        }
    }

    int k = arr[i+1];
    arr[i+1] = pivot;
    arr[high] = k;
    return i+1;
}

void quickksort(int arr[],int low, int high)
{
    if(low<high)
    {
        int pi = partitionn(arr,low,high);

        quickksort(arr,low,pi-1);
        quickksort(arr,pi+1,high);
    }
}

void mergee(int arr[],int low, int mid, int high)
{
    int n1 = mid-low+1;
    int n2 = high-mid;

    int arr1[n1];
    int arr2[n2];

    for(int i=0;i<n1;i++)
    {
        arr1[i] = arr[low+i];
    }

    for(int j=0;j<n2;j++)
    {
        arr2[j] = arr[mid+1+j];
    }

    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeesort(int arr[],int low, int high)
{
    if(low>=high)
    {
        return;
    }
    int mid = (low+high)/2;
    mergeesort(arr,low,mid);
    mergeesort(arr,mid+1,high);
    mergee(arr,low,mid,high);
}

void insertion(int arr[], int size)
{
    for(int i=1;i<size;i++)
    {
        int key = i;

        while(key>0 && arr[key-1]>arr[key])
        {
            int k = arr[key-1];
            arr[key-1] = arr[key];
            arr[key] = k;
            key--;
        }
    }

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void selection(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                int k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void bubble(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }
        }
    }

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {2,0,0,1,2,0,1,1,2,0,1,0,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    //bubble(arr,size);
    //selection(arr,size);
    //insertion(arr,size);
    //mergeesort(arr,0,size-1);
    quickksort(arr,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}