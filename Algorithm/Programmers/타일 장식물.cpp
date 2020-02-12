#include <string>
#include <vector>
using namespace std;

long long solution(int N) {
    long long dp[81];
    dp[0] = 4;
    dp[1] = 6;
    for(int i=2;i<=N;i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[N-1];
}
