#include "Common.h"

#include "radix_tree.hpp"

class YtakanoRadixTreeInsertFixture : public ::hayai::Fixture
{
public:
	virtual void SetUp()
	{
		srand(1);
		m_index = 0;
	}

	virtual void TearDown()
	{
	}

protected:
	inline void InsertSequential()
	{
		m_tree[kBenchmarkStrings[m_index++]] = NULL;
	}

	inline void InsertRandom()
	{
		m_tree[kBenchmarkStrings[rand() % kBenchmarkStringsSize]] = NULL;
	}

private:

	radix_tree<std::string, void*> m_tree;
	size_t                         m_index;
};

class YtakanoRadixTreeFindFixture : public ::hayai::Fixture
{
public:
	virtual void SetUp()
	{
		srand(1);
		m_index = 0;
		for (size_t i = 0; i < kBenchmarkStringsSize; ++i)
			m_tree[kBenchmarkStrings[i]] = NULL;
	}

	virtual void TearDown()
	{
	}

protected:
	inline void FindSequential()
	{
		m_tree.find(kBenchmarkStrings[m_index++]);
	}

	inline void FindRandom()
	{
		m_tree.find(kBenchmarkStrings[rand() % kBenchmarkStringsSize]);
	}

private:

	radix_tree<std::string, void*> m_tree;
	size_t                         m_index;
};

BENCHMARK_CONTAINER_INSERTION(YtakanoRadixTreeInsertFixture);
BENCHMARK_CONTAINER_FIND(YtakanoRadixTreeFindFixture);
