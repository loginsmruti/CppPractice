class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) 
    {
        std::vector<int> selfDividingNum;
        for(size_t i = left; i <= right; ++i) {
            size_t num = i;
            bool flag = true;
            while(num > 0)
            {
                size_t dig = num % 10;
                if ( dig == 0 || i % dig != 0) {
                    flag = false;
                    break;
                }
                num /= 10;
            }
            if (flag) {
                selfDividingNum.push_back(i);
            }
        }
        return selfDividingNum;
    }
};