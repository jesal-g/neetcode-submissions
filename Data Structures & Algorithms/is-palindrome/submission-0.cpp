class Solution {
public:
    bool isPalindrome(string s) {
        std::string stripped;
        for (auto& c : s) {
            if (std::isalnum(static_cast<unsigned char>(c))) {
                stripped += std::tolower(static_cast<unsigned char>(c));
            }
        }
        std::string reversed{stripped.rbegin(), stripped.rend()};
        return reversed == stripped;
    }
};
