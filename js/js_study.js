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