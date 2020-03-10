#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ipair;
int constructSTmain(vector<pair<int,ipair>> &st,vector<int> arr,int l,int r,int index)
{
    st[index].second.first=l;
    st[index].second.second=r;
    if(l==r)
    {
        st[index].first=arr[l];
        return arr[l];
    }
    
    int mid=(l+r)/2;
    return st[index].first=constructSTmain(st,arr,l,mid,2*index)+constructSTmain(st,arr,mid+1,r,2*index+1);
}
int constructST(int n)
{
    
     n=n<<1;
    while((n&(n-1))!=0)
    n=n&(n-1);
    return n;
    
}
int main() {
    
    int n;
    cin>>n;
    vector<int> arr(n);
    
    
    for(int i=0;i<n;i++)
    {
     cin>>arr[i];  
    }
     int size=constructST(n);
     vector<pair<int,ipair>> st(2*size-1+1);
    //Printing original array
    /*for(auto i: arr)
    cout<<i<<endl;
    */
    
    constructSTmain(st,arr,0,n-1,1);
    //Printing Segment Tree
   /* 
   for(auto i : st)
    cout<<i.second.first<<"-"<<i.second.second<<"-> "<<i.first<<endl;
    */
    
}