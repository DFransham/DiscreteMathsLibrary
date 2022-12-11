/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2022 Media Design School
File Name : test.h
Description : header file containing code to run the testing program for discrete maths project
Author : David Fransham
Mail : david.fransham@mds.ac.nz
**************************************************************************/

#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "discretemaths.h"

using std::string;

enum class EColour
{
	COLOUR_WHITE_ON_BLACK = 0, // White on Black.
	COLOUR_RED_ON_BLACK = 1, // Red on Black.
	COLOUR_GREEN_ON_BLACK = 2, // Green on Black.
	COLOUR_YELLOW_ON_BLACK = 3, // Yellow on Black.
	COLOUR_BLUE_ON_BLACK = 4, // Blue on Black.
	COLOUR_MAGENTA_ON_BLACK = 5, // Magenta on Black.
	COLOUR_CYAN_ON_BLACK = 6, // Cyan on Black.
	COLOUR_BLACK_ON_GRAY = 7, // Black on Gray.
	COLOUR_BLACK_ON_WHITE = 8, // Black on White.
	COLOUR_RED_ON_WHITE = 9, // Red on White.
	COLOUR_GREEN_ON_WHITE = 10, // Green on White.
	COLOUR_YELLOW_ON_WHITE = 11, // Yellow on White.
	COLOUR_BLUE_ON_WHITE = 12, // Blue on White.
	COLOUR_MAGENTA_ON_WHITE = 13,// Magenta on White.
	COLOUR_CYAN_ON_WHITE = 14, // Cyan on White.
	COLOUR_WHITE_ON_WHITE = 15 // White on White.
};

enum class EFunctions
{
	MAGNITUDE = 0,
	EQUALS_FLOAT = 1,
	SIGNUM = 2,
	FLOOR = 3,
	CEILING = 4,
	FACTORIAL = 5,
	COMBINATION = 6,
	PERMUTATION = 7,
	CARDINALITY = 8,
	POWER = 9,
	EQUALS_SET = 10,
	SUBSET = 11,
	SUPERSET = 12,
	UNION = 13,
	INTERSECTION = 14,
	DISJOINT = 15,
	SET_DIFFERENCE = 16,
	SYMMETRIC_DIFFERENCE = 17,
	COMPLEMENT = 18,
	CARTESIAN_PRODUCT = 19
};

//Program control functions
void StartTesting();
void HardcodedNumberTests();
void HardcodedSetTests();
void RunManualTests();
void InitiateFunction(const EFunctions _keChoice);
void IncrementCounters(const bool _kbResult, const EFunctions _keFuncTested);

//Numerical testing functions
void InitiateEqualsTest(const float _kfSignatureIdentifier);
void TestEquals(const float _kfTestValueA, const float _kfTestValueB,
	const float _kfPrecision, const bool _kbExpectedValue);
void InitiateFactorialTest();
void TestFactorial(const double _kdTestValue, const double _kdExpectedValue);
void InitiateOneFloatTest(float(*_p1fFunc)(float), EFunctions _eChoice);
void TestOneFloatFunc(const float _kfTestValue, const float _kfExpectedValue, 
	float(*pfFunc)(float), EFunctions _eChoice);
void InitiateTwoDoubleTest(double(*_p2dFunc)(double, double), EFunctions _eChoice);
void TestTwoDoubleFunc(const double _kdTestValA, const double _kdTestValB, const double _kdExpected, 
	double(*_p2dFunc)(double, double), EFunctions _eChoice);
int InitiateOneFloatTest(EFunctions _eFuncChoice, const float _kfA, const float _kfB, 
	float(*_p1fFunc)(float), const int _kiYpos);
int InitiateTwoDoubleTest(EFunctions _eFuncChoice, const double _kDA, const double _kDB, 
	const double _kdEx, double(*_p2dFunc)(double, double), const int _kiYpos);
int InitiateEqualsTest(const float _kfA, const float _kfB, const float _kfP,
	const bool _kbEV, const int _kiYpos);
int InitiateFactorialTest(const double _kdTest, const double _kdExpected, const int _kiYpos);

//Set testing functions
void InitiateComplementTest();
void TestComplement(TSet& _krA, TSet& _krExpected);
void InitiateCartesianProductTest();
void TestCartesianProduct(TSet& _krA, TSet& _krB, int _iExpected);
void InitiateOneSetTest(int(*prFunc)(TSet&), EFunctions _eChoice);
void TestOneSetFunc(EFunctions _eFuncChoice, TSet& _rA, const int _kiExpected, 
	int(*_p1rFunc)(TSet&));
void InitiateTwoSetTest(bool(*_p2rFunc)(TSet&, TSet&), EFunctions _eChoice);
void TestTwoSetFunc(EFunctions _eFuncChoice, TSet& _rA, TSet& _rB, bool _bExpected, 
	bool(*_p2rFunc)(TSet&, TSet&));
void InitiateThreeSetTest(TSet& (*_p3rFunc)(TSet&, TSet&, TSet&), EFunctions _eChoice);
void TestThreeSetFunc(EFunctions _eFuncChoice, TSet& _rA, TSet& _rB, TSet& _resultant,
	TSet& _rExpected, TSet& (*_p3rFunc)(TSet&, TSet&, TSet&));
void CalculateSetExpectation(EFunctions _eFuncChoice, TSet& (*_p3rFunc)(TSet&, TSet&, TSet&),
	TSet& _rA, TSet& _rB, TSet& _expectedResult);
void PopulateHardcodedSet(TSet& _setForTesting, int _iElements[], int _iSize);
void PopulateSetForTesting(TSet& _setToPopulate, bool _bRandom = true, int _iSize = 0);
void AddElement100(TSet& _setToCopy);

void LogicTestsPrintSet(TSet& _rPrint, const int _iSetIndex);

void LogicTestsPrintAll(TSet& _rA, TSet& _rB, TSet& _rC, TSet& _rD);

void LogicTestsPopulateSets(TSet& _rA, TSet& _rB, TSet& _rC, TSet& _rD);

void LogicTestFunctionCall(TSet& _rA, TSet& _rB, TSet& _rC, TSet& _rD, TSet& (*_ptr)(TSet&, TSet&, TSet&), EFunctions _func);

void SpecificLogicTesting();

//Screen tidying functions
void PrepareForNextBatch(int _iYpos, bool _bNextBatch = true);
void PrintTestResult(const bool _kbResult);
void PrintCumulativeResults();
void PrintFunctionMenu();
void PrintIndividualTestHeader(const EFunctions _keFuncToTest, int _iPrintX = 0, int _iPrintY = 0);
void ClearScreen();
void ResizeConsoleWindow(int _iWidth, int _iHeight);
void SetFontSize(int _iSize);
void GoToXY(const int _kiX, const int _kiY);
void SetRgb(EColour colour);
COORD GetCursorPos();

//Input control functions
string GetUserInput(const int _kiCursorResetPos = 0);
bool IsOnlyNumbers(const string& str, const bool _kbIncDecimal = false, const bool _kbIncNegative = false);
int GetInt(const bool _kbSpecificRange = false, const int _kiMin = 0, const int _kiMax = 1);
float GetFloat(const bool _kbSpecificRange = false, const float _kfMin = 0.0f, const float _kfMax = 1.0f);
double GetDouble(const bool _kbSpecificRange = false, const double _kdMin = 0.0, const double _kdMax = 1.0);
bool TakeInputRepeatTest();
int GetRandomNumber(const int _kiMaxRand, const int _kiMinRand = 0);