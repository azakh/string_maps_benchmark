#include "Common.h"

#include "sparsehash/dense_hash_map"

class DenseHashMapInsertFixture : public ::hayai::Fixture
{
public:
	virtual void SetUp()
	{
		srand(1);
		m_index = 0;
		m_tree.set_empty_key(std::string());
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

	google::dense_hash_map<std::string, void*> m_tree;
	size_t                                     m_index;
};

class DenseHashMapFindFixture : public ::hayai::Fixture
{
public:
	virtual void SetUp()
	{
		srand(1);
		m_index = 0;
		m_tree.set_empty_key(std::string());
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

	google::dense_hash_map<std::string, void*> m_tree;
	size_t                                     m_index;
};

BENCHMARK_CONTAINER_INSERTION(DenseHashMapInsertFixture);
BENCHMARK_CONTAINER_FIND(DenseHashMapFindFixture);
