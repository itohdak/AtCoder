import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final String c = sc.next();
        List<String> vowel = new ArrayList<String>(Arrays.asList("a", "e", "i", "o", "u"));
        if(vowel.contains(c)) {
            System.out.println("vowel");
        } else {
            System.out.println("consonant");
        }
    }
}
