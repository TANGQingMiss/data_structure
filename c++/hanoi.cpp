#include <iostream>
using namespace std;

//move to top disk from src to dest
void move(char src, char dest){
	cout<<src<<"-->"<<dest<<endl;
}

//move n from src to medium, n-1 on the medium
void hanoi(int n, char src, char medium, char dest){
	if(n == 1) move(src,dest);
	else{
		hanoi(n-1,src,dest,medium);
		move(src,dest);
		hanoi(n-1,medium,src,dest);
	}
}

int main(){
	int m;
	cout<<"input the number of disks: ";
	cin>>m;
	cout<<"the steps to moving "<<m<<"disks: "<<endl;
	hanoi(m,'A','B','C');
	return 0;
}