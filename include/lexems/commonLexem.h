#pragma once
#include <string>

class commonLexem {
private:
	std::string lex;
	size_t lineIndex;
	size_t linePos;
public:
	// E.g.
	//
	// 0 int A;
	// 1 int B;
	//
	// lexem B has ind = 1, pos = 4
	commonLexem(std::string s, size_t ind, size_t pos); // name of lexem, number of line, position in the line
		// Allowed Lexem: 
		// 1. key word:
		// 1.1 data types: int, double, void (functions only), var[size]
		// 1.2 myoperators: if(){}, else{}, while(){}, print(), scan()
		// 1.3 return
		// 2. myoperators:
		// 2.1 numeric: +, -, *, /, +=, -=, *=, /=
		// 2.2 logic: &&, ||, ==, !=, <, <=, >, >=
		// 2.3 special: =
		// 3. numbers: without . or e - integer, with . or e - real
		// 4. special symbols: (, ), ;, {, }, [, ], ,, (functions only), " (for print())
		//
		// Rules for program:
		// 1. A new line after each ; or {
		// 2. If, While, Else blocks must be signed with {}
		// 3. C syntax
		// 4. Function with name GLOBAL is prohibited
		//
		// New key words: 
		// JMPIF (expr) cmd - jump if expression is true
		// JMP cmd - jump always
		//
	std::string getName() const noexcept;
	void setName(std::string s) noexcept;
	size_t getInd() const noexcept;
	size_t getPos() const noexcept;
	void setInd(size_t _ind) noexcept;
	void setPos(size_t _pos) noexcept;
	virtual ~commonLexem() {}
	virtual void showInfo() const = 0;
	virtual std::string getClass() const = 0;
};