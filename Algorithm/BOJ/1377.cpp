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
int n;
vector< pair<int,int> > arr;
int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		arr.push_back( make_pair(x,i) );
	}
	sort(arr.begin(), arr.end() );
	int ans = 0;
	for(int i=1;i<=n;i++){
	//	cout << origin[arr[i-1].first] << ' ' << i<< '\n';
		ans = max(ans, arr[i-1].second-i+1);
	}
	cout << ans;
}
