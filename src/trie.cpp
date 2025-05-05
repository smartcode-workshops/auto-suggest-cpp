#include "trie.hpp"
#include <algorithm>
#include <iostream>

bool Trie::insert(const std::string& word) {
    auto current = root;
    for (char c : word) {
        if (!current->hasChild(c)) {
            current->children[c] = std::make_shared<TrieNode>(c);
        }
        current = current->children[c];
    }
    if (current->isEndOfWord) {
        return false;
    }
    current->isEndOfWord = true;
    return true;
}

std::vector<std::string> Trie::getSpellingSuggestions(const std::string& word) const {
    if (word.empty()) {
        return {};
    }

    char firstLetter = word[0];
    std::vector<std::string> suggestions;
    
    if (!root->hasChild(firstLetter)) {
        return suggestions;
    }

    auto firstNode = root->children.at(firstLetter);
    std::vector<std::string> words = getAllWordsWithPrefix(
        firstNode, std::string(1, firstLetter));

    for (const auto& w : words) {
        int distance = levenshteinDistance(word, w);
        if (distance <= 2) {
            suggestions.push_back(w);
        }
    }

    return suggestions;
}

int Trie::levenshteinDistance(const std::string& s, const std::string& t) {
    int m = s.length();
    int n = t.length();
    
    if (m == 0) return n;
    if (n == 0) return m;

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (s[i-1] == t[j-1]) ? 0 : 1;
            dp[i][j] = std::min({
                dp[i-1][j] + 1,
                dp[i][j-1] + 1,
                dp[i-1][j-1] + cost
            });
        }
    }

    return dp[m][n];
}

std::vector<std::string> Trie::autoSuggest(const std::string& prefix) const {
    auto currentNode = root;
    for (char c : prefix) {
        if (!currentNode->hasChild(c)) {
            return {};
        }
        currentNode = currentNode->children[c];
    }
    return getAllWordsWithPrefix(currentNode, prefix);
}

std::vector<std::string> Trie::getAllWordsWithPrefix(
    const std::shared_ptr<TrieNode>& node, 
    const std::string& prefix) const {
    
    std::vector<std::string> words;
    if (node->isEndOfWord) {
        words.push_back(prefix);
    }

    for (const auto& pair : node->children) {
        char c = pair.first;
        auto childWords = getAllWordsWithPrefix(pair.second, prefix + c);
        words.insert(words.end(), childWords.begin(), childWords.end());
    }

    return words;
}

std::vector<std::string> Trie::getAllWords() const {
    return getAllWordsWithPrefix(root, "");
}

void Trie::printTrieStructure() const {
    std::cout << "\nroot" << std::endl;
    printTrieNodes(root, " ", true);
}

void Trie::printTrieNodes(const std::shared_ptr<TrieNode>& node, 
                         const std::string& prefix, 
                         bool isLastChild) const {
    if (!node) {
        return;
    }

    std::cout << prefix;

    if (isLastChild) {
        std::cout << "└─";
    } else {
        std::cout << "├─";
    }

    std::cout << node->value << std::endl;

    std::vector<std::pair<char, std::shared_ptr<TrieNode>>> children(
        node->children.begin(), node->children.end());
    
    std::sort(children.begin(), children.end(), 
        [](const auto& a, const auto& b) { return a.first < b.first; });

    for (size_t i = 0; i < children.size(); ++i) {
        bool isLast = (i == children.size() - 1);
        std::string newPrefix = prefix + (isLastChild ? "  " : "│ ");
        printTrieNodes(children[i].second, newPrefix, isLast);
    }
}
