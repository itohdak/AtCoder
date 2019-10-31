import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final String w = sc.next();
        Map<Character, Integer> alpha = new HashMap<>();
        for(int i=0; i<w.length(); i++) {
            char c = w.charAt(i);
            if(alpha.containsKey(c)) {
                alpha.put(c, alpha.get(c)+1);
            } else {
                alpha.put(c, 1);
            }
        }
        boolean ok = true;
        for(int val: alpha.values()) {
            if(val % 2 != 0) {
                ok = false;
                break;
            }
        }
        if(ok) System.out.println("Yes");
        else System.out.println("No");
    }
}

