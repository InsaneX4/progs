public class assignment10_3 {

    public static void main(String[] args) {
        String somestring = "Hello";
        String somestring2 = "Bye";

        System.out.println(somestring);
        changecase(somestring);
        System.out.println();
        reversestring(somestring);
        System.out.println();
        comparestring(somestring,somestring2);
        insertanother(somestring,somestring2);
        System.out.println();
    }
private static void insertanother(String somestring, String somestring2) {
    
        somestring += somestring2.substring(0,somestring2.length());
        System.out.println(somestring);
    

}
    
    private static void comparestring(String somestring,String somestring2) {
        if(somestring.length() > somestring2.length()){
            System.out.println(somestring+"is larger");
        }else{
            System.out.println(somestring2+"is larger");
        }
    }

    private static void reversestring(String somestring2) {
        for(int i = 0; i < somestring2.length(); i++) {
            System.out.print(somestring2.charAt(somestring2.length()-i-1));
        }
    }

    private static void changecase(String somestring) {
            for(int i = 0; i < somestring.length(); i++){
                if(Character.isUpperCase(somestring.charAt(i)) == true) {
                    System.out.print(Character.toLowerCase(somestring.charAt(i)));
                    
                }else{
                
                   System.out.print(Character.toUpperCase(somestring.charAt(i)));
                   
               }

            }
            
    }

}
