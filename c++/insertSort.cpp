#include <iostream>
#include <string>
#include <vector>
using namespace std;


void insertSort(vector<int> &arr,int n){
    vector<int> res;
	for(int i = 0; i < n; i++){
        if(res.size() == 0){
            res.push_back(arr[i]);
        }else{
            for(int j = res.size() - 1; j >= 0; j--){
                if(arr[i] >= res[j]){
                    res.insert(res.begin()+j+1,arr[i]);
                    break;
                }else if(j == 0){
                    res.insert(res.begin(),arr[i]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        arr[i] = res[i];
    }
    res.clear();
}

int main(){
	vector<int> nums;
	int len;
	cout<<"input length: "<<endl;
	cin>>len;
	cout<<"input unordered array: "<<endl;
	for(int i = 0; i < len; i++){
		int tmp;
		cin>>tmp;
		nums.push_back(tmp);
	}

	cout<<"before insert sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;

    insertSort(nums,len);

    cout<<"after insert sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;
    return 0;
}

