const a = [1, 2, 3, 4];
const b = [-3, -1, 0, 2];

function solution(a, b) {
  var answer = 0;
  for (let i in a) {
    answer += a[i] * b[i];
  }
  return answer;
}
solution(a, b);
