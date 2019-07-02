/*
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
Time Complexity : O(N*M)
Space Complexit : O(N*M);

Top Down approach
Intution:
Base case 1.Both strings are zero answer is 0 ==> dp[0][0]
Base case 2.s1 length is 0 answer is sum of s2 ascii's 
Base case 3.s2 length is 0 answee is sum of s1 ascii's 
recurrancerelation
    1.if s1[i-1] == s2[j-1] dp[i][j] = dp[i-1][j-1];
    2.s1[i-1] != s2[j-1] dp[i][j] = min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1])
ans is dp[n][m] n and m are length of s1 and length s2
 */
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int dp[n+2][m+2] = {0};
        dp[0][0] = 0;
        //s1 length is 0
        for(int i=1;i<=m;i++){
            dp[0][i] = dp[0][i-1]+s2[i-1];
        }
        //s2 length is 0
        for(int i=1;i<=n;i++){
            dp[i][0] = dp[i-1][0]+s1[i-1];
        }
        for(int i = 1 ;i <= n ;i++){
            for(int j =1;j <= m ;j++){
                //s1 and s2 are equal
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    //Checking for min case
                dp[i][j] = min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
                }
            }
        }
        return dp[n][m];
    }
};