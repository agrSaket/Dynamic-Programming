// Longest Common Substring 

#include<bits/stdc++.h>
using namespace std;

// tabulation
int lcsTab(string &s, string &t){
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    int res = 0;
    // 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                res = max(res, dp[i][j]);
            }
            else{dp[i][j] = 0;}
        }
    }
    return res;
}

// space optimise
int lcsSp(string &s, string &t){
    int n = s.length(), m = t.length();
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);
    // 
    int res = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                curr[j] = 1+prev[j-1];
                res = max(res, curr[j]);
            }
            else{curr[j] = 0;}
        }
        prev = curr;
    }
    return res;
}

// driver code
int main(){
    string s, t;
    cout<<"Enter string s: "; cin>>s;
    cout<<"Enter string t: "; cin>>t;

    cout<<"Using tabulation: "<<lcsTab(s, t)<<"\n";

    cout<<"Using space optimisation: "<<lcsSp(s, t)<<"\n";
    return 0;
}