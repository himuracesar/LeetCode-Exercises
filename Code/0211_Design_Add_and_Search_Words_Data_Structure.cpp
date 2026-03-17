class WordDictionary {
public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        Trie* root = trie;
        for(auto i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            
            if(root->nodes[index] == nullptr)
                root->nodes[index] = new Trie();

            if(i == word.length()-1)
                root->nodes[index]->endWord = true;

            root = root->nodes[index];
        }
    }
    
    bool search(string word) {
        return search(trie, word, 0);
    }

private:
    const static int ALPHABET_SIZE = 26;

    struct Trie{
        Trie* nodes[ALPHABET_SIZE];
        bool endWord;

        Trie(){
            endWord = false;
            for(auto i = 0; i < ALPHABET_SIZE; i++)
                nodes[i] = nullptr;
        }
    };

    Trie* trie;

    bool search(Trie* root, string word, int index){
        if(index == word.length())
            return false;

        if(word[index] == '.'){
            for(auto i = 0; i < ALPHABET_SIZE; i++){
                if(root->nodes[i] != nullptr){
                    if(index == word.length()-1 && root->nodes[i]->endWord)
                        return true;
                    
                    if(search(root->nodes[i], word, index+1))
                        return true;
                }
            }
        } else {
            int inx = word[index] - 'a';
            if(root->nodes[inx] != nullptr){
                if(index == word.length()-1 && root->nodes[inx]->endWord)
                    return true;
                
                if(search(root->nodes[inx], word, index+1))
                    return true;
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */