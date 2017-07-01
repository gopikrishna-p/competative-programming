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
 
/********************************MODULAR EXPONENTIATION   Iterative**********************************************
 * x^n
if n is even divide n=n/2 and x=x*x
if n is odd  divide x*x^n-1  where as n-1 is odd
Time complexity O(Log n);
Spacecomplexit O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int x,k;
int modularexponention(int x,int n)
{
    
    int result=1;
    while(n>0)
    {
        if(n%2==1)
            result=result*x;
            
      x=x*x;
      n=n/2;
        
    }
    return result;
    
    
}

 

int main()
{
    cin>>x>>k;
    long int ans=modularexponention(x,k);
    cout<<ans<<endl;
    
     return 0;
}
