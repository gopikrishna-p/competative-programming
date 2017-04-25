

///the time complexity  of this algorithm is O(n+m)
///prints  staring index of string a in string s
//INPUT
abdabcabc
abc
output
3
6


void preprocess()
{
    temp[0]=0;
    int k=0,i=1;
    while(i<m)
    {
        if(a[i]==a[k])
        {
            k++;
            temp[i]=k;
            i++;
            
        }
        else 
        {
            if(k==0)
            {
                temp[i]=0;
                i++;
            }
            else
            {
                k=temp[k-1];
            }
            
        }
    }
    
}
void kmpsearch()
{
    int i=0;
    int j=0;
    while(i<n)
    {
        if(s[i]==a[j])
        {
            i++;
            j++;
            //cout<<"hai";
        }
        if(j==(m))
        {
            cout<<(i-j)<<endl;
            //cout<<i<<endl;
            j=temp[j-1];
        }
        
        else if((i<n) and (s[i]!=a[j]))
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=temp[j-1];
            }
        }
        
    }
    
}
