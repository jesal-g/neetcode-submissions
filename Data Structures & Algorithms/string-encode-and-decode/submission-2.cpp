class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res;
        for (auto& str : strs) {
            res += std::to_string(str.size());
            res.push_back(',');
        }
        res.push_back('#');
        for (auto& str : strs) {
            res += std::move(str);
        }
        return res;
    }

    vector<string> decode(string s) {
        std::vector<int> sizes;
        size_t curr_pointer = 0;
        while (s[curr_pointer] != '#') {
            if (std::isdigit(s[curr_pointer])) {
                std::string curr_sz {s[curr_pointer]};
                curr_pointer++;
                while (std::isdigit(s[curr_pointer]) && s[curr_pointer] != ',') {
                    curr_sz += s[curr_pointer];
                    curr_pointer++;
                }
                sizes.push_back(std::stoi(curr_sz));
            }
            curr_pointer++;
        }

        // curr_pointer is at delim #, so increment
        curr_pointer++;
        std::vector<string> res;
        for (int& size : sizes) {
            res.push_back(s.substr(curr_pointer, size));
            curr_pointer += size;
        }
        return res;
    }
};
