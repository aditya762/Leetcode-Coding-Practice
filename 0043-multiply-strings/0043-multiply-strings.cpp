class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);
        
        // Perform multiplication digit by digit
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Convert result vector into string
        string product;
        for (int num : result) {
            if (!(product.empty() && num == 0)) { // Skip leading zeros
                product.push_back(num + '0');
            }
        }
        
        return product.empty() ? "0" : product; // Handle edge case where product is "0"
    }
};
