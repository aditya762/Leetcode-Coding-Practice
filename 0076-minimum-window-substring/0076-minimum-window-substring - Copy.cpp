class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> dict_t;
        for (char c : t) dict_t[c]++;

        int required = dict_t.size();
        int l = 0, r = 0;
        int formed = 0;
        unordered_map<char, int> window_counts;

        int min_length = numeric_limits<int>::max();
        pair<int, int> min_window = {0, 0};

        while (r < s.length()) {
            char c = s[r];
            window_counts[c]++;

            if (dict_t.count(c) && window_counts[c] == dict_t[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                c = s[l];

                if (r - l + 1 < min_length) {
                    min_length = r - l + 1;
                    min_window = {l, r + 1};
                }

                window_counts[c]--;
                if (dict_t.count(c) && window_counts[c] < dict_t[c]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return min_length == numeric_limits<int>::max() ? "" : s.substr(min_window.first, min_window.second - min_window.first);
    }
};