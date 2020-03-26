#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s;
int main(){ 
    long long dp[5002] = {1};
    cin >> s;
    int len = s.size();
  
    if(s[0] == '0'){
		cout << "0";
		return 0;
	}
	
	if(s[1] - '0') dp[1]++; 	// len이 1이어도 상관없다.
	
    for(int i=2;i<=len;i++){
		if(s[i-1] - '0') dp[i] = dp[i-1] % 1000000;
		int su = (s[i-1] - '0') + ((s[i-2]-'0') * 10);
		if(su >= 10 && su <= 26) dp[i] = (dp[i]+dp[i-2]) % 1000000;
    }
    cout << dp[len];
    return 0;
}
