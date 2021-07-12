let array = [1, 4, 3, 4];
let com = [
  [2, 2, 1],
  [2, 4, 2],
];

// 자바스크립트에서는 sort시 유니코드 순서대로 하기 때문에, 값의 크기에 따른 비교를 정의해 주어야한다.
function solution(array, commands) {
  var answer = [];
  for (let i of commands) {
    answer.push(
      array.slice(i[0] - 1, i[1]).sort(function (a, b) {
        if (a > b) {
          return 1;
        }
        if (a < b) {
          return -1;
        }
        return 0;
      })[i[2] - 1]
    );
  }
  return answer;
}

solution(array, com);
