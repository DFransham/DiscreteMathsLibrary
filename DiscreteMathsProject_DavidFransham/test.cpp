#include "test.h"

int g_iTestsPerformed = 0;
int g_iTestsPassed = 0;
int g_iFuncTestCounter[20][2];
int g_iRightColumnX = 100;
bool g_bUserTests = false;

string g_sFuncNameArray[20] =
{
	"Magnitude",
	"Equals (float)",
	"Signum",
	"Floor",
	"Ceiling",
	"Factorial",
	"Combination",
	"Permutation",
	"Cardinality",
	"Power",
	"Equals (set)",
	"Subset",
	"Superset",
	"Union",
	"Intersection",
	"Disjoint",
	"Set Difference",
	"Symmetric Difference",
	"Complement",
	"Cartesian Product"
};

//Control functions

/***********************************************
* StartTesting: controls the flow of the testing program
* @author: David Fransham
* @parameter: none
* @return: void
************************************************/
void StartTesting()
{
	ResizeConsoleWindow(1100, 700);
	SetFontSize(17);

	srand(static_cast<UINT>(time(0)));
	std::cout.setf(std::ios::boolalpha);
	
	while (true) //infinite loop -> exits by exiting program through menu.
	{
		ClearScreen();
		PrintCumulativeResults();
		GoToXY(0, 0);

		SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
		std::cout << "Welcome to the discrete maths project testing facility.\n\n";
		std::cout << "Would you like to view some pre-programmed tests, or conduct some manual tests?\n";
		std::cout << "Please type a number to choose an option below, followed by ENTER:\n";
		SetRgb(EColour::COLOUR_BLUE_ON_BLACK);
		std::cout << "1: Run pre-programmed tests;\n";
		std::cout << "2: Conduct manual tests;\n";
		std::cout << "3: Exit program.\n";
		SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);

		string sWaitForInput;
		int iChoice = GetInt(true, 1, 3);
		switch (iChoice)
		{
		case 1://hardcoded tests
			std::cout << "Please choose an option from the menu below:\n\n";
			std::cout << "1: Numerical function tests;\n";
			std::cout << "2: Set function tests;\n";
			std::cout << "3: Both of the above.\n";
			std::cout << "---Or---\n4: If you wish to view some specific logic testing done manually during development.\n";
			iChoice = GetInt(true, 1, 4);
			ClearScreen();
			switch (iChoice)
			{
			case 1:
				HardcodedNumberTests();
				break;
			case 2:
				HardcodedSetTests();
				break;
			case 3:
				HardcodedNumberTests();
				HardcodedSetTests();
				break;
			case 4:
				SpecificLogicTesting();
			default:
				break;
			}
			break;

		case 2://Manual testing
			RunManualTests();
			break;

		case 3: //Exit Program
			ClearScreen();
			GoToXY(40, 10);
			SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
			std::cout << "Thanks for taking part in testing today.";
			GoToXY(40, 12);
			std::cout << "You conducted a total of ";
			SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
			std::cout << g_iTestsPerformed;
			SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
			std::cout << " tests today.";
			GoToXY(40, 13); 
			SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
			std::cout << g_iTestsPassed;
			SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
			std::cout << " of them were successful!";
			GoToXY(40, 15);
			std::cout << "Press ENTER to exit... ironically.";
			sWaitForInput = GetUserInput();
			return;
		default:
			break;
		}
	}
}

/***********************************************
* HardcodedNumberTests: runs 4 tests across each numerical function, testing different inputs.
* @author: David Fransham
* @parameter: none
* @return: void
************************************************/
void HardcodedNumberTests()
{
	float (*p1fFunc)(float) = nullptr;
	double (*p2dFunc)(double, double) = nullptr;
	EFunctions funcChoice = EFunctions::MAGNITUDE;
	int iNextY;

	/*
	* Hard coded Magnitude tests
	*/
	p1fFunc = Magnitude;

	iNextY = InitiateOneFloatTest(funcChoice, 1.2f, 1.2f, p1fFunc, 0);
	iNextY = InitiateOneFloatTest(funcChoice, -15.5f, 15.5f, p1fFunc, iNextY);
	iNextY = InitiateOneFloatTest(funcChoice, 0.0f, 0.0f, p1fFunc, iNextY);
	iNextY = InitiateOneFloatTest(funcChoice, -3.5f, 3.5f, p1fFunc, iNextY);
	PrepareForNextBatch(iNextY);

	/*
	* Hard coded Equals tests
	*/
	funcChoice = EFunctions::EQUALS_FLOAT;
	iNextY = InitiateEqualsTest(1.2f, 1.2f, 0.00001f, true, 0);
	iNextY = InitiateEqualsTest(-2.5f, -2.6f, 0.01f, false, iNextY);
	iNextY = InitiateEqualsTest(-2.5f, -2.6f, 0.1f, true, iNextY);
	iNextY = InitiateEqualsTest(3.14159f, 3.1416f, 0.001f, true, iNextY);
	PrepareForNextBatch(iNextY);

	/*
	* Hard coded Signum tests
	*/
	p1fFunc = Signum;
	funcChoice = EFunctions::SIGNUM;
	iNextY = InitiateOneFloatTest(funcChoice, 4.8f, 1.0f, p1fFunc, 0);
	iNextY = InitiateOneFloatTest(funcChoice, -17.2f, -1.0f, p1fFunc, iNextY);
	iNextY = InitiateOneFloatTest(funcChoice, 0.0f, 0.0f, p1fFunc, iNextY);
	iNextY = InitiateOneFloatTest(funcChoice, -5.1f, -1.0f, p1fFunc, iNextY);
	PrepareForNextBatch(iNextY);

	/*
	* Hard coded Floor tests
	*/
	p1fFunc = Floor;
	funcChoice = EFunctions::FLOOR;
	iNextY = InitiateOneFloatTest(funcChoice, 1.5f, 1.0f, p1fFunc, 0);
	iNextY = InitiateOneFloatTest(funcChoice, -1.001f, -2.0f, p1fFunc, iNextY);
	iNextY = InitiateOneFloatTest(funcChoice, 0.0f, 0.0f, p1fFunc, iNextY);
	iNextY = InitiateOneFloatTest(funcChoice, 1.001f, 1.0f, p1fFunc, iNextY);
	PrepareForNextBatch(iNextY);

	/*
	* Hard coded Ceiling tests
	*/
	p1fFunc = Ceiling;
	funcChoice = EFunctions::CEILING;
	iNextY = InitiateOneFloatTest(funcChoice, 8.9f, 9.0f, p1fFunc, 0);
	iNextY = InitiateOneFloatTest(funcChoice, -8.9f, -8.0f, p1fFunc, iNextY);
	iNextY = InitiateOneFloatTest(funcChoice, 0.0f, 0.0f, p1fFunc, iNextY);
	iNextY = InitiateOneFloatTest(funcChoice, 1.001f, 2.0f, p1fFunc, iNextY);
	PrepareForNextBatch(iNextY);

	/*
	* Hard coded Factorial tests
	*/
	funcChoice = EFunctions::FACTORIAL;
	iNextY = InitiateFactorialTest(6, 720, 0);
	iNextY = InitiateFactorialTest(7.5, -1, iNextY); //my factorial function returns -1 for undefined behaviour
	iNextY = InitiateFactorialTest(-1, -1, iNextY);
	iNextY = InitiateFactorialTest(12, 479001600, iNextY);
	std::cout << "Please note: this function has been programmed to return -1 in the event of invalid input, such as negatives or non-integers.";
	PrepareForNextBatch(iNextY);

	/*
	* Hard coded Combination tests
	*/
	p2dFunc = Combination;
	funcChoice = EFunctions::COMBINATION;
	iNextY = InitiateTwoDoubleTest(funcChoice, 6, 3, 20, p2dFunc, 0);
	iNextY = InitiateTwoDoubleTest(funcChoice, -1, 1, -1, p2dFunc, iNextY); 
	iNextY = InitiateTwoDoubleTest(funcChoice, 6.5, 5, -1, p2dFunc, iNextY);
	iNextY = InitiateTwoDoubleTest(funcChoice, 16, 10, 8008, p2dFunc, iNextY);
	std::cout << "Please note: this function has been programmed to return -1 in the event of invalid input, such as negatives or non-integers.";
	PrepareForNextBatch(iNextY);

	/*
	* Hard coded Permutation tests
	*/
	p2dFunc = Permutation;
	funcChoice = EFunctions::PERMUTATION;
	iNextY = InitiateTwoDoubleTest(funcChoice, 6, 3, 120, p2dFunc, 0);
	iNextY = InitiateTwoDoubleTest(funcChoice, -1, 1, -1, p2dFunc, iNextY);
	iNextY = InitiateTwoDoubleTest(funcChoice, 6.5, 3, -1, p2dFunc, iNextY);
	iNextY = InitiateTwoDoubleTest(funcChoice, 7, -1, -1, p2dFunc, iNextY);
	std::cout << "Please note: this function has been programmed to return -1 in the event of invalid input, such as negatives or non-integers.";
	int iY = GetCursorPos().Y;
	PrintCumulativeResults();
	GoToXY(0, iY + 2);

	SetRgb(EColour::COLOUR_RED_ON_BLACK);
	std::cout << "That concludes the pre-programmed numerical function testing.\n\n";
	std::cout << "Please press ENTER to continue.\n";

	string waitForInteraction = GetUserInput();
	ClearScreen();

}

