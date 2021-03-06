#include<bits/stdc++.h>
using namespace std;
#define mx 10001
int ara[mx];
int tree[mx*3];
void initial(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=ara[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    initial(left,b,mid);
    initial(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int i,int new_value)
{
    if(i>e || i<b)
    {
        return;
    }
    if(b>=i && e<=i)
    {
       tree[node]=new_value;
       return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,new_value);
    update(right,mid+1,e,i,new_value);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ara[i];
    }
    initial(1,1,n);
}
