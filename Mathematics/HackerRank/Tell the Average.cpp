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
int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long ans;
    cin >> ans;
    for(int i=1;i<n;i++){
        long long su;
        cin >> su;
        ans = ans+su+ans*su;
        ans %= mod;
    }
    cout << ans % mod;
}
