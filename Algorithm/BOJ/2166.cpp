// https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-2166-%EB%8B%A4%EA%B0%81%ED%98%95%EC%9D%98-%EB%A9%B4%EC%A0%81 참고함
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
long long ans;
vector< pair<long long, long long> > arr;

long long ccw(pair<long long, long long>& a, pair<long long, long long>& b, pair<long long, long long>& c ){
	return ((b.first - a.first) * (c.second - a.second)) - ((b.second-a.second)*(c.first-a.first));
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		int x, y;
		cin >> x >> y;
		arr.push_back( make_pair(x,y) );
	}
	for(int i=1;i<n-1;i++){
		ans += ccw(arr[0], arr[i], arr[i+1]);
	}
	printf("%.1lf", abs(ans / 2.0));
}
