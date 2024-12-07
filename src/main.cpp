#include <iostream>
#include <string>
#include <sqltoast.h>

int main() {
    std::string input = "SELECT a FROM t1";
    sqltoast::parse_result_t res;
    sqltoast::parse_input_t subject(input.cbegin(), input.cend());

    res = sqltoast::parse(subject);
    if (res.code == sqltoast::PARSE_OK)
        std::cout << "Success!" << std::endl;
    else if (res.code == sqltoast::PARSE_SYNTAX_ERROR)
        std::cout << "Syntax error: " << res.error << std::endl;
    return 0;
}
