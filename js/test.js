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

let a = 1, b = 2;
console.log(a, b)