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
		g[v].push_back(w);//v -> w
		if(!directed){
			g[w].push_back(v);
		}//if non-directed, w -> v
		m++;//add an edge from v to w
	}

	//check whether has an edge
	bool hasEdge(int v, int w){
		for(int i = 0; i < g[v].size(); i++){
			if(g[v][i] == w) return true;
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

	void dfs(int v){
		vector<bool> visited(n,false);
		stack<int> s;
		s.push(v);
		while(!s.empty()){
			int tmp = s.top();
			if(!visited[tmp]){ //if node isn't visited
				cout<<tmp<<" ";
			}
			visited[tmp] = true;
			s.pop();
			int size = g[tmp].size();//push each element non-visited connected with tmp
			for(int i = 0; i < size; i++){
				int b = g[tmp][i];
				if(!visited[b]) s.push(b);
			}
		}
		cout<<endl;
	}

	void bfs(int v){
		vector<bool> visited(n,false);
		queue<int> que;
		que.push(v);
		while(!que.empty()){
			int tmp = que.front();
			if(!visited[tmp]) cout<<tmp<<" ";
			visited[tmp] = true;
			que.pop();
			int size = g[tmp].size();
			for(int i = 0; i < size; i++){
				int b = g[tmp][i];
				if(!visited[b]) que.push(b);
			}
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
	SparseGraph myGraph(vertex,false);
	for(int i = 0; i < edge; i++){
		int from,to;
		cout<<"add an edge between: "<<endl;
		cin>>from>>to;
		myGraph.addEdge(from,to);
	}
	myGraph.print();
	myGraph.dfs(0);
	myGraph.bfs(0);
    return 0;
}
