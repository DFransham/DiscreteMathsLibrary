/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2022 Media Design School
File Name : discretemaths.cpp
Description : implementation file for discrete maths project assignment: GD1M01_22071
Author : David Fransham
Mail : david.fransham@mds.ac.nz
**************************************************************************/
#include "discretemaths.h"

/***********************************************
* Magnitude: calculates absolute value of the input
* @author: Jeremy Teal
* @parameter: Accepts a Float to calculate the magnitude of
* @return: the return value of the function
************************************************/
float Magnitude(const float _kfX)
{
	if (_kfX >= 0)
	{
		return _kfX;
	}
	else
	{
		return _kfX * -1;
	}
	return 0.0f;
}

/***********************************************
* Equals: calculates whether two values are equal to a certain degree of precision
* @author: Jeremy Teal
* @parameter: Accepts two floats to compare, and another float indicating precision level
* @return: bool indicating equal or not
************************************************/
bool Equals(const float _kfA, const float _kfB, const float _kfPrecision)
{
	if (Magnitude(_kfA - _kfB) <= _kfPrecision)
	{
		return true;
	}

	return false;
}

/***********************************************
* Signum: calculates the signum of a given float value
* @author: David Fransham
* @parameter: Accepts a Float to calculate the signum of
* @return: float Signum figure
************************************************/
float Signum(const float _kfX)
{
	if (_kfX > 0.0f)
	{
		return 1.0f;
	}
	else if (_kfX < 0.0f)
	{
		return -1.0f;
	}
	return 0.0f;
}

/***********************************************
* Floor: calculates the floor of a given float value
* @author: David Fransham
* @parameter: Accepts a Float to calculate the floor of
* @return: float floor figure
************************************************/
float Floor(const float _kfX)
{
	float fTrunc = truncf(_kfX);
	
	//if signum is 0 or positive, or truncated value is equal to given value, return truncated value
	if ((Signum(_kfX) >= 0.0f) || Equals(fTrunc, _kfX, 0.00001f))  
	{
		return fTrunc;
	}
	else
	{
		return (fTrunc - 1); //if negative, truncated value is greater than so subtract one to get next integer
	}
	
	//return std::floorf( _kfX);  <- would have been easier and doesn't use any includes other than <iostream>
}

/***********************************************
* Ceiling: calculates the ceiling of a given float value
* @author: David Fransham
* @parameter: Accepts a Float to calculate the ceiling of
* @return: float ceiling figure
************************************************/
float Ceiling(const float _kfX)
{
	float fTrunc = truncf(_kfX);

	//if signum is 0 or negative, or truncated value is equal to given value, return truncated value
	if ((Signum(_kfX) <= 0.0f) || Equals(fTrunc, _kfX, 0.00001f))
	{
		return fTrunc;
	}
	else
	{
		return (fTrunc + 1); //if positive, truncated value is less than so add one to get next integer
	}

	//return std::ceilf(_kfX);  <- similar to floorf
}

/***********************************************
* Factorial: computes the factorial of a given double value
* @author: David Fransham
* @parameter: Accepts a double to compute the factorial of
* @return: double: factorial result
************************************************/
double Factorial(const double _kdn)
{
	//Factorial only defined for non-negative integers, and anything greater than 170! won't fit within DBL_MAX
	if ((_kdn < 0) || (_kdn > 170))
	{
		return -1;
	}

	//factorial not defined for non-integers, so check for value being == to floor of value to verify integer
	float fN = static_cast<float>(_kdn);
	if (!Equals(fN,Floor(fN),0.00001f))
	{
		return -1;
	}
	
	//truncate to remove possible imprecision
	double kdt = trunc(_kdn);
	double dResult = 1;

	for (int i = 1; i <= kdt; i++)
	{
		dResult *= i;
	}
	return dResult;
}

