
/* 
P.Gopikrishna,KLUniversity
Hardwork never fails :)

Dijkstra's algorithm using priority_queue
Time complexity: Q(N+logM)
N-Number of vertices
M-Number of Edges

INPUT 
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0

OUTPUT
0 4 12 19 21 11 9 8 14 
HAPPY CODING :)
*/


#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define INF MAX
#define pii pair< int, int >
#define pb(x) push_back(x)
 
 /* below comp function is used to compare the weights that are pushed in queue
 */
 
 
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
 
vector< pii > v[MAX];
int dist[MAX];
bool vis[MAX];
int x,y,w,n,m,src; 



int main()
{
    cin>>n>>m;


for(int i=0;i<m;i++)
{
    cin>>x>>y>>w;
    v[x].pb(pii(y, w));
    v[y].pb(pii(x, w));
}

cin>>src;
memset(vis,0,sizeof(vis));
for(int i=0;i<n;i++)
{
    dist[i]=INF;
}
priority_queue< pii, vector< pii >, comp > q;
dist[src]=0;
q.push(pii(src,0));

while(!q.empty())
{
    x=q.top().first;
    q.pop();

    if(vis[x])continue;
    
    for(int i=0;i<v[x].size();i++)
    {
        y=v[x][i].first;
        w=v[x][i].second;
       
        if(!vis[x] && ((dist[x]+w) < dist[y]))
        {
            dist[y]=dist[x]+w;
           
            q.push(pii(y,dist[y]));
            
        }
    }
    vis[x]=1;
}
for(int i=0;i<n;i++)
{
    cout<<dist[i]<<" ";
}
return 0;
}
