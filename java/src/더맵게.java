import java.util.PriorityQueue;

public class 더맵게 {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        for (int val : scoville) {
            priorityQueue.add(val);
        }
        while (priorityQueue.peek() < K) {
            if (priorityQueue.size() == 1) {
                answer = -1;
                break;
            }
            int first = priorityQueue.poll();
            int second = priorityQueue.poll();
            priorityQueue.add(first + second * 2);
            answer++;
        }
        System.out.println(answer);
        return answer;
    }
}
