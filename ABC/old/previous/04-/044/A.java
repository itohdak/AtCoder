import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int K = sc.nextInt();
        final int X = sc.nextInt();
        final int Y = sc.nextInt();
        if(N < K) {
            System.out.println(X * N);
        } else {
            System.out.println(X * K + Y * (N - K));
        }
    }
}

