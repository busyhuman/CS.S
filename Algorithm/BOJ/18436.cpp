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
int n, arr[100001], m;
vector<int> tree;

void init(int node, int left, int right) {
	if (left == right) {
		tree[node] = arr[left] % 2;
		return;
	}
	int mid = (left + right) >> 1;
	init(node * 2, left, mid);
	init(node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(int node, int start, int end, int pos, int k) {
	if (start > pos || end < pos) return;
	if (start == end) {
		tree[node] = (k%2);
		return;
	}
	int mid = (start + end) >> 1;
	update(node * 2, start, mid, pos, k);
	update(node * 2 + 1, mid + 1, end, pos, k);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	tree.resize(400004);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	cin >> m;
	while (m--) {
		int a, b, k;
		cin >> a >> b >> k;
		if (a == 1)
			update(1, 1, n, b, k);
		else if (a == 2)
			cout << k-b-query(1, 1, n, b, k) + 1<< '\n';
		else if(a == 3)
			cout << query(1, 1, n, b, k) << '\n';
	}
}
