#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Node {
    public:
        Node () 
        { 
            mLetter = ' ';
            mTerminator = false;
        }

        ~Node () {}
        void setword (char c) {
            mLetter = c;
        }
        char getword () {
            return mLetter;
        }
        void setterminator () {
            mTerminator = true;
        }
        bool getterminator () {
            return mTerminator;
        }
        void appendChild(Node *child) {
            mchildren.push_back(child);
        }
        vector<Node*> getchildren () {
            return mchildren;
        }

        Node *findChild(char c);
        void printNode();
        void printBranch(Node *, char *, int count);
    private:
        char mLetter;
        bool mTerminator;
        vector<Node*> mchildren;
        int testing;

};

Node* Node::findChild(char c) {
    for(size_t i=0; i< mchildren.size() ; i++) {

        Node *ptr = mchildren.at(i);
        if(ptr->getword() == c) {
            return ptr;
        }
    }
    return NULL;
}

void Node::printBranch(Node *node, char *word, int count) {
    if(node->mLetter != ' ') {
        word[count++] = node->mLetter;
    }
    if(node->getterminator()){
        cout<<endl;
        for(int i=0; i<count; i++)
            cout<<word[i];
    }
    for(unsigned int i=0; i<(node->mchildren).size(); i++)
        printBranch((node->mchildren).at(i), word, count);
}

void Node::printNode() {
    char *word = new char[300];
    for(size_t i =0; i < mchildren.size(); i++)
    {
        Node *ptr = mchildren.at(i);
        printBranch(ptr, word, 0);
    }
}

class Trie {
    public:
        Trie();
        void addWord(string s);
        bool searchword(string s);
        void printTrie();
        void printBranch();
    private:
        Node *root;
};

void Trie::printTrie() {
    root->printNode();
}

Trie::Trie() {
    root = new Node;
}

void Trie::addWord(string s) {
    Node *current = root;

    if(s.length() == 0) {
        current->setterminator();
        return;
    }
    for(size_t i=0; i<s.length(); i++) {
        Node *child = current->findChild(s[i]);
        if(child != NULL) {
            current = child;
        }
        else {
            Node *ptr = new Node;
            ptr->setword(s[i]);
            current->appendChild(ptr);
            current = ptr;
        }
        if(i == s.length() -1)
            current->setterminator();
    }
}

bool Trie::searchword(string s) {
    Node *current = root;
    while(current != NULL) {
        for(size_t i=0; i<s.length(); i++) {
            Node *ptr = current->findChild(s[i]);
            if(ptr == NULL)
                return false;
            current = ptr;
        }
        if(current->getterminator())
            return true;
        else
            return false;
    }
    return false;
}

int main() {
    Trie *trie = new Trie();
    
    trie->addWord("cat");
    trie->addWord("cats");
    trie->addWord("catsdogcats");
    trie->addWord("catxdogcatsrat");
    trie->addWord("dog");
    trie->addWord("dogcatsdog");
    trie->addWord("hippopotamuses");
    trie->addWord("rat");
    trie->addWord("ratcatdogcat");

    if ( !trie->searchword("hippopotamus") )
        cout << "Not Found hippopotamus" << endl;

    if ( trie->searchword("catsdogcats") )
        cout << "Found catsdogcats" << endl;

    if ( trie->searchword("ratcatdogcat") )
        cout << "Found ratcatdogcat" << endl;

    trie->printTrie();
    return 0;
}

