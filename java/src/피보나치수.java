public class 피보나치수 {
    public static final int MAX = 100001;

    public int solution(int n) {
        int answer = 0;
        int[] fibo = new int[MAX];
        fibo[0] = 0;
        fibo[1] = 1;
        for (int i = 2; i < MAX; i++) {
            fibo[i] = fibo[i - 1] % 1234567 + fibo[i - 2] % 1234567;
        }
        answer = fibo[n];
        System.out.println(fibo[n]);
        return answer;
    }
}
