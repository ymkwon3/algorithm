let a = [1, 2, 3, 4, 5, 6];

let b = a.map((cur, idx, arr) => {
  //반복하는데다
  console.log(cur,idx);
  return cur + 1;

});
//정렬하는거다
b.sort((a,b) => b - a);
console.log(b);