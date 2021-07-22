const arr = [10];
solution(arr);

function solution(arr) {
  var answer = [];
  let pair = new Object();
  pair.index = 0;
  pair.value = arr[0];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] < pair.value) {
      pair.index = i;
      pair.value = arr[i];
    }
  }

  arr.splice(pair.index, 1);
  if (arr.length === 0) answer.push(-1);
  else answer = arr;
  console.log(answer);

  return answer;
}
