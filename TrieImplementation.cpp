/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node
{
    private:
    Node* links[26];
    bool flag;
    
    public:
        Node()
        {
            flag=false;
            for(int i=0;i<26;i++) links[i]=NULL;
        }
    
    bool containkey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }

    bool isEnd()
    {
        return flag;
    }

    void setEnd()
    {
        flag=true;
    }

};
class Trie {
private:
    Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containkey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containkey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!node->containkey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
