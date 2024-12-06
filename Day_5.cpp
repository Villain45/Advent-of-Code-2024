#include<bits/stdc++.h>
using namespace std;
vector<string> rules;
int ans=0;
void makeItBetter(vector<string> &order) {
    unordered_map<string,int> mp;
    for(int i=0;i<order.size();i++) {
        for(int j=0;j<order.size();j++) {
            if(i!=j) {
                string temp = order[i] + "|" + order[j];
                if(find(rules.begin(),rules.end(),temp)!=rules.end()) {
                    mp[order[i]]++;
                    mp[order[j]]--;
                }
            }
        }
    }
    for(auto x:mp) {
        if(x.second == 0) {
            ans+=stoi(x.first);
        }
    }
}
void isCorrectOrder(string temp1,string temp2,vector<string> &order,bool &checker,bool whoIsIt) {
    bool flag1 = false,flag2 = false;
    if(whoIsIt and find(rules.begin(),rules.end(),temp1)!=rules.end()) flag1 = true;
    if(!whoIsIt and find(rules.begin(),rules.end(),temp2)!=rules.end()) flag2 = true;
    if(flag1==flag2) {
        checker = false;
    }
}
int main() {
    fstream file;
    file.open("input.txt",ios::in);
    string line;
    while(getline(file,line)) {
        if(find(line.begin(),line.end(),'|') != line.end()) {
            rules.push_back(line);
        }
    }
    file.close();
    file.open("input.txt",ios::in);
    while(getline(file,line)) {
        if(find(line.begin(),line.end(),',') != line.end()) {
            stringstream ss(line);
            string temp;
            vector<string> order;
            while(!ss.eof()) {
                getline(ss,temp,',');
                order.push_back(temp);
            }
            bool checker = true;
            for(int i=0;i<order.size();i++) {
                for(int j=0;j<order.size();j++) {
                    if(i!=j) {
                        string temp1 = order[i]+"|"+order[j];
                        string temp2 = order[j]+"|"+order[i];
                        bool whoIsIt = i < j;
                        isCorrectOrder(temp1,temp2,order,checker,whoIsIt);
                    }
                }
            }
            // For Part - 1
            // if(checker) {
                // int mid = (order.size()-1)/2;
                // ans+=stoi(order[mid]);
            // }

            // For Part - 2
            if(!checker) {
                makeItBetter(order);
            }
        }
    }
    cout<<ans;
}