import java.util.HashMap;

public class 스킬트리 {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        for (int i = 0; i < skill.length(); i++) {
            map.put(skill.charAt(i), i + 1);
        }

        for (int i = 0; i < skill_trees.length; i++) {
            int sequence = 1;
            for (int j = 0; j < skill_trees[i].length(); j++) {
                int cmp = 0;
                if (map.get(skill_trees[i].charAt(j)) != null) {
                    cmp = map.get(skill_trees[i].charAt(j));
                }
                if (cmp != 0 && cmp == sequence) {
                    sequence++;
                } else if (cmp != 0 && cmp != sequence) {
                    break;
                }
                if (j == skill_trees[i].length() - 1)
                    answer++;
            }
        }

        System.out.println(answer);
        return answer;
    }
}
