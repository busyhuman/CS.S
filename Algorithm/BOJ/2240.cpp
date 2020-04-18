#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <bitset>
#include <regex>
#include <set>
#include <map>
using namespace std;
#define inf 2000000000
#define mod 1000000007
int t, w, su, dp[2][1001][32];
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t >> w;
	cin >> su;
	
	if(su == 1) dp[0][1][1] = 1;
	else dp[1][1][2] = 1;
	
	for(int i=2;i<=t;i++){
		cin >> su;
		for(int j=1;j<=w+1;j++){
			if(su == 1){
				dp[0][i][j] = max(dp[0][i-1][j]+1, dp[1][i-1][j-1]+1);
				dp[1][i][j] = max(dp[1][i-1][j], dp[0][i-1][j-1]);
			}
			else{
				dp[0][i][j] = max(dp[0][i-1][j], dp[1][i-1][j-1]);
				dp[1][i][j] = max(dp[1][i-1][j]+1, dp[0][i-1][j-1]+1);
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=w+1;i++) ans = max(ans, max(dp[0][t][i],dp[1][t][i]) );
	cout << ans;
}