/***********************************************
* HardcodedSetTests: runs 2-4 tests across each set function, testing different scenarios.
* @author: David Fransham
* @parameter: none
* @return: void
************************************************/
void HardcodedSetTests()
{
	TSet testSet1 = TSet();
	TSet testSet2 = TSet();
	TSet resultSet = TSet();
	TSet expectedSet = TSet();

	int (*p1rFunc)(TSet&) = nullptr;
	bool (*p2rFunc)(TSet&, TSet&) = nullptr;
	TSet& (*p3rFunc)(TSet&, TSet&, TSet&) = nullptr;
	EFunctions funcChoice;
	string waitForInput = "";

	int* elements = nullptr;
	int iSize = 5;
	int iY = 0;
	/*
	* Hard coded Cardinality tests
	*/
	funcChoice = EFunctions::CARDINALITY;
	p1rFunc = Cardinality;

	//TEST ONE
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);
	TestOneSetFunc(funcChoice, testSet1, iSize, p1rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 10;
	PopulateSetForTesting(testSet1, true, iSize);
	TestOneSetFunc(funcChoice, testSet1, iSize, p1rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 15;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 100 - (2 * i);
	}
	PopulateHardcodedSet(testSet1, elements, iSize);
	TestOneSetFunc(funcChoice, testSet1, iSize, p1rFunc);

	iY = GetCursorPos().Y;
	PrintCumulativeResults();
	GoToXY(0, iY + 1);

	SetRgb(EColour::COLOUR_RED_ON_BLACK);
	std::cout << "Testing program successful - error found in source code\n\n";
	std::cout << "Missing equals character means the 'AddElement' function is not working as intended.\n";
	std::cout << "As a result, the program is not adding the element 100 to the set when requested\n\n";
	std::cout << "Press ENTER to continue to next batch of tests.";
	waitForInput = GetUserInput();

	/*
	* Hard coded Power tests
	*/
	funcChoice = EFunctions::POWER;
	p1rFunc = Power;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);
	TestOneSetFunc(funcChoice, testSet1, 32, p1rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 10;
	PopulateSetForTesting(testSet1, true, iSize);
	TestOneSetFunc(funcChoice, testSet1, 1024, p1rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 15;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet1, elements, iSize);
	TestOneSetFunc(funcChoice, testSet1, 32768, p1rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1);

	/*
	* Hard coded Equals tests
	*/
	funcChoice = EFunctions::EQUALS_SET;
	p2rFunc = Equals;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);
	PopulateHardcodedSet(testSet2, elements, iSize);
	TestTwoSetFunc(funcChoice, testSet1, testSet2, true, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 10;
	PopulateSetForTesting(testSet1, true, iSize);
	PopulateSetForTesting(testSet2, true, iSize);
	TestTwoSetFunc(funcChoice, testSet1, testSet2, false, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 15;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet1, elements, iSize);

	delete[] elements;
	iSize = 14;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet2, elements, iSize);

	TestTwoSetFunc(funcChoice, testSet1, testSet2, false, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1);

	/*
	* Hard coded Subset tests
	*/
	funcChoice = EFunctions::SUBSET;
	p2rFunc = Subset;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);
	PopulateHardcodedSet(testSet2, elements, iSize);
	TestTwoSetFunc(funcChoice, testSet1, testSet2, true, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 10;
	PopulateSetForTesting(testSet1, true, iSize);
	PopulateSetForTesting(testSet2, true, iSize);
	TestTwoSetFunc(funcChoice, testSet1, testSet2, false, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 15;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}

	PopulateHardcodedSet(testSet1, elements, iSize);

	delete[] elements;
	iSize = 14;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet2, elements, iSize);

	TestTwoSetFunc(funcChoice, testSet2, testSet1, true, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1);

	/*
	* Hard coded Superset tests
	*/
	funcChoice = EFunctions::SUPERSET;
	p2rFunc = Superset;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);
	PopulateHardcodedSet(testSet2, elements, iSize);
	TestTwoSetFunc(funcChoice, testSet1, testSet2, true, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 10;
	PopulateSetForTesting(testSet1, true, iSize);
	PopulateSetForTesting(testSet2, true, iSize);
	TestTwoSetFunc(funcChoice, testSet1, testSet2, false, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 15;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}

	PopulateHardcodedSet(testSet1, elements, iSize);

	iSize = 14;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet2, elements, iSize);

	TestTwoSetFunc(funcChoice, testSet1, testSet2, true, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1);

	/*
	* Hard coded Union tests
	*/
	funcChoice = EFunctions::UNION;
	p3rFunc = Union;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 3;
	}

	PopulateHardcodedSet(testSet2, elements, iSize);

	iSize = 7;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(expectedSet, elements, iSize);

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 7;
	PopulateSetForTesting(testSet1, true, iSize);
	TestThreeSetFunc(funcChoice, testSet1, testSet1, resultSet, testSet1, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 89 - (2 * i);
	}
	PopulateHardcodedSet(testSet2, elements, iSize);

	iSize = 10;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(expectedSet, elements, iSize);

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST FOUR
	testSet1.SetUniversal();
	for (int i = 0; i < 95; i++)
	{
		testSet1.RemoveElement(i);
	}

	testSet2.SetClear();
	for (int i = 0; i < 5; i++)
	{
		testSet2.AddElement(i);
	}

	expectedSet.SetUniversal();
	for (int i = 5; i < 95; i++)
	{
		expectedSet.RemoveElement(i);
	}

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1);

	/*
	* Hard coded Intersection tests
	*/
	funcChoice = EFunctions::INTERSECTION;
	p3rFunc = Intersection;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 3;
	}

	PopulateHardcodedSet(testSet2, elements, iSize);

	iSize = 3;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 3;
	}

	PopulateHardcodedSet(expectedSet, elements, iSize);
	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 10;
	PopulateSetForTesting(testSet1, true, iSize);
	TestThreeSetFunc(funcChoice, testSet1, testSet1, resultSet, testSet1, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 15;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 69 - (2 * i);
	}
	PopulateHardcodedSet(testSet2, elements, iSize);

	expectedSet.SetClear();

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST FOUR
	testSet1.SetUniversal();
	for (int i = 0; i < 90; i++)
	{
		testSet1.RemoveElement(i);
	}

	testSet2.SetClear();
	for (int i = 85; i < 95; i++)
	{
		testSet2.AddElement(i);
	}

	iSize = 5;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 90;
	}

	PopulateHardcodedSet(expectedSet, elements, iSize);

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1);

	/*
	* Hard coded Disjoint tests
	*/
	funcChoice = EFunctions::DISJOINT;
	p2rFunc = Disjoint;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 3;
	}

	PopulateHardcodedSet(testSet2, elements, iSize);
	TestTwoSetFunc(funcChoice, testSet1, testSet2, false, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 10;
	}

	PopulateHardcodedSet(testSet2, elements, iSize);
	TestTwoSetFunc(funcChoice, testSet1, testSet2, true, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 15;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet1, elements, iSize);

	delete[] elements;
	iSize = 14;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet2, elements, iSize);

	TestTwoSetFunc(funcChoice, testSet1, testSet2, false, p2rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1);

	/*
	* Hard coded SetDifferencetests
	*/
	funcChoice = EFunctions::SET_DIFFERENCE;
	p3rFunc = SetDifference;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 3;
	}

	PopulateHardcodedSet(testSet2, elements, iSize);

	iSize = 2;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(expectedSet, elements, iSize);
	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 10;
	PopulateSetForTesting(testSet1, true, iSize);

	expectedSet.SetClear();
	TestThreeSetFunc(funcChoice, testSet1, testSet1, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 15;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 89 - (2 * i);
	}
	PopulateHardcodedSet(testSet2, elements, iSize);

	iSize = 5;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(expectedSet, elements, iSize);

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST FOUR
	testSet1.SetUniversal();
	for (int i = 0; i < 90; i++)
	{
		testSet1.RemoveElement(i);
	}

	testSet2.SetClear();
	for (int i = 85; i < 95; i++)
	{
		testSet2.AddElement(i);
	}

	expectedSet.SetUniversal();
	for (int i = 0; i < 95; i++)
	{
		expectedSet.RemoveElement(i);
	}

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1);

	/*
	* Hard coded SymmetricDifference tests
	*/
	funcChoice = EFunctions::SYMMETRIC_DIFFERENCE;
	p3rFunc = SymmetricDifference;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 3;
	}

	PopulateHardcodedSet(testSet2, elements, iSize);

	iSize = 4;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		if (i < 2)
		{
			elements[i] = i + 1;
		}
		else
		{
			elements[i] = i + 4;
		}
	}

	PopulateHardcodedSet(expectedSet, elements, iSize);

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 10;
	PopulateSetForTesting(testSet1, true, iSize);
	expectedSet.SetClear();
	TestThreeSetFunc(funcChoice, testSet1, testSet1, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST THREE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 89 - (2 * i);
	}
	PopulateHardcodedSet(testSet2, elements, iSize);

	iSize = 10;
	delete[] elements;
	elements = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = 99 - (2 * i);
	}
	PopulateHardcodedSet(expectedSet, elements, iSize);

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST FOUR
	testSet1.SetUniversal();
	for (int i = 0; i < 90; i++)
	{
		testSet1.RemoveElement(i);
	}

	testSet2.SetClear();
	for (int i = 85; i < 95; i++)
	{
		testSet2.AddElement(i);
	}

	expectedSet.SetUniversal();
	for (int i = 0; i < 85; i++)
	{
		expectedSet.RemoveElement(i);
	}
	for (int i = 90; i < 95; i++)
	{
		expectedSet.RemoveElement(i);
	}

	TestThreeSetFunc(funcChoice, testSet1, testSet2, resultSet, expectedSet, p3rFunc);
	PrepareForNextBatch(GetCursorPos().Y + 1);


	/*
	* Hard coded Compliment tests
	*/
	funcChoice = EFunctions::COMPLEMENT;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}
	PopulateHardcodedSet(testSet1, elements, iSize);

	expectedSet.SetUniversal();
	for (int i = 1; i <= iSize; i++)
	{
		expectedSet.RemoveElement(i);
	}

	TestComplement(testSet1, expectedSet);

	std::cout << "Press ENTER to continue.";
	waitForInput = GetUserInput();

	//TEST TWO
	testSet2.SetUniversal();
	for (int i = 1; i <= 45; i++)
	{
		testSet2.RemoveElement(i);
	}

	iSize = 45;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}
	PopulateHardcodedSet(expectedSet, elements, iSize);

	TestComplement(testSet2, expectedSet);

	std::cout << "Press ENTER to continue.";
	waitForInput = GetUserInput();

	/*ClearScreen();
	PrintCumulativeResults();
	GoToXY(0, 0);
	std::cout << "Press ENTER to continue.";
	waitForInput = GetUserInput();*/

	/*
	* Hard coded CartesianProduct tests
	*/
	funcChoice = EFunctions::CARTESIAN_PRODUCT;

	//TEST ONE
	iSize = 5;
	delete[] elements;
	elements = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 1;
	}

	PopulateHardcodedSet(testSet1, elements, iSize);

	for (int i = 0; i < iSize; i++)
	{
		elements[i] = i + 10;
	}

	PopulateHardcodedSet(testSet2, elements, iSize);

	TestCartesianProduct(testSet1, testSet2, (iSize * iSize));
	PrepareForNextBatch(GetCursorPos().Y + 1, false);

	//TEST TWO
	iSize = 10;
	PopulateSetForTesting(testSet1, true, iSize);
	PopulateSetForTesting(testSet2, true, iSize);
	TestCartesianProduct(testSet1, testSet2, (iSize * iSize));

	iY = GetCursorPos().Y;
	PrintCumulativeResults();
	GoToXY(0, iY + 2);

	SetRgb(EColour::COLOUR_RED_ON_BLACK);
	std::cout << "That concludes the pre-programmed set function testing.\n\n";
	std::cout << "Please press ENTER to continue.\n";

	string waitForInteraction = GetUserInput();
	ClearScreen();

	delete[] elements;
	elements = nullptr;
}

