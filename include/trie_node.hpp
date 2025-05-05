#pragma once
#include <unordered_map>
#include <memory>

class TrieNode {
public:
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;
    bool isEndOfWord;
    char value;

    TrieNode() : isEndOfWord(false), value(' ') {}
    explicit TrieNode(char val) : isEndOfWord(false), value(val) {}

    bool hasChild(char c) const {
        return children.find(c) != children.end();
    }
};
