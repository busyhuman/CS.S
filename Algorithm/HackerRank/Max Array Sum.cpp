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
int n,ans,dp[100001];
vector<int> arr;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int su;
        cin >> su;
        dp[i] = su;
        arr.push_back(su);
    }
    for(int i=2;i<n;i++){
        if(i-3 >= 0) dp[i-2] = max(dp[i-2],dp[i-3]);
        dp[i] = max(dp[i], dp[i-2]+arr[i]);
    }
    int ans = -inf;
    for(int i=0;i<n;i++)
        ans = max(ans,dp[i]);
    cout << ans;
}
