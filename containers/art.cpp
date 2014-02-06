#include "Common.h"

#include "art.hpp"

class ArtInsertFixture : public ::hayai::Fixture
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
		m_tree.insert(kBenchmarkStrings[m_index++]);
	}

	inline void InsertRandom()
	{
		m_tree.insert(kBenchmarkStrings[rand() % kBenchmarkStringsSize]);
	}

private:

	art::artree m_tree;
	size_t      m_index;
};

class ArtFindFixture : public ::hayai::Fixture
{
public:
	virtual void SetUp()
	{
		srand(1);
		m_index = 0;
		for (size_t i = 0; i < kBenchmarkStringsSize; ++i)
			m_tree.insert(kBenchmarkStrings[i]);
	}

	virtual void TearDown()
	{
	}

protected:
	inline void FindSequential()
	{
		m_tree.search(kBenchmarkStrings[m_index++]);
	}

	inline void FindRandom()
	{
		m_tree.search(kBenchmarkStrings[rand() % kBenchmarkStringsSize]);
	}

private:

	art::artree m_tree;
	size_t      m_index;
};

BENCHMARK_CONTAINER_INSERTION(ArtInsertFixture);
BENCHMARK_CONTAINER_FIND(ArtFindFixture);
