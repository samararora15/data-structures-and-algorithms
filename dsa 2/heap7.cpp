//k closest points to origin
#include<bits/stdc++.h>
using namespace std;
void funcheap(pair<int,int> arr[],int size,int k)
{
    priority_queue<pair<int,pair<int,int>>> maxh;

    for(int i=0;i<size;i++)
    {
        pair<int,int> temp = arr[i];
        int x = temp.first;
        int y = temp.second;

        //distance from origin
        int distance = sqrt(pow(x,2)+pow(y,2));
        maxh.push(make_pair(distance,temp));

        if(maxh.size()>k)
        {
            maxh.pop();
        }
    }

    while(!maxh.empty())
    {
        pair<int,int> temp = maxh.top().second;
        cout<<temp.first<<" "<<temp.second<<endl;
        maxh.pop();
    }
}
int main()
{   
    pair<int,int> arr[4] = {make_pair(1,3),make_pair(-2,2),make_pair(5,8),make_pair(0,1)}; 
    int k;
    cout<<"enter constraint k:";
    cin>>k;
    funcheap(arr,4,k);
    return 0;
}