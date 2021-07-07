#include "Token.hpp"

namespace LazyscriptInterpreter
{
    Token::Token(const TokenType& type, 
        const std::string& lexeme, 
        const std::any literal, 
        const int& line):
    type{type},
    lexeme{lexeme},
    literal{literal},
    line{line}
    {
    }

    std::string Token::toString() const
    {
        return TokenTypeToString(type) + " " + lexeme + " " + literalToString();
    }

    std::string Token::literalToString() const
    {
        switch (type) {
        case STRING:
            return std::any_cast<std::string>(literal);
        case NUMBER:
            return std::to_string(std::any_cast<double>(literal));
        default:
            return "";
        }
    }

} // namespace LazyscriptInterpreter