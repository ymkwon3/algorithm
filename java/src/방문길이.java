import java.util.*;

public class 방문길이 {
    int MAX = 5;

    class P {
        int x1;
        int y1;
        int x2;
        int y2;

        P(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        // 사용자 클래스를 set으로 하려면 오버라이딩을 해줘야함
        public int hashCode() {
            return (Integer.toString(x1) + Integer.toString(y1) + Integer.toString(x2) + Integer.toString(y2))
                    .hashCode();
        }

        public boolean equals(Object obj) {
            if (obj instanceof P) {
                P temp = (P) obj;
                return x1 == temp.x1 && y1 == temp.y1 && x2 == temp.x2 && y2 == temp.y2;
            } else {
                return false;
            }
        }

        public void printP() {
            System.out.println(x1 + " " + y1 + " " + x2 + " " + y2);
        }
    }

    public int solution(String dirs) {
        int answer = 0;
        int[] position = { 0, 0 };
        HashSet<P> s = new HashSet<P>();
        for (int i = 0; i < dirs.length(); i++) {
            if (dirs.charAt(i) == 'U') {
                if (position[1] + 1 <= MAX) {
                    s.add(new P(position[0], position[1], position[0], position[1] + 1));
                    s.add(new P(position[0], position[1] + 1, position[0], position[1]));
                    position[1]++;
                }
            } else if (dirs.charAt(i) == 'D') {
                if (position[1] - 1 >= -MAX) {
                    s.add(new P(position[0], position[1], position[0], position[1] - 1));
                    s.add(new P(position[0], position[1] - 1, position[0], position[1]));
                    position[1]--;
                }
            } else if (dirs.charAt(i) == 'R') {
                if (position[0] + 1 <= MAX) {
                    s.add(new P(position[0], position[1], position[0] + 1, position[1]));
                    s.add(new P(position[0] + 1, position[1], position[0], position[1]));
                    position[0]++;
                }
            } else if (dirs.charAt(i) == 'L') {
                if (position[0] - 1 >= -MAX) {
                    s.add(new P(position[0], position[1], position[0] - 1, position[1]));
                    s.add(new P(position[0] - 1, position[1], position[0], position[1]));
                    position[0]--;
                }
            }
        }

        System.out.println(s.size());
        answer = s.size() / 2;
        return answer;
    }
}
