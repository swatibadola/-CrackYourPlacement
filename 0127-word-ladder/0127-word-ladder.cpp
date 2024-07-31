class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord))
            return 0;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == endWord) return steps;
            for(int i=0; i<word.length(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(word == endWord)
                        return steps+1;
                    if(st.count(word)){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};