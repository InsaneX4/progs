import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;

public class WinterSale {
    public static void main(String[] args) {
        final DecimalFormat decfor = new DecimalFormat("0.00");  
        try (Scanner s = new Scanner(System.in)) {
            double x = s.nextInt();
            double p = s.nextInt();

            double mp = (p*100)/(100-x);
            decfor.setRoundingMode(RoundingMode.UP);  
            System.out.println(decfor.format(mp));  
        }

    }
}
