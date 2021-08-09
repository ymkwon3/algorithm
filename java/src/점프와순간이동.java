import java.util.*;

public class 점프와순간이동 {
    public int solution(int n) {
        int ans = 1;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = (n - 1) / 2;
                ans++;
            }
        }
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println(ans);

        return ans;
    }
}