/***********************************************
* Combination: computes the number of ways to choose combinations of items
* @author: David Fransham
* @parameter: Double total number, double number required to select
* @return: double: total possible combinations available
************************************************/
double Combination(const double _kdn, const double _kdr)
{
	//Factorial only defined for non-negative integers, and anything greater than 170! won't fit within DBL_MAX
	//Factorial required to calculate Combination so limited by Factorial limitations
	//Also R cannot be greater than N, as you can't choose more than you have to start with
	if ((_kdn < 0) || (_kdr < 0) || (_kdn > 170) || (_kdr > _kdn))
	{
		return -1;
	}

	//factorial not defined for non-integers, so check for value being == to floor of value to verify integer
	float fN = static_cast<float>(_kdn);
	if (!Equals(fN, Floor(fN), 0.00001f))
	{
		return -1;
	}

	float fR = static_cast<float>(_kdr);
	if (!Equals(fR, Floor(fR), 0.00001f))
	{
		return -1;
	}

	double dNum = Factorial(_kdn);

	double dDenom = Factorial(_kdr);
	if (dDenom < 0)
	{
		return -1;
	}
	dDenom *= (Factorial(_kdn - _kdr));
	if ((dNum < 0) || (dDenom < 0))
	{
		return -1;
	}
	return (dNum / dDenom);
}

/***********************************************
* Permutation: computes the number of ways to choose combinations of items where order matters
* @author: David Fransham
* @parameter: Double total number, double number required to select
* @return: double: total possible permutations available
************************************************/
double Permutation(const double _kdn, const double _kdr)
{

	//Factorial only defined for non-negative integers, and anything greater than 170! won't fit within DBL_MAX
	//Factorial required to calculate Permutation so limited by Factorial limitations
	//Also R cannot be greater than N, as you can't choose more than you have to start with
	if ((_kdn < 0) || (_kdr < 0) || (_kdn > 170) || (_kdr > _kdn))
	{
		return -1;
	}

	//factorial not defined for non-integers, so check for value being == to floor of value to verify integer
	float fN = static_cast<float>(_kdn);
	if (!Equals(fN, Floor(fN), 0.00001f))
	{
		return -1;
	}

	float fR = static_cast<float>(_kdr);
	if (!Equals(fR, Floor(fR), 0.00001f))
	{
		return -1;
	}

	double dNum = Factorial(_kdn);

	double dDenom = Factorial(_kdn - _kdr);
	if ((dNum < 0) || (dDenom < 0))
	{
		return -1;
	}
	return (dNum / dDenom);
}

/***********************************************
* Cardinality: computes the number of elements in a set of integers
* @author: David Fransham
* @parameter: TSet struct address to compute size of
* @return: int - size of set
************************************************/
int Cardinality(TSet& _rSet)
{
	int iCounter = 0;
	for (int i = 0; i < SET_SIZE_MAX; i++)
	{
		if (_rSet.ContainsElement(i+1))
		{
			iCounter++;
		}
	}
	return iCounter;
}

/***********************************************
* Cardinality: computes the size of the "Power Set" of a set of integers
* @author: David Fransham
* @parameter: TSet struct address to compute size of
* @return: int - size of power set
************************************************/
int Power(TSet& _rSet)
{
	return static_cast<int>(pow(2, Cardinality(_rSet)));
}

/***********************************************
* Equals: calculates whether two given sets of integers are equivalent
* @author: David Fransham
* @parameter: 2x TSet struct address to compare
* @return: bool - true for equality, negative for nonequality
************************************************/
bool Equals(TSet& _rA, TSet& _rB)
{
	for (int i = 0; i < SET_SIZE_MAX; i++)
	{
		if (!(_rA.ContainsElement(i) == _rB.ContainsElement(i)))
		{
			return false;
		}
	}
	return true;
}

/***********************************************
* Subset: identifies whether given set A is a subset of given set B
* @author: David Fransham
* @parameter: 2x TSet struct addresses to compare
* @return: bool - true (A is a subset of B), false (A is not a subset of B)
************************************************/
bool Subset(TSet& _rA, TSet& _rB)
{
	for (int i = 0; i < SET_SIZE_MAX; i++)
	{
		if (_rA.ContainsElement(i))
		{
			if (!_rB.ContainsElement(i))
			{
				return false;
			}
		}
	}
	return true;
}

