#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string FirstName;
	int FirstLength;
	string LastName;
	int LastLength;
	string GradePrompt;
	bool NonAlpha;
	int ExamScore;
	int TotalPoints;
	int i;
	stringstream ss;
	string si;
	double CourseScore;
	char FinalGradeLetter;
	double FinalPercentage;

	i = 0;
	NonAlpha = false;
	TotalPoints = 0;

	cout << "Enter First Name:" << '\n';
	cin >> FirstName;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(200, '\n');
		cin >> FirstName;
		FirstLength = FirstName.size();

		while ((i <= FirstLength) && (NonAlpha = false))
		{
			if (isalpha(FirstName[i]))
			{
				i = i + 1;
			}
			else
			{
				cout << "Error: Use only letters when entering names." << '\n' << "Enter First Name:" << '\n';
				NonAlpha = true;
			}
		}
	}

	i = 0;
	NonAlpha = false;

	cout << "Enter Last Name:" << '\n';
	cin >> LastName;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(200, '\n');
		cin >> LastName;
		LastLength = LastName.size();

		while ((i <= LastLength) && (NonAlpha = false))
		{
			if (isalpha(LastName[i]))
			{
				i = i + 1;
			}
			else
			{
				cout << "Error: Use only letters when entering names." << '\n' << "Enter Last Name:" << '\n';
				NonAlpha = true;
			}
		}
	}

	i = 1;

	while (i < 6)
	{
		ss << i;
		si = ss.str();
		GradePrompt = "Enter Exam " + si + " Score :";
		ss.str("");
		cout << GradePrompt << '\n';
		cin >> ExamScore;

		if ((ExamScore >= 0) && (ExamScore <= 100))
		{
			cin.clear();
			cin.ignore(200, '\n');
			TotalPoints = TotalPoints + ExamScore;
			i++;
			cin.get();
		}

		else
		{
			cout << "Invalid score entry. Please enter whole numbers only." << '\n';
		}

	};

	cout << "Total Exam Points: " << TotalPoints << '\n';
	CourseScore = TotalPoints / 500.00;
	{
		FinalPercentage = (CourseScore * 100);
		cout.precision(1);
		cout << fixed;
	}

	if (FinalPercentage >= 90)
	{
		FinalGradeLetter = 'A';
	}
	else if (FinalPercentage >= 80)
	{
		FinalGradeLetter = 'B';
	}
	else if (FinalPercentage >= 70)
	{
		FinalGradeLetter = 'C';
	}
	else if (FinalPercentage >= 60)
	{
		FinalGradeLetter = 'D';
	}
	else
	{
		FinalGradeLetter = 'F';
	}

	cout << LastName << ", " << FirstName << '\t' << FinalGradeLetter << " (" << TotalPoints << "/500 = " << FinalPercentage << "%)" << '\n';
}