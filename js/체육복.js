let n = 5;
let lost = [2, 4];
let reserve = [3];

function solution(n, lost, reserve) {
  let student = [-1];
  var answer = 0;
  for (let i = 1; i <= n; i++) {
    student.push(1);
  }
  for (let val of lost) {
    student[val]--;
  }
  for (let val of reserve) {
    student[val]++;
  }

  for (let i = 1; i <= n; i++) {
    if (student[i] === 2) {
      if (i - 1 > 0 && student[i - 1] === 0) {
        student[i - 1]++;
        student[i]--;
      } else if (i + 1 < n && student[i + 1] === 0) {
        student[i + 1]++;
        student[i]--;
      }
    }
  }

  for (let val of student) {
    if (val > 0) answer++;
  }
  return answer;
}

solution(n, lost, reserve);
