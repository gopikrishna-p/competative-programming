
/*
P.GOPIKRISHNA, KLUNIVERSITY
Problem link
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=499

Detecting cycles in a graph BELLMAN FORD ALGORITHM :)
TIME COMPLEXITY :O(N*M)

*/

#include<bits/stdc++.h>
using namespace std;
        int main()
        {
            // std::cin.sync_with_stdio(false);
            int t,n,m;
            cin>>t;
            while(t--)
            {
                cin>>n>>m;
                vector<int>v[1000];
                int distance[n];
                memset(distance,INT_MAX,sizeof(distance));
                int x,y,w;
                for(int i=0;i<m;i++)
                {
                    cin>>x>>y>>w;
                    v[i].push_back(x);
                    v[i].push_back(y);
                    v[i].push_back(w);
                }
                distance[0]=0;
                for(int i=0;i<n-1;i++)
                {
                    int j=0;
                    while(v[j].size()!=0)
                    {
                        
                        if(distance[v[j][0]]+v[j][2]<distance[v[j][1]])
                        {
                            distance[v[j][1]]=distance[v[j][0]]+v[j][2];
                        }
                        j++;
                    }
                    //j++;
                    
                }
                bool flag=0;
                for(int i=0;i<m;i++)
                {
                     if(distance[v[i][0]]+v[i][2]<distance[v[i][1]])
                     {
                         flag=1;   ////////////////////CYCLES FOUND
                     }
                }
                
                if(flag==0)
                {
                    cout<<"not possible"<<endl;//NO cycles
                }
                else
                {
                    cout<<"possible"<<endl;//cycle found
                }
                
                
                
                
            }
        return 0;
        
        } 
