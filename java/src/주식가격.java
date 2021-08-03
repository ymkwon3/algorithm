import java.util.*;

public class 주식가격 {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(0);
        for (int i = 1; i < prices.length; i++) {
            if (!stack.isEmpty() && prices[i] < prices[stack.peek()]) {
                answer[stack.peek()] = i - stack.peek();
                stack.pop();
                i--;
            } else {
                stack.push(i);
            }
        }

        while (!stack.isEmpty()) {
            answer[stack.peek()] = prices.length - stack.peek() - 1;
            stack.pop();
        }

        for (int i : answer) {
            System.out.println(i);
        }

        return answer;
    }
}
