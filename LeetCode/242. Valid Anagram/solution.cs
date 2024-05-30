/*
Runtime
52
ms
Beats
92.32%
of users with C#
Memory
41.94
MB
Beats
80.87%
of users with C#
*/
public class Solution {
    public bool IsAnagram(string s, string t) {
        int len = s.Length;
        if(len != t.Length) return false;

        int[] azArr = new int[26];
        for(int i = 0; i < len; i++){
            azArr[s[i] - 'a']++;
            azArr[t[i] - 'a']--;
        }

        if(len > 26){
            for(int i = 0; i < 26; i++){
                if(azArr[i] != 0) 
                    return false;
            }
        }else{
            for(int i = 0; i < len; i++){
                if(azArr[t[i] - 'a'] != 0)
                    return false;
            }
        }
        
        return true;
    }
}








public class Solution {
    public bool IsAnagram(string s, string t) {
        Dictionary<char, int> dict = new();

        if(s.Length != t.Length) 
            return false;

        for(int i = 0; i < t.Length; i++){
            if(dict.ContainsKey(t[i])){
                dict[t[i]]++;
            }else{
                dict.Add(t[i], 1);
            }
        }

        for(int i = 0; i < s.Length; i++){
            if(dict.ContainsKey(s[i])){
                if(dict[s[i]]-- == 0){
                    return false;
                }
            }else{
                return false;
            }
        }

        return true;
    }
}