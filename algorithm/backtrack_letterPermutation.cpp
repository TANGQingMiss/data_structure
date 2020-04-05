//make letter permutation in upper and lower case by dfs(backtracking)
//for example: input string s = 'a1B2'
//we need to output ['a1B2','a1b2','A1b2','A1B2']
//for each alphabet, we need to consider two case: upper or lower
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

void dfs(string s, vector<string> &res, int i){
    if(i >= s.size()){
        res.push_back(s);
        return;
    }
    if(s[i] >= 'A' && s[i] <= 'Z'){
        s[i] += 32;
        dfs(s,res,i+1);
        s[i] -= 32;
        dfs(s,res,i+1);
    }else if(s[i] >= 'a' && s[i] <= 'z'){
        s[i] -= 32;
        dfs(s,res,i+1);
        s[i] += 32;
        dfs(s,res,i+1);
    }else dfs(s,res,i+1);
}

void letterCasePermutation(string s, vector<string> &res){
    dfs(s,res,0);
}

int main(){
    string s;
    cout<<"input original string: "<<endl;
    cin>>s;

    vector<string> res;
    letterCasePermutation(s,res);
    cout<<"result permutation is: "<<endl;
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}