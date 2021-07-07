#include "Scanner.hpp"
#include "Lazyscript.hpp"

namespace LazyscriptInterpreter
{
    std::map<std::string, TokenType> Scanner::keywords {
        {"and", AND},
        {"class", CLASS},
        {"else", ELSE},
        {"false", FALSE},
        {"for", FOR},
        {"fun", FUN},
        {"if", IF},
        {"OR", NIL},
        {"print", PRINT},
        {"return", RETURN},
        {"super", SUPER},
        {"this", THIS},
        {"true", TRUE},
        {"var", VAR},
        {"while", WHILE}
    };

    Scanner::Scanner(std::string&& source):
    source{source},
    tokens{}
    {
    }

    std::vector<Token*> Scanner::scanTokens()
    {
        while(!isAtEnd())
        {
            start = current;
            scanToken();
        }

        tokens.push_back(new Token(EOF_TOKEN, "", nullptr, line));
        return tokens;
    }

    void Scanner::scanToken()
    {
        char c = advance();

        switch (c)
        {
        case '(': addToken(LEFT_PAREN); break;
        case ')': addToken(RIGHT_PAREN); break;
        case '{': addToken(LEFT_BRACE); break;
        case '}': addToken(RIGHT_BRACE); break;
        case ',': addToken(COMMA); break;
        case '.': addToken(DOT); break;
        case '-': addToken(MINUS); break;
        case '+': addToken(PLUS); break;
        case ';': addToken(SEMICOLON); break;
        case '*': addToken(STAR); break;
        case '!': addToken(match('=') ? BANG_EQUAL : BANG); break;
        case '=': addToken(match('=') ? EQUAL_EQUAL : EQUAL); break;
        case '<': addToken(match('=') ? LESS_EQUAL : LESS); break;
        case '>': addToken(match('=') ? GREATER_EQUAL : GREATER); break;
        case '/': 
            if(match('/'))
                while(peek() != '\n' and !isAtEnd()) advance();
            else
                addToken(SLASH);
            break;
        case ' ': break;
        case '\r': break;
        case '\t': break;
        case '\n': line++; break;
        case '"': string(); break;
        default:
            if(std::isdigit(c))
                number();
            else if(std::isalpha(c))
                identifier();
            else
                Lazyscript::getInstance().error(line, "Unexpected character.");
            break;
        }
    }

    void Scanner::identifier()
    {
        while(std::isalnum(peek())) advance();

        const auto text = source.substr(start, current);
        auto keyword_it = keywords.find(text);
        if(keyword_it != keywords.end())
            addToken(keyword_it->second);
        else
            addToken(IDENTIFIER);
    }

    void Scanner::number()
    {
        while(std::isdigit(peek())) advance();

        if(peek() == '.' && std::isdigit(peekNext()))
        {
            advance();

            while(std::isdigit(peek())) advance();
        }

        addToken(NUMBER, std::stod(source.substr(start, current)));
    }

    void Scanner::string()
    {
        while(peek() != '"' and !isAtEnd())
        {
            if(peek() == '\n') line++;
            advance();
        }

        if(isAtEnd()) 
        {
            Lazyscript::getInstance().error(line, "Unterminated string.");
            return;
        }

        advance();

        std::string value = source.substr(start + 1, current - 1);
        addToken(STRING, value);
    }

    const bool Scanner::match(char expected)
    {
        return (isAtEnd() or source.at(current++ != expected)) ? false : true;
    }

    char Scanner::peek()
    {
        return isAtEnd() ? '\0' : source.at(current);
    }

    char Scanner::peekNext()
    {
        return current + 1 >= source.length() ? '\0' : source.at(current + 1);
    }

    const bool Scanner::isAtEnd()
    {
        return current >= source.length();
    }

    char Scanner::advance()
    {
        return source.at(current++);
    }

    void Scanner::addToken(TokenType type)
    {
        addToken(type, nullptr);
    }

    void Scanner::addToken(TokenType type, std::any literal)
    {
        std::string text = source.substr(start, current);
        tokens.push_back(new Token(type, text, literal, line));
    }
    
} // namespace LazyscriptInterpreter
