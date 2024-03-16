class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        ostringstream oss;
        string word;
        while (iss >> word) {
            reverse(word.begin(), word.end());
            oss << word << " ";
        }
        return oss.str().substr(
            0, oss.str().size() - 1);
        
    }
};