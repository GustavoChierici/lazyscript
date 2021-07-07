#include "Lazyscript.hpp"

namespace LazyscriptInterpreter
{
    bool Lazyscript::had_error = false;
    Lazyscript::Lazyscript()
    {
    }

    Lazyscript& Lazyscript::getInstance()
    {
        static Lazyscript instance;

        return instance;
    }

    void Lazyscript::init(std::vector<std::string> args /* {} */)
    {  
        if(args.size() > 1)
        {
            std::cout << "Usage: lazyscript [script]" << std::endl;
            std::exit(64);
        }
        else if(args.size() == 1)
            runFile(args[0]);
        else
            runPrompt();
    }

    void Lazyscript::runFile(const std::string& path)
    {
        auto ifs = std::ifstream(path, std::ios::binary|std::ios::ate);
        auto pos = ifs.tellg();

        std::string bytes;

        ifs.seekg(0, std::ios::beg);
        ifs.read(&bytes[0], pos);

        run(bytes);

        if(had_error) std::exit(65);
    }

    void Lazyscript::runPrompt()
    {
        std::string line;
        unsigned long count = 2;
        std::cout << "(1)> ";
        while(std::getline(std::cin, line)) 
        {
            if(std::cin.bad()) break;
            run(line);
            had_error = false;
            std::cout << '(' << count++ << ")> ";
        }
    }

    void Lazyscript::run(std::string source)
    {
        auto scanner = new Scanner(std::move(source));
        std::vector<Token*> tokens = scanner->scanTokens();

        for(auto token : tokens)
            std::cout << token->toString() << std::endl;
    }

    void Lazyscript::error(int line, std::string message)
    {
        report(line, "", message);
    }

    void Lazyscript::report(int line, std::string where, std::string message)
    {
        std::cerr << "[line " << line << "] Error " << where << ": " << message << std::endl;
        had_error = true;
    }
}