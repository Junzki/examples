/*
 * Here is a simple unit test "framework".
 * Tutorial: https://zhuanlan.zhihu.com/p/22460835
 */

#ifndef UGLY_TEST_H__
#define UGLY_TEST_H__

#include <cstdio>

#define EXPECT_EQ_BASE(equality, expect, actual, format)				\
	do {																\
		++test_count;													\
		if (equality)													\
			++test_passed;												\
		else {															\
			fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual); \
			test_status = EXIT_FAILURE;									\
		}																\
	}																	\
	while (0);															\

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")
#define EXPECT_EQ_DOUBLE(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%f")

#endif
