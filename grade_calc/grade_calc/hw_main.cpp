#include "HomeworkList.h"
#include<iostream>
#include<iomanip> //Include iomanip library to allow use of set precision
#include<cmath> //Include cmath library to allow use of absolute value function
#include<string> //Include string library to allow use of string and string functions

using namespace std; 

int main()
{
	string studentName; // Initialize studentName as a string for user input
	cout << "Enter student's name: "; // cout statement for the student name request
	getline(cin, studentName); // Use getline for the studentName string so the compiler will read the whole line of input (including the possible spaces)
	HomeworkList hwScores; // Create a variable from the HomeworkList.h file which will allow us to use functions from the .h file
	char yesOrNo; // Assign the yes or no (y/n) option as a char for user input

	// For entering scores, it is ideal to use the "do" loop. Given that we are unsure of the amount of 
		// the "do" loop will check the condition at the end of the loop (y/n) to ensure whether or not
		// the program will continue to go again. We will follow this up with a "while" loop to check for
		// the "yes" condition the user may enter in the "More scores?" section. If the user enters "n" in
		// this option, the do loop will only run once since the condition is not defined anywhere else.
	do
	{
		// Include the score and max score options for user input as well as the "more scores?" option in the do loop
		int score, maxPossible; 
		cout << "Enter score and max as two values: ";
		cin >> score >> maxPossible;
		// Function call for addScore must be after the input otherwise there will be a build error
		hwScores.addScore(score, maxPossible);
		// User input statement for the more scores condition
		cout << "More Scores? y/n: ";
		cin >> yesOrNo;
	}
	// Since the do loop will be run first, we will use the "More Scores?" condition from the user input as 
		// our condition in the while loop. That way the loop will continue to run when the user enters "y" and
		// will terminate when the user enters "no".
	while (yesOrNo == 'y'); //While loop for the 'y' condition
	{
		cout << "How many scores should be used in computing hw grade? ";
		// Create an int variable (which will be defined from user input) to use in the percentageFromBest function
		int topNumber;
		cin >> topNumber;
		// Our function call for the percentageFromBest fuction from the .h file must be assigned to a variable.
		// The percentageFromBest function will handle the calculation for percentage based on the amount of assignments 
		// the user requested to be calculated for the final grade. When assigning this calculation to a variable,
		// we can then use it in the cout statement.
		double finalGrade = hwScores.percentageFromBest(topNumber);
		// The cout statement will also include the function call for numberOfHWs from the .h file. This function
		// reads the amount of times the loop was run which is equal to the amount of total homework assignments 
		// entered by the user. The function call may be used AS ITSELF, since it is defined as a size_t and const in the .h file
		cout << "The homework grade for " << studentName << " based on the best " << topNumber
			<< " homework scores out of " << hwScores.numberOfHWs() << " is " << setprecision(2) << fixed << finalGrade << "%\n";
		// Use if else statement for the conditions based on the finalGrade number with proper boolean operators.
		// The cout statements will be determined by the finalGrade percentage.
		if (finalGrade >= 95)
		{
			cout << "This is excellent";
		}
		else if (finalGrade >= 80 && finalGrade < 95)
		{
			cout << "This is good";
		}
		else if (finalGrade >= 70 && finalGrade < 80)
		{
			cout << "This is decent";
		}
		else
		{
			cout << "This is poor";
		}
	} // This bracked closes the while loop above

	return 0;
}