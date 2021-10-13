public class 카카오프렌즈컬러링북 {
    boolean[][] visit;

    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        visit = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && picture[i][j] != 0) {
                    int tmp = dfs(i, j, picture);
                    maxSizeOfOneArea = maxSizeOfOneArea < tmp ? tmp : maxSizeOfOneArea;
                    numberOfArea++;
                }
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }

    public int dfs(int i, int j, int[][] picture) {
        int cnt = 1;
        visit[i][j] = true;
        if (i + 1 < picture.length && (!visit[i + 1][j] && picture[i][j] == picture[i + 1][j])) {
            cnt += dfs(i + 1, j, picture);
        }
        if (j + 1 < picture[i].length && (!visit[i][j + 1] && picture[i][j] == picture[i][j + 1])) {
            cnt += dfs(i, j + 1, picture);
        }
        if (i - 1 >= 0 && (!visit[i - 1][j] && picture[i][j] == picture[i - 1][j])) {
            cnt += dfs(i - 1, j, picture);
        }
        if (j - 1 >= 0 && (!visit[i][j - 1] && picture[i][j] == picture[i][j - 1])) {
            cnt += dfs(i, j - 1, picture);
        }
        return cnt;
    }
}