/***********************************************
* RunTestingProgram: prints menu, asks user for input then calls the tests
* @author: David Fransham
* @parameter: none
* @return: none
************************************************/
void RunManualTests()
{
	g_bUserTests = true;
	while (true) //infinite loop
	{
		ClearScreen();
		PrintCumulativeResults();
		PrintFunctionMenu();
		int iChoice = GetInt(true, 1, 21);
		if (iChoice == 21)
		{
			g_bUserTests = false;
			return;
		}
		ClearScreen();
		InitiateFunction(static_cast<EFunctions>(iChoice - 1));
	}
}

/***********************************************
* InitiateFunction: initiates the testing of the function specified by user
* @author: David Fransham
* @parameter: Enumerated function name to start
* @return: void
************************************************/
void InitiateFunction(const EFunctions _keChoice)
{
	float (*p1fFunc)(float) = nullptr;
	double (*p2dFunc)(double, double) = nullptr;
	int (*p1rFunc)(TSet&) = nullptr;
	bool (*p2rFunc)(TSet& ,TSet&) = nullptr;
	TSet& (*p3rFunc)(TSet&, TSet&, TSet&) = nullptr;

	string pauseToRead = "";
	bool bRepeat = true;
	while (bRepeat)
	{
		switch (_keChoice)
		{
		case EFunctions::EQUALS_FLOAT:
			InitiateEqualsTest(0.0f);
			break;

		case EFunctions::MAGNITUDE:
			p1fFunc = Magnitude;
			InitiateOneFloatTest(p1fFunc,_keChoice);
			break;

		case EFunctions::SIGNUM:
			p1fFunc = Signum;
			InitiateOneFloatTest(p1fFunc, _keChoice);
			break;

		case EFunctions::FLOOR:
			p1fFunc = Floor;
			InitiateOneFloatTest(p1fFunc, _keChoice);
			break;

		case EFunctions::CEILING:
			p1fFunc = Ceiling;
			InitiateOneFloatTest(p1fFunc, _keChoice);
			break;

		case EFunctions::FACTORIAL:
			InitiateFactorialTest();
			break;

		case EFunctions::COMBINATION:
			p2dFunc = Combination;
			InitiateTwoDoubleTest(p2dFunc, _keChoice);
			break;

		case EFunctions::PERMUTATION:
			p2dFunc = Permutation;
			InitiateTwoDoubleTest(p2dFunc, _keChoice);
			break;

		case EFunctions::CARDINALITY:
			p1rFunc = Cardinality;
			InitiateOneSetTest(p1rFunc, _keChoice);
			break;

		case EFunctions::POWER:
			p1rFunc = Power;
			InitiateOneSetTest(p1rFunc, _keChoice);
			break;

		case EFunctions::EQUALS_SET:
			p2rFunc = Equals;
			InitiateTwoSetTest(p2rFunc, _keChoice);
			break;

		case EFunctions::SUBSET:
			p2rFunc = Subset;
			InitiateTwoSetTest(p2rFunc, _keChoice);
			break;

		case EFunctions::SUPERSET:
			p2rFunc = Superset;
			InitiateTwoSetTest(p2rFunc, _keChoice);
			break;

		case EFunctions::UNION:
			p3rFunc = Union;
			InitiateThreeSetTest(p3rFunc, _keChoice);
			break;

		case EFunctions::INTERSECTION:
			p3rFunc = Intersection;
			InitiateThreeSetTest(p3rFunc, _keChoice);
			break;

		case EFunctions::DISJOINT:
			p2rFunc = Disjoint;
			InitiateTwoSetTest(p2rFunc, _keChoice);
			break;

		case EFunctions::SET_DIFFERENCE:
			p3rFunc = SetDifference;
			InitiateThreeSetTest(p3rFunc, _keChoice);
			break;

		case EFunctions::SYMMETRIC_DIFFERENCE:
			p3rFunc = SymmetricDifference;
			InitiateThreeSetTest(p3rFunc, _keChoice);
			break;

		case EFunctions::COMPLEMENT:
			InitiateComplementTest();
			break;

		case EFunctions::CARTESIAN_PRODUCT:
			InitiateCartesianProductTest();
			break;

		default:
			break;
		}
		bRepeat = !TakeInputRepeatTest();
	}
}

/***********************************************
* IncrementCounters: increments the global variables counting numbers of tests, including array of individual function tests
* @author: David Fransham
* @parameter: boolean indicating success or failure, enumerated function name to be counted
* @return: void
************************************************/
void IncrementCounters(const bool _kbResult, const EFunctions _keFuncTested)
{
	g_iTestsPerformed++;
	g_iFuncTestCounter[static_cast<int>(_keFuncTested)][0]++;
	if (_kbResult)
	{
		g_iTestsPassed++;
		g_iFuncTestCounter[static_cast<int>(_keFuncTested)][1]++;
	}
}

//Numerical test functions

/***********************************************
* InitiateSingleFloatTest: for hardcoded tests: prints header, calls test function, returns y cursor position
* @author: David Fransham
* @parameter: function pointer (float), function enum name, floats to test, int for row to print on
* @return: int representing next row for cursor to print tidily
************************************************/
int InitiateOneFloatTest(EFunctions _eFuncChoice, const float _kfA, const float _kfB,
	float (*_p1fFunc)(float), const int _kiYpos)
{
	PrintIndividualTestHeader(_eFuncChoice, 0, _kiYpos);
	TestOneFloatFunc(_kfA, _kfB, _p1fFunc, _eFuncChoice);
	return(GetCursorPos().Y + 1);
}

/***********************************************
* TestOneFloatFunc: calls single float function by pointer, compares result to given expected value
* @author: David Fransham
* @parameter: function pointer to a float in/float out function, value to calculate, expected value, and enum function name for printing.
* @return: void
************************************************/
void TestOneFloatFunc(const float _kfTestValue, const float _kfExpectedValue,
	float (*pfOneFunc)(float), EFunctions _eChoice)
{
	float functionReturn = pfOneFunc(_kfTestValue);

	bool result = Equals(functionReturn, _kfExpectedValue, 0.0001f);

	SetRgb(EColour::COLOUR_BLUE_ON_BLACK);
	std::cout << "\nFloat data == " << _kfTestValue;
	std::cout << "\nCalculated result == " << functionReturn;
	std::cout << "\nExpected result == " << _kfExpectedValue;
	PrintTestResult(result);

	IncrementCounters(result, _eChoice);
}

/***********************************************
* InitiateOneFloatTest: asks user for input to call the Test function for a single float operation
* @author: David Fransham
* @parameter: function pointer to a float in/float out function, and an enum function name for printing purposes.
* @return: void
************************************************/
void InitiateOneFloatTest(float (*pfOneFunc)(float), EFunctions _eChoice)
{
	PrintIndividualTestHeader(_eChoice);

	std::cout << "Enter a float value: ";
	float fTestValue = GetFloat();

	std::cout << "Enter expected value of function: ";
	float fExpectedValue = GetFloat();

	TestOneFloatFunc(fTestValue, fExpectedValue, pfOneFunc, _eChoice);
}

