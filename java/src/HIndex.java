import java.util.*;

public class HIndex {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        for (int i = 0; i < citations.length; i++) {
            if (citations[citations.length - 1 - i] > i)
                answer = i + 1;
            else
                break;
        }
        System.out.println(answer);
        return answer;
    }
}
