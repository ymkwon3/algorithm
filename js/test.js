// var foo = "Hello";
// (function() {
//   var bar = " World";
//   console.log(foo + bar, 1);
// })();
// console.log(foo + bar);
// 두번째 콘솔에서 bar not defined error 뜸

// var foo = {n: 1};
// var bar = foo;
// foo.x = foo = {n: 2};
// foo에는 n이라는 키 밖에 없다.

// var foo = [];
// foo.push(1);
// foo.push(2);
// console.log(foo.length) 2

// var foo = 10 + '20'
// string형태의 1020

// console.log(0.1 + 0.2 == 0.3)
// false 저장방식 차이 가수부? 지수부


// const add = (a, b) => (b || b === 0) ? console.log(a + b, 1) : (b) => console.log(a + b, 2);
// add(1)(3)

// console.log("i'm a lasagna hog".split("").reverse().join(""))
// 거꾸로 됨

// console.log(window.foo || ( window.foo = "bar" ))

// console.log('one');
// setTimeout(function() {
//   console.log('two');
// }, 0);
// console.log('three');

// var foo = {n: 1};
// var bar = foo;
// foo.x = foo = {n: 2};
// console.log(foo.x)

// let list = [1, 2, 3];
// const a = list.shift();
// console.log(a, list)

// const graph = {
//   A: ["B", "C"],
//   B: ["A", "D"],
//   C: ["A", "G", "H", "I"],
//   D: ["B", "E", "F"],
//   E: ["D"],
//   F: ["D"],
//   G: ["C"],
//   H: ["C"],
//   I: ["C", "J"],
//   J: ["I"]
// };

// const DFS = (graph, startNode) => {
//   const visited = []; // 탐색을 마친 노드들
//   let needVisit = []; // 탐색해야할 노드들

//   needVisit.push(startNode); // 노드 탐색 시작

//   while (needVisit.length !== 0) { // 탐색해야할 노드가 남아있다면
//     const node = needVisit.shift(); // queue이기 때문에 선입선출, shift()를 사용한다.
//     if (!visited.includes(node)) { // 해당 노드가 탐색된 적 없다면
//       visited.push(node); 
//       needVisit = [...graph[node], ...needVisit];
//     }
//   }
//   return visited;
// };

// console.log(DFS(graph, "A"));
// // ["A", "B", "D", "E", "F", "C", "G", "H", "I", "J"]


let a = 1;
let b = a;
a = 3;
console.log(a, b)