/***********************************************
* InitiateTwoDoubleTest: for hardcoded tests: prints header, calls test function, returns y cursor position
* @author: David Fransham
* @parameter: function pointer (doubles), function enum name, doubles to test, int for row to print on
* @return: int representing next row for cursor to print tidily
************************************************/
int InitiateTwoDoubleTest(EFunctions _eFuncChoice, const double _kDA, const double _kDB, const double _kdEx,
	double (*_p2dFunc)(double, double), const int _kiYpos)
{
	PrintIndividualTestHeader(_eFuncChoice, 0, _kiYpos);
	TestTwoDoubleFunc(_kDA, _kDB, _kdEx, _p2dFunc, _eFuncChoice);
	return(GetCursorPos().Y + 1);
}

/***********************************************
* InitiateTwoDoubleTest: asks user for input to call the Test function for a double double operation (Combination/Permutation)
* @author: David Fransham
* @parameter: function pointer to a two double in/double out function, and an enum function name for printing purposes.
* @return: void
************************************************/
void InitiateTwoDoubleTest(double (*pdTwoFunc)(double, double), EFunctions _eChoice)
{
	PrintIndividualTestHeader(_eChoice);
	double dTestTotal = 0.0;
	double dTestSelection = 0.0;
	std::cout << "Enter number of items selecting from (N): ";
	bool tryAgain = true;
	while (tryAgain)
	{
		dTestTotal = GetDouble(true, 0, 170);
		float rN = static_cast<float>(dTestTotal);
		if (!Equals(Floor(rN), rN, 0.0001f))
		{
		std::cout << "Be reasonable. You can't choose from a group including half a person.  Integers only please.\n";
		}
		else
		{
			tryAgain = false;
		}
	}
	tryAgain = true;
	std::cout << "Enter number of items to be selected (R): ";
	while (tryAgain)
	{
		dTestSelection = GetDouble(true, 0, dTestTotal);
		float fR = static_cast<float>(dTestSelection);
		if (!Equals(Floor(fR), fR, 0.0001f))
		{
			std::cout << "Come now. You can't choose half a person.  Integers only please.\n";
		}
		else
		{
			tryAgain = false;
		}
	}

	std::cout << "Enter expected value of function: ";
	double dExpected = GetFloat();

	TestTwoDoubleFunc(dTestTotal, dTestSelection, dExpected, pdTwoFunc, _eChoice);
}

/***********************************************
* TestTwoDoubleFunc: calls double float function by pointer, compares result to given expected value
* @author: David Fransham
* @parameter: function pointer to a 2double in/double out function, value to calculate, expected value, and enum function name for printing.
* @return: void
************************************************/
void TestTwoDoubleFunc(const double _kdTestValA, const double _kdTestValB, const double _kdExpected,
	double (*pdTwoFunc)(double, double), EFunctions _eChoice)
{
	double dFuncReturn = pdTwoFunc(_kdTestValA, _kdTestValB);

	bool result = Equals(static_cast<float>(dFuncReturn), static_cast<float>(_kdExpected), 0.0001f);
	SetRgb(EColour::COLOUR_BLUE_ON_BLACK);
	std::cout << "\nTotal number == " << _kdTestValA;
	std::cout << "\nRequired number == " << _kdTestValB;
	std::cout << "\nCalculated result == " << dFuncReturn;
	std::cout << "\nExpected result == " << _kdExpected;
	PrintTestResult(result);

	IncrementCounters(result, _eChoice);
}

/***********************************************
* InitiateEqualsTest: for hardcoded tests: prints header, runs test, returns y cursor position
* @author: David Fransham
* @parameter: floats to test, int for row to print on, bool of expected value
* @return: int representing next row for cursor to print tidily
************************************************/
int InitiateEqualsTest(const float _kfA, const float _kfB, const float _kfPrecision, const bool _kbExpected, const int _kiYpos)
{
	PrintIndividualTestHeader(EFunctions::EQUALS_FLOAT, 0, _kiYpos);
	TestEquals(_kfA, _kfB, _kfPrecision, _kbExpected);
	return(GetCursorPos().Y + 1);
}

/***********************************************
* InitiateEqualsTest: asks user for input to call the TestEquals function for comparing floats
* @author: David Fransham
* @parameter: nonsense float variable purely to differentiate this function from the Equals function for Sets.
* @return: void
************************************************/
void InitiateEqualsTest(const float _kfSignatureIdentifier)
{
	PrintIndividualTestHeader(EFunctions::EQUALS_FLOAT);

	std::cout << "Enter first float value: ";
	float fTestValueA = GetFloat();

	std::cout << "Enter second float value: ";
	float fTestValueB = GetFloat();

	std::cout << "Enter precision value (float): ";
	float fPrecision = Magnitude(GetFloat());

	std::cout << "Enter expected value of Equals function (true = 1/false = 0): ";
	bool bRepeat = true;
	bool bExpectedValue;
	string sInput = "";
	while (bRepeat)
	{
		sInput = GetUserInput();
		if (sInput == "true" || sInput == "TRUE" || sInput == "1")
		{
			bExpectedValue = true;
			bRepeat = false;
		}
		else if (sInput == "false" || sInput == "FALSE" || sInput == "0")
		{
			bExpectedValue = false;
			bRepeat = false;
		}
		else
		{
			std::cout << "Invalid input.  Please type TRUE or FALSE: ";
		}
	}

	TestEquals(fTestValueA, fTestValueB, fPrecision, bExpectedValue);
	PrintCumulativeResults();
}

/***********************************************
* TestEquals (floats): calls equals function to test the validity of the comparison being made
* @author: David Fransham
* @parameter: float value A, float value B, desired precision level, boolean indicating expected return
* @return: void
************************************************/
void TestEquals(const float _kfTestValueA, const float _kfTestValueB,
	const float _kfPrecision, const bool _kbExpectedValue)
{
	bool bFunctionReturn = Equals(_kfTestValueA, _kfTestValueB, _kfPrecision);
	SetRgb(EColour::COLOUR_BLUE_ON_BLACK);
	std::cout << "\nFloat data one == " << _kfTestValueA;
	std::cout << "\nFloat data two == " << _kfTestValueB;
	std::cout << "\nPrecision level == " << _kfPrecision;
	std::cout << "\nCalculated result == " << bFunctionReturn;
	std::cout << "\nExpected result == " << _kbExpectedValue;
	PrintTestResult((bFunctionReturn == _kbExpectedValue));

	IncrementCounters(((bFunctionReturn == _kbExpectedValue)), EFunctions::EQUALS_FLOAT);
}

/***********************************************
* InitiateFactorialTest: for hardcoded tests: prints header, runs test, returns y cursor position
* @author: David Fransham
* @parameter: double to test, int for row to print on, double of expected value
* @return: int representing next row for cursor to print tidily
************************************************/
int InitiateFactorialTest(const double _kdTest, const double _kdExpected, const int _kiYpos)
{
	PrintIndividualTestHeader(EFunctions::FACTORIAL, 0, _kiYpos);
	TestFactorial(_kdTest, _kdExpected);
	return(GetCursorPos().Y + 1);
}

/***********************************************
* InitiateFactorialTest: asks user for input to call the TestFactorial function calculating factorials
* @author: David Fransham
* @parameter: none
* @return: void
************************************************/
void InitiateFactorialTest()
{
	PrintIndividualTestHeader(EFunctions::FACTORIAL);

	bool bRepeat = true;
	double dExpected, dTestInput;
	float fTestInput;
	std::cout << "Enter value: ";
	while (bRepeat)
	{
		dTestInput = GetDouble();
		fTestInput = static_cast<float>(dTestInput);
		if (dTestInput > 170)
		{
			std::cout << "The result of that calculation may as well be infinite.  Try something smaller.\n";
		}
		else if ((static_cast<float>(dTestInput) < 0) || (!Equals(Floor(fTestInput), fTestInput, 0.0001f)))
		{
			std::cout << "Factorials are only defined for non-negative integers. Please try again.\n";
		}
		else
		{
			std::cout << "Enter expected value of Factorial function: ";
			dExpected = GetDouble();
			bRepeat = false;
		}
	}
	
	TestFactorial(dTestInput, dExpected);

	PrintCumulativeResults();
}

/***********************************************
* TestFactorial: calls Factorial function to test function against given expected value
* @author: David Fransham
* @parameter: float value A, float value B, desired precision level, boolean indicating expected return
* @return: void
************************************************/
void TestFactorial(const double _kdTestValue, const double _kdExpectedValue)
{
	double dFunctionReturn = Factorial(_kdTestValue);
	SetRgb(EColour::COLOUR_BLUE_ON_BLACK);
	std::cout << "\nInput value (double) == " << _kdTestValue;
	std::cout << "\nCalculated result == " << dFunctionReturn;
	std::cout << "\nExpected result == " << _kdExpectedValue;
	PrintTestResult((dFunctionReturn == _kdExpectedValue));

	IncrementCounters(((dFunctionReturn == _kdExpectedValue)), EFunctions::FACTORIAL);
}

//Set Function Tests

/***********************************************
* InitiateComplementTest: asks user for input, or allows computer to populate sets, to call the relevant Test function
* @author: David Fransham
* @parameter: none
* @return: void
************************************************/
void InitiateComplementTest()
{
	ClearScreen();
	PrintIndividualTestHeader(EFunctions::COMPLEMENT);

	TSet testSet = TSet();
	SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
	std::cout << "Would you like to populate the test set or let the program do it randomly?\n";
	std::cout << "1: Populate set manually;\n2: Randomly populate set.\n";
	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
	bool bChoice = GetInt(true, 1, 2) - 1;

	PopulateSetForTesting(testSet, bChoice);

	TSet expectedSet = TSet();

	if (!bChoice)
	{
		SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
		std::cout << "Would you like to populate the expected set or let the program do it for you?\n";
		std::cout << "1: Populate set manually;\n2: Allow program to do it.\n";
		SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
		bChoice = GetInt(true, 1, 2) - 1;
	}

	switch (bChoice)
	{
	case 0:
		PopulateSetForTesting(expectedSet, bChoice);
		break;
	case 1:
		for (int i = 1; i <= SET_SIZE_MAX; i++)
		{
			if (!testSet.ContainsElement(i))
			{
				expectedSet.AddElement(i);
			}
		}
	}

	TestComplement(testSet,expectedSet);
}

