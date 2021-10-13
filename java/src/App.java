public class App {
    public static void main(String[] args) throws Exception {
        // 두개이하로다른비트 sol = new 두개이하로다른비트();
        // long[] l = { 2, 7 };
        // sol.solution(l);
        long x = 7;
        long zero = (~x) & (x + 1);
        long newX = zero | x;
        System.out.println(~(zero >> 1) & newX);
    }
}
