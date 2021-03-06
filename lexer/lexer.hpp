#ifndef LEXER_HPP
#define LEXER_HPP

#include "trie.hpp"

#include <string>
#include <vector>

class Lexer
{
public:
	Lexer(const std::string& source);
	~Lexer();

	void advanceString();

	void advance();


public:
	Token scanToken();
	std::vector<Token> scanAll();

private:
	void addKeyword(const char* word, TokenType type);			// add word to trie
	bool checkKeyword(const char* string);		// check for word in trie

	char peekBehind();
	char peek();							// peek current char
	char peekNext();						// peek enxt char

	bool isAtEnd();							// check if at the end of the string
	void skipWhiteSpaces();


private:
	std::string::const_pointer start;				// pointer to current char in string
	std::string::const_pointer current;
	int line;

	std::unique_ptr<Trie> trie;
	std::shared_ptr<TrieNode> currentNode;
	std::vector<Token> tokens;

};


#endif