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
#define inf 20000000000
#define mod 1000000007
vector<long long> arr;
int n,ans[3];
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		int su;
		cin >> su;
		arr.push_back(su);
	}
	sort(arr.begin(), arr.end() );
	long long answer = inf;
	
	for(int i=0;i<n-2;i++){
		int l = i+1, r = n-1;
		
		while(l < r){
			long long sum = arr[r] + arr[l] + arr[i];
	//		cout << i << ' ' << l << ' ' << r << ' ' << sum << '\n';
			if(answer > abs(sum)){
				answer = abs(sum);
				ans[0] = arr[i];
				ans[1] = arr[l];
				ans[2] = arr[r];
			}
			
			if(sum < 0) l++;
			else r--;
		}

	}
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}
