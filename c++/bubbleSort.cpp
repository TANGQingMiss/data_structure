#include <iostream>
#include <string>
using namespace std;

void bubbleSort_v1(int arr[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

void bubbleSort_v2(int arr[], int n){
	bool sorted;
	for(int i = 0; i < n; i++){
		sorted = true;
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				sorted = false;
			}
		}
		if(sorted) break;
	}
}

int main(){
	int len;
	cout<<"input array length:"<<endl;
	cin>>len;
    int a[len];
    cout<<"please input array:"<<endl;
    for(int i = 0; i < len; i++){
    	cin>>a[i];
    }
    bubbleSort_v2(a,len);
    cout<<"after bubble sort: "<<endl;
    for(int j = 0; j < len; j++){
    	cout<<a[j]<<" ";
    }
    cout<<endl;
    return 0;
}


