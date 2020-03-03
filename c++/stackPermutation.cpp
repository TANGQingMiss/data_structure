//this file is used to check whether one stack can be permutated to another stack
//in other ways, check structure 312
//for n-length array, stack permutations is (2n!)/((n+1)!n!)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkPermutation(vector<int> arr1, vector<int> arr2, int n){
	//extra vector for middle transportation of arr1 and arr2
	vector<int> s;
	int j = 0;
	for(int i = 0; i < n; i++){
		//for every element of arr1, push it to s
		s.push_back(arr1[i]);
		//if the top element is equel to the first element of arr2
		while(s[s.size()-1] == arr2[j] && j < n){
			s.pop_back();
			//pop it and j++ to check later element
			j++;
		}
	}
	//if s has no element, that means all elements have been popped, return true
	if(s.size() == 0) return true;
	//if not, check whether remanent elements in s.pop == arr[j++]
	while(j < n){
		if(s[s.size() - 1] == arr1[j]){
			s.pop_back();
			j++;
		}else return false;
	}
	return true;
}


int main(){
	int len;
	cout<<"input array length:"<<endl;
	cin>>len;
    vector<int> a;
    cout<<"please input original array a:"<<endl;
    for(int i = 0; i < len; i++){
    	int k;
        cin>>k;
        a.push_back(k);
    }
    vector<int> b;
    cout<<"please input array b:"<<endl;
    for(int i = 0; i < len; i++){
    	int k;
        cin>>k;
        b.push_back(k);
    }
    if(checkPermutation(a,b,len)){
    	cout<<"b is a permutation of a"<<endl;
    }else{
    	cout<<"b isn't a permutation of a"<<endl;
    }

    return 0;
}


