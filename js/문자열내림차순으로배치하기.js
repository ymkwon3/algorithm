const s = "Zbcdefg";
solution(s);
function solution(s) {
  var answer = "";
  let tmp = [];
  for (let val of s) {
    tmp.push(val);
  }
  tmp.sort(function (a, b) {
    return a > b ? -1 : a < b ? 1 : 0;
  });
  for (let val of tmp) {
    answer += val;
  }
  return answer;
}
