#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <deque>
#include <bitset>
#include <set>
#include <map>
using namespace std;
#define inf 100000000
struct arr {
	int from;
	int to;
	int cost;
};
long long dist[501];

int main() {
	int n, m;
	cin >> n >> m;
	vector<arr> arr(m);
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &arr[i].from, &arr[i].to, &arr[i].cost);
	for (int i = 1; i <= n; i++)
		dist[i] = inf;
	bool b = false;
	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int x = arr[j].from;
			int y = arr[j].to;
			int z = arr[j].cost;

			if (dist[x] != inf && dist[y] > dist[x] + z) {
				dist[y] = dist[x] + z;
				if (i == n)
					b = true;
			}
		}
	}
	if (b) cout << "-1\n";
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == inf) dist[i] = -1;
			cout << dist[i] << '\n';
		}
	}
}
