//this file is used to solve dijkstra algorithm
//to find nearest distance for each vertex i,j
//by dynamic programming, for example:
//min(A,G), if there are two points E and F pointing at G, then min(A,G) = min(min(A,E)+length(EG),min(A,F)+length(FG))
let vertex = 7;
let matrix = new Array(vertex);
for(let i = 0; i < vertex; i++){
	matrix[i] = new Array(vertex);
	matrix[i].fill(500);//we note 500 as maximum distance
	matrix[i][i] = 0;
}

console.log("initial matrix: ",matrix);

//add edge between u and v
//where 0 <= u,v <= vertex-1 && u != v
function addEdge(u,v,weight){
	matrix[u][v] = weight;
}

//here we have 7 vertexes, 0,1,2,3,4,5,6 and 8 edges
addEdge(0,1,1);
addEdge(0,2,3);
addEdge(1,2,4);
addEdge(1,4,6);
addEdge(1,3,3);
addEdge(4,6,4);
addEdge(2,3,5);
addEdge(3,6,2);

console.log("after adding edges, matrix is: ",matrix);

function dp(v, w,length){
	if(v == w) return 0;
	else{
		for(let i = 0; i < vertex; i++){
			if(i != w && matrix[i][w] != 500){
				length = Math.min(dp(v,i,length) + matrix[i][w],length);
			}
		}
		return length;
	}
}

console.log(dp(0,6,500));

