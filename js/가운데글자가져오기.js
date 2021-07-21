const s = "abc";
solution(s);
function solution(s) {
  var answer = "";
  if (s.length % 2 === 0) {
    answer += s[Math.ceil(s.length / 2) - 1];
    answer += s[Math.ceil(s.length / 2)];
  } else {
    answer += s[Math.ceil(s.length / 2) - 1];
  }
  console.log(answer);
  return answer;
}
