const arr1 = [
  [1, 2],
  [2, 3],
];
const arr2 = [
  [3, 4],
  [5, 6],
];

solution(arr1, arr2);

function solution(arr1, arr2) {
  var answer = new Array(arr1.length);
  for (let i = 0; i < answer.length; i++) {
    answer[i] = new Array(arr1[0].length);
  }

  for (let row = 0; row < arr1.length; row++) {
    for (let col = 0; col < arr1[0].length; col++) {
      answer[row][col] = arr1[row][col] + arr2[row][col];
    }
  }

  return answer;
}
