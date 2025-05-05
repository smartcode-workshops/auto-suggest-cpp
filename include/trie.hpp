#pragma once
#include "trie_node.hpp"
#include <vector>
#include <string>
#include <memory>

class Trie {
private:
    std::shared_ptr<TrieNode> root;

    void printTrieNodes(const std::shared_ptr<TrieNode>& node, 
                       const std::string& prefix, 
                       bool isLastChild) const;
    
    std::vector<std::string> getAllWordsWithPrefix(
        const std::shared_ptr<TrieNode>& node, 
        const std::string& prefix) const;

    static int levenshteinDistance(const std::string& s, 
                                 const std::string& t);

public:
    Trie() : root(std::make_shared<TrieNode>()) {}

    bool insert(const std::string& word);
    
    std::vector<std::string> autoSuggest(const std::string& prefix) const;
    
    std::vector<std::string> getAllWords() const;
    
    void printTrieStructure() const;
    
    std::vector<std::string> getSpellingSuggestions(const std::string& word) const;
};
