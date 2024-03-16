class Solution {
public:
    int findNumbers(vector<int>& nums) {
        size_t evenNos = 0;
        if (nums.size() >= 1 && nums.size() <= 500) {
            for (auto& num : nums) {
                if (num >= 1 && num <= 100000) {
                    int noOfDigit = floor(log10(abs(num))) + 1;
                    if (noOfDigit % 2 == 0)
                        evenNos++;

                }
            }
        } else {
            return 0;
        }
        return evenNos;
    }
};