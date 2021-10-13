public class 카펫 {
    public int[] solution(int brown, int yellow) {
        int[] answer = { 0, 0 };

        for (int i = 1; i <= yellow; i++) {
            if (yellow % i == 0 && ((yellow / i) + 2 == (brown - i * 2) / 2)) {
                answer[0] = (yellow / i) + 2;
                answer[1] = (brown + yellow) / answer[0];
                break;
            }
        }
        System.out.println(answer[0] + " " + answer[1]);
        return answer;
    }
}