/***********************************************
* TestComplement: calls Complement function to test function against given expected result
* @author: David Fransham
* @parameter: TSet address A, TSet address of expected result for comparison
* @return: void
************************************************/
void TestComplement(TSet& _rA, TSet& _rExpected)
{
	ClearScreen();
	//PrintIndividualTestHeader(EFunctions::COMPLEMENT);

	SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
	std::cout << "Testing the " << g_sFuncNameArray[static_cast<int>(EFunctions::COMPLEMENT)] << " function.\n";

	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);

	std::cout << "Test set:";
	_rA.Print();
	std::cout << "\nSize of set: " << Cardinality(_rA) << "\n";

	std::cout << "\nExpected complement set:";
	_rExpected.Print();

	Compliment(_rA);

	std::cout << "\nCalculated result set:";
	_rA.Print();
	std::cout << "\nSize of set: " << Cardinality(_rA) << "\n";

	bool success = Equals(_rA, _rExpected);

	PrintTestResult(success);

	IncrementCounters(success, EFunctions::COMPLEMENT);
}

/***********************************************
* InitiateCartesianProductTest: asks user for input, or allows computer to populate sets, to call the relevant Test function
* @author: David Fransham
* @parameter: none
* @return: void
************************************************/
void InitiateCartesianProductTest()
{
	PrintIndividualTestHeader(EFunctions::CARTESIAN_PRODUCT);

	TSet testSetA = TSet();
	SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
	std::cout << "Would you like to populate the first set or let the program do it randomly?\n";
	std::cout << "1: Populate set manually;\n2: Randomly populate set.\n";
	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
	bool bChoice = GetInt(true, 1, 2) - 1;

	PopulateSetForTesting(testSetA, bChoice);

	TSet testSetB = TSet();

	if (!bChoice)
	{
		SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
		std::cout << "Would you like to populate the second set or let the program do it for you?\n";
		std::cout << "1: Populate set manually;\n2: Allow program to do it.\n";
		SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
		bChoice = GetInt(true, 1, 2) - 1;
	}
	PopulateSetForTesting(testSetB, bChoice);

	ClearScreen();

	SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
	std::cout << "Testing the " << g_sFuncNameArray[static_cast<int>(EFunctions::CARTESIAN_PRODUCT)] << " function.\n";

	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);

	std::cout << "First set:";
	testSetA.Print();
	std::cout << "\nSize of set: " << Cardinality(testSetA) << "\n\n";

	std::cout << "Second set:";
	testSetB.Print();
	std::cout << "\nSize of set: " << Cardinality(testSetB) << "\n\n";

	std::cout << "Please enter expected size of the Cartesian Product: ";
	int iExpected = GetInt();

	TestCartesianProduct(testSetA, testSetB, iExpected);
}

/***********************************************
* TestCartesianProduct: calls cartesian product function to test function against given expected result
* @author: David Fransham
* @parameter: TSet addresss A and B, and int of expected result
* @return: void
************************************************/
void TestCartesianProduct(TSet& _rA, TSet& _rB, int _iExpected)
{
	ClearScreen();
	//PrintIndividualTestHeader(EFunctions::CARTESIAN_PRODUCT);

	SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
	std::cout << "Testing the " << g_sFuncNameArray[static_cast<int>(EFunctions::CARTESIAN_PRODUCT)] << " function.\n";

	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);

	std::cout << "Size of set A: " << Cardinality(_rA) << "\n";
	std::cout << "Size of set B: " << Cardinality(_rB) << "\n\n";

	std::cout << "Expected size of cartesian product: " << _iExpected;
	int iResult = CartesianProduct(_rA, _rB);
	std::cout << "\nCalculated size of cartesian product: " << iResult;
	
	PrintTestResult(_iExpected == iResult);

	IncrementCounters((_iExpected == iResult), EFunctions::CARTESIAN_PRODUCT);
}

/***********************************************
* InitiateOneSetTest: calls single set function by pointer, compares result to given expected value
* @author: David Fransham
* @parameter: function pointer to a set in/int out function, enum function name for printing.
* @return: void
************************************************/
void InitiateOneSetTest(int (*prFunc)(TSet&), EFunctions _eChoice)
{
	PrintIndividualTestHeader(_eChoice);

	TSet testSet = TSet();
	SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
	std::cout << "Would you like to populate the test set or let the program do it randomly?\n";
	std::cout << "1: Populate set manually;\n2: Randomly populate set.\n";
	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
	bool bChoice = GetInt(true, 1, 2) - 1;

	PopulateSetForTesting(testSet, bChoice);

	ClearScreen();
	PrintIndividualTestHeader(_eChoice);

	std::cout << "Your set:";
	testSet.Print();

	std::cout << "\n\nEnter expected value for the " << g_sFuncNameArray[static_cast<int>(_eChoice)] << " function.\n";
	int iExpected = GetInt();

	TestOneSetFunc(_eChoice, testSet, iExpected, prFunc);
}

/***********************************************
* TestOneSetFunc: calls (Tset in|int out) function to test function against given expected result
* @author: David Fransham
* @parameter: Enum function name, TSet addresss A to test, int of expected result, relevant function pointer
* @return: void
************************************************/
void TestOneSetFunc(EFunctions _eFuncChoice, TSet& _rA, const int _kiExpected, int (*_p1rFunc)(TSet&))
{
	ClearScreen();
	PrintIndividualTestHeader(_eFuncChoice);

	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);

	int iResult = _p1rFunc(_rA);

	std::cout << "Test set:";
	_rA.Print();
	std::cout << "\nSize of set: " << Cardinality(_rA) << "\n";

	std::cout << "\nExpected result of the function: " << _kiExpected;
	std::cout << "\nCalculated result: " << iResult << std::endl;

	PrintTestResult(_kiExpected == iResult);

	IncrementCounters((_kiExpected == iResult), _eFuncChoice);
}

/***********************************************
* InitiateTwoSetTest: calls double set function by pointer, compares result to given expected value
* @author: David Fransham
* @parameter: function pointer to a (2x set in|bool out) function, enum function name for printing.
* @return: void
************************************************/
void InitiateTwoSetTest(bool (*_p2rFunc)(TSet&, TSet&), EFunctions _eChoice)
{
	PrintIndividualTestHeader(_eChoice);

	TSet testSetA = TSet();
	SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
	std::cout << "Would you like to populate the test set or let the program do it randomly?\n";
	std::cout << "1: Populate set manually;\n2: Randomly populate set.\n";
	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
	bool bChoice = GetInt(true, 1, 2) - 1;

	PopulateSetForTesting(testSetA, bChoice);

	TSet testSetB = TSet();

	if (!bChoice)
	{
		SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
		std::cout << "Would you like to populate the second set or let the program do it for you?\n";
		std::cout << "1: Populate set manually;\n2: Randomly populate set.\n";
		SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
		bool bChoice = GetInt(true, 1, 2) - 1;
	}
	PopulateSetForTesting(testSetB, bChoice);

	PrintIndividualTestHeader(_eChoice);

	std::cout << "Set A:";
	testSetA.Print();
	std::cout << "\nSize of set: " << Cardinality(testSetA) << "\n";

	std::cout << "\nSet B:";
	testSetB.Print();
	std::cout << "\nSize of set: " << Cardinality(testSetB) << "\n";
	
	std::cout << "\nEnter expected value for the " << g_sFuncNameArray[static_cast<int>(_eChoice)] << " function.\n";
	std::cout << "1: True; 0: False:";
	bool bExpected = GetInt(true);

	TestTwoSetFunc(_eChoice, testSetA, testSetB, bExpected, _p2rFunc);
}

/***********************************************
* TestTwoSetFunc: calls (2x Tset in|bool out) function to test function against given expected result
* @author: David Fransham
* @parameter: Enum function name, TSet addressss to test, bool of expected result, relevant function pointer
* @return: void
************************************************/
void TestTwoSetFunc(EFunctions _eFuncChoice, TSet& _rA, TSet& _rB, bool _bExpected,
	bool (*_p2rFunc)(TSet&, TSet&))
{
	ClearScreen();
	PrintIndividualTestHeader(_eFuncChoice);

	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);

	bool bResult = _p2rFunc(_rA,_rB);

	std::cout << "Set A:";
	_rA.Print();
	std::cout << "\nSize of set: " << Cardinality(_rA) << "\n";

	std::cout << "\nSet B:";
	_rB.Print();
	std::cout << "\nSize of set: " << Cardinality(_rB) << "\n";

	std::cout << "\nExpected result of the function: " << _bExpected;
	std::cout << "\nCalculated result: " << bResult << std::endl;

	PrintTestResult(_bExpected == bResult);

	IncrementCounters((_bExpected == bResult), _eFuncChoice);
}

