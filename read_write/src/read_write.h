#pragma once
#pragma warning(disable : 4996)

#ifndef READ_WRITE_H
#define READ_WRITE_H

#include <iostream>
#include <cstdio>
#include <cerrno>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <cstring>
#include <sstream>

#if defined(WIN32)
#include <Windows.h>
#include <synchapi.h>

#define ssize_t int

void sleep(int seconds) {
    auto milli = seconds * 1000;
    Sleep(milli);
}
#else
#include <unistd.h>
#endif


namespace read_write {

    const char* shm_file = "shm__pipe_file";
    const std::string shutdown_keyword = "shutdown";

    class shm_read_write {
    public:
        shm_read_write() {
            fd_ = open(shm_file, O_CREAT | O_APPEND | O_RDWR, S_IREAD | S_IWRITE);  // Just copy this line, I'll describe the parameters later.
            if (-1 == fd_) {  // Cannot open "shared" file, quit with failure.
                std::cout << "Error: " << errno << std::endl;
                exit(errno);
            }

            buf_ = new char[BUFSIZ];
            memset(buf_, 0, BUFSIZ);
        }

        ~shm_read_write() {
            if (-1 != fd_)
                close(fd_);

            delete[] buf_;
        }

        auto read_to_string() const {
            std::stringstream ss;

            ssize_t n_read = -1;
            while (true) {
                n_read = read(fd_, buf_, BUFSIZ);
                if (0 == n_read)
                    break;

                ss.write(buf_, n_read);
            }

            return ss.str();
        }

        void write_from_string(const std::string& s) const {
            // Note:
            // - std::string.c_str() returns containing raw bytes of entire string.
            write(fd_, s.c_str(), s.length());
        }

    private:
        int fd_ = -1;
        char* buf_;
    };

}

#endif // READ_WRITE_H
