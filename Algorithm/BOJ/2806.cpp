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
int dp[2][1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string str;
	cin >> str;

	for (int i = 1; i <= n; i++) {
		dp[str[i-1] - 'A'][i] = dp[str[i-1] - 'A'][i - 1];

		if (str[i-1] == 'A') dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + 1;
		else dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + 1;
	}
	cout << dp[0][n] << '\n';
}
