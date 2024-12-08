#include<bits/stdc++.h>
using namespace std;
long long result;
set<long long> s;
void solve(vector<string> &equations,int idx,long long ans) {
    if(idx == equations.size()) {
        if(result == ans) s.insert(ans);
        return;
    }
    solve(equations,idx+1,ans + stoll(equations[idx]));
    solve(equations,idx+1,ans * stoll(equations[idx]));
    // Part 2
    solve(equations,idx+1,stoll(to_string(ans)+equations[idx]));
}
int main() {
    fstream file;
    file.open("input.txt",ios::in);
    string line;
    while(getline(file,line)) {
        stringstream ss(line);
        string temp;
        bool flag = true;
        vector<string> equations; 
        while(!ss.eof()) {
            getline(ss,temp,':');
            if(flag) {
                result = stoll(temp);
                flag = false;
            } else {
                stringstream ss1(temp);
                ss1.ignore();
                string temp1;
                while(!ss1.eof()) {
                    getline(ss1,temp1,' ');
                    equations.push_back(temp1);
                }
            }
        }
        solve(equations,1,stoll(equations[0]));
    }
    cout<<accumulate(s.begin(),s.end(),0LL);
}