class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.size();
        
        // Skip leading whitespaces
        while (i < n && isspace(s[i])) i++;
        
        // Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        
        bool isNumeric = false;
        
        // Check for digits before decimal point
        while (i < n && isdigit(s[i])) {
            isNumeric = true;
            i++;
        }
        
        // Check for decimal point
        if (i < n && s[i] == '.') {
            i++;
            // Check for digits after decimal point
            while (i < n && isdigit(s[i])) {
                isNumeric = true;
                i++;
            }
        }
        
        // Check for exponent
        if (isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            isNumeric = false; // Exponent must be followed by digits
            
            // Check for sign after exponent
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            
            // Check for digits after exponent
            while (i < n && isdigit(s[i])) {
                isNumeric = true;
                i++;
            }
        }
        
        // Skip trailing whitespaces
        while (i < n && isspace(s[i])) i++;
        
        // Return true if entire string is processed and isNumeric is true
        return isNumeric && i == n;
    }
};
