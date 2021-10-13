public class 가장큰정사각형찾기 {
    public int solution(int[][] board) {
        int answer = board[0][0];

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    if (board[i][j] >= 1 && board[i - 1][j - 1] >= 1 && board[i - 1][j] >= 1 && board[i][j - 1] >= 1) {
                        board[i][j] += Math.min(Math.min(board[i - 1][j - 1], board[i - 1][j]), board[i][j - 1]);
                        if (board[i][j] > answer) {
                            answer = board[i][j];
                        }
                    }
                } else if (board[i][j] == 1 && answer == 0) {
                    answer = 1;
                }
            }
        }
        System.out.println(answer * answer);
        return answer * answer;
    }
}
