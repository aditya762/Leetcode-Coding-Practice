class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int index = 0;

        while (index < words.size()) {
            int totalChars = words[index].length();
            int last = index + 1;

            // Determine the last word that can fit in the current line
            while (last < words.size()) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length();
                last++;
            }

            string line;
            int gapCount = last - index - 1;

            // Check if the line is the last line or has only one word
            if (last == words.size() || gapCount == 0) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' '); // Fill the remaining spaces
            } else {
                int spaces = (maxWidth - totalChars) / gapCount;
                int extraSpaces = (maxWidth - totalChars) % gapCount;

                for (int i = index; i < last - 1; i++) {
                    line += words[i];
                    line += string(spaces + 1, ' '); // Add the minimum space
                    if (extraSpaces > 0) { // Add an extra space if needed
                        line += " ";
                        extraSpaces--;
                    }
                }
                line += words[last - 1]; // Append the last word
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};
