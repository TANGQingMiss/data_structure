//find all subsets for an array with repetitive elements
//for example [1,2,2] => [],[1],[2],[1,2],[2,2],[1,2,2]
//we shouldn't have [1,2] and [1,2] twice
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

void backtrack(vector<int> &array, vector<vector<int> > &res, int start, vector<int> tmp){
    res.push_back(tmp);
    for(int i = start; i < array.size(); i++){
        if(i - 1 >= start && array[i-1] == array[i]) continue;
        tmp.push_back(array[i]);
        backtrack(array,res,i+1,tmp);
        tmp.pop_back();
    }
}

void getSubsets(vector<int> &array, vector<vector<int> > &res){
    sort(array.begin(), array.end());
    vector<int> tmp;
    backtrack(array,res,0,tmp);
}

int main(){
    int n;
    cout<<"input positive integer number n : "<<endl;
    cin>>n;

    vector<int> array;
    cout<<"input each integer: "<<endl;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        array.push_back(tmp);
    }

    vector<vector<int> > res;
    getSubsets(array,res);
    cout<<"result subsets: "<<endl;
    for(int i = 0; i < res.size(); i++){
        if(res[i].size() == 0) cout<<"[]"<<endl;
        else{
            cout<<"[";
            for(int j = 0; j < res[i].size(); j++){
                cout<<res[i][j]<<" ";
            }
            cout<<"]"<<endl;    
        }
    }

    return 0;
}