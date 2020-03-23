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
int n, ans;
vector<int> arr,arr2;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		int x, y;
		cin >> x >> y;
		arr.push_back(x+y);
		arr2.push_back(x-y);
	}
	sort(arr.begin(), arr.end() );
	sort(arr2.begin(), arr2.end() );
	ans = max(arr[n-1] - arr[0], arr2[n-1] - arr2[0]);
	cout << ans;
}
