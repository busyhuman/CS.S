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
int n;
vector<int> pos, neg;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		int su;
		cin >> su;
		if(su >= 0) pos.push_back(su);
		else neg.push_back(-su);
	}

	int posLen = pos.size(), negLen = neg.size(), ans=inf, ans2, ans3;
	
	if(posLen >= 2){
		ans = min(pos[0]+pos[1],ans);
		ans2 = pos[0];
		ans3 = pos[1];
	}
	if(negLen >= 2){
		ans = min(neg[negLen-1]+neg[negLen-2],ans);
		ans2 = -neg[negLen-2];
		ans3 = -neg[negLen-1];
	}

	if(posLen){
		for(int i=0;i<negLen;i++){
			int num = neg[i], left = 0, right = posLen-1;

			while(left <= right) {
				int mid = (left+right)/2;
				int sum = pos[mid]-num;
		//		cout << left << ' ' << mid << ' ' << right << ' ' << sum << '\n';
				if(ans > abs(sum)){
					ans = abs(sum);
					ans2 = -num;
					ans3 = pos[mid];
				}
				if(sum < 0) left = mid+1;
				else right = mid-1;
			}
		}
	}
	cout << ans2 << ' ' << ans3;
}
