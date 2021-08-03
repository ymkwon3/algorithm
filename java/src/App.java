public class App {
    public static void main(String[] args) throws Exception {
        가장큰정사각형찾기 sol = new 가장큰정사각형찾기();
        int[][] board = { { 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1 }, { 0, 1, 1, 1, 1 } };
        sol.solution(board);
    }
}
