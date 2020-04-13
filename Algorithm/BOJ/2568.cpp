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
int n, cnt;
bool ans[500001];
vector<int> dp;
vector< pair<int,int> > arr, path;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		int x, y;
		cin >> x >> y;
		arr.push_back( {x,y} );
	}
	sort(arr.begin(), arr.end() );
	dp.push_back(arr[0].second);
	path.push_back( {0,arr[0].first} );
	
	for(int i=1;i<n;i++){
		int temp = arr[i].second;
		if(dp[cnt] < temp){
			dp.push_back(temp);
			path.push_back( {++cnt,arr[i].first} );
		}
		else{
			int pos = lower_bound(dp.begin(), dp.end(), temp) - dp.begin();
			*lower_bound(dp.begin(), dp.end(), temp) = temp;
			path.push_back( {pos,arr[i].first} );
		}
	}

	cout << n-dp.size() << '\n';
	
	for(int i=path.size()-1;i>=0;i--){
		int pathf = path[i].first, paths = path[i].second;

		if(pathf == cnt){
	//		cout << pathf << ' ' << paths << '\n';
			ans[paths] = true;
			if( --cnt == -1) break;
		}
	}
	
	for(int i=0;i<n;i++)
		if(ans[arr[i].first] == false)
			cout << arr[i].first << '\n';
}
