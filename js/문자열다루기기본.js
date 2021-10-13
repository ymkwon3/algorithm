const s = "a234";
solution(s);

function solution(s) {
  var answer = true;
  if (s.length === 4 || s.length === 6) {
    for (let val of s) {
      if (val < "0" || val > "9") {
        answer = false;
        break;
      }
    }
  } else answer = false;
  console.log(answer);
  return answer;
}
