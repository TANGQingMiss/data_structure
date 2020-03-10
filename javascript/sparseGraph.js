//this file is used to create a graph
//and realize breadth first search
//as well as depth first search

//initialize an adjacent matrix
//0 means no edge between these two vertexes
//1 means there is an edge from row - col
//we consider here a directed graph
let vertex = 5;
let matrix = new Array(vertex);
for(let i = 0; i < vertex; i++){
	matrix[i] = new Array(vertex);
	matrix[i].fill(0);
}

//add edge between u and v
//where 0 <= u,v <= vertex-1 && u != v
function addEdge(u,v){
	matrix[u][v] = 1;//change edge state to 1
	console.log("add an edge between given vertex");
	console.log(u);
	console.log(v);
	console.log("u to v is: ",matrix[u][v]);
}

function bfs(matrix){
	console.log("breadth first search result: ");
	let visited = new Array(vertex);
	visited.fill(false);
	let s = new Array();
	s.push(0);//start from the number 0 vertex
	while(s.length > 0){
		let tmp = s.pop();
		if(visited[tmp] == false){
			console.log(tmp);
		}
		visited[tmp] = true;
		for(let i = 0; i < vertex; i++){
			let layer = matrix[tmp][i];
			if(visited[i] == false && layer == 1){
				s.push(i);
			}
		}
	}
}

function dfs(matrix){
	console.log("depth first search result: ");
	let visited = new Array(vertex);
	visited.fill(false);
	let s = new Array();
	s.push(0);//start from the number 0 vertex
	while(s.length > 0){
		let tmp = s.shift();
		if(visited[tmp] == false){
			console.log(tmp);
		}
		visited[tmp] = true;
		for(let i = 0; i < vertex; i++){
			let layer = matrix[tmp][i];
			if(visited[i] == false && layer == 1){
				s.push(i);
			}
		}
	}
}

//here we have 5 vertexes, 0,1,2,3,4
addEdge(0,1);
addEdge(0,4);
addEdge(1,3);
addEdge(3,2);
addEdge(2,1);
dfs(matrix);
bfs(matrix);