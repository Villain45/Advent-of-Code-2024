#include<bits/stdc++.h>
using namespace std;
bool canbeGood(vector<int> v) {
	bool isIncreasing = v[0] < v[1];
	bool isAns = true;
	for(int i=0;i<v.size()-1;i++) {
		if(isIncreasing) {
			if(v[i]>v[i+1]) {
				isAns = false;
				break;
			}
			if(v[i+1]-v[i]>3 or v[i+1]-v[i]<1) {
				isAns = false;
				break;
			}
		} else {
			if(v[i]<v[i+1]) {
				isAns = false;
				break;
			}
			if(v[i]-v[i+1]>3 or v[i]-v[i+1]<1) {
				isAns = false;
				break;
			}
		}
	}
	return isAns;
}
bool isGood(vector<int> v){
	if(canbeGood(v))
		return true;
	for(int i=0;i<v.size();i++) {
		vector<int> temp = v;
		temp.erase(temp.begin()+i);
		if(canbeGood(temp))
			return true;
	}
	return false;
}
int main() {
	fstream file;
	file.open("input.txt",ios::in);
	string line;
	int count=0;
	while(getline(file,line)) {
		stringstream ss(line);
		string temp;
		vector<int> v;
		while(!ss.eof()) {
			getline(ss,temp,' ');
			v.push_back(stoi(temp));
		}
		if(isGood(v)) {
			count++;
		}
	}
	cout<<count;
}