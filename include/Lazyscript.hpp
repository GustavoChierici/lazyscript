#pragma once

#include <exception>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>
#include "Scanner.hpp"

namespace LazyscriptInterpreter
{
    class Lazyscript
    {
    public:
        static Lazyscript& getInstance(std::vector<std::string> args = {});

        // Lazyscript(Lazyscript const&) = delete;
        // Lazyscript(Lazyscript&&) = delete;
        // void operator=(Lazyscript const&) = delete;
        // void operator=(Lazyscript&&) = delete;

        static void error(int line, std::string message);
        ~Lazyscript() = default;
    private:
        Lazyscript(std::vector<std::string> args = {});

        static void runFile(const std::string& path);
        static void runPrompt();
        static void run(std::string source);
        static void report(int line, std::string where, std::string message);

    public:
        static bool had_error;
    };
}