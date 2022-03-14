const a = ["one", "two", "three", "four"];
a.splice(1, 1); // index 1부터 1개만큼 제거
console.log(a) // ['one', 'three', 'four']
a.splice(1, 0, "two") // index 1부터 0개만큼 제거 후 "two" 추가
console.log(a)