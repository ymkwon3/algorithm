import java.util.*;

public class 삼각달팽이 {
    public ArrayList<Integer> solution(int n) {
        ArrayList<Integer> answer = new ArrayList<>();
        int len = 0;
        for (int i = 1; i <= n; i++)
            len += i;
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            ArrayList<Integer> tmp = new ArrayList<>(Collections.nCopies(i, 0));
            arr.add(tmp);
        }

        int value = 1;
        int i = 0, j = 0;
        boolean up = false;
        while (value <= len) {
            if (arr.get(i).get(j) == 0) {
                arr.get(i).set(j, value);
                value++;
                if ((i + 1 < n && !up) && arr.get(i + 1).get(j) == 0) {
                    i++;
                } else if (j + 1 < arr.get(i).size() && arr.get(i).get(j + 1) == 0) {
                    j++;
                } else if ((i - 1 >= 0 && j - 1 >= 0) && arr.get(i - 1).get(j - 1) == 0) {
                    i--;
                    j--;
                    up = true;
                } else {
                    up = false;
                    i++;
                }
            }
        }

        for (ArrayList<Integer> obj : arr) {
            for (int val : obj) {
                answer.add(val);
            }
        }

        System.out.println(answer);
        return answer;
    }
}
