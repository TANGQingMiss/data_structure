//this file is used to create a graph and realize breadth first search
//as well as depth first search
//in adjacent list
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

	void dijkstra(int v){
		int tmpDistance[n];
		bool minimized[n];
		for(int i = 0; i < n; i++){
			minimized[i] = false;
			if(i == v) minimized[i] = true;
		}//note whether arrived at minimized value
		for(int i = 0; i < n; i++){
			tmpDistance[i] = g[v][i];
		}//initialize distance for vertex v

		for(int i = 0; i < n - 1; i++){
			//to find nearest vertex for v
			int min = 500;
			int u;
			for(int j = 0; j < n; j++){
				if(minimized[j] == false && tmpDistance[j] < min){
					min = tmpDistance[j];
					u = j;
				}
			}
			minimized[u] = true;
			//start from beginning to update distance
			for(int k = 0; k < n; k++){
				if(g[u][k] < 500 && g[u][k] > 0){
					if(g[u][k] + tmpDistance[u] < tmpDistance[k]){
						tmpDistance[k] = g[u][k] + tmpDistance[u];
					}
				}
			}
		}
		cout<<"nearest distance starting from vertex "<<v<<" is: "<<endl;
		for(int i = 0; i < n; i++){
			cout<<tmpDistance[i]<<" ";
		}
		cout<<endl;
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
	myGraph.dijkstra(0);
    return 0;
}
