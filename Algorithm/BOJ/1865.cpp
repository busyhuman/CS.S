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
#define inf 2000000000
struct arr {
	int from;
	int to;
	int cost;
};
int dist[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, w;
	cin >> t;
	while (t--) {
		cin >> n >> m >> w;
		vector<arr> arr(2 * m + w);
		for (int i = 0; i < m; i++) {
			cin >> arr[i].from >> arr[i].to >> arr[i].cost;
			arr[i + m] = arr[i];
			swap(arr[i + m].from, arr[i + m].to);
		}
		for (int i = 2 * m; i<2 * m + w; i++) {
			cin >> arr[i].from >> arr[i].to >> arr[i].cost;
			arr[i].cost *= -1;
		}

		bool b=false;
		for(int k=2*m;k<2 * m + w;k++){
			fill(dist,dist+n+1,inf);
			dist[arr[k].from] = 0;
			if(b) break;
			b = false;
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j<2 * m + w; j++) {
					int x = arr[j].from;
					int y = arr[j].to;
					int z = arr[j].cost;
					if (dist[x] != inf && dist[y] > dist[x] + z) {
						dist[y] = dist[x] + z;
						if (i == n) b = true;
					}
				}
			}
		}
		if(b) cout << "YES\n";
		else cout << "NO\n";
	}
}
