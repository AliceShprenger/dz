#pragma once
#include<string>
#include<vector>
#define ALPHABET_SIZE 26
// ��������� ���� ������
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, ���� ���� �������� ������ �����
	bool isEndOfWord;
};
void insert(TrieNode* root, std::string key);
TrieNode* getNewNode();
std::vector<std::string>  search(struct TrieNode* root, std::string key);