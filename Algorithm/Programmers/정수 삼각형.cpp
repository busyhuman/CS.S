#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0, height = 0;
    dp[0][0] = triangle[0][0];
    
    int len = triangle.size();
    for(int i=1;i<len;i++){
        height++;
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        dp[i][height] = dp[i-1][height-1] + triangle[i][height];
        
        for(int j=1;j<height;j++)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
    }
    for(int i=0;i<len;i++)
        answer = max(answer, dp[len-1][i]);
    
    return answer;
}
