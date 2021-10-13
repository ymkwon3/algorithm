import java.util.*;

public class N개의최소공배수 {
    public int solution(int[] arr) {
        int answer = 1;
        int[][] prime = new int[arr.length][101];
        int[] lcm = new int[101];
        for (int i = 0; i < prime.length; i++) {
            HashSet<Integer> pNum = new HashSet<Integer>();
            int e = arr[i];
            int div = 2;
            while (e != 1) {
                if (e % div == 0) {
                    e /= div;
                    prime[i][div]++;
                    pNum.add(div);
                } else {
                    div++;
                }
            }
            for (int val : pNum) {
                if (lcm[val] == 0 || lcm[val] < prime[i][val]) {
                    lcm[val] = prime[i][val];
                }
            }
        }
        for (int i = 0; i < lcm.length; i++) {
            if (lcm[i] != 0) {
                System.out.println(lcm[i]);
                answer *= (int) (Math.pow(i, lcm[i]));
            }
        }
        return answer;
    }
}
