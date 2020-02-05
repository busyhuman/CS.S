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
bool check[1001][1001];
int bfs(int n){
	queue<int> q,c,l;
	q.push(1);
	c.push(0);
	l.push(0);
	
	while(!q.empty()){
		int qf = q.front(), cf = c.front(), lf = l.front();
		q.pop(), c.pop(), l.pop();
		if(qf == n) return lf;
		
		if(!check[qf][qf]){
			check[qf][qf] = true;
			q.push(qf);
			c.push(qf);
			l.push(lf+1);
		}
		
		if(qf+cf <= n && !check[qf+cf][cf]){
			q.push(qf+cf);
			c.push(cf);
			l.push(lf+1);
		}
		
		if(qf-1 > 0 && !check[qf-1][cf]){
			q.push(qf-1);
			c.push(cf);
			l.push(lf+1);
		}
	}
	return 0;
}

int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << bfs(n);
}
