import java.util.*;

public class 가장큰수 {
    public String solution(int[] numbers) {
        String answer = "";
        ArrayList<String> conv = new ArrayList<>();
        for (int val : numbers) {
            conv.add(String.valueOf(val));
        }
        conv.sort((a, b) -> (a + b).compareTo(b + a));

        for (String val : conv) {
            System.out.println(val);
            answer = val + answer;
        }

        while (answer.length() > 1 && answer.charAt(0) == '0') {
            answer = answer.substring(1);
        }

        System.out.println(answer);
        return answer;
    }
}
