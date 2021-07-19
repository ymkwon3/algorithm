const numbers = [5, 0, 2, 7];

function solution(numbers) {
  var answer = [];
  let arr = [];
  for (let i = 0; i < 201; i++) {
    arr[i] = 0;
  }

  for (let i = 0; i < numbers.length - 1; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      arr[numbers[i] + numbers[j]] = 1;
    }
  }

  for (let i = 0; i < 201; i++) {
    if (arr[i] === 1) {
      answer.push(i);
    }
  }
  return answer;
}
solution(numbers);
