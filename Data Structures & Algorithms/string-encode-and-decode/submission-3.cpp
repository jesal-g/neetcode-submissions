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
            res += (std::move(str));
        }

        return res;
    }

    vector<string> decode(string s) {
        size_t num_strings;
        std::vector<size_t> str_lens;

        // extract total str count
        int p = 0;
        while (s[p] != '#') p++;
        num_strings = static_cast<size_t>(std::stoi(s.substr(0, p)));

        while (num_strings > 0) {
            std::string curr_str_len;
            p++;
            while (s[p] != '#') {
                curr_str_len += s[p];
                p++;
            }
            str_lens.push_back(static_cast<size_t>(std::stoi(curr_str_len)));
            num_strings--;
        }

        std::vector<std::string> res;
        p++;
        for (auto sz : str_lens) {
            res.push_back(s.substr(p, sz));
            p += sz;
        }
        return res;
    }
};
