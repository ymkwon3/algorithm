import java.util.*;

public class 다리를지나는트럭 {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int currentWeight = 0;
        Queue<Integer> q = new LinkedList<Integer>();
        Queue<Integer> truck = new LinkedList<Integer>();
        for (int i = 0; i < bridge_length; i++) {
            q.add(0);
        }
        for (int val : truck_weights) {
            truck.add(val);
        }
        while (true) {
            answer++;
            System.out.println(q);

            if (!truck.isEmpty() && weight >= currentWeight + truck.peek()) {
                q.add(truck.peek());
                currentWeight -= q.poll();
                currentWeight += truck.poll();
            } else {
                if ((!truck.isEmpty() && weight > currentWeight - q.peek())
                        && weight >= currentWeight - q.peek() + truck.peek()) {
                    q.add(truck.peek());
                    currentWeight = currentWeight - q.poll() + truck.poll();

                } else {
                    q.add(0);
                    currentWeight -= q.poll();
                }
            }
            if (currentWeight == 0 && truck.isEmpty())
                break;
        }
        System.out.println(answer);

        return answer;
    }
}
