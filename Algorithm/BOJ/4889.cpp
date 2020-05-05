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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int tc = 0;

	while (cin >> s && ++tc) {
		if (s[0] == '-') break;
		stack<bool> st;
		int ans = 0;

		for (char c : s) {
			if (c == '}') {
				if (st.empty()) {
					ans++;
					st.push(0);
				}
				else
					st.pop();
			}
			else 
				st.push(0);
		}

		cout << tc << ". " << ans + st.size() / 2 << '\n';
	}
}
