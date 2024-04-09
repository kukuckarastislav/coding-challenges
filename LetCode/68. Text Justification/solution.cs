public class Solution {
    public IList<string> FullJustify(string[] words, int maxWidth) {
        List<string> lines = new List<string>();
        
        int n = words.Length;
        int i = 0;
        int j = 0;

        int charsCount = 0;
        while(j < n){
            charsCount += words[j].Length;
            if(charsCount < maxWidth){
                charsCount++; //for space
                if(j == n-1){
                    string line = "";
                    while(i <= j){
                        line += words[i];
                        if(i < j)
                            line += ' ';
                        i++;
                    }
                    while(line.Length < maxWidth) line += ' ';
                    charsCount = 0;
                    lines.Add(line);
                }
            }else if(charsCount == maxWidth){
                string line = "";
                while(i <= j){
                    line += words[i];
                    if(i < j)
                        line += ' ';
                    i++;
                }
                charsCount = 0;
                lines.Add(line);
            }else{
                string line = "";
                j--;

                int onlyCharsCount = 0;
                for(int k = i; k <= j; k++) {
                    onlyCharsCount += words[k].Length;
                }
                
                int blankSpaces = j-i;
                int spaces = maxWidth - onlyCharsCount;
                int spacesPerBlankSpace = 0;
                int reminder = 0;
                if(blankSpaces != 0){
                    spacesPerBlankSpace = spaces / blankSpaces;
                    reminder = spaces % blankSpaces;
                }
                
                for(int k = i; k <= j; k++){
                    line += words[k];
                    if(k == j) break;
                    for(int s = 0; s < spacesPerBlankSpace; s++){
                        line += ' ';
                    }
                    if(reminder > 0){
                        line += ' ';
                        reminder--;
                    }
                }
                
                while(line.Length < maxWidth) line += ' ';


                lines.Add(line);
                charsCount = 0;
                i = j;
                i++;
            }

            j++;
        }
        
        return lines;
    }
}
