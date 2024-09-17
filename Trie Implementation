#include <bits/stdc++.h>
using namespace std;


struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch , Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
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
        Node* node = root; // dummy variable of root
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i]) == false){//if this character not in node then insert it
                node->put(word[i],new Node());
            }
            //move to next reference trie
            node = node->get(word[i]);//move to next reference
        }
        node->setEnd();
    }

    bool search(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i]) == false){
                return false; // this word does not exist
            }
            node = node->get(word[i]);//move to next reference
        }
        return node->isEnd(); // if end is true then word exist otherwise not
    }

    bool startsWith(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i]) == false){
                return false;
            }
            node = node->get(word[i]);//move to next reference
        }
        return true;
    }

};


void solveit() {

    Trie trie;

    trie.insert("arvind");
    trie.insert("prakash");
    trie.insert("deepak");
    trie.insert("sandhya");
    trie.insert("anand");
    trie.insert("naina");

    cout<<trie.search("arvind")<<endl; //true
    cout<<trie.search("goku")<<endl; //false
    cout<<trie.startsWith("nain")<<endl; //true
    cout<<trie.startsWith("arvindd")<<endl; //false


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
