public class 숫자의표현 {
    public int solution(int n) {
        int answer = 1;

        for (int i = 1; i < (int) Math.round((double) n / 2); i++) {
            int tmp = 0;
            for (int j = i; j < (int) Math.round((double) n / 2) + 1; j++) {
                System.out.print(j);
                tmp += j;
                if (tmp > n)
                    break;
                if (tmp == n) {
                    answer++;
                    break;
                }
            }
            System.out.println();
        }
        System.out.println(answer);
        return answer;
    }
}
