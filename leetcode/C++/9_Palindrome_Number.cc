class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        string str = to_string(x);
        int Len = str.length();
        
        for (int i = 0; i < Len / 2; ++i) {
            if (str[i] != str[Len - 1 - i])
                return false;
        }
    
        return true;
    }
};