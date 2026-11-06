class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res;
        res += std::to_string(strs.size());
        res += '#';
        for (auto& str : strs) {
            res += std::to_string(str.size());
            res += '#';
        }
        for (auto& str : strs) {
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        std::vector<std::string> res;
        size_t str_count;
        std::vector<size_t> str_sizes;
        
        size_t p = 0;
        std::string str_count_;
        while (s[p] != '#') {
            str_count_ += s[p];
            p++;
        }
        p++;
        str_count = static_cast<size_t>(std::stoi(str_count_));

        for (size_t i = 0; i < str_count; i++) {
            std::string str_size_;
            while (s[p] != '#') {
                str_size_ += s[p];
                p++;
            }
            str_sizes.push_back(static_cast<size_t>(std::stoi(str_size_)));
            p++;
        }

        for (size_t i = 0; i < str_count; i++) {
            res.push_back(s.substr(p, str_sizes[i]));
            p += str_sizes[i];
        }
        return res;
    }
};
