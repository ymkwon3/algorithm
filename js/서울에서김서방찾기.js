const seoul = ["Jane", "Kim"];
solution(seoul);
function solution(seoul) {
  var answer = "";
  let index = 0;
  index = seoul.indexOf("Kim");
  answer = "김서방은 " + index + "에 있다";
  return answer;
}
