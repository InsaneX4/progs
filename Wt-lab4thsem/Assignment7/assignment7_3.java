import java.util.*;

class assignment7_3{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        ArrayList arr = new ArrayList<>();
        System.out.println("Enter the number of integers");
        int n = s.nextInt();
        for(int i=0;i<n;i++){
            arr.add(s.nextInt());
        }
        Collections.sort(arr);

        for(int i=0;i<n;i++){
            System.out.println(arr.get(i));
        }
    }
}