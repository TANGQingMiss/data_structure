//find all possible combinations whose sum == target
//example[1,1,2,4,5], target = 7 => [1,2,4],[2,5],but we can't have two [1,2,4]
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void backtrack(vector<int> &array, vector<vector<int> > &res, int start, vector<int> tmp, int target){
    if(target == 0){
        res.push_back(tmp);
        return;
    }
    if(target < 0) return;
    for(int i = start; i < array.size(); i++){
        if(i > start && array[i] == array[i-1]) continue;
        tmp.push_back(array[i]);
        backtrack(array,res,i+1,tmp,target-array[i]);
        tmp.pop_back();
    }
}

void getSubsets(vector<int> &array, vector<vector<int> > &res, int target){
    sort(array.begin(), array.end());
    vector<int> tmp;
    backtrack(array,res,0,tmp, target);
}

int main(){
    int n;
    cout<<"input positive integer number n : "<<endl;
    cin>>n;

    int target;
    cout<<"input target value: "<<endl;
    cin>>target;

    vector<int> array;
    cout<<"input each integer: "<<endl;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        array.push_back(tmp);
    }

    vector<vector<int> > res;
    getSubsets(array,res,target);
    cout<<"result subsets: "<<endl;
    for(int i = 0; i < res.size(); i++){
        cout<<"[";
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"]"<<endl;    
    }
    return 0;
}