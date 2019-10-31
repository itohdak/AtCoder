import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int K = sc.nextInt();
        int ans = 1;
        for(int i=0; i<N; i++) {
            if(i == 0) ans *= K;
            else ans *= K-1;
        }
        System.out.println(ans);
    }
}
