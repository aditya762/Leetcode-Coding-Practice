class Solution {
public:
    string intToRoman(int num) {
        // Define Roman numerals and their corresponding integer values
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string result = "";
        
        // Traverse through the roman numerals
        for (const auto& [value, symbol] : roman) {
            // Add the symbol while the number is greater or equal to the value
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};
