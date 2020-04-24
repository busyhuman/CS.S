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
#include <cassert>
#include <set>
#include <map>
using namespace std;
#define inf 2000000000
#define mod 1000000007
int n, m, h;
int arr[301][301], dp[301][302];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> h;
	memset(dp, -1, sizeof(dp));
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < h; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[x][y] = max(arr[x][y], z);
	}

	m-=1;
	dp[1][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			for (int k = 1; k <= m; k++) {
				if(arr[j][i] != -1 && dp[j][k-1] != -1)
				dp[i][k] = max(dp[i][k], dp[j][k - 1] + arr[j][i]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans = max(ans, dp[n][i]);

	cout << ans;
}
