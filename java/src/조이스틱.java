import java.util.Arrays;

public class 조이스틱 {
    public int solution(String name) {
        int answer = 0;
        int cursor = 0;
        char[] s = name.toCharArray();
        char[] arr = name.toCharArray();

        for (int i = 0; i < name.length(); i++) {
            s[i] = 'A';
        }

        while (!Arrays.equals(s, arr)) {
            if (s[cursor] != arr[cursor]) {
                answer += Math.min(up(s[cursor], arr[cursor]), down(s[cursor], arr[cursor]));
                s[cursor] = arr[cursor];
            }

            if (!Arrays.equals(s, arr)) {
                int[] arr1 = left(s, arr, cursor);
                int[] arr2 = right(s, arr, cursor);
                cursor = arr1[1];
                if (arr1[0] == arr2[0]) {
                    cursor = left(s, arr, arr1[1])[1] > right(s, arr, arr2[1])[1] ? arr2[0] : arr1[0];
                }
                answer += Math.min(arr1[0], arr2[0]);
            }
        }
        System.out.println("answer :  " + answer);

        return answer;
    }

    public int up(char s, char c) {
        int cnt = 0;
        while (s != c) {
            s++;
            if (s == 91)
                s = 65;
            cnt++;
        }
        return cnt;
    }

    public int down(char s, char c) {
        int cnt = 0;
        while (s != c) {
            s--;
            if (s == 64)
                s = 90;
            cnt++;
        }
        return cnt;
    }

    public int[] left(char[] s, char[] c, int cursor) {
        int cnt = 1;
        cursor--;
        if (cursor == -1)
            cursor = s.length - 1;
        while (s[cursor] == c[cursor]) {
            cursor--;
            if (cursor == -1)
                cursor = s.length - 1;
            cnt++;
        }
        return new int[] { cnt, cursor };
    }

    public int[] right(char[] s, char[] c, int cursor) {
        int cnt = 1;
        cursor++;
        if (cursor == s.length)
            cursor = 0;
        while (s[cursor] == c[cursor]) {
            cursor++;
            if (cursor == s.length)
                cursor = 0;
            cnt++;
        }
        return new int[] { cnt, cursor };
    }
}
