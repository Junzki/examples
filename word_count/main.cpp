#include "word_count.h"

int
main() {
    auto s = std::string();
    std::cout << "Input contents here" << std::endl;

    int* origin = nullptr;
    int* report = nullptr;

    characters_from_stream(std::cin, origin);
    reduce_report(report, origin);

    repr_report(report);

    return 0;
}