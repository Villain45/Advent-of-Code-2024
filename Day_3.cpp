#include<bits/stdc++.h>
using namespace std;
string a,b;
bool isValid(string &s,int i,int j) {
    bool flag = true,canbeAns = false;
    a="";b="";
    while(j<s.size()) {
        if(isdigit(s[j])) {
            if(flag) {
                a+=s[j];
            } else {
                b+=s[j];
            }
        } else if (s[j]==',') {
            canbeAns = true;
            flag=false;
        } else if (s[j]==')') {
            if(canbeAns) {
                return true;
            }
            return false;
        } else {
            return false;
        }
        j++;
    }
    return false;
}
int main() {
    fstream file;
    file.open("input.txt",ios::in);
    string s, whole_string;
    stringstream temp;
    temp << file.rdbuf();
    whole_string = temp.str();
    int count=0,i=0;
    long long ans = 0;
    bool canDo = true;
    while(i < whole_string.size()-3) {
        if(whole_string.substr(i,4)=="do()") {
            canDo = true;
        }
        if(whole_string.substr(i,7)=="don't()") {
            canDo = false;
        }
        if(whole_string.substr(i,4)=="mul(") {
            if(canDo && isValid(whole_string,i,i+4)) {
                long long temp=1;
                temp*=stoll(a);
                temp*=stoll(b);
                ans+=temp;
            }
        }
        i++;
    }
    cout<<ans;
}