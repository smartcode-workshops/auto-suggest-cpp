#include "trie.hpp"
#include <gtest/gtest.h>

class TrieTest : public ::testing::Test {
protected:
    void SetUp() override {
        trie = std::make_unique<Trie>();
    }

    std::unique_ptr<Trie> trie;
};

TEST_F(TrieTest, InsertNewWord) {
    EXPECT_TRUE(trie->insert("hello"));
    EXPECT_TRUE(trie->insert("world"));
}

TEST_F(TrieTest, InsertDuplicateWord) {
    EXPECT_TRUE(trie->insert("hello"));
    EXPECT_FALSE(trie->insert("hello"));
}

TEST_F(TrieTest, InsertEmptyString) {
    EXPECT_TRUE(trie->insert(""));
    EXPECT_FALSE(trie->insert(""));
}

TEST_F(TrieTest, InsertSpecialCharacters) {
    EXPECT_TRUE(trie->insert("hello!"));
    EXPECT_TRUE(trie->insert("world@"));
}

TEST_F(TrieTest, CaseSensitiveInsert) {
    EXPECT_TRUE(trie->insert("Hello"));
    EXPECT_TRUE(trie->insert("hello"));  // 视为不同单词
}
