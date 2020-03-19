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
using namespace std;
#define inf 2000000000
#define mod 1000000007
int arr[100001],dp[100001];
int find(int u){
	if(u == dp[u]) return u;
	else return dp[u] = find(dp[u]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);
	dp[a] = b;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int g,p;
	cin >> g >> p;
	for(int i=1;i<=g;i++) dp[i]=i;
	for(int i=0;i<p;i++) cin >> arr[i];
	int ans = 0;
	for(int i=0;i<p;i++){
		int su = find(arr[i]);
		if(dp[arr[i]] == 0) break;
		uni(su,su-1);
		ans++;
	}
	cout << ans;
}
