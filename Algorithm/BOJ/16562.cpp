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
using namespace std;
#define inf 2000000000
#define mod 1000000007
int ans, n, m, k, cost[10001], parent[10001];

int find(int u){
	if( u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);
	parent[b] = a;
	cost[a] = min(cost[a], cost[b]);
	cost[b] = inf;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) parent[i] = i;
	for(int i=1;i<=n;i++) cin >> cost[i];
	
	for(int i=0;i<m;i++){
		int x, y;
		cin >> x >> y;
		uni(x, y);
	}
	for(int i=1;i<=n;i++)
		if(cost[i] != inf) ans += cost[i];
	if(ans <= k) cout << ans;
	else cout << "Oh no";
}
