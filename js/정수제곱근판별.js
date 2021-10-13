const n = 121;
solution(n);
function solution(n) {
  var answer = 0;
  if (Math.sqrt(n) % 1 === 0) {
    answer = (Math.sqrt(n) + 1) * (Math.sqrt(n) + 1);
  } else {
    answer = -1;
  }
  console.log(Math.sqrt(n));
  return answer;
}
