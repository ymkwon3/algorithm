public class JadenCase문자열만들기 {
    public String solution(String s) {
        String answer = "";
        boolean flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 && s.charAt(i) >= 97 && s.charAt(i) <= 122) {
                flag = false;
                answer += (char) (s.charAt(i) - 32);
            } else if (s.charAt(i) == ' ') {
                flag = true;
                answer += ' ';
            } else if (flag && s.charAt(i) >= 97 && s.charAt(i) <= 122) {
                flag = false;
                answer += (char) (s.charAt(i) - 32);
            } else if (flag && s.charAt(i) >= 65 && s.charAt(i) <= 90) {
                flag = false;
                answer += (char) (s.charAt(i));
            } else if (s.charAt(i) >= 65 && s.charAt(i) <= 90) {
                flag = false;
                answer += (char) (s.charAt(i) + 32);
            } else {
                flag = false;
                answer += (char) (s.charAt(i));
            }
        }
        System.out.println(answer);
        return answer;
    }
}
