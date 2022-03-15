// let a = [1, 2, 3, 4];
// let b = a.map((value, index, arr) => value + index); //필요에 다라 value 하나만 사용할 수 있다.
// //arr는 map()을 호출한 배열
// console.log(a, b) // [1, 2, 3, 4], [1, 3, 5, 7]
// // a배열은 여전히 [1, 2, 3, 4]의 값을 가짐, b배열은 a의 각각의 요소들에 index를 더한 값 [2, 3, 4, 5]를 가짐



// let a = [1, 2, 3, 4];
// let init = 0;
// let b = a.reduce((acc, cur, idx, arr) => acc + cur, init);
// // acc: 리듀스 함수가 실행되고 저장되는 값이다. 즉 reduce()의 결과값이 저장된다.
// // cur, idx: 처리할 현재 값, 인덱스이다.
// // arr: reduce()를 호출한 배열이다.
// console.log(a, b) // [1, 2, 3, 4] 10



// let a = [1, 2, 3, 4];
// let b = a.find((e, idx, arr) => e > 2);
// let c = a.findIndex((e, idx, arr) => e > 2);
// // e: 처리할 현재의 요소(값)
// // idx: 처리할 현재 요소의 인덱스
// // arr: find(), findIndex()를 호출하는 배열
// console.log(b, c); // 3 2
// // 2보다 큰 요소의 첫번째 값은 3이고 이에 해당하는 인덱스는 2이다.



// let a = ["hello", "world", "abcd", "efgh"];
// let b = a.indexOf("world");
// let c = a.includes("world");
// let d = a.includes("world", 2);
// console.log(b, c, d) // 1 true false
// // b : 해당 값의 인덱스인 1을 반환
// // c : 헤당 값이 포함되어 있는지 판별
// // d : 해당 값이 인덱스 2 이후부터 포함되어 있는지 판별



// let a = "a b c d"
// let b = a.split(' ')
// let c = a.split(' ', 2);
// let d = b.join(' ');
// console.log(a, b, c, d) // a b c d ['a', 'b', 'c', 'd'] ['a', 'b'] a b c d
// // split과 join의 매개변수로는 공통으로 구분자가 들어가지만
// // split의 경우에 limit이라는 매개변수가 추가로 있을 수 있습니다.
// // 이는 끊어진 문자열의 최대 개수를 나타냅니다.



// const a = [3, 2, 10, 1, 3, 6]
// a.sort();
// console.log(a) // [1, 10, 2, 3, 3, 6]
// a.sort((a, b) => a - b); 
// // 왼쪽이 오른쪽보다 더 작은 값을 갖고 싶다면 -값이 리턴되게 - 오름차순
// // 왼쪽이 오른쪽보다 더 큰 값을 갖고 싶다면 +값이 리턴되게 - 내림차순
// // 값이 같을 때는 0리턴
// console.log(a) // [1, 2, 3, 3, 6, 10]
// a.reverse();
// console.log(a)  // [10, 6, 3, 3, 2, 1]



// const a = ["one", "two", "three", "four"];
// a.splice(1, 1); // index 1부터 1개만큼 제거
// console.log(a) // ['one', 'three', 'four']
// a.splice(1, 0, "two") // index 1부터 0개만큼 제거 후 "two" 추가
// console.log(a) // ['one', 'two', 'three', 'four']



// let a = [1, 3, 5, 9, 8, 2];
// let f = a.filter((element, index, arr) => element > 5);
// // element : 처리할 현재 요소
// // index : 처리할 현재 요소의 인덱스
// // arr : filter를 호출한 배열
// let m = a.map(e => e > 5);
// console.log(f) // [9, 8]
// console.log(m) // [false, false, false, true, true, false]
// //개인적으로 filter와 map의 차이는 반환되는 배열의 크기가 다르다는 것같다.



// const arr1 = [1, 2, 3];
// const arr2 = [4, 5, 6];
// const arr3 = arr1.concat(arr2);
// console.log(arr3) // [1, 2, 3, 4, 5, 6]



// const arr1 = [1, 2, 3];
// const first = arr1.shift();
// console.log(first); // 1
// console.log(arr1); // [2, 3]