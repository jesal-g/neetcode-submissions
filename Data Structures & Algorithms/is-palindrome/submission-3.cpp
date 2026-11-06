class Solution {
public:
    bool isPalindrome(string s) {
        size_t lp = 0;
        size_t rp = s.size() - 1;

        while (lp < rp) {
            while (lp < rp && !std::isalnum(static_cast<unsigned char>(s[lp]))) lp++;
            while (lp < rp && !std::isalnum(static_cast<unsigned char>(s[rp]))) rp--;
            if (lp < rp && std::tolower(static_cast<unsigned char>(s[lp])) !=
                std::tolower(static_cast<unsigned char>(s[rp]))) {
                    return false;
                }
            lp++;
            if (rp > 0) rp--;
        }
        return true;
    }
};