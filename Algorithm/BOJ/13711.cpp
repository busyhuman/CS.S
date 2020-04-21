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
int idx[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, su;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> su;
		idx[su] = i;
	}

	cin >> su;
	vector<int> dp;
	dp.push_back(idx[su]);
	int len = 0;
	for (int i = 1; i < n; i++) {
		cin >> su;
		if (dp[len] < idx[su]) {
			dp.push_back(idx[su]);
			len++;
		}
		else {
			*lower_bound(dp.begin(), dp.end(), idx[su]) = idx[su];
		}
	}
	cout << len+1;
}
