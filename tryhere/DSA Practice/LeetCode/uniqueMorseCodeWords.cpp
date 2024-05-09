class Solution {
public:
    string wordToMorse(string word) 
    {
        string morseCode [26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string morse = "";
        for (char c : word) {
            morse += morseCode[c - 'a'];
        }
        return morse;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        for (string word : words) {
            st.insert(wordToMorse(word));
        }
        return st.size();
    }
};