/***********************************************
* Superset: identifies whether given set A is a superset of given set B
* @author: David Fransham
* @parameter: 2x TSet struct addresses to compare
* @return: bool - true (A is a superset of B), false (A is not a superset of B)
************************************************/
bool Superset(TSet& _rA, TSet& _rB)
{
	for (int i = 0; i < SET_SIZE_MAX; i++)
	{
		if (_rB.ContainsElement(i))
		{
			if (!_rA.ContainsElement(i))
			{
				return false;
			}
		}
	}
	return true;
}

/***********************************************
* Union: populates a given TSet Struct with the union of the other two given sets
* @author: David Fransham
* @parameter: 3x TSet struct addresses: Set A, Set B to make the union of, set Result to hold the union
* @return: TSet address of the resultant set object
************************************************/
TSet& Union(TSet& _rA, TSet& _rB, TSet& _rResultant)
{
	TSet copySet;
	bool copyNeeded = false;
	//check if output set has same address as either input set before clearing it
	if ((&_rA == &_rResultant) ||(&_rB == &_rResultant))
	{
		copyNeeded = true;
	}

	if (copyNeeded) //if copy needed, fill it aside from 100 first, then fill resultant after
	{
		for (int i = 0; i < SET_SIZE_MAX; i++)
		{
			if ((_rA.ContainsElement(i) || _rB.ContainsElement(i)))
			{
				copySet.AddElement(i);
			}
		}
	}

	//check if element 100 will be needed, set universal if yes
	if (_rA.ContainsElement(100) || _rB.ContainsElement(100))
	{
		_rResultant.SetUniversal(); 
		switch (copyNeeded)
		{
		case 0:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (!(_rA.ContainsElement(i) || _rB.ContainsElement(i)))
				{
					_rResultant.RemoveElement(i);
				}
			}
			break;

		case 1:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (!copySet.ContainsElement(i))
				{
					_rResultant.RemoveElement(i);
				}
			}
			break;
		}
	}
	else //100 not needed so start with blank set
	{
		_rResultant.SetClear();
		switch (copyNeeded)
		{
		case 0:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if ((_rA.ContainsElement(i) || _rB.ContainsElement(i)))
				{
					_rResultant.AddElement(i);
				}
			}
			break;

		case 1:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (copySet.ContainsElement(i))
				{
					_rResultant.AddElement(i);
				}
			}
			break;
		}
	}

	return _rResultant;
}

/***********************************************
* Intersection: populates a given TSet Struct with the intersection of the other two given sets
* @author: David Fransham
* @parameter: 3x TSet struct addresses: Set A, Set B to make the intersection of, set Result to hold the intersection
* @return: TSet address of the resultant set object
************************************************/
TSet& Intersection(TSet& _rA, TSet& _rB, TSet& _rResultant)
{
	TSet copySet;
	bool copyNeeded = false;
	//check if output set has same address as either input set before clearing it
	if ((&_rA == &_rResultant) || (&_rB == &_rResultant))
	{
		copyNeeded = true;
	}

	if (copyNeeded) //if copy needed, fill it aside from 100 first, then fill resultant after
	{
		for (int i = 0; i < SET_SIZE_MAX; i++)
		{
			if ((_rA.ContainsElement(i) && _rB.ContainsElement(i)))
			{
				copySet.AddElement(i);
			}
		}
	}

	//check if element 100 will be needed, set universal if yes
	if (_rA.ContainsElement(100) && _rB.ContainsElement(100))
	{
		_rResultant.SetUniversal();
		switch (copyNeeded)
		{
		case 0:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (!(_rA.ContainsElement(i) && _rB.ContainsElement(i)))
				{
					_rResultant.RemoveElement(i);
				}
			}
			break;

		case 1:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (!copySet.ContainsElement(i))
				{
					_rResultant.RemoveElement(i);
				}
			}
			break;
		}
	}
	else //100 not needed so start with blank set
	{
		_rResultant.SetClear();
		switch (copyNeeded)
		{
		case 0:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if ((_rA.ContainsElement(i) && _rB.ContainsElement(i)))
				{
					_rResultant.AddElement(i);
				}
			}
			break;

		case 1:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (copySet.ContainsElement(i))
				{
					_rResultant.AddElement(i);
				}
			}
			break;
		}
	}

	return _rResultant;
}