/***********************************************
* InitiateThreeSetTest: calls 3xTset function by pointer, compares result to given expected value
* @author: David Fransham
* @parameter: function pointer to a (3set in|tset out) function, enum function name for printing.
* @return: void
************************************************/
void InitiateThreeSetTest(TSet& (*_p3rFunc)(TSet&, TSet&, TSet&), EFunctions _eChoice)
{
	PrintIndividualTestHeader(_eChoice);

	TSet testSetA = TSet();
	SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
	std::cout << "Would you like to populate the test set or let the program do it randomly?\n";
	std::cout << "1: Populate set manually;\n2: Randomly populate set.\n";
	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
	bool bChoice = GetInt(true, 1, 2) - 1;

	PopulateSetForTesting(testSetA, bChoice);

	TSet testSetB = TSet();

	if (!bChoice)
	{
		SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
		std::cout << "\nWould you like to populate the second set or let the program do it for you?\n";
		std::cout << "1: Populate set manually;\n2: Randomly populate set.\n";
		SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
		bChoice = GetInt(true, 1, 2) - 1;
	}
	PopulateSetForTesting(testSetB, bChoice);

	PrintIndividualTestHeader(_eChoice);

	std::cout << "Set A:";
	testSetA.Print();
	std::cout << "\nSize of set: " << Cardinality(testSetA) << "\n";

	std::cout << "\nSet B:";
	testSetB.Print();
	std::cout << "\nSize of set: " << Cardinality(testSetB) << "\n";

	TSet expectedSet = TSet();
	SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
	std::cout << "\nWould you like to enter the expected set manually or let the program calculate it?\n";
	std::cout << "1: Populate set manually;\n2: Randomly populate set.\n";
	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
	bChoice = GetInt(true, 1, 2) - 1;

	if (bChoice)
	{
		CalculateSetExpectation(_eChoice, _p3rFunc, testSetA, testSetB, expectedSet);
	}
	else
	{
		PopulateSetForTesting(expectedSet, bChoice);
	}

	TSet resultSet = TSet();

	TestThreeSetFunc(_eChoice, testSetA, testSetB, resultSet, expectedSet, _p3rFunc);
}

/***********************************************
* TestThreeSetFunc: calls (3x Tset in|tset out) function to test function against given expected result
* @author: David Fransham
* @parameter: Enum function name, TSet addressss to test/expected set/return set, relevant function pointer
* @return: void
************************************************/
void TestThreeSetFunc(EFunctions _eFuncChoice, TSet& _rA, TSet& _rB, TSet& _resultant, TSet& _rExpected,
	TSet& (*_p3rFunc)(TSet&, TSet&, TSet&))
{
	ClearScreen();

	SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
	std::cout << "Testing the " << g_sFuncNameArray[static_cast<int>(_eFuncChoice)] << " function.\n";

	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);

	_p3rFunc(_rA, _rB, _resultant);

	std::cout << "Set A:";
	_rA.Print();
	std::cout << "\nSize of set: " << Cardinality(_rA) << "\n";

	std::cout << "\nSet B:";
	_rB.Print();
	std::cout << "\nSize of set: " << Cardinality(_rB) << "\n";

	std::cout << "\nExpected result set:";
	_rExpected.Print();

	std::cout << "\n\nCalculated result set:";
	_resultant.Print();

	bool bResult = Equals(_rExpected, _resultant);

	PrintTestResult(bResult);

	IncrementCounters(bResult, _eFuncChoice);
}

/***********************************************
* CalculateSetExpectation: attempts to calculate the expected result set from a three-set function
* @author: David Fransham
* @parameter: Enum function name, relevant function pointer, TSet addressss to test/expected set to return
* @return: void
************************************************/
void CalculateSetExpectation(EFunctions _eFuncChoice, TSet& (*_p3rFunc)(TSet&, TSet&, TSet&),
	TSet& _rA, TSet& _rB,TSet& _expectedResult)
{
	switch (_eFuncChoice)
	{
	case EFunctions::UNION:
		for (int i = 1; i <= SET_SIZE_MAX; i++)
		{
			if (_rA.ContainsElement(i) || _rB.ContainsElement(i))
			{
				_expectedResult.AddElement(i);
			}
		}
		break;

	case EFunctions::INTERSECTION:
		for (int i = 1; i <= SET_SIZE_MAX; i++)
		{
			if (_rA.ContainsElement(i) && _rB.ContainsElement(i))
			{
				_expectedResult.AddElement(i);
			}
		}
		break;

	case EFunctions::SET_DIFFERENCE:
		for (int i = 1; i <= SET_SIZE_MAX; i++)
		{
			if (_rB.ContainsElement(i))
			{
				_expectedResult.RemoveElement(i);
			}
		}
		break;

	case EFunctions::SYMMETRIC_DIFFERENCE:
		for (int i = 1; i <= SET_SIZE_MAX; i++)
		{
			if ((_rA.ContainsElement(i) || _rB.ContainsElement(i)) && !(_rA.ContainsElement(i) && _rB.ContainsElement(i)))
			{
				_expectedResult.AddElement(i);
			}
		}
		break;
	}
}

/***********************************************
* PopulateHardcodedSet: populates a testing set with values for hardcoded test implementation
* @author: David Fransham
* @parameter: TSet address to populate, array of elements to add, int representing size
* @return: void
************************************************/
void PopulateHardcodedSet(TSet& _setForTesting, int _iElements[], int _iSize)
{
	_setForTesting.SetClear();

	for (int i = 0; i < _iSize; i++)
	{
		_setForTesting.AddElement(_iElements[i]);
	}
}

/***********************************************
* PopulateSetForTesting: populates a testing set with values for test implementation
* @author: David Fransham
* @parameter: TSet address to populate, optional bool to randomly allocate elements, optional int to specify size
* @return: void
************************************************/
void PopulateSetForTesting(TSet& _setToPopulate, bool _random, int _iSize)
{
	int iSize;
	int iElementToAdd;

	_setToPopulate.SetClear();

	if (!_random)
	{
		std::cout << "How many items would you like to populate your set with? (1-100):";
		iSize = GetInt(true, 1, 100);
	}
	else if (_iSize != 0)
	{
		iSize = _iSize;
	}
	else
	{
		//capped to 15 as any more than that is just painful at the next step
		iSize = GetRandomNumber(15, 1);
	}
	bool repeat;

	for (int i = 0; i < iSize; i++)
	{
		repeat = true;
		while (repeat)
		{
			if (!_random)
			{
				std::cout << "Enter a number to add to your set (1-100):";
				iElementToAdd = GetInt(true, 1, 100);
			}
			else
			{
				//capped to 99 instead of 100 due to error in AddElement()
				//some tests were failing as 100 was randomly being selected and not added to array
				iElementToAdd = GetRandomNumber(99, 1);
			}

			if (!_setToPopulate.ContainsElement(iElementToAdd))
			{
				if (iElementToAdd == 100)
				{
					AddElement100(_setToPopulate);
				}
				else
				{
					_setToPopulate.AddElement(iElementToAdd);
				}
				repeat = false;
				if (!_random)
				{
					std::cout << "Element added successfully\n";
				}
			}
			else
			{
				if (!_random)
				{
					std::cout << "Element already added to set.  Please try another number.\n";
				}
			}
		}
	}
	SetRgb(EColour::COLOUR_MAGENTA_ON_BLACK);
	std::cout << "\nSet successfully populated with " << iSize << " elements.\n";
}

/***********************************************
* AddElement100: adds element 100 to sets at user request - can't use AddElement due to typographical error.
* @author: David Fransham
* @parameter: TSet address to add 100 to
* @return: void
************************************************/
void AddElement100(TSet& _setToCopy)
{
	TSet tempSet = TSet();

	for (int i = 1; i < SET_SIZE_MAX; i++)
	{
		if (_setToCopy.ContainsElement(i))
		{
			tempSet.AddElement(i);
		}
	}

	_setToCopy.SetUniversal();
	for (int i = 1; i < SET_SIZE_MAX; i++)
	{
		if (!tempSet.ContainsElement(i))
		{
			_setToCopy.RemoveElement(i);
		}
	}
}

//Specific Set function Logic tests

/***********************************************
* LogicTestsPrintSet: prints the relevant information for the tests to be verified visually on screen
* @author: David Fransham
* @parameter: set address to print, index identifying which set is being printed
* @return: void
************************************************/
void LogicTestsPrintSet(TSet& _rPrint, const int _iSetIndex)
{
	EColour desired = EColour::COLOUR_GREEN_ON_BLACK;
	string toprint = "";

	switch (_iSetIndex)
	{
	case 1:
		desired = EColour::COLOUR_YELLOW_ON_BLACK;
		toprint = "one";
		break;
	case 2:
		desired = EColour::COLOUR_CYAN_ON_BLACK;
		toprint = "two";
		break;
	case 3:
		desired = EColour::COLOUR_BLUE_ON_BLACK;
		toprint = "three";
		break;
	case 4:
		desired = EColour::COLOUR_RED_ON_BLACK;
		toprint = "four";
	default:
		break;
	}
	SetRgb(desired);
	std::cout << "\nSet " << toprint << ":\nAddress: " << &_rPrint;
	_rPrint.Print();
}

/***********************************************
* LogicTestsPrintAll: calls the individual print function to repeatedly print logic test details
* @author: David Fransham
* @parameter: 4 set addresses
* @return: void
************************************************/
void LogicTestsPrintAll(TSet& _rA, TSet& _rB, TSet& _rC, TSet& _rD)
{
	LogicTestsPrintSet(_rA, 1);
	LogicTestsPrintSet(_rB, 2);
	LogicTestsPrintSet(_rC, 3);
	LogicTestsPrintSet(_rD, 4);
}

