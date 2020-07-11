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
#include <cassert>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
#define inf 2000000000
#define mod 1000000007
string s;
int n, k;
stack<char> st;
vector<char> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> k;
    cin >> s;
    
    for(int i=0;i<n;i++){
        
        while(!st.empty() && st.top() < s[i] && k){
            k--;
            st.pop();
        }
        st.push(s[i]);
    }
    
    while(k--){
        st.pop();
    }
    
    while( !st.empty() ){
        ans.push_back(st.top());
        st.pop();
    }
    
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i];
    }
}
