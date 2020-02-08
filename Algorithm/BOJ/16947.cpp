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
bool cycle[3001], check[3001];
vector<int> arr[3001];

bool dfs(int now, int cnt, int dest){
	for(int su : arr[now]){
		if(su == dest && cnt >= 2) return true;
		if(check[su]) continue;
		check[su]=true;
		if(dfs(su,cnt+1,dest)) return true;
		check[su]=false;
	}
	return false;
}

int bfs(int now){
	queue<int> q,l;
	q.push(now);
	l.push(0);
	check[now]=true;
	
	while( !q.empty() ){
		int qf = q.front(), lf = l.front();
		q.pop(), l.pop();
		if( cycle[qf] ) return lf;
		for(int su : arr[qf]){
			if(check[su] == false){
				check[su] = true;
				q.push(su);
				l.push(lf+1);
			}
		}
	}
	return 0;
}
int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		check[i] = true;
		cycle[i] = dfs(i, 0, i);
		memset(check,false,sizeof(check));
	}
	for(int i=1;i<=n;i++){
		if(cycle[i]) cout << "0";
		else cout << bfs(i);
		cout << ' ';
		memset(check,false,sizeof(check));
	}
}
