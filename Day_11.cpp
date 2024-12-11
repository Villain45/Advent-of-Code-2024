#include<bits/stdc++.h>
using namespace std;
vector<unordered_map<long long,long long>> dp(76);
pair<long long,long long> divide(long long num) {
    long long mid = (log10(num) + 1)/2;
    string s = to_string(num);
    return {stoll(s.substr(0,mid)),stoll(s.substr(mid))};
}
long long blinkItDP(long long stone,int rep,vector<unordered_map<long long,long long>> &dp) {
    if(rep == 0) {
        return 1;
    }
    if(dp[rep][stone]!=0)
        return dp[rep][stone];
    if(stone == 0) {
        return dp[rep][stone] = blinkItDP(1,rep-1,dp);
    } else if(!(to_string(stone).length()%2)) {
        auto nums = divide(stone);
        return dp[rep][stone] = blinkItDP(nums.first,rep-1,dp) + blinkItDP(nums.second,rep-1,dp);
    } else {
        return dp[rep][stone] = blinkItDP(stone*2024,rep-1,dp);
    }
}
int main() {
    fstream file;
    file.open("input.txt",ios::in);
    string line;
    vector<long long> stones;
    while(getline(file,line)) {
        stringstream ss(line);
        string temp;
        while(!ss.eof()) {
            getline(ss,temp,' ');
            stones.push_back(stoll(temp));
        }
    }
    for(int i=0;i<stones.size();i++) {
        blinkItDP(stones[i],75,dp);
    }
    long long ans = 0;
    for(auto x:stones) {
        ans += dp[75][x];
    }
    cout<<ans;
}