#pragma once

#ifndef INTER_WRITE_H
#define INTER_WRITE_H

#include <iostream>

namespace inter_write {
    const char* shm_name = "shm__inter_write";

    typedef struct context {

    };

    size_t write(std::string);
}

#endif // INTER_WRITE_H
