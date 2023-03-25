public class assignment7_2 {
    public static void main(String[] args) {
        int Count_even = 0;
        int Count_odd = 0;
        int i = 0;
        for(String val: args){
            double a = Double.parseDouble(args[i]);
            i++;
            if(a%2 == 0){
                Count_even++;
            } else{
                Count_odd++;
            }
        }
        System.out.println("Even Count: "+ Count_even);
        System.out.println("Odd Count: "+ Count_odd);
    }
}
