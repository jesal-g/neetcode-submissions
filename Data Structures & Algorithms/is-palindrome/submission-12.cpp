class Solution {
public:
    bool isPalindrome(string s) {
        int lp = 0;
        int rp = static_cast<int>(s.size()) - 1;
        while (lp < rp) {
            while (lp < rp && 
                  !std::isalnum(static_cast<unsigned char>(s[lp]))) {
                lp++;
            }
            while (lp < rp && 
                  !std::isalnum(static_cast<unsigned char>(s[rp]))) {
                rp--;
            }
            if (std::tolower(s[lp]) != std::tolower(s[rp])) {
                return false;
            }
            lp++;
            rp--;
        }
        return true;
    }
};
