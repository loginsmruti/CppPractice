#define to_lower(c) (c | (1<<5))
class Solution {
public:
    string toLowerCase(string s) {
        for (auto &character :s) {
            if(character >= 'A' && character <= 'Z')
                character = to_lower(character);
        }
        return s;
    }
};