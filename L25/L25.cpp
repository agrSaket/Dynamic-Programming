// Longest Common Subsequence | 

#include<bits/stdc++.h>
using namespace std;

// recursion
int lcsRec(int i, int j, string &s, string &t){
    if(i<0 || j<0){return 0;}       // base case
    // if match
    if(s[i]==t[j]){
        return 1+lcsRec(i-1, j-1, s, t);
    }
    // if not match
    return max(lcsRec(i-1, j, s, t), lcsRec(i, j-1, s, t));
}

// memoization
int lcsMem(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(i<0 || j<0){return 0;}       // base case
    if(dp[i][j]!=-1){return dp[i][j];}
    // if match
    if(s[i]==t[j]){
        return dp[i][j] = 1+lcsMem(i-1, j-1, s, t, dp);
    }
    // if not match
    return dp[i][j] = max(lcsMem(i-1, j, s, t, dp), lcsMem(i, j-1, s, t, dp));
}

// tabulation
int lcsTab(string &s, string &t){
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    // base case
    for(int j=0; j<=m; j++){dp[0][j] = 0;}
    for(int i=0; i<=n; i++){dp[i][0] = 0;}
    // 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){dp[i][j] = 1+dp[i-1][j-1];}
            else{dp[i][j] = max(dp[i][j-1], dp[i-1][j]);}
        }
    }
    return dp[n][m];
}

// space optimise
int lcsSp(string &s, string &t){
    int n = s.length(), m = t.length();
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);
    // base case
    for(int j=0; j<=m; j++){prev[j] = 0;}
    // 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){curr[j] = 1+prev[j-1];}
            else{curr[j] = max(curr[j-1], prev[j]);}
        }
        prev = curr;
    }
    return prev[m];
}

// driver code
int main(){
    string s, t;
    cout<<"Enter string s: "; cin>>s;
    cout<<"Enter string t: "; cin>>t;

    int n = s.length(), m = t.length();
    cout<<"Using recursion: "<<lcsRec(n-1, m-1, s, t)<<"\n";

    vector<vector<int>> dp(n, vector<int>(m,-1));
    cout<<"Using memoization: "<<lcsMem(n-1, m-1, s, t, dp)<<"\n";

    cout<<"Using tabulation: "<<lcsTab(s, t)<<"\n";

    cout<<"Using space optimisation: "<<lcsSp(s, t)<<"\n";
    return 0;
}