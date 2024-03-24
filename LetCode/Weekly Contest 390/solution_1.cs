public class Solution {
    public int MaximumLengthSubstring(string s) {
        
        int maxLengthPossible = 0;
        Dictionary<char, int> dict = new();
        
        int i = 0;
        int j = 0;
        
        while(j < s.Length){
            //Console.WriteLine("Current substring: "+s.Substring(i,j-i+1));
            
            if(dict.ContainsKey(s[j])){
                dict[s[j]] += 1;
                //Console.WriteLine("Inc char:"+s[j]+" now are:"+dict[s[j]]);
                
                if(dict[s[j]] > 2){
                    while(dict[s[j]] > 2){
                        //Console.WriteLine("i++; deleting char:"+s[i]);
                        dict[s[i]] -= 1;
                        i++;
                    }
                }
            }else{
                //Console.WriteLine("First time added char:"+s[j]);
                dict.Add(s[j], 1);
            }
            
            if( (j-i+1) > maxLengthPossible ){
                maxLengthPossible = j - i + 1;
            }
            
            j++;
            
        }
        
        return maxLengthPossible;
        
        
    }
}