// https://jaimemin.tistory.com/791 참고
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
int t, arr[1000001][2];
bool visit[1000001];

void bfs(int n){
	queue<int> q;
	visit[1]=true;
	q.push(1);
	arr[1][0] = -1;
	arr[1][1] = 1;
	
	while( !q.empty() ){
		int qf = q.front();
		q.pop();
		
		int t1 = (qf*10) % n, t2 = (qf*10+1) % n;
		
		if(!visit[t1]){
			arr[t1][0] = qf;
			arr[t1][1] = 0;
			
			if(!t1) return;
			
			visit[t1] = true;
			q.push(t1);
		}
		if(!visit[t2]){
			arr[t2][0] = qf;
			arr[t2][1] = 1;
			
			if(!t2) return;
			
			visit[t2] = true;
			q.push(t2);
		}
	}
}

void print(int su){
	if(su == -1) return;
	print(arr[su][0]);
	cout << arr[su][1];
}

int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n==1){
			cout << "1\n";
			continue;
		}
		memset(visit,false,sizeof(visit));
		bfs(n);
		print(0);
		cout << '\n';
	}
}
