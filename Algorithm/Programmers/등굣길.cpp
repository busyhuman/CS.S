#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0,len = puddles.size();
    for(int i=0;i<len;i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    dp[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1) continue;
            if(dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] = dp[i][j] % 1000000007;
        }
    }
    
    return dp[n][m];
}
