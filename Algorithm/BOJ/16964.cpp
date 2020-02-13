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
bool check[100001];
vector<int> arr[100001],ans;
int serial[100001], order[100001];
bool comp(int a, int b){
	return order[a] < order[b];
}

void dfs(int now){
	if(check[now]) return;
	check[now] = true;
	
	ans.push_back(now);
	
	for(int su : arr[now]){
		if(!check[su])
			dfs(su);
	}
}
int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=1;i<n;i++){
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin >> serial[i];
		order[serial[i]] = i;
	}
	for(int i=1;i<=n;i++){
		sort(arr[i].begin(), arr[i].end(), comp);
	}
	
	dfs(1);
	for(int i=1;i<=n;i++){
		if(ans[i-1] != serial[i]){
			cout << "0";
			return 0;
		}
	}
	cout << "1";
}
