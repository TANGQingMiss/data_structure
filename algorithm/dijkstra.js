//this file is used to solve dijkstra algorithm
//to find nearest distance for each vertex i,j
let vertex = 6;
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

//here we have 6 vertexes, 0,1,2,3,4,5 and 9 edges
addEdge(0,1,1);
addEdge(0,2,12);
addEdge(1,2,9);
addEdge(1,3,3);
addEdge(3,2,4);
addEdge(2,4,5);
addEdge(3,4,13);
addEdge(3,5,15);
addEdge(4,5,4);

console.log("after adding edges, matrix is: ",matrix);

function dijkstra(matrix,v){
		let n = matrix.length;
		let tmpDistance = new Array(n);
		let minimized = new Array(n);
		for(let i = 0; i < n; i++){
			minimized[i] = false;
			if(i == v) minimized[i] = true;
		}//note whether arrived at minimized value
		for(let i = 0; i < n; i++){
			tmpDistance[i] = matrix[v][i];
		}//initialize distance for vertex v

		for(let i = 0; i < n - 1; i++){
			//to find nearest vertex for v
			let min = 500;
			let u;
			for(let j = 0; j < n; j++){
				if(minimized[j] == false && tmpDistance[j] < min){
					min = tmpDistance[j];
					u = j;
				}
			}
			minimized[u] = true;
			//start from beginning to update distance
			for(let k = 0; k < n; k++){
				if(matrix[u][k] < 500 && matrix[u][k] > 0){
					if(matrix[u][k] + tmpDistance[u] < tmpDistance[k]){
						tmpDistance[k] = matrix[u][k] + tmpDistance[u];
					}
				}
			}
		}
		console.log("nearest distance starting from vertex: ",v);
		console.log(tmpDistance);
}

dijkstra(matrix,0);

