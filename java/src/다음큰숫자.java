public class 다음큰숫자 {
    public int solution(int n) {
        int answer = 0;
        String s = Integer.toBinaryString(n);
        int cnt1 = returnCnt(n);

        for (int i = n + 1;; i++) {
            int cmp = returnCnt(i);
            if (cnt1 == cmp) {
                answer = i;
                break;
            }
        }
        return answer;
    }

    private int returnCnt(int n) {
        String tmp = Integer.toBinaryString(n);
        int cnt = 0;
        for (int i = 0; i < tmp.length(); i++) {
            if (tmp.charAt(i) == '1')
                cnt++;
        }
        return cnt;
    }
}
