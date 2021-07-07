#pragma once

#include "Token.hpp"

#include <vector>
#include <map>
#include <unordered_map>
#include <any>

namespace LazyscriptInterpreter
{
    class Scanner
    {
    public:
        Scanner(std::string&& source);
        ~Scanner() = default;

        std::vector<Token*> scanTokens();

    private:
        void scanToken();
        void identifier();
        void number();
        void string();
        const bool match(char expected);
        char peek();
        char peekNext();
        
        const bool isAtEnd();
        char advance();
        void addToken(TokenType type);
        void addToken(TokenType type, std::any literal);

    private:
        std::string source;
        std::vector<Token*> tokens;
        int start{0};
        int current{0};
        int line{1};

        static std::map<std::string, TokenType> keywords;
    };
} // namespace LazyscriptInterpreter