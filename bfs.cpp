/* 

   PAVULURI GOPIKRISHNA
   DEPT OF ECE
   K L UNIVERSITY
*/
 /*
   TIME OF COMPLEXITY OF THIS ALGORITHMS IS O(N+M)
   WHERE AS N IS NUMBER OF NODES 
   M IS NUMBER OF EDGES
*/
 
 /*
 INPUT
 8
8
0 1
0 2
0 3
1 4
1 5
2 6
2 7
3 7

OUTPUT
0 1 2 3 4 5 6 7 
*/ 
   

#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int main()
{
    int n,m,x,y;
    cin>>n;/////NUMBER OF NODES
    cin>>m;//////number of edges
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);//////UNDIRECTED GRAPH
    }
    int s=0;/////source vertex
    bool vis[n]={false};//bolean array to mark vertices
    queue<int>q;
    vis[s]=true;//marking source vertex 
    q.push(s);///inserting source vertex to the queue
    while(!q.empty())
    {
        int p=q.front();////storing the front node for further process
        cout<<p<<" ";
        q.pop();
        for(int i=0;i<v[p].size();i++)
        {
            if(!vis[v[p][i]])
            {
                q.push(v[p][i]);
                vis[v[p][i]]=true;
            }
            
        }
        
    }
  return 0;
}
