import java.util.*;

public class 영어끝말잇기 {
    public int[] solution(int n, String[] words) {
        int[] answer = { 0, 0 };
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        char pre = words[0].charAt(words[0].length() - 1);
        map.put(words[0], 1);
        for (int i = 1; i < words.length; i++) {
            if (pre == words[i].charAt(0)) {
                if (map.get(words[i]) == null) {
                    map.put(words[i], 1);
                    pre = words[i].charAt(words[i].length() - 1);
                } else {
                    answer[0] = (i + 1) % n == 0 ? n : (i + 1) % n;
                    answer[1] = (int) Math.ceil((double) (i + 1) / n);
                    break;
                }
            } else {
                answer[0] = (i + 1) % n == 0 ? n : (i + 1) % n;
                answer[1] = (int) Math.ceil((double) (i + 1) / n);
                break;
            }

        }

        System.out.println(answer[0] + " " + answer[1]);

        return answer;
    }
}
