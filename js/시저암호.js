const s = "a B z";
const n = 4;
solution(s, n);
function solution(s, n) {
  var answer = "";
  for (let val of s) {
    if (val === " ") {
      answer += " ";
      continue;
    }
    if (
      val.charCodeAt(0) + n > 90 &&
      val.charCodeAt(0) > 64 &&
      val.charCodeAt(0) < 91
    )
      answer += String.fromCharCode(val.charCodeAt(0) + n - 90 + 64);
    else if (
      val.charCodeAt(0) + n > 122 &&
      val.charCodeAt(0) > 96 &&
      val.charCodeAt(0) < 123
    )
      answer += String.fromCharCode(val.charCodeAt(0) + n - 122 + 96);
    else answer += String.fromCharCode(val.charCodeAt(0) + n);
  }
  console.log(answer);
  return answer;
}
