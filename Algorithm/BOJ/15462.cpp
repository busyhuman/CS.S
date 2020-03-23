// 정답 참고했음.
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
int n,ans,arr[100001],check[100001];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	
	// 소가 가려는 방향을 저장하고 소가 가려는 곳의 숫자를 1증가 시킨다.
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		check[arr[i]]++;
	}
	
	ans=n;
	
	// check배열에서 0인곳은 어느 소도 방문하지 않았기에 사이클이 생기지 않는다.
	for(int i=1;i<=n;i++){
		if(!check[i]){
			q.push(i);
			ans--;
		}
	}
	
	// 사이클이 아닌 곳에서 출발한 소가 만나는 곳들은 전부 사이클이 아니다.
	while( !q.empty() ){
		int qf = q.front();
		q.pop();
		if( --check[arr[qf]] == 0){
			q.push(arr[qf]);
			ans--;
		}
	}
	cout << ans;
}
