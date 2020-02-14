//delete duplicate element in an ordered array
//function uniquify
#include <iostream>
#include <string>
using namespace std;

void uniqueArray(char a[], int n){
	int unique = 0;
    for(int i = 0; i < n - 1; i++){
    	if(a[i+1] != a[i]){
    		unique++;
    		a[unique] = a[i+1];
    	}
    }
}

int main(){
	int len;
	cout<<"input array length:"<<endl;
	cin>>len;
    char a[len];
    cout<<"please input array:"<<endl;
    for(int i = 0; i < len; i++){
    	cin>>a[i];
    }
    uniqueArray(a,len);
    cout<<"after deleting duplicate elements: "<<a<<endl;
    return 0;
}


