
#include "word_count.h"


void
reduce_report(int*& out, const int* in) {
    out = new int[report_size];
    memset(out, 0, sizeof(int) * report_size);

    char c      = base_alpha;
    auto offset = 0;
    for (int i = 0; i < origin_cap; ++i) {
        if (! std::isalpha(i))
            continue;

        c      = std::tolower(i);
        offset = c - base_alpha;
        out[offset] += in[i];
    }
}


void repr_report(int* report) {

    char c;
    for (auto i = 0; i < report_size; ++i) {
        c = base_alpha + i;
        std::cout << "Character: " << c << " -> " << report[i] << std::endl;
    }
}


void
characters_from_stream(std::istream& s, int*& report) {
    report = new int[origin_cap];
    memset(report, 0, sizeof(int) * origin_cap);

    std::string buf;
    std::getline(s, buf);
    while (! buf.empty()) {
        for (auto i : buf) {
            if (! isalpha(i))
                continue;

            report[i] += 1;
        }

        std::getline(s, buf);
    }
}
