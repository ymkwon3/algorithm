let board = [
  [0, 0, 0, 0, 0],
  [0, 0, 1, 0, 3],
  [0, 2, 5, 0, 1],
  [4, 2, 4, 4, 2],
  [3, 5, 1, 3, 1],
];
let moves = [1, 5, 3, 5, 1, 2, 1, 4];

function solution(board, moves) {
  let st = [0];
  var answer = 0;
  for (let i of moves) {
    for (let j = 0; j < board.length; j++) {
      if (board[j][i - 1] !== 0) {
        if (st[st.length - 1] === board[j][i - 1]) {
          answer += 2;
          st.pop();
        } else {
          st.push(board[j][i - 1]);
        }
        board[j][i - 1] = 0;
        break;
      }
    }
  }
  return answer;
}

solution(board, moves);
