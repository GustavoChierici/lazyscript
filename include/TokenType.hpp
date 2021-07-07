#pragma once

#include <string>

namespace LazyscriptInterpreter
{
    enum TokenType
    {
        //Single-character tokens
        LEFT_PAREN, 
        RIGHT_PAREN,
        LEFT_BRACE, 
        RIGHT_BRACE,
        COMMA, 
        DOT, 
        MINUS, 
        PLUS, 
        SEMICOLON, 
        SLASH, 
        STAR,

        //One or two character tokens
        BANG, 
        BANG_EQUAL,
        EQUAL, 
        EQUAL_EQUAL,
        GREATER, 
        GREATER_EQUAL,
        LESS, 
        LESS_EQUAL,

        //Literals
        IDENTIFIER, 
        STRING, 
        NUMBER,

        //Keywords
        AND, 
        CLASS, 
        ELSE, 
        FALSE, 
        FUN, 
        FOR, 
        IF, 
        NIL, 
        OR,
        PRINT, 
        RETURN, 
        SUPER, 
        THIS, 
        TRUE, 
        VAR, 
        WHILE,

        EOF_TOKEN
    };

    static std::string TokenTypeToString(TokenType type)
    {
        switch (type)
        {
        case AND: return "AND";
        case BANG: return "BANG";
        case BANG_EQUAL: return "BANG_EQUAL";
        case CLASS: return "CLASS";
        case COMMA: return "COMMA";
        case DOT: return "DOT";
        case ELSE: return "ELSE";
        case EOF_TOKEN: return "EOF_TOKEN";
        case EQUAL: return "EQUAL";
        case EQUAL_EQUAL: return "EQUAL_EQUAL";
        case FALSE: return "FALSE";
        case FOR: return "FOR";
        case FUN: return "FUN";
        case GREATER: return "GREATER";
        case GREATER_EQUAL: return "GREATER_EQUAL";
        case IDENTIFIER: return "IDENTIFIER";
        case IF: return "IF";
        case LEFT_PAREN: return "LEFT_PAREN";
        case LEFT_BRACE: return "LEFT_BRACE";
        case LESS: return "LESS";
        case LESS_EQUAL: return "LESS_EQUAL";
        case MINUS: return "MINUS";
        case NIL: return "NIL";
        case NUMBER: return "NUMBER";
        case OR: return "OR";
        case PLUS: return "PLUS";
        case PRINT: return "PRINT";
        case RETURN: return "RETURN";
        case RIGHT_PAREN: return "RIGHT_PAREN";
        case RIGHT_BRACE: return "RIGHT_BRACE";
        case SEMICOLON: return "SEMICOLON";
        case SLASH: return "SLASH";
        case STAR: return "STAR";
        case STRING: return "STRING";
        case SUPER: return "SUPER";
        case THIS: return "THIS";
        case TRUE: return "TRUE";
        case VAR: return "VAR";
        case WHILE: return "WHILE";
        }

        return "";
    }

} // namespace LazyscriptInterpreter