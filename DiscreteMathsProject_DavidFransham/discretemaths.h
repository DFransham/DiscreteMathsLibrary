#include <iostream>
#define SET_SIZE_MAX 100

// For the implementation of the following 
// you are NOT permitted to use math.h / <cmath>
// or ANY other library includes other than iostream 

float Magnitude(const float _kfX);	// absolute value

bool Equals(const float _kfA, const float _kfB, const float _kfPrecision);

float Signum(const float _kfX);

float Floor(const float _kfX);

float Ceiling(const float _kfX);

double Factorial(const double _kdn);

double Combination(const double _kdn, const double _kdr);

double Permutation(const double _kdn, const double _kdr);

// Implementation for a Set of integers between 1 and 100 inclusive
// where integer values of '0' in the array are considered 'empty' ie. not an element. 
// U = { x : x E Z, x >= 1 & x <= 100 }
struct TSet
{
private:
	int* m_piArray = nullptr;
	const int m_iMaxSize = SET_SIZE_MAX;

public:
	TSet()
	{
		m_piArray = new int[SET_SIZE_MAX];
		SetClear();
	}

	~TSet()
	{
		delete[] m_piArray;
	}

	void Print()
	{
		std::cout << "\nSet Elements: { ";
		for (int i = 0; i < m_iMaxSize; i++)
		{
			if (m_piArray[i] != 0)
			{
				if (i == 0)
				{
					std::cout << m_piArray[i] << ",";
				}
				else if (i < m_iMaxSize - 1)
				{
					std::cout << " " << m_piArray[i] << ",";
				}
				else
				{
					std::cout << " " << m_piArray[i];
				}
			}
		}
		std::cout << " }; ";
	}

	void SetClear()
	{
		for (int n = 0; n < m_iMaxSize; n++)
		{
			m_piArray[n] = 0;
		}
	}

	void SetUniversal()
	{
		for (int n = 0; n < m_iMaxSize; n++)
		{
			m_piArray[n] = n + 1;
		}
	}

	void AddElement(int _iElement)
	{
		if ((_iElement < m_iMaxSize) && (_iElement > 0))
		{
			m_piArray[_iElement - 1] = _iElement;
		}
	}

	void RemoveElement(int _iElement)
	{
		if ((_iElement < m_iMaxSize) && (_iElement > 0))
		{
			m_piArray[_iElement - 1] = 0;
		}
	}

	bool ContainsElement(int _iElement)
	{
		if ((_iElement <= m_iMaxSize) && (_iElement > 0))
		{
			return (m_piArray[_iElement - 1] != 0);
		}
		return false;
	}
};

int Cardinality(TSet& _rSet);

int Power(TSet& _rSet);

bool Equals(TSet& _rA, TSet& _rB);

bool Subset(TSet& _rA, TSet& _rB);

bool Superset(TSet& _rA, TSet& _rB);

TSet& Union(TSet& _rA, TSet& _rB, TSet& _rResultant);

TSet& Intersection(TSet& _rA, TSet& _rB, TSet& _rResultant);

bool Disjoint(TSet& _rA, TSet& _rB);

TSet& SetDifference(TSet& _rA, TSet& _rB, TSet& _rResultant);

TSet& SymmetricDifference(TSet& _rA, TSet& _rB, TSet& _rResultant);

TSet& Compliment(TSet& _rA);

int CartesianProduct(TSet& _rA, TSet& _rB);