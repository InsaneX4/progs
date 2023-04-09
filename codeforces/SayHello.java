
import java.util.Scanner;

public class SayHello {
    public static void main() {
        try (Scanner s = new Scanner(System.in)) {
            System.out.println("Hello, "+ s.nextLine());
        }
    }
}