/***********************************************
* LogicTestsPopulateSets: resets the testing sets to the same values for repeated tests
* @author: David Fransham
* @parameter: 4 set addresses
* @return: void
************************************************/
void LogicTestsPopulateSets(TSet& _rA, TSet& _rB, TSet& _rC, TSet& _rD)
{
	_rA.SetClear();
	for (int i = 0; i < 10; i++)
	{
		_rA.AddElement(i + 1);
	}

	_rB.SetClear();
	for (int i = 10; i < 15; i++)
	{
		_rB.AddElement(i);
	}

	_rC.SetUniversal();
	for (int i = 1; i < 90; i++)
	{
		_rC.RemoveElement(i);
	}

	_rD.SetUniversal();
	for (int i = 5; i < 95; i++)
	{
		_rD.RemoveElement(i);
	}
}

/***********************************************
* LogicTestFunctionCall: calls the same combinations of tests on four specific functions using four sets passed in
* @author: David Fransham
* @parameter: 4 set addresses, set function pointer, enum set name for printing
* @return: void
************************************************/
void LogicTestFunctionCall(TSet& _rA, TSet& _rB, TSet& _rC, TSet& _rD, TSet& (*_ptr)(TSet&, TSet&, TSet&), EFunctions _func)
{
	string waitForInput = "";
	string sName = "";

	switch (_func)
	{
	case EFunctions::UNION:
		sName = "Union";
		break;
	case EFunctions::INTERSECTION:
		sName = "Intersection";
		break;
	case EFunctions::SET_DIFFERENCE:
		sName = "Set Difference";
		break;
	case EFunctions::SYMMETRIC_DIFFERENCE:
		sName = "Symmetric Difference";
	default:
		break;
	}

	ClearScreen();
	LogicTestsPopulateSets(_rA, _rB, _rC, _rD);
	LogicTestsPrintAll(_rA, _rB, _rC, _rD);

	std::cout << "\n\n------" << sName << "------ - \n";

	std::cout << "\n" << sName << ": (1 + 3) -> 3\n";
	_ptr(_rA, _rC, _rC);
	LogicTestsPrintSet(_rA, 1);
	LogicTestsPrintSet(_rC, 3);

	std::cout << "\n\n" << sName << ": (4 + 2) -> 4\n";
	_ptr(_rD, _rB, _rD);
	LogicTestsPrintSet(_rB, 2);
	LogicTestsPrintSet(_rD, 4);

	std::cout << "\nPress ENTER to continue";
	waitForInput = GetUserInput();

	ClearScreen();
	LogicTestsPopulateSets(_rA, _rB, _rC, _rD);
	LogicTestsPrintAll(_rA, _rB, _rC, _rD);

	std::cout << "\n\n------" << sName << "------ - \n";

	std::cout << "\n" << sName << ": (2 + 1) -> 1\n";
	_ptr(_rB, _rA, _rA);
	LogicTestsPrintSet(_rB, 2);
	LogicTestsPrintSet(_rA, 1);

	std::cout << "\n\n" << sName << ": (3 + 4) -> 3\n";
	_ptr(_rC, _rD, _rC);
	LogicTestsPrintSet(_rD, 4);
	LogicTestsPrintSet(_rC, 3);

	std::cout << "\nPress ENTER to continue";
	waitForInput = GetUserInput();
	ClearScreen();
}

/***********************************************
* SpecificLogicTesting: organises and runs a series of tests on specific logic used in some of the set functions
* @author: David Fransham
* @parameter: none
* @return: void
************************************************/
void SpecificLogicTesting()
{
	ClearScreen();
	std::cout << "This series of tests were conducted and visually verified by matching addresses and set contents\n";
	std::cout << "The purpose was to verify the logic used in checking that set contents were not going to be overwritten\n";
	std::cout << "in the event that the same set was passed as an input and a return set, as well as checking logic to do with \n";
	std::cout << "the requirement to use universal sets and clear sets if the element 100 was included in either of the input sets.\n\n";
	std::cout << "They have not been programmatically verified, but will still be included in the count of cumulative tests\n";
	std::cout << "\n\nPress ENTER to continue.";
	
	string waitForInput = GetUserInput();

	TSet set1;
	TSet set2;
	TSet set3;
	TSet set4;

	TSet& (*ptr)(TSet&, TSet&, TSet&);

	ptr = Union;
	LogicTestFunctionCall(set1, set2, set3, set4, ptr, EFunctions::UNION);

	ptr = Intersection;
	LogicTestFunctionCall(set1, set2, set3, set4, ptr, EFunctions::INTERSECTION);

	ptr = SetDifference;
	LogicTestFunctionCall(set1, set2, set3, set4, ptr, EFunctions::SET_DIFFERENCE);

	ptr = SymmetricDifference;
	LogicTestFunctionCall(set1, set2, set3, set4, ptr, EFunctions::SYMMETRIC_DIFFERENCE);

	for (int i = 0; i < 4; i++)
	{
		IncrementCounters(true, EFunctions::UNION);
		IncrementCounters(true, EFunctions::INTERSECTION);
		IncrementCounters(true, EFunctions::SET_DIFFERENCE);
		IncrementCounters(true, EFunctions::SYMMETRIC_DIFFERENCE);
	}
}

//Printing or screen tidy functions

/***********************************************
* PrepareForNextBatch: prints cumulative results, resets cursor, waits for input then clears screen for next batch of tests
* @author: David Fransham
* @parameter: int representing y position of cursor for tidy printing
* @return: void
************************************************/
void PrepareForNextBatch(int _iYpos, bool _bNextBatch)
{
	PrintCumulativeResults();
	GoToXY(0, _iYpos);
	if (_bNextBatch)
	{
		SetRgb(EColour::COLOUR_RED_ON_BLACK);
		std::cout << "Press ENTER to continue to next batch of tests";
	}
	else
	{
		SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
		std::cout << "Press ENTER to continue to next test.";
	}

	string waitForInteraction = GetUserInput();
	ClearScreen();
}

/***********************************************
* PrintFunctionMenu: Prints the list of functions for user to choose to test
* @author: David Fransham
* @parameter: none
* @return: void
************************************************/
void PrintFunctionMenu()
{
	GoToXY(0, 0);
	for (int i = 0; i < 20; i++)
	{
		if ((i % 2) == 1)
		{
			SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
		}
		else
		{
			SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
		}
		std::cout << i + 1 << ": " << g_sFuncNameArray[i] << std::endl;
	}
	SetRgb(EColour::COLOUR_BLUE_ON_BLACK);
	std::cout << "21: Return to top menu\n";
	SetRgb(EColour::COLOUR_MAGENTA_ON_BLACK);
	std::cout << "\nWhich function would you like to test?\n\n";
	SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
}

/***********************************************
* PrintIndividualTestHeader: Prints the header information relating to a specific test being conducted
* @author: David Fransham
* @parameter: enum function name, x and y integers for cursor position
* @return: void
************************************************/
void PrintIndividualTestHeader(const EFunctions _keFuncToTest, int _iPrintX, int _iPrintY)
{
	if (g_bUserTests)
	{
		ClearScreen();
	}
	PrintCumulativeResults();
	GoToXY(_iPrintX, _iPrintY);
	SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
	std::cout << "Testing the " << g_sFuncNameArray[static_cast<int>(_keFuncToTest)] << " function.\n";

	SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
}

/***********************************************
* RepeatTest: asks user whether they want to repeat previous test or return to main menu
* @author: David Fransham
* @parameter: none
* @return: boolean indicating repeat (true) or not (false)
************************************************/
bool TakeInputRepeatTest()
{
	ClearScreen();
	PrintCumulativeResults();
	GoToXY(0, 0);
	SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
	std::cout << "Would you like to repeat tests on the same function?\n";
	bool bRepeat = true;
	std::cout << "1: Yes, repeat tests on the same function.\n";
	std::cout << "2: No, return to previous menu.\n";
	SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
	int iResponse = GetInt(true, 1, 2);
	return iResponse - 1;
}

/***********************************************
* PrintTestResult: Prints the outcome of an individual test
* @author: David Fransham
* @parameter: boolean indicating success or failure.
* @return: void
************************************************/
void PrintTestResult(const bool _kbResult)
{
	if (_kbResult)
	{
		SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
		std::cout << "\nCalculated value matched the expected value.  Test Passed.\n";
	}
	else
	{
		SetRgb(EColour::COLOUR_RED_ON_BLACK);
		std::cout << "\nCalculated value did not match the expected value.  Test Failed.\n";
	}
	if (g_bUserTests)
	{
		std::cout << "\nPress ENTER to continue";
		string pauseToRead = GetUserInput();
	}
}

