numbers = [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2];
hand = "left";
function distance(lr, m) {
  let lr_row = parseInt(lr / 3);
  if (lr % 3 == 0) {
    lr_row -= 1;
  }
  let m_row = parseInt(m / 3);
  let lr_col = lr % 3;
  if (lr_col == 0) {
    lr_col = 1;
  }
  let m_col = m % 3;
  return Math.abs(lr_row - m_row) + Math.abs(lr_col - m_col);
}

function solution(numbers, hand) {
  let left = 10;
  let right = 12;
  let mid = 0;
  var answer = "";
  for (let i of numbers) {
    if (i % 3 == 1) {
      left = i;
      answer += "L";
    } else if (i % 3 == 0 && i != 0) {
      right = i;
      answer += "R";
    } else {
      mid = i;
      if (i == 0) {
        mid = 11;
      }
      if (distance(left, mid) < distance(right, mid)) {
        left = mid;
        answer += "L";
      } else if (distance(left, mid) > distance(right, mid)) {
        right = mid;
        answer += "R";
      } else {
        if (hand == "left") {
          left = mid;
          answer += "L";
        } else {
          right = mid;
          answer += "R";
        }
      }
    }
  }
  return answer;
}
solution(numbers, hand);
