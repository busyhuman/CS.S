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
int n, arr[100001],dp[2][100001];
int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	int ans = dp[0][0] = dp[1][0] = arr[0];
	for(int i=1;i<n;i++){
		dp[0][i] = max(dp[0][i-1]+arr[i],arr[i]);
		dp[1][i] = max(dp[0][i-1],dp[1][i-1]+arr[i]);
		ans = max(ans,max(dp[0][i], dp[1][i]));
	}
	cout << ans;
}
