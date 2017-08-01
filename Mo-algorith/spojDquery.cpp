
MO'S ALGORITHM /QUERY SQUARE ROOT DECOMPOSITION

SPOJ LINK:http://www.spoj.com/problems/DQUERY/

Time complexity :O(N*SQRT(N))


/*
**********************************
 * P.Gopikrishna                  *
 * K L University:)               *
 * Never Give up                  *
 * Hard work never fails:)        *
 *                                *
 *                                *                                                    
 * ********************************
 */
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 30010
#define A 1000010
#define block 180
#define M 200010

int freq=0;
struct node
{
    int l,r,i;
}q[M];
int ans[M];
int a[N];
int coun[A];

bool comp(node x,node y)
{
    if(x.l/block != y.l/block)
        return (x.l)/block < (y.l)/block;
        
    return x.r < y.r;
}

int main() {
   ios_base::sync_with_stdio(false);
   int n,m;
   scanf("%d",&n);
   
 
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   scanf("%d",&m);
 
   for(int i=0;i<m;i++)
   {
       scanf("%d %d",&q[i].l,&q[i].r);
       q[i].l--;
       q[i].r--;
       q[i].i=i;
       
   }
   sort(q,q+m,comp);
   int currentl=0,currentr=0;
   
   for(int i=0;i<m;i++)
   {
       int left=q[i].l;
       int right=q[i].r;
       while(currentl<left)
       {
           coun[a[currentl]]--;
           if(coun[a[currentl]]==0)
           {
               freq--;
           }
           currentl++;
           
       }
       
       while(currentl>left)
       {
            coun[a[currentl-1]]++;
           if(coun[a[currentl-1]]==1)
           {
               freq++;
           }
           currentl--;
           
       }
       while(currentr<=right)
       {
           coun[a[currentr]]++;
           if(coun[a[currentr]]==1)
           {
               freq++;
           }
           currentr++;
           
       }
       while(currentr>right+1)
       {
            coun[a[currentr-1]]--;
           if(coun[a[currentr-1]]==0)
           {
               freq--;
           }
           currentr--;
           
       }
       ans[q[i].i]=freq;
       
   }
   for(int i=0;i<m;i++)
   {
       printf("%d\n",ans[i]);
   }
   
   
    return 0;
}
