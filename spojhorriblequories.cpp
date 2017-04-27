/*P.GOPIKRISHNA,K L University
-----------------------------
SPOJ HORRIBLE QUORIES SOLUTION
------------------------------

http://www.spoj.com/problems/HORRIBLE/
concept used :::LAZY PROPAGATION (UPDATING INTERVELS)
update ----->timecomplexity-O(logn)
query------->timecomplexity-O(logn)

*/
#include<bits/stdc++.h>
using namespace std;
long long int lazy[400005];
long long int segment[400005];

void update(long long int node,long long int start,long long int end,long long int left,long long int right,long long int value)
{
    if(lazy[node]!=0)
    {
        segment[node]+=(((end-start)+1)*lazy[node]);
        if(start!=end)
        {
            lazy[node*2+1]+=lazy[node];
            lazy[node*2+2]+=lazy[node];
            
        }
        lazy[node]=0;
        
    }
    if(start>end or start>right or end<left)
    return;
    if(left<=start and right>=end)
    {
        segment[node]+=((end-start)+1)*value;
        if(start!=end)
        {
            lazy[2*node+1]+=value;
            lazy[2*node+2]+=value;
        }
        return;
        
    }
    long long int mid=(start+end)/2;
    update(2*node+1,start,mid,left,right,value);
    update(2*node+2,mid+1,end,left,right,value);
    segment[node]=segment[node*2+1]+segment[2*node+2];
    
}

long long int query(long long int node,long long int start,long long int end,long long int left,long long int right)
{
    if(start>end or start>right or end<left)
    return 0;
    if(lazy[node]!=0)
    {
        
        segment[node]+=((end-start)+1)*lazy[node];
        if(start!=end)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    
    if(start>=left and right>=end)
    {
        return segment[node];
    }
    long long int mid=(start+end)/2;
    long long int h=query(node*2+1,start,mid,left,right);
    long long int w=query(node*2+2,mid+1,end,left,right);
    return h+w;
}


int main()
{
    long long int t;
    cin>>t;
    long long int n,c,op,p,q,v;
    while(t--)
    {
        cin>>n>>c;
        
        memset(segment,0,sizeof(segment));
        memset(lazy,0,sizeof(lazy));
        while(c--)
        {
        cin>>op;
        if(op==0)
        {
            cin>>p>>q>>v;
            //cout<<p<<q<<v<<endl;
            //cout<<"hai";
            update(0,0,n-1,p-1,q-1,v);
        }
        if(op==1)
        {
            cin>>p>>q;
            //cout<<p<<q<<endl;
            cout<<query(0,0,n-1,p-1,q-1)<<endl;   
        //cout<<"hello";
        
        }
        }
        //cout<<endl;
    }
    return 0;
    }
