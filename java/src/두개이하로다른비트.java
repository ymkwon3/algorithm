public class 두개이하로다른비트 {
    public long[] solution(long[] numbers) {
        long[] answer = new long[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            long x = numbers[i];

            if (x % 2 == 0) {
                answer[i] = x + 1;
            } else {
                long zeroBit = (~x) & (x + 1);
                long newX = zeroBit | x;
                answer[i] = (~(zeroBit >> 1)) & newX;
            }
        }

        return answer;
    }
}
