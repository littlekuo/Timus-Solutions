#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;


int main(){
    vector<char> mp;
    std::string str;
    getline(cin, str);
    for(auto& l:str){
        if(mp.empty() || mp.back() != l) mp.push_back(l);
        else{
            while(!mp.empty() && mp.back() == l){
                mp.pop_back();
            }
        }
    }
    for(auto& c:mp){
        cout << c;
    } 
}