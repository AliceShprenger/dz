#include"Trie.h"
#include<queue>
#include<iostream>
using namespace std;
TrieNode* getNewNode()
{
    // ¬ыдел€ем пам€ть под новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым указателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void insert(TrieNode* root, string key)
{
    TrieNode* current = root;
    for (int i = 0; i < key.size(); i++)
    {
        if (current->children[((int)key[i]) - 97] == nullptr)
        {
            TrieNode* newnode = getNewNode();
            current->children[((int)key[i]) - 97] = newnode;
            current = newnode;
        }
        else current = current->children[((int)key[i]) - 97];
    }
    current->isEndOfWord = 1;
}

vector<string> search(struct TrieNode* root, string key)
{
    vector<string> words;
    TrieNode* node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return vector<string> (0);

        node = node->children[index];
    }
    if(node == nullptr) return vector<string>(0);
    queue<pair< TrieNode*, string>> Q;
    Q.push({ node,key });
    while (!Q.empty())
    {
        string strcur = Q.front().second;
        TrieNode* cur = Q.front().first;
        Q.pop();
        if (cur->isEndOfWord)words.push_back(strcur);
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (cur->children[i])
            {
                Q.push({ cur->children[i], strcur + (char)(97 + i) });
            }
        }
    }
    return words;
}