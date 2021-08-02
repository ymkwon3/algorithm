import java.util.*;

public class 최댓값과최솟값 {
    public String solution(String s) {
        String[] strArr = s.split(" ");
        int[] intArr = Arrays.stream(strArr).mapToInt(Integer::parseInt).sorted().toArray();
        return intArr[0] + " " + intArr[intArr.length - 1];
    }
}
