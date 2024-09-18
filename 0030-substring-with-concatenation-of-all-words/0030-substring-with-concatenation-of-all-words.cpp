class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Result vector to store starting indices
        vector<int> result;
        
        // Edge case: if s is empty or words is empty
        if (s.empty() || words.empty()) return result;
        
        // Length of each word and total length of concatenated words
        int wordLength = words[0].length();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;
        
        // Map to store the frequency of words
        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }
        
        // Loop over all possible start positions
        for (int i = 0; i < wordLength; i++) {
            int left = i;  // Left boundary of the window
            int right = i; // Right boundary of the window
            unordered_map<string, int> seen; // Map to track seen words in current window
            int count = 0; // Count of valid words in the current window

            // Slide the window by word lengths
            while (right + wordLength <= s.length()) {
                // Get the word from the right end of the window
                string word = s.substr(right, wordLength);
                right += wordLength; // Move right boundary
                
                // Check if the word is part of the words list
                if (wordMap.find(word) != wordMap.end()) {
                    seen[word]++;
                    count++;
                    
                    // If word is seen too many times, move the left boundary
                    while (seen[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seen[leftWord]--;
                        count--;
                        left += wordLength; // Move left boundary
                    }
                    
                    // If all words matched, store the starting index
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // If the word is not part of words, reset and move left pointer to right
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};