/***********************************************
* PrintCumulativeResults: Prints the cumulative totals of tests conducted and passed
* @author: David Fransham
* @parameter: none
* @return: void
************************************************/
void PrintCumulativeResults()
{
	if (g_iTestsPerformed != 0)
	{
		int y = 0;

		SetRgb(EColour::COLOUR_BLUE_ON_BLACK);
		GoToXY(g_iRightColumnX, y++);
		std::cout << "Cumulative Test Results";

		SetRgb(EColour::COLOUR_WHITE_ON_BLACK);
		GoToXY(g_iRightColumnX, ++y);
		std::cout << "Total tests performed: " << g_iTestsPerformed;

		SetRgb(EColour::COLOUR_GREEN_ON_BLACK);
		GoToXY(g_iRightColumnX, ++y);
		std::cout << "Total tests passed: " << g_iTestsPassed;

		SetRgb(EColour::COLOUR_RED_ON_BLACK);
		GoToXY(g_iRightColumnX, ++y);
		std::cout << "Total tests failed: " << g_iTestsPerformed - g_iTestsPassed;

		y += 2;

		int x1 = g_iRightColumnX - 10;
		int x2 = x1 + 25;
		int x3 = x2 + 10;
		int x4 = x3 + 10;

		bool bColourSwitch = false;


		SetRgb(EColour::COLOUR_BLUE_ON_BLACK);
		GoToXY(x1, y);
		std::cout << "Function:";
		GoToXY(x2, y);
		std::cout << "Pass";
		GoToXY(x3, y);
		std::cout << "Fail";
		GoToXY(x4, y++);
		std::cout << "Total";

		for (int i = 0; i < 20; i++)
		{
			if (g_iFuncTestCounter[i][0] != 0)
			{
				if (bColourSwitch)
				{
					SetRgb(EColour::COLOUR_YELLOW_ON_BLACK);
				}
				else
				{
					SetRgb(EColour::COLOUR_CYAN_ON_BLACK);
				}
				bColourSwitch = !bColourSwitch;

				GoToXY(x1, y);
				std::cout << g_sFuncNameArray[i];
				GoToXY(x4, y);
				std::cout << g_iFuncTestCounter[i][0];
				GoToXY(x2, y);
				std::cout << g_iFuncTestCounter[i][1];
				GoToXY(x3, y++);
				std::cout << (g_iFuncTestCounter[i][0] - g_iFuncTestCounter[i][1]);
			}
		}
	}
}

/***********************************************
* GetRandomNumber: generates a (pseudo)random number within a specified range
* @author: David Fransham
* @parameter: integer - max value allowed.  Optional parameter - integer specifying minimum allowed.  Default is 0
* @return: "random" integer value
************************************************/
int GetRandomNumber(const int _kiMaxRand, const int _kiMinRand)
{
	return _kiMinRand + rand() % ((_kiMaxRand - _kiMinRand) + 1);
}

/***********************************************
* IsOnlyNumbers: loops through string (usually user input) to validate that it is of numerical type
* @author: David Fransham
* @parameter: string object address to check.
* @parameters: optional bool parameters to also allow a leading - or a single . for different number types
* @return: boolean confirming the string matches numerical type or not.
************************************************/
bool IsOnlyNumbers(const string& str, const bool _kbIncDecimal, const bool _kbIncNegative)
{
	bool decimalUsed = false;
	bool negativeUsed = true;

	if (_kbIncNegative && (str[0] == '-'))
	{
		negativeUsed = false;
	}

	for (char const& c : str)
	{
		if (std::isdigit(c) == 0)
		{
			if (_kbIncNegative && (c == '-'))
			{
				if (negativeUsed)
				{
					return false;
				}
				else
				{
					negativeUsed = true;
				}
			}
			else if (_kbIncDecimal && (c == '.'))
			{
				if (decimalUsed)
				{
					return false;
				}
				else
				{
					decimalUsed = true;
				}
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

/***********************************************
* GetUserInput: accepts string input from user.
* @author: David Fransham
* @parameter: optional parameter of return position (default 0).  If specified, resets cursor to given x value.
* @return: string of input, or "NO_INPUT_GIVEN" if user only pressed enter without typing anything first
************************************************/
string GetUserInput(const int _kiCursorResetPosition)
{

	string tempStr;
	std::getline(std::cin, tempStr);

	if (_kiCursorResetPosition != 0)
	{
		GoToXY(_kiCursorResetPosition, GetCursorPos().Y);
	}

	if (tempStr.empty())
	{
		return "NO_INPUT_GIVEN";
	}
	return tempStr;
}

/***********************************************
* GetCursorPos: gets current cursor position from windows console application
* @author: unknown - I found it on StackOverflow and didn't record who has posted it
* @parameter: none
* @return: COORD object indicating position of cursor
************************************************/
COORD GetCursorPos()
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi = { };
	BOOL ok = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
	return csbi.dwCursorPosition;
}

/***********************************************
* ResizeConsoleWindow: resizes and moves the windows console window
* @author: can't remember, I think I found it online somewhere
* @parameter: integers representing the desired width and height
* @return: void
************************************************/
void ResizeConsoleWindow(int _iWidth, int _iHeight)
{
	// Get console window handle
	HWND wh = GetConsoleWindow();

	// Move window to required position
	MoveWindow(wh, 50, 50, _iWidth, _iHeight, TRUE);
}

/***********************************************
* SetFontSize: sets windows console font to a given size
* @author: can't remember, I think I found it online somewhere
* @parameter: integers representing the desired font size
* @return: void
************************************************/
void SetFontSize(int _iSize)
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 200; //default 400
	fontex.dwFontSize.X = _iSize;
	fontex.dwFontSize.Y = _iSize;//default 16
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}

/***********************************************
* GoToXY: sets console cursor position to given x and y coordinates
* @author: unknown - it was copied from lecture slides
* @parameter: integers representing the desired x and y positions
* @return: void
************************************************/
void GoToXY(const int _kiX, const int _kiY)
{
	COORD point;
	point.X = _kiX;
	point.Y = _kiY;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);

	return;
}

/***********************************************
* ClearScreen: Clears windows console screen of all printed data
* @author: unknown - it was copied from lecture slides
* @parameter: none
* @return: void
************************************************/
void ClearScreen()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

/***********************************************
* SetRgb: changes windows console font colour to specified colour
* @author: unknown - it was copied from lecture slides
* @parameter: enumerated value that specifies the desired colour
* @return: void
************************************************/
void SetRgb(EColour colour)
{
	switch (colour)
	{
	case EColour::COLOUR_WHITE_ON_BLACK: // White on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case EColour::COLOUR_RED_ON_BLACK: // Red on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case EColour::COLOUR_GREEN_ON_BLACK: // Green on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	case EColour::COLOUR_YELLOW_ON_BLACK: // Yellow on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case EColour::COLOUR_BLUE_ON_BLACK: // Blue on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	case EColour::COLOUR_MAGENTA_ON_BLACK: // Magenta on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case EColour::COLOUR_CYAN_ON_BLACK: // Cyan on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case EColour::COLOUR_BLACK_ON_GRAY: // Black on Gray.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_INTENSITY);
		break;
	case EColour::COLOUR_BLACK_ON_WHITE: // Black on White.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		break;
	case EColour::COLOUR_RED_ON_WHITE: // Red on White.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED);
		break;
	case EColour::COLOUR_GREEN_ON_WHITE: // Green on White.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN);
		break;
	case EColour::COLOUR_YELLOW_ON_WHITE: // Yellow on White.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case EColour::COLOUR_BLUE_ON_WHITE: // Blue on White.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE);
		break;
	case EColour::COLOUR_MAGENTA_ON_WHITE: // Magenta on White.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case EColour::COLOUR_CYAN_ON_WHITE: // Cyan on White.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case EColour::COLOUR_WHITE_ON_WHITE: // White on White.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	default: // White on Black.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	}
	return;
}

/***********************************************
* GetInt: takes input from user repeatedly until it matches an "integer" type
* @author: David Fransham
* @parameter: accepts optional parameters bool to initiate check for specific range
* @parameters: if bool is true, only returns input that is between other two parameters
* @return: integer value which has been input by user
************************************************/
int GetInt(const bool _kbSpecificRange, const int _kiMin, const int _kiMax)
{
	string sInput = "";
	int iTemp = INT_MIN;
	while (true)
	{
		sInput = GetUserInput();
		if (IsOnlyNumbers(sInput, false, true))
		{
			iTemp = stoi(sInput);
			if (_kbSpecificRange)
			{
				if ((iTemp >= _kiMin) && (iTemp <= _kiMax))
				{
					return iTemp;
				}
				else
				{
					std::cout << "Invalid input, try again\n";
				}
			}
			else
			{
				return iTemp;
			}
		}
		else
		{
			std::cout << "Invalid input, try again\n";
		}
	}
}

/***********************************************
* GetFloat: takes input from user repeatedly until it matches a "float" type
* @author: David Fransham
* @parameter: accepts optional parameters bool to initiate check for specific range
* @parameters: if bool is true, only returns input that is between other two parameters
* @return: float value which has been input by user
************************************************/
float GetFloat(const bool _kbSpecificRange, const float _kfMin, const float _kfMax)
{
	string sInput = "";
	float fTemp = FLT_MIN;
	while (true)
	{
		sInput = GetUserInput();
		if (IsOnlyNumbers(sInput, true, true))
		{
			fTemp = stof(sInput);
			if (_kbSpecificRange)
			{
				if ((fTemp >= _kfMin) && (fTemp <= _kfMax))
				{
					return fTemp;
				}
				else
				{
					std::cout << "Invalid input, try again\n";
				}
			}
			else
			{
				return fTemp;
			}
		}
		else
		{
			std::cout << "Invalid input, try again\n";
		}
	}
}

/***********************************************
* GetDouble: takes input from user repeatedly until it matches a "double" type
* @author: David Fransham
* @parameter: accepts optional parameters bool to initiate check for specific range
* @parameters: if bool is true, only returns input that is between other two parameters
* @return: double value which has been input by user
************************************************/
double GetDouble(const bool _kbSpecificRange, const double _kdMin, const double _kdMax)
{
	string sInput = "";
	double dTemp = DBL_MIN;
	while (true)
	{
		sInput = GetUserInput();
		if (IsOnlyNumbers(sInput, true, true))
		{
			dTemp = stod(sInput);
			if (_kbSpecificRange)
			{
				if ((dTemp >= _kdMin) && (dTemp <= _kdMax))
				{
					return dTemp;
				}
				else
				{
					std::cout << "Invalid input, try again\n";
				}
			}
			else
			{
				return dTemp;
			}
		}
		else
		{
			std::cout << "Invalid input, try again\n";
		}
	}
}
