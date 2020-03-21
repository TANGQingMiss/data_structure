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

void heapSort(vector<int> &arr, vector<int> &res){
	while(arr.size() > 0){
		int tmp = arr[0];
		res.push_back(tmp);
		remove(arr);
	}
}

int main(){
	vector<int> nums;
	vector<int> res;
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


    heapSort(nums,res);

    cout<<"after heap sort: "<<endl;
    for(int j = res.size() - 1; j >= 0; j--){
    	cout<<res[j]<<" ";
    }
    cout<<endl;

    return 0;
}

