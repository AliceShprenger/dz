#include<iostream>
#include"Trie.h"
using namespace std;
int main() {
	TrieNode* root = getNewNode();
	size_t kolWords;
	cout << "Enter the number of words in the dictionary: " ;
	cin >> kolWords;
	cout << "Enter "<< kolWords <<" words into the dictionary: ";
	string word;
	for (size_t i = 0; i < kolWords; i++) {
		cin >> word;
		insert(root, word);
	}
	cout << "Dictionary is full" << "\n";

	string input;
	while (true) {
		cout << "Enter a word fragment or '-' to exit: ";
		cin >> input;
		if (input == "-") break;
		vector<string> L=search(root, input);
		cout<<"Auto-completion: "<< "\n";
		for (int i = 0; i < L.size(); i++) {
			cout << i+1<<") "<<L[i] << "\n";
		}
		cout << "Make a choice, 0 - leave everything as it was: ";
		int choice;
		cin >> choice;
		if (choice < 0 or choice >= L.size() + 1)cout << "Incorrect input" << "\n";
		else
		{
			if (choice == 0) cout << input << "\n";
			else cout << L[choice - 1] << "\n";
		}

	}
	return 0;
}