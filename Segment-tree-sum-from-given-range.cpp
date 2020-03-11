#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ipair;
int updateArrayValue(vector<pair<int,ipair>> &st,vector<int> &arr,int in,int val,int index)
{
    int l1 =st[index].second.first;
    int r1 =st[index].second.second;
    if(l1==r1)
    {
        int temp=arr[in];
        arr[in]=val;
        st[index].first=val;
        return val-temp;
    }
    if(!(l1<=in&&in<=r1))
    return 0;
    int temp=st[index].first;
    st[index].first+=updateArrayValue(st,arr,in,val,2*index)+updateArrayValue(st,arr,in,val,2*index+1);
    return st[index].first-temp;
    
}
int sumLR(vector<pair<int,ipair>> st,vector<int> arr,int l,int r,int index)
{
    int l1=st[index].second.first;
    int r1=st[index].second.second;
    
    if(l<=l1&&r1<=r)
    {
        
    return st[index].first;
    }
    else if(l1>r||r1<l)
   {
       return 0;
   }
    
    else
    {
        return sumLR(st,arr,l,r,2*index)+sumLR(st,arr,l,r,2*index+1);
    }
}
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
    
    
    constructSTmain(st,arr,0,n-1,1);
    
    //cout<<sumLR(st,arr,2,4,1);
    updateArrayValue(st,arr,2,12,1);
    //Printing original array
    ///*
    for(auto i: arr)
    cout<<i<<endl;
    //*/
    //Printing Segment Tree
   ///*
    for(auto i : st)
    cout<<i.second.first<<"-"<<i.second.second<<"-> "<<i.first<<endl;
    //*/
    
}