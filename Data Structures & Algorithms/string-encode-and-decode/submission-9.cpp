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
        size_t num_strings;
        std::vector<size_t> str_sizes;
        size_t p = 0;
        std::string tmp;

        while (s[p] != '#') {
            tmp += s[p];
            p++;
        }
        num_strings = static_cast<size_t>(std::stoi(tmp));
        
        for (size_t i = 0; i < num_strings; ++i) {
            tmp = "";
            p++;
            while (s[p] != '#') {
                tmp += s[p];
                p++;
            }
            str_sizes.push_back(static_cast<size_t>(std::stoi(tmp)));
        }

        p++;
        for (size_t i = 0; i < num_strings; ++i) {
            res.push_back(s.substr(p, str_sizes[i]));
            p += str_sizes[i];
        }
        return res;
    }
};
