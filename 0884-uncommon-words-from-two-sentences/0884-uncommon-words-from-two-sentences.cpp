class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> word_count;
        vector<string> result;
        string word;
        
        // Split both sentences and count occurrences
        stringstream ss(s1 + " " + s2);
        while (ss >> word) {
            word_count[word]++;
        }

        // Find the words that appear exactly once
        for (auto& entry : word_count) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};