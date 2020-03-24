
//use two tables to store men preferences and women preferences
let menPreference = [[1,2,3],[2,3,1],[2,1,3]];
let womenPreference = [[2,1,3],[2,3,1],[3,1,2]];
//use a table to store result 3 by 3
//if man i and woman j not matched - res[i][j] = 0
//else res[i][j] = 1;
let res = new Array(3);
for(let i = 0; i < 3; i++){
	res[i] = new Array(3);
	res[i].fill(0);
}
let matchedMen = new Array(3);
let matchedWomen = new Array(3);
matchedMen.fill(false);
matchedWomen.fill(false);
let cnt = 0;//store matched pairs, == 3 means three pairs are all matched
while(cnt < 3){
	for(let man = 0; man < 3; man++){
		//check man 
		for(let i = 0; i < 3; i++){
			if(matchedMen[man] == false){
				let wish = menPreference[man][i] - 1;
				if(matchedWomen[wish] == false){//first preference isn't matched,directly match them
					matchedMen[man] = true;
					matchedWomen[wish] = true;
					res[man][wish] = 1;
					cnt++;
					break;
				}else{//else check women preference
					//find current matched man for wish
					let cur = res[0][wish] == 1 ? 0 : (res[1][wish] == 1 ? 1 : 2);
					let idxCur = womenPreference[wish].indexOf(cur + 1);
					let idxMan = womenPreference[wish].indexOf(man + 1);
					if(idxCur > idxMan){//idx > -> means preferences <
						res[cur][wish] = 0;
						matchedMen[man] = true;
						matchedWomen[wish] = true;
						res[man][wish] = 1;
						matchedMen[cur] = false;
						break;
					}
				}
			}
		}
	}
}

console.log(res);
for(let i = 0; i < 3; i++){
	for(let j = 0; j < 3; j++){
		if(res[i][j] == 1){
			console.log("matched", i+1, j+1);
		}
	}
}
