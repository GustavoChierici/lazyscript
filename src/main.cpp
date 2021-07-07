#include "Lazyscript.hpp"

int main()
{
    auto interpreter = LazyscriptInterpreter::Lazyscript::getInstance();
    interpreter.init();
    return 0;
}