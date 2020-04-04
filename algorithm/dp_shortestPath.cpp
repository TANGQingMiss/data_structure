//this file is used to solve dijkstra algorithm
//to find nearest distance for each vertex i,j
//by dynamic programming, for example:
//min(A,G), if there are two points E and F pointing at G, then min(A,G) = min(min(A,E)+length(EG),min(A,F)+length(FG))
#include <iostream>
#include <stdio.h>
#include <string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class SparseGraph{
public:
	int n, m;//n nodes, m edges
	bool directed;//directed or non-directed
	vector<vector<int> > g;//2D vector

	//construct function
	SparseGraph(int n, bool directed){
		this->n = n;
		this->directed = directed;
		for(int i = 0; i < n; i++){
			g.push_back(vector<int>());
		}
		//establish matrix for storing distance
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) g[i].push_back(0);
				else{
					g[i].push_back(500);//we use 500 to note maximum distance, or INT_MAX
				}
			}
		}
	}

	//deconstruct function
	~SparseGraph(){}

	//get node number
	int getV(){
		return n;
	}

	//get edge number
	int getE(){
		return m;
	}

	//add edge between two nodes
	void addEdge(int v, int w, int weight){
		g[v][w] = weight;//v -> w
		if(!directed){
			g[w][v] = weight;
		}//if non-directed, w -> v
		m++;//add an edge from v to w
	}

	void print(){
		for(int i = 0; i < g.size(); i++){
			cout<<"edge "<<i<<" : ";
			for(int j = 0; j < g[i].size(); j++){
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	int dp(int v, int w, int length){
		if(v == w) return 0;
		else{
			for(int i = 0; i < n; i++){
				if(i != w && g[i][w] != 500){
					length = min(dp(v,i,length) + g[i][w],length);
				}
			}
			return length;
		}
	}

};

int main(){
	
	int vertex,edge;
	cout<<"input vertex number"<<endl;
	cin>>vertex;
	cout<<"input edge number"<<endl;
	cin>>edge;
	SparseGraph myGraph(vertex,true);
	for(int i = 0; i < edge; i++){
		int from,to,weight;
		cout<<"add an edge and its weight: "<<endl;
		cin>>from>>to>>weight;
		myGraph.addEdge(from,to,weight);
	}

	myGraph.print();
	cout<<"input begin vertex and end vertex between 0 and "<<vertex-1<<endl;
	int begin,end;
	cin>>begin>>end;
	cout<<"shortest path is: "<<myGraph.dp(begin,end,500)<<endl;
    return 0;
}
