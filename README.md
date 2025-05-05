# SmartCode Workshop 自动推荐系统示例应用（C++版）

## 概述

在此示例项目中，你将使用C++开发一个应用程序，该应用程序使用字典自动完成单词并提供拼写建议。你将使用一个预先准备好的项目代码库，其中包含字典树（trie）数据结构的一些初始代码和常用操作。

## 项目背景

作为一名资深的开发人员，你刚刚接手了这个叫做自动推荐系统（auto-suggestion）的项目。这个项目的特性包括通过存储一个大量单词的词库，实现快速搜索与给定前缀匹配的字词，以提供自动完成功能。另外，这个项目还支持对拼写错误的单词实施拼写建议。

你已经拿到了一个使用字典树（trie）数据结构的现有代码库，该结构是一种基于树的数据结构，对于前缀匹配和自动完成非常有用。你需要快速熟悉这个代码库并对其进行扩展才能满足项目组对于自动推荐系统的需求。

## 有关字典树（trie）数据结构

在计算机科学中，trie，又称前缀树或字典树，是一种有序树，用于保存关联数组，其中的键通常是字符串。与二叉查找树不同，键不是直接保存在节点中，而是由节点在树中的位置决定。一个节点的所有子孙都有相同的前缀，也就是这个节点对应的字符串，而根节点对应空字符串。一般情况下，不是所有的节点都有对应的值，只有叶子节点和部分内部节点所对应的键才有相关的值。

![](trie.png)

## 环境需求

你需要准备以下环境以便可以顺利的完成此项目：
- Windows 10/11 或者 MacOS
- Git 2.45 以上版本
- C++17 兼容的编译器（如g++/clang++）
- CMake 3.10 以上版本（可选）
- 对C++编程语言的基本了解

## 构建与运行

### 使用CMake构建
```bash
mkdir build && cd build
cmake ..
make
./auto_suggest
```

### 运行单元测试
```bash
# 确保已安装Google Test框架
brew install googletest

# 构建并运行测试
cd build
cmake -DCMAKE_PREFIX_PATH=/usr/local/opt/googletest ..
make
./trie_tests
```

### 直接编译
```bash
clang++ -std=c++17 -Iinclude src/*.cpp -o auto_suggest
./auto_suggest
```

## 功能说明

1. **单词插入**：将单词插入Trie树
2. **前缀自动补全**：输入前缀获取匹配的单词列表
3. **拼写建议**：基于编辑距离(≤2)提供拼写建议
4. **Trie可视化**：打印Trie树结构

## 项目结构
```
auto-suggest-cpp/
├── include/
│   ├── trie.hpp
│   └── trie_node.hpp
├── src/
│   ├── trie.cpp
│   ├── main.cpp
│   └── tests/
│       └── trie_tests.cpp
├── CMakeLists.txt
└── README.md
```

## 联系我们

如果您在使用过程中遇到任何问题，或者您有任何建议和反馈，请随时联系我们。您可以通过以下方式联系我们：

- 网址 https://leansoftx.com
- 电子邮件 info@leansoftx.com
- 微信公众号 DevOps
