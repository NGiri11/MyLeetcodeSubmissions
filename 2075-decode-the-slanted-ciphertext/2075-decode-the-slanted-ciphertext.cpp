class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        int n = encodedText.size();
        int cols = n / rows;
        vector<vector<char>> grid(rows, vector<char>(cols));
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = encodedText[idx++];
            }
        }
        string result;
        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;
            while (i < rows && j < cols) {
                result += grid[i][j];
                i++;
                j++;
            }
        }
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};