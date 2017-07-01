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
 
/********************************MODULAR EXPONENTIATION RECURSIVE**********************************************
 * x^n
if n is even divide n=n/2 and x=x*x
if n is odd  divide x*x^n-1  where as n-1 is odd
Time complexity O(Log n);
Spacecomplexit O(Log n)
*/

#include<bits/stdc++.h>
using namespace std;
int x,k;
int modularexponention(int x,int n)
{
    
   if(n==0)
        return 1;
        
   if(n%2==0)
    return modularexponention(x*x,n/2);
   if(n%2==1)
        return x*modularexponention(x*x,(n-1)/2);
    
    
}

 

int main()
{
    cin>>x>>k;
    long int ans=modularexponention(x,k);
    cout<<ans<<endl;
    
     return 0;
}



