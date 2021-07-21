const a = 5;
const b = 3;
solution(a, b);

function solution(a, b) {
  var answer = 0;
  let tmp = 0;
  if (a > b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  console.log(a, b);
  for (let i = a; i <= b; i++) {
    answer += i;
  }
  console.log(answer);
  return answer;
}
