#ifndef COMMON_H
#define COMMON_H

#include "hayai.hpp"
#include <stdlib.h>

static const size_t kBenchmarkIterationsCount = 5;

extern const char*  kBenchmarkStrings[];
extern const size_t kBenchmarkStringsSize;

#define BENCHMARK_CONTAINER_INSERTION(FIXTURE) \
	BENCHMARK_F(FIXTURE, InsertSequential, kBenchmarkIterationsCount, kBenchmarkStringsSize) \
	{ \
		InsertSequential(); \
	} \
	BENCHMARK_F(FIXTURE, InsertRandom, kBenchmarkIterationsCount, kBenchmarkStringsSize) \
	{ \
		InsertRandom(); \
	}

#define BENCHMARK_CONTAINER_FIND(FIXTURE) \
	BENCHMARK_F(FIXTURE, FindSequential, kBenchmarkIterationsCount, kBenchmarkStringsSize) \
	{ \
		FindSequential(); \
	} \
	BENCHMARK_F(FIXTURE, FindRandom, kBenchmarkIterationsCount, kBenchmarkStringsSize) \
	{ \
		FindRandom(); \
	}


#endif // COMMON_H
