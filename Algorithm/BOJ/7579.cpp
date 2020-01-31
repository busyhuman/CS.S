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
#include <set>
#include <map>
#include <regex>
using namespace std;
#define inf 2000000000
#define mod 1000000007
int n, m, memory[101],cost[101],dp[101][10001];
int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> memory[i];
	for(int i=0;i<n;i++) cin >> cost[i];
	
	for(int i=1;i<=n;i++){
		int curCost = cost[i-1], curMemory = memory[i-1];
		for(int j=0;j<curCost;j++) dp[i][j] = dp[i-1][j];
		for(int j=curCost;j<=10000;j++) dp[i][j] = max(dp[i-1][j], dp[i-1][j-curCost] + curMemory);
	}
    
	for(int i=0;i<=10000;i++){
		if(dp[n][i] >= m){
			cout << i;
			return 0;
		}
	}
}