/***********************************************
* Disjoint: identifies whether given sets A and B are disjoint
* @author: David Fransham
* @parameter: 2x TSet struct addresses to compare
* @return: bool - true (The sets share no elements in common), false (at least one element is in both sets)
************************************************/
bool Disjoint(TSet& _rA, TSet& _rB)
{
	for (int i = 0; i < SET_SIZE_MAX; i++)
	{
		if (_rA.ContainsElement(i) && _rB.ContainsElement(i))
		{
			return false;
		}
	}
	return true;
}

/***********************************************
* SetDifference: populates a given TSet Struct with the result of (Set A - Set B).
* @author: David Fransham
* @parameter: 3x TSet struct addresses: Set B to subtract from Set A, set Result to hold the difference
* @return: TSet address of the resultant set object
************************************************/
TSet& SetDifference(TSet& _rA, TSet& _rB, TSet& _rResultant)
{
	TSet copySet;
	bool copyNeeded = false;
	//check if output set has same address as either input set before clearing it
	if ((&_rA == &_rResultant) || (&_rB == &_rResultant))
	{
		copyNeeded = true;
	}

	if (copyNeeded) //if copy needed, fill it aside from 100 first, then fill resultant after
	{
		for (int i = 0; i < SET_SIZE_MAX; i++)
		{
			if ((_rA.ContainsElement(i) && !(_rB.ContainsElement(i))))
			{
				copySet.AddElement(i);
			}
		}
	}
	
	//check if element 100 will be needed, set universal if yes
	if (_rA.ContainsElement(100) && !(_rB.ContainsElement(100)))
	{
		_rResultant.SetUniversal();
		switch (copyNeeded)
		{
		case 0:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if ((!_rA.ContainsElement(i)) || _rB.ContainsElement(i))
				{
					_rResultant.RemoveElement(i);
				}
			}
			break;

		case 1:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (!copySet.ContainsElement(i))
				{
					_rResultant.RemoveElement(i);
				}
			}
			break;
		}
	}
	else //100 not needed so start with blank set
	{
		_rResultant.SetClear();
		switch (copyNeeded)
		{
		case 0:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if ((_rA.ContainsElement(i) && !(_rB.ContainsElement(i))))
				{
					_rResultant.AddElement(i);
				}
			}
			break;

		case 1:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (copySet.ContainsElement(i))
				{
					_rResultant.AddElement(i);
				}
			}
			break;
		}
	}

	return _rResultant;
}

