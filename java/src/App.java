public class App {
    public static void main(String[] args) throws Exception {
        카카오프렌즈컬러링북 sol = new 카카오프렌즈컬러링북();
        int[][] picture = { { 0, 1, 0 }, { 1, 1, 0 }, { 0, 0, 0 } };
        sol.solution(3, 3, picture);
    }
}
