
	function bubbleSort_v1(arr){
		let n = arr.length;
		for(let i = 0; i < n; i++){
			for(let j = 0; j < n - i - 1; j++){
				if(arr[j] > arr[j+1]){
					int tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = tmp;
				}
			}
		}
	}

	function bubbleSort_v2(arr){
		let sorted;
		let n = arr.length;
		for(let i = 0; i < n; i++){
			sorted = true;
			for(let j = 0; j < n - i - 1; j++){
				if(arr[j] > arr[j+1]){
					int tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = tmp;
					sorted = false;
				}
			}
			if(sorted) break;
		}
	}
