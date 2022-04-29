#pragma once

#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <iostream>
#include <string>
#include <cstring>

const char   base_alpha  = 'a';
const size_t origin_cap  = 128;
const size_t report_size = 26;

void characters_from_stream(std::istream&, int*&);
void reduce_report(int*&, const int*);
void repr_report(int*);


#endif
