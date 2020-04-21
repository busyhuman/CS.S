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
int dp[101][101][101], ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b, c;
	cin >> a >> b >> c;
	int alen = a.size(), blen = b.size(), clen = c.size();

	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			for (int k = 1; k <= clen; k++) {
				if (a[i-1] == b[j-1] && b[j-1] == c[k-1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
					ans = max(ans, dp[i][j][k]);
				}
				else {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
				}
			}
		}
	}
	cout << ans;
}
