class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st;

        for (string word : wordList)
            st.insert(word);

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        st.erase(beginWord);

        while (!q.empty()) {

            string word = q.front().first;
            int len = q.front().second;
            q.pop();

            

            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    

                    if (st.find(word) != st.end()) {
                        if(word==endWord) return len+1;
                        q.push({word, len + 1});
                        st.erase(word);
                    }
                }

                // restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};