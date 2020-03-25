#include <iostream>
#include <string>
using namespace std;

void shellSort(int arr[], int n){
    int gap;//determine increment
    int tmp;
    for(gap = n / 2; gap > 0; gap /= 2){
        for(int i = 0; i < gap; i++){
            for(int j = i + gap; j < n; j+= gap){
                if(arr[j] < arr[j - gap]){
                    tmp = arr[j];
                    int k = j - gap;
                    while(k >= 0 && arr[k] > tmp){
                        arr[k+gap] = arr[k];
                        k -= gap;
                    }
                    arr[k+gap] = tmp;
                }
            }
        }
    }
}

int main(){
	int len;
    cout<<"input array length:"<<endl;
    cin>>len;
    int nums[len];
    cout<<"please input array:"<<endl;
    for(int i = 0; i < len; i++){
        cin>>nums[i];
    }

	cout<<"before shell sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;

    shellSort(nums,len);

    cout<<"after shell sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<nums[j]<<" ";
    }
    cout<<endl;
    return 0;
}

