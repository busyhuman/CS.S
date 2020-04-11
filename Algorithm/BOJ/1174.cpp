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
#include <regex>
#include <set>
#include <map>
using namespace std;
#define inf 2000000000
#define mod 1000000007
int n,cnt;
vector<long long> arr;
void dfs(int curr, long long sum){
	if(sum > 9876543210) return;
    arr.push_back(sum);
	sum *= 10;
	for(int i=curr;i>=0;i--) dfs(i-1,sum+i);
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
 
	if(n > 1023){
		cout << "-1";
		return 0;
	}
 
	dfs(9, 0);
	sort(arr.begin(), arr.end());
	cout << arr[n];
}
