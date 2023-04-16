import java.util.* ;
//import java.io.*; 
public class Nextgreater {
    public static long bobsHomework(int n)
    {
        if(n> 0 && n < 100 && isrevsame(n) == n){
            return -1;
        } 
       /*  if(rearrange(n) == n){
            return -1;
        }*/
        //rearrange(n);
        
        return rearrange(n);
    }

    public static long isrevsame(int num){

        int reverse = 0;
        while(num != 0){
            reverse = reverse*10 + num%10;
            num = num/10; 
        }

        return reverse;
        
    }
    public static int rearrange(int n){

        HashMap<Integer,Integer> map = new HashMap<>();
        int temp = n;
        int e = 0;
        int first = 0;
        int firstkey = 0;
        int newnumber = 0;
        while(temp != 0){
            if(temp > 0 && temp < 9){
                first = temp;
                firstkey = e;
            }
            map.put(e, temp%10);
            temp = temp / 10;
            e++;
        }


        for(int i=0; i<map.size(); i++){
            if(firstkey != i && map.get(firstkey) == map.get(i)){
                first = map.get(i);
                //break;
            }
            else if(map.get(i) > first){
                first = map.get(i);
                //System.out.println(first);
                
            }else{
                continue;
            }
            newnumber = first;
        }
        
        for(int i=0; i<map.size(); i++){
            if(map.get(i) != first || map.get(i) < newnumber%10){
                newnumber = newnumber*10 + map.get(i);
            }
        }
        return newnumber;
    } 
    public static void main(String[] args) {
        int n = 252;
        System.out.println(bobsHomework(n));
    }
}
// 3 4 2
