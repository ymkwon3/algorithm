const s = "Pyy";

solution(s);

function solution(s) {
  var answer = true;
  let p = 0;
  let y = 0;
  for (let val of s) {
    if (val === "p" || val === "P") p++;
    if (val === "y" || val === "Y") y++;
  }
  p == y ? (answer = true) : (answer = false);
  console.log(answer);
  return answer;
}
