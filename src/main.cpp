#include <iostream>
#include <string>
#include <sqltoast.h>

int main(int __argc, char *__argv[]) {
    std::string input;
    if (__argc == 2) {
        input.assign(__argv[1]);
    } else {
        std::cout << "Supply a SQL string to parse." << std::endl;
        return 1;
    }
    sqltoast::parse_result_t res;
    sqltoast::parse_input_t subject(input.cbegin(), input.cend());

    res = sqltoast::parse(subject);
    if (res.code == sqltoast::PARSE_OK)
        std::cout << "Success!" << std::endl;
    else if (res.code == sqltoast::PARSE_SYNTAX_ERROR)
        std::cout << "Syntax error: " << res.error << std::endl;
}
