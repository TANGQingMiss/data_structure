//this file is used to solve a simple tsp(travelling salesman problem)
//first input number of village and number of roads
//next for each road, input start village and end village, directed
//output maximum traverse villages
#include <iostream>
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
	void addEdge(int v, int w){//v,w between 1 - N while index from 0 - N-1
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
			cout<<"edge from "<<i+1<<" : ";
			for(int j = 0; j < g[i].size(); j++){
				cout<<g[i][j]+1<<" ";
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
				cout<<tmp+1<<" ";
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
};

int main(){
	
	int village,road;
	cout<<"input village number"<<endl;
	cin>>village;
	cout<<"input road number"<<endl;
	cin>>road;
	SparseGraph myGraph(village,true);//a directed road
	for(int i = 0; i < road; i++){
		int from,to;//between 1 and village number 
		cout<<"add an edge between: "<<endl;
		cin>>from>>to;
		myGraph.addEdge(from,to);
	}
	myGraph.print();
	for(int i = 0; i < village; i++){
		myGraph.dfs(i);
	}
    return 0;
}
