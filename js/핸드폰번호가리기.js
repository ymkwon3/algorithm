const phone_number = "01033334444";
solution(phone_number);
function solution(phone_number) {
  var answer = "";
  for (let i = 0; i < phone_number.length - 4; i++) {
    answer += "*";
  }
  for (let i = phone_number.length - 4; i < phone_number.length; i++) {
    answer += phone_number[i];
  }
  console.log(answer);
  return answer;
}
