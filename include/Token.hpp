#pragma once

#include "TokenType.hpp"
#include <any>
#include <string>

namespace LazyscriptInterpreter
{
    class Token
    {
    public:
        Token(const TokenType& type, 
            const std::string& lexeme, 
            std::any literal, 
            const int& line);
        ~Token() = default;

        std::string toString() const;
        std::string literalToString() const;

    public:
        TokenType type;
        std::string lexeme;
        std::any literal;
        int line;
    };
    
} // namespace LazyscriptInterpreter
