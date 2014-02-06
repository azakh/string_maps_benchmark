#include "Common.h"

#include "structured_map.hpp"

class StructuredMapInsertFixture : public ::hayai::Fixture
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

	containers::structured_map<std::string, void*> m_tree;
	size_t                                         m_index;
};

class StructuredMapFindFixture : public ::hayai::Fixture
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

	containers::structured_map<std::string, void*> m_tree;
	size_t                                         m_index;
};

BENCHMARK_CONTAINER_INSERTION(StructuredMapInsertFixture);
BENCHMARK_CONTAINER_FIND(StructuredMapFindFixture);
