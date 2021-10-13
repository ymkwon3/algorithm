const left = 13;
const right = 17;
solution(left, right);

function measure(num) {
  let cnt = 0;
  for (let i = 1; i <= num; i++) {
    if (num % i === 0) cnt++;
  }
  return cnt % 2 === 0 ? 1 : -1;
}

function solution(left, right) {
  var answer = 0;

  for (let i = left; i <= right; i++) {
    answer += measure(i) * i;
  }
  console.log(answer);
  return answer;
}