/***********************************************
* SymmetricDifference: populates a given TSet Struct with the symmetric difference of Set A and Set B.
* @author: David Fransham
* @parameter: 3x TSet struct addresses: Sets A and B calculate the symmetric difference of, set Result to hold the difference
* @return: TSet address of the resultant set object
************************************************/
TSet& SymmetricDifference(TSet& _rA, TSet& _rB, TSet& _rResultant)
{
	TSet copySet;
	bool copyNeeded = false;
	//check if output set has same address as either input set before clearing it
	if ((&_rA == &_rResultant) || (&_rB == &_rResultant))
	{
		copyNeeded = true;
	}

	if (copyNeeded) //if copy needed, fill it aside from 100 first, then fill resultant after
	{
		for (int i = 0; i < SET_SIZE_MAX; i++)
		{
			//symmetric difference contains (a or b) but/and NOT (a and b)
			if ((_rA.ContainsElement(i) || _rB.ContainsElement(i)) 
				&& !(_rA.ContainsElement(i) && _rB.ContainsElement(i)))
			{
				copySet.AddElement(i);
			}
		}
	}

	//check if element 100 will be needed, set universal if yes
	if ((_rA.ContainsElement(100) || _rB.ContainsElement(100)) 
		&& !(_rA.ContainsElement(100) && _rB.ContainsElement(100)))
	{
		_rResultant.SetUniversal();
		switch (copyNeeded)
		{
		case 0:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if ((_rA.ContainsElement(i) || _rB.ContainsElement(i))
					&& !(_rA.ContainsElement(i) && _rB.ContainsElement(i)))
				{
					//do nothing - it's already in the universal set
				}
				else
				{
					_rResultant.RemoveElement(i);
				}
			}
			break;

		case 1:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (!copySet.ContainsElement(i))
				{
					_rResultant.RemoveElement(i);
				}
			}
			break;
		}
	}
	else //100 not needed so start with blank set
	{
		_rResultant.SetClear();
		switch (copyNeeded)
		{
		case 0:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if ((_rA.ContainsElement(i) || _rB.ContainsElement(i))
					&& !(_rA.ContainsElement(i) && _rB.ContainsElement(i)))
				{
					_rResultant.AddElement(i);
				}
			}
			break;

		case 1:
			for (int i = 0; i < SET_SIZE_MAX; i++)
			{
				if (copySet.ContainsElement(i))
				{
					_rResultant.AddElement(i);
				}
			}
			break;
		}
	}

	return _rResultant;
}

/***********************************************
* Compliment: constructs the complement set of a given set.  Also pays a bonus compliment to the tester.
* @author: David Fransham
* @parameter: TSet struct address to invert into its complement
* @return: TSet address of the input set that has been modified
************************************************/
TSet& Compliment(TSet& _rA)
{
	/*This is what my code would say if not for the typo in AddElement() and RemoveElement()
	for (int i = 0; i < SET_SIZE_MAX; i++)
	{
		if (_rA.ContainsElement(i))
		{
			_rA.RemoveElement(i);
		}
		else
		{
			_rA.AddElement(i);
		}
	}
	*/

	//This is my workaround due to the inability to add or remove element 100:
	TSet tempSet = TSet();

	if (_rA.ContainsElement(100)) //result needs to have no element 100, so start with blank set
	{
		for (int i = 0; i < SET_SIZE_MAX; i++)
		{
			if (!_rA.ContainsElement(i)) //only add elements input set did not contain
			{
				tempSet.AddElement(i);
			}
		}
		_rA.SetClear(); //temp set now contains everything return set needs
		for (int i = 0; i < SET_SIZE_MAX; i++)
		{
			if (tempSet.ContainsElement(i))
			{
				_rA.AddElement(i); //copy elements back to return set
			}
		}
	}
	else //input set contains no 100, so output needs to contain it
	{
		for (int i = 0; i < SET_SIZE_MAX; i++)
		{
			if (_rA.ContainsElement(i)) //start by copying input/output set into tempset
			{
				tempSet.AddElement(i);
			}
		}

		_rA.SetUniversal();//fill output set with every element

		for (int i = 0; i < SET_SIZE_MAX; i++)
		{
			if (tempSet.ContainsElement(i))
			{
				_rA.RemoveElement(i); //remove all elements that were in original set
			}

		}
	}

	//Compliment vs Complement - the function has to do what the title suggests, so...
	std::cout << "\n\nCompliment: That's a well-formed set you've got there!\n";
	return _rA;
}

/***********************************************
* CartesianProduct: computes the size of the cartesian product of two given sets
* @author: David Fransham
* @parameter: 2 x TSet struct addresses to compute the cartesian product of
* @return: int - size of cartesian product
************************************************/
int CartesianProduct(TSet& _rA, TSet& _rB)
{
	return (Cardinality(_rA) * Cardinality(_rB));
}
