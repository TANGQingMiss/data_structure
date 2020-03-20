//this file is used to create a graph and realize breadth first search
//input m villages and n pairs of village whose distance < target
//we have to make sure that each pair of village don't use the same frequency browdcast
//here we only consider two types of frequency
//so the aim is to make each adjacent village have either A or B frequency but not the same
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
	void addEdge(int v, int w){
		g[v-1].push_back(w-1);//v -> w
		if(!directed){
			g[w-1].push_back(v-1);
		}//if non-directed, w -> v
		m++;//add an edge from v to w
	}

	//check whether has an edge
	bool hasEdge(int v, int w){
		for(int i = 0; i < g[v-1].size(); i++){
			if(g[v-1][i] == w-1) return true;
		}
		return false;
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

	int bfs(int v){
		vector<bool> visited(n,false);//note whether visited
		vector<int> frequency(n,2);//node type of frequency by 0 or 1,use 2 as initial state
		queue<int> que;
		que.push(v-1);
		frequency[v-1] = 0;
		while(!que.empty()){
			int tmp = que.front();
			if(!visited[tmp]){
				que.pop();
				visited[tmp] = true;
				int size = g[tmp].size();
				for(int i = 0; i < size; i++){
					int b = g[tmp][i];
					if(!visited[b]){
						que.push(b);
						if(frequency[b] == 2){
							frequency[b] = frequency[tmp] == 0 ? 1 : 0;
						}else if(frequency[b] == frequency[tmp]) return -1;
					}
				}
			}
		}
		return 1;
	}
};

int main(){
	int vertex,edge;
	cout<<"input number of villages:"<<endl;
	cin>>vertex;
	cout<<"input edge number"<<endl;
	cin>>edge;
	SparseGraph myGraph(vertex,false);
	for(int i = 0; i < edge; i++){
		int from,to;
		cout<<"add an edge between: "<<endl;
		cin>>from>>to;
		myGraph.addEdge(from,to);
	}
	myGraph.print();
	cout<<"result is: "<<endl;
	cout<<myGraph.bfs(1)<<endl;;

    return 0;
}
