import java.util.LinkedList;
import java.util.Queue;
import java.util.ArrayList;

public class 기능개발 {
    public ArrayList<Integer> solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> answer = new ArrayList<Integer>();
        int[] loading = speeds.clone();

        int cnt = 1;
        int func = 0;
        int index = 0;
        Queue<Integer> q = new LinkedList<>();
        for (int val : progresses) {
            q.add(val);
        }
        while (!q.isEmpty()) {
            if (q.peek() + loading[index] >= 100) {
                index++;
                func++;
                q.poll();
            } else if (func != 0) {
                answer.add(func);
                func = 0;
            } else {
                for (int i = 0; i < speeds.length; i++) {
                    if (loading[i] < 100) {
                        loading[i] = speeds[i] * cnt;
                    }
                }
                cnt++;
            }
            if (q.isEmpty()) {
                answer.add(func);
                func = 0;
                break;
            }
        }
        System.out.println(answer);
        return answer;
    }
}
