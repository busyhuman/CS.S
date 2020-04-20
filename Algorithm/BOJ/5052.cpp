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
#include <cassert>
using namespace std;
#define inf 2000000000
#define mod 1000000007
map<string, long long> dict;
vector<string> arr;
void makeAns(string str) {
	string temp = "";
	for (char c : str) {
		temp += c;
		dict[temp]++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		dict.clear();
		arr.clear();

		bool ans = true;

		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			arr.push_back(str);
			makeAns(str);
		}

		for (string s : arr) {

			if (dict[s] >= 2) {
				ans = false;
				break;
			}
		}

		if (ans) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
}
