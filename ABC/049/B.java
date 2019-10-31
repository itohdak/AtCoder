import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int H = sc.nextInt();
        final int W = sc.nextInt();
        String[] C = new String[H];
        for(int i=0; i<H; i++) {
            C[i] = sc.next();
        }
        for(int i=0; i<H; i++) {
            for(int j=0; j<2; j++) {
                System.out.println(C[i]);
            }
        }
    }
}
