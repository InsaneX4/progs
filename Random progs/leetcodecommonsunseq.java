import java.util.HashMap;

   

public class leetcodecommonsunseq
{
    
     public  int longestCommonSubsequence(String text1, String text2) {
        if(text1.equals(text2)){
            return text1.length();
        }
        
        int larger= text1.length()>text2.length() ? text1.length() : text2.length();
        int common=0;
        int smaller =0;
        HashMap<Character, Integer> map = new HashMap<>();
        if(text1.length() == larger){
            smaller = text2.length();
        for(int i = 0; i<text1.length();i++){
            map.put(text1.charAt(i), i);
        }
     }else{
        smaller = text1.length();
        for(int i = 0;i<text2.length();i++){
            map.put(text2.charAt(i), i);
        }
     }
        if(smaller == text2.length()){
        for(int i = 0;i<text2.length();i++){
            if(map.containsKey(text2.charAt(i))){
                common++;
            }
        }
        }else{
        for(int i = 0;i<text1.length();i++){
            if(map.containsKey(text1.charAt(i))){
                common++;
            }
        }
         }
        
        return common;
        }
 

	public static void main(String[] args) {
		leetcodecommonsunseq ob = new leetcodecommonsunseq();
		System.out.print(ob.longestCommonSubsequence("ezupkr","ubmrapg"));
	}
}