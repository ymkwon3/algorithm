import java.util.*;

public class 짝지어제거하기 {
    public int solution(String s) {
        int answer = -1;
        Stack<Character> stack = new Stack<Character>();
        stack.push(s.charAt(0));
        for (int i = 1; i < s.length(); i++) {
            if (!stack.empty() && s.charAt(i) == stack.peek()) {
                stack.pop();
                continue;
            } else {
                stack.push(s.charAt(i));
            }
        }
        if (stack.empty())
            answer = 1;
        else
            answer = 0;
        return answer;
    }
}
