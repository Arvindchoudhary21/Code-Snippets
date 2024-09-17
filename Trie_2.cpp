#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch , Node* node){
        links[ch - 'a'] = node;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;//for delete the word
    }
    void deletePrefix(){
        cntPrefix--; //for delete the word
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
private:
    Node* root;
public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(node->containsKey(word[i]) == false){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i]) == false){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i]) == false){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->deletePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
};


void solveit() {

    Trie trie;

    trie.insert("arvind");
    trie.insert("arvind");
    trie.insert("prakash");
    trie.insert("deepak");
    trie.insert("sandhya");
    trie.insert("anand");
    trie.insert("naina");

    cout<<trie.countWordsEqualTo("arvind")<<endl;
    cout<<trie.countWordsStartingWith("arvin")<<endl;
    cout<<trie.countWordsStartingWith("arvin")<<endl;
    trie.erase("arvind");
    trie.erase("arvind");
    cout<<trie.countWordsEqualTo("arvind")<<endl;
    cout<<trie.countWordsStartingWith("arvin")<<endl;
    


}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    clock_t z = clock();
    int t = 1;
    while (t--) solveit();
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}
