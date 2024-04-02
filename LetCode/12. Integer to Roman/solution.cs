
public class Solution {
    public string IntToRoman(int num) {
        string romanStr = "";
        string[,] romanChars = {
            {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"M", "MM", "MMM", "", "", "", "", "", ""}
        };

        for(int i = 3; i >= 0; i--){
            int d = (int)(num / Math.Pow(10, i)) % 10;
            if(d > 0)
                romanStr += romanChars[i, d-1];
        }

       
        return romanStr;
        
    }

}

public class Solution {
    public string IntToRoman(int num) {
        string romanStr = "";
        int d = 0;

        if(num >= 1000){
            d = num / 1000;
            switch(d){
                case 1: romanStr += "M"; break;
                case 2: romanStr += "MM"; break;
                case 3: romanStr += "MMM"; break;
            }
        }
        
        if(num >= 100){
            d = (num / 100) % 10;
            switch(d){
                case 1: romanStr += "C"; break;
                case 2: romanStr += "CC"; break;
                case 3: romanStr += "CCC"; break;
                case 4: romanStr += "CD"; break;
                case 5: romanStr += "D"; break;
                case 6: romanStr += "DC"; break;
                case 7: romanStr += "DCC"; break;
                case 8: romanStr += "DCCC"; break;
                case 9: romanStr += "CM"; break;
            }
        }
        
        if(num >= 10){
            d = (num / 10) % 10;
            switch(d){
                case 1: romanStr += "X"; break;
                case 2: romanStr += "XX"; break;
                case 3: romanStr += "XXX"; break;
                case 4: romanStr += "XL"; break;
                case 5: romanStr += "L"; break;
                case 6: romanStr += "LX"; break;
                case 7: romanStr += "LXX"; break;
                case 8: romanStr += "LXXX"; break;
                case 9: romanStr += "XC"; break;
            }
        }

        if(num > 0){
            d = num % 10;
            switch(d){
                case 1: romanStr += "I"; break;
                case 2: romanStr += "II"; break;
                case 3: romanStr += "III"; break;
                case 4: romanStr += "IV"; break;
                case 5: romanStr += "V"; break;
                case 6: romanStr += "VI"; break;
                case 7: romanStr += "VII"; break;
                case 8: romanStr += "VIII"; break;
                case 9: romanStr += "IX"; break;
            }
        }

        return romanStr;
        
    }

}

public class Solution {
    public string IntToRoman(int num) {
        int i = 1;
        string romanStr = "";
        
        while(num > 0){
            int d = num % 10;

            if(i == 1)      romanStr += intToRomanChar(d, 'I', 'V', 'X');
            else if(i == 2) romanStr += intToRomanChar(d, 'X', 'L', 'C');
            else if(i == 3) romanStr += intToRomanChar(d, 'C', 'D', 'M');
            else if(i == 4) romanStr += intToRomanChar(d, 'M', '_', '_');
            
            num /= 10;
            i++;
        }

        return Reverse(romanStr);
    }

    private string Reverse(string s){
        char[] charArray = s.ToCharArray();
        Array.Reverse(charArray);
        return new string(charArray);
    }

    private string intToRomanChar(int x, char c1, char c2, char c3){
        string r = "";
        switch(x){
            case 1: r += ""+c1; break;
            case 2: r += ""+c1+c1; break;
            case 3: r += ""+c1+c1+c1; break;
            case 4: r += ""+c2+c1; break;
            case 5: r += ""+c2; break;
            case 6: r += ""+c1+c2; break;
            case 7: r += ""+c1+c1+c2; break;
            case 8: r += ""+c1+c1+c1+c2; break;
            case 9: r += ""+c3+c1; break;
        }
        return r;
    }
}