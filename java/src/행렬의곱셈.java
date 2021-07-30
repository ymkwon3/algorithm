public class 행렬의곱셈 {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = new int[arr1.length][arr2[0].length];
        for (int i = 0; i < arr1.length; i++) {
            for (int j = 0; j < arr2[0].length; j++) {
                answer[i][j] = mul(arr1, arr2, i, j);
                System.out.println(answer[i][j]);
            }
        }

        return answer;
    }

    int mul(int[][] arr1, int[][] arr2, int y, int x) {
        int result = 0;

        for (int i = 0, j = 0; i < arr1[y].length; i++, j++) {
            result += arr1[y][i] * arr2[j][x];
            System.out.println(arr1[y][i] + " * " + arr2[j][x]);
        }
        return result;
    }
}
