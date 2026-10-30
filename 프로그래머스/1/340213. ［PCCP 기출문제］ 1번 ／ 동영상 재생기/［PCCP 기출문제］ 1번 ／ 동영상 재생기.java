class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        int st = 0;
        int en = toMinute(video_len);
        
        int opSt = toMinute(op_start);
        int opEn = toMinute(op_end);
        int cur = escapeOp(toMinute(pos),opSt,opEn);
        
            
        for( String com :  commands){
            
            if("next".equals(com)){
                cur = Math.min(en, cur+10);
            }
            else if("prev".equals(com)){
                cur = Math.max(st, cur-10);
            }
            cur=escapeOp(cur, opSt,opEn);

        }
        
        
        return toTime(cur);
    }
    
    int escapeOp(int cur, int opSt, int opEn){
        if(cur >= opSt && cur <=opEn)
            cur =opEn;
        return cur;
    }
    
    int toMinute(String time){
        String [] t = time.split(":");
        int h=  Integer.parseInt(t[0]);
        int m=  Integer.parseInt(t[1]);

        return h*60+m;
    }
                               
    String toTime(int t){
        String h = t/60/10 > 0 ? String.valueOf(t/60) : "0"+String.valueOf(t/60);
        String m = t%60/10 > 0 ? String.valueOf(t%60) : "0"+String.valueOf(t%60);
        return h+":"+m;
    }
}