// http://melonicedlatte.com/algorithm/2018/02/04/145104.html 참고함
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
int n, post[100001],in[100001],inidx[100001];

void dfs(int is, int ie, int ps, int pe){
	if(is > ie || ps > pe) return;
	cout << post[pe] << ' ';
	int mid = inidx[post[pe]];
	dfs(is, mid-1, ps, ps+mid-is-1);
	dfs(mid+1,ie, ps+mid-is, pe-1);
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> in[i];
		inidx[in[i]] = i;
	}
	for(int i=1;i<=n;i++) cin >> post[i];
	dfs(1,n,1,n);
}
