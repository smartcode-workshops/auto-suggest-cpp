#include "trie.hpp"
#include <iostream>
#include <vector>
#include <string>

const std::vector<std::string> words = {
    "as", "astronaut", "asteroid", "are", "around",
    "cat", "cars", "cares", "careful", "carefully",
    "for", "follows", "forgot", "from", "front",
    "mellow", "mean", "money", "monday", "monster",
    "place", "plan", "planet", "planets", "plans",
    "the", "their", "they", "there", "towards"
};

Trie initializeTrie(const std::vector<std::string>& words) {
    Trie trie;
    for (const auto& word : words) {
        trie.insert(word);
    }
    return trie;
}

void printTrie(const Trie& trie) {
    std::cout << "The dictionary contains the following words:\n";
    auto allWords = trie.getAllWords();
    for (const auto& word : allWords) {
        std::cout << word << ", ";
    }
    std::cout << "\n";
}

void searchWord(Trie& dictionary) {
    printTrie(dictionary);
    std::cout << "Enter a word to search for, or press Enter to exit.\n";
    std::string input;
    while (std::getline(std::cin, input) && !input.empty()) {
        auto suggestions = dictionary.getSpellingSuggestions(input);
        if (!suggestions.empty()) {
            std::cout << "Did you mean:\n";
            for (const auto& word : suggestions) {
                std::cout << word << "\n";
            }
        } else {
            std::cout << "No suggestions found for \"" << input << "\"\n";
        }
    }
}

void prefixAutoComplete(Trie& dictionary) {
    printTrie(dictionary);
    std::cout << "Enter a prefix to search for:\n";
    std::string prefix;
    while (std::getline(std::cin, prefix) && !prefix.empty()) {
        auto suggestions = dictionary.autoSuggest(prefix);
        if (!suggestions.empty()) {
            std::cout << "Suggestions for \"" << prefix << "\":\n";
            for (const auto& word : suggestions) {
                std::cout << word << "\n";
            }
        } else {
            std::cout << "No words found with prefix \"" << prefix << "\"\n";
        }
    }
}

int main() {
    Trie dictionary = initializeTrie(words);
    dictionary.printTrieStructure();

    while (true) {
        std::cout << "\nMenu:\n"
                  << "1. Search word\n"
                  << "2. Prefix auto-complete\n"
                  << "3. Exit\n"
                  << "Enter choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline

        switch (choice) {
            case 1:
                searchWord(dictionary);
                break;
            case 2:
                prefixAutoComplete(dictionary);
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice\n";
        }
    }
}
