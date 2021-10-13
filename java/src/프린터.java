import java.util.*;

public class 프린터 {
    class Pair {
        int index;
        int value;

        Pair(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }

    public int solution(int[] priorities, int location) {
        int answer = 0;
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());
        Queue<Pair> q = new LinkedList<>();

        for (int i = 0; i < priorities.length; i++) {
            q.add(new Pair(i, priorities[i]));
            priorityQueue.add(priorities[i]);
        }

        while (!q.isEmpty()) {
            Pair pair = q.poll();
            if (pair.value < priorityQueue.peek()) {
                q.add(pair);
            } else {
                priorityQueue.remove();
                answer++;
                if (pair.index == location)
                    break;
            }

        }
        System.out.println(answer);

        return answer;
    }
}
