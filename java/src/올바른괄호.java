import java.util.*;

public class 올바른괄호 {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Integer> stack = new Stack<Integer>();
        if (s.charAt(0) == '(')
            stack.push(0);
        if (s.charAt(0) == ')')
            return false;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(0);
            } else if (s.charAt(i) == ')') {
                if (!stack.isEmpty()) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        if (!stack.isEmpty())
            answer = false;
        System.out.println(answer);

        return answer;
    }
}
