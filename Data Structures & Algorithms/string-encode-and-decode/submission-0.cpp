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
            res += str;
        }
        std::cout <<res;
        return res;
    }

    vector<string> decode(string s) {
        std::vector<std::string> res;
        std::vector<int> sizes;
        int i = 0;
        int j;
        while (s[i] != '#') {
            j = i;
            std::string currSz;
            while (s[j] != ',') {
                currSz += s[j];
                j++;
            }
            sizes.push_back(std::stoi(currSz));
            i = j + 1;
        }

        // i is at # position, so increment it
        i++;
        for (int sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }

        return res;
    }
};
