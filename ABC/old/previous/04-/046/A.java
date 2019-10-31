import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int a = sc.nextInt();
        final int b = sc.nextInt();
        final int c = sc.nextInt();
        Set<Integer> se = new HashSet<Integer>();
        se.add(a);
        se.add(b);
        se.add(c);
        System.out.println(se.size());
    }
}
