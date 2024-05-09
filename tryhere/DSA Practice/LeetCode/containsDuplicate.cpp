class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> intSet(nums.begin(), nums.end());
        if ( nums.size() == intSet.size())
            return false;
        
        return true;
    }
};