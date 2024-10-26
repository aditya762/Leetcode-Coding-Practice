class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [currentWord, length] = q.front();
            q.pop();

            if (currentWord == endWord) return length;

            for (int i = 0; i < currentWord.size(); ++i) {
                char originalChar = currentWord[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    currentWord[i] = c;
                    if (wordSet.find(currentWord) != wordSet.end()) {
                        wordSet.erase(currentWord);
                        q.push({currentWord, length + 1});
                    }
                }
                currentWord[i] = originalChar;
            }
        }

        return 0;
    }
};
