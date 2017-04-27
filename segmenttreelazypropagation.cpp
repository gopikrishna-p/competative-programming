/*P.GOPIKRISHNA,K L University

concept:::LAZY PROPAGATION (UPDATING INTERVELS)
update ----->timecomplexity-O(logn)
query------->timecomplexity-O(logn)
build------->timecomplexity-O(logn)

*/
#include<bits/stdc++.h>
using namespace std;
int lazy[400005];
int segment[400005];

void update( int node,int start,int end,int left, int right,int value)
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
     int mid=(start+end)/2;
    update(2*node+1,start,mid,left,right,value);
    update(2*node+2,mid+1,end,left,right,value);
    segment[node]=segment[node*2+1]+segment[2*node+2];
    
}

 int query(int node,int start, int end,int left,int right)
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
     int mid=(start+end)/2;
     int h=query(node*2+1,start,mid,left,right);
     int w=query(node*2+2,mid+1,end,left,right);
    return h+w;
}
void build(int node, int start, int end)
{
    if(start == end)
    {
       
        segment[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
      
        build(2*node+1, start, mid);
       
        build(2*node+2, mid+1, end);
        segment[node] = segment[2*node+1] + segment[2*node+2];
    }
}


