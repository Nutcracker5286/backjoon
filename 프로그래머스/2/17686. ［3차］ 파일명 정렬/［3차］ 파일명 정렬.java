import java.util.*;



class Solution {
    
    
    static class  FileInfo{
        String ori ;        
        String head ;
        int num;

        
    }
    
    public String[] solution(String[] files) {
        FileInfo [] infos = new FileInfo[files.length];
        
        for(int i=0; i<files.length; i++){
            infos[i] = parseFile(files[i]);
        }
        
        Arrays.sort(infos, (a,b) ->
                   {
                       int cmp = a.head.compareTo(b.head);
                    if(cmp!=0) return cmp; 
                       return Integer.compare(a.num,b.num);
                       
                   }
                  );
        String[] answer = new String[files.length];

        for (int i = 0; i < infos.length; i++) {
            answer[i] = infos[i].ori;
        }

        return answer;
    }
    
    
    public FileInfo parseFile(String s){
        int i=0 ,sn=0;
        FileInfo res  = new FileInfo();
        
        while(i < s.length() && !Character.isDigit(s.charAt(i))) i++;
        res.head = s.substring(0,i).toLowerCase();
        sn = i;
         while(i < s.length()&& Character.isDigit(s.charAt(i))) i++;
        res.num = Integer.parseInt(s.substring(sn,i));
        
        res.ori = s;
        return res;
        
        
    }
    
    
}