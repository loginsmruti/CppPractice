class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        auto it = std::remove(nums.begin(), nums.end(),0);
        
        for(auto itr =it ; it != nums.end() ; it++){
            *it = 0;
        }
        
        /*
        size_t len = nums.size();
        size_t idx = 0;
        for(size_t i =0; i<len; i++ ){
            if(nums[i] != 0)
                nums[idx++] = nums[i];
        }
        for(size_t i = idx; i<len; i++){
            nums[i] = 0;
        }
        */
    }
};