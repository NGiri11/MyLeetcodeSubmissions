class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for (int num : nums) {
            vector<int> temp;
            while (num) {
                temp.push_back(num % 10);
                num /= 10;
            }
            reverse(temp.begin(), temp.end());
            answer.insert(answer.end(), temp.begin(), temp.end());
        }
        return answer;
    }
};
