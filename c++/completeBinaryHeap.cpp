#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

void makeHeap(vector<int> &arr){
    for(int i = arr.size() - 1; i >= 0; i--){
        int idx = i;
        int tmp = arr[idx];
        while(idx * 2 + 1 < arr.size() - 1){
            int left = arr[idx*2+1];
            int right = arr[idx*2+2];
            if(arr[idx] >= left && arr[idx] >= right){
                break;
            }else{
                if(left >= right){
                    arr[idx] = left;
                    arr[idx*2+1] = tmp;
                    idx = idx * 2 + 1;
                }else{
                    arr[idx] = right;
                    arr[idx*2+2] = tmp;
                    idx = idx * 2 + 2;
                }
            }
        }
        //consider only left
        if(idx * 2 + 1 == arr.size() - 1){
            if(arr[idx] < arr[arr.size() - 1]){
                arr[idx] = arr[arr.size() - 1];
                arr[arr.size() - 1] = tmp;
            }
        }
    }
}

void insert(vector<int> &arr, int target){
	arr.push_back(target);//add to the last and go up
    int idx = arr.size() - 1;
    while(ceil(idx / 2) - 1 >= 0){
        int parent = arr[ceil(idx / 2) - 1];
        if(target <= parent) break;
        else{
            arr[idx] = parent;
            arr[ceil(idx / 2) - 1] = target;
            idx = ceil(idx / 2) - 1;
        }
    }
}

void remove(vector<int> &arr){
	if(arr.size() == 0) return;
    if(arr.size() == 1){
        arr.pop_back();
    }
    //put the last number to the root position -> first
    //go down for change
    else{
	    int tmp = arr[arr.size()-1];
	    arr.pop_back();
	    arr[0] = tmp;
	    int len = arr.size();
	    int idx = 0;
	    //no left and no right
	    while(idx * 2 + 1 < len - 1){
	        int left = arr[idx*2+1];
	        int right = arr[idx*2+2];
	        if(arr[idx] >= left && arr[idx] >= right){
	            break;
	        }else{
	            if(left >= right){
	                arr[idx] = left;
	                arr[idx*2+1] = tmp;
	                idx = idx * 2 + 1;
	            }else{
	                arr[idx] = right;
	                arr[idx*2+2] = tmp;
	                idx = idx * 2 + 2;
	            }
	        }
	    }
	    //consider only left
	    if(idx * 2 + 1 == len - 1){
	        if(arr[idx] < arr[len - 1]){
	            arr[idx] = arr[len - 1];
	            arr[len - 1] = tmp;
	        }
	    }
	}
}


int main(){
	vector<int> nums;
	int len;
	cout<<"input initial length: "<<endl;
	cin>>len;
	cout<<"input initial vector: "<<endl;
	for(int i = 0; i < len; i++){
		int tmp;
		cin>>tmp;
		nums.push_back(tmp);
	}

	cout<<"before heapification: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;

    makeHeap(nums);

    cout<<"after heapification: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;

    insert(nums,4);
    cout<<"after insert 4: "<<endl;
    for(int j = 0; j < nums.size(); j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;

    insert(nums,5);
    cout<<"after insert 5: "<<endl;
    for(int j = 0; j < nums.size(); j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;

    remove(nums);
    cout<<"after remove of largest element: "<<endl;
    for(int j = 0; j < nums.size(); j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;
    return 0;
}


