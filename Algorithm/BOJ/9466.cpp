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
int t, n, arr[100001],ans;
bool visit[100001],used[100001];

void dfs(int now){
	if(visit[now]) return;
	visit[now] = true;
	
	int next = arr[now];
	
	if(!visit[next]) dfs(next);
	else if(!used[next]){
		ans++;
		for(int i=next;i!=now;i=arr[i]) ans++;
	}
	used[now] = true;
}

int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		cin >> n;
		memset(visit,false,sizeof(visit));
		memset(used,false,sizeof(used));
		ans=0;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			arr[i]--;
		}
		for(int i=0;i<n;i++){
			dfs(i);
		}
		cout << n-ans << '\n';
	}
}
