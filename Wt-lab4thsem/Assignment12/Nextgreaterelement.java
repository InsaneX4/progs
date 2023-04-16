import java.util.Arrays;

public class Nextgreaterelement {
    public int NextGreaterElement(int n){
        char[] number = (n + "").toCharArray();

        int i,j;
        // I) Start from the right most digit and 
        // find the first digit that is
        // smaller than the digit next to it.
        for(i = number.length-1; i>0;i--){
            if(number[i-1] < number[i]){
                break;
            }
        }
         // If no such digit is found, its the edge case 1.
        if (i == 0)
        return -1;
           
         // II) Find the smallest digit on right side of (i-1)'th 
         // digit that is greater than number[i-1
        int x = number[i-1];
        int smaller = i;
        for(j = i+1 ;j < number.length;j++){
            if(number[j] > x && number[j] <= number[smaller]){
                smaller = j;
            }
        }    
        // III) Swap the above found smallest digit with 
        // number[i-1]
        char temp = number[i-1];
        number[i-1] = number[smaller];
        number[smaller] = temp;
        
        Arrays.sort(number, i,  number.length);
        long val = Long.parseLong(new String(number));
        return (val <= Integer.MAX_VALUE) ? (int) val : -1;

    }
    public static void main(String[] args) {
        Nextgreaterelement obj = new Nextgreaterelement();
        System.out.println( obj.NextGreaterElement(225));
    }
}
