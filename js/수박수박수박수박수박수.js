const n = 3;
solution(n);
function solution(n) {
  var answer = "";
  for (let i = 0; i < n; i++) {
    if (i % 2 === 0) answer += "박";
    else answer += "수";
  }
  return answer;
}
