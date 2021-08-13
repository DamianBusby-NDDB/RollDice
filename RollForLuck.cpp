#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <ctime>

int main() {
	//Variable Declaration
	double numberOfRolls = 0.0; //Store the amount of rolls the user wants to do.
	int rollValue; //Store the value of each roll.
	double numOfSixes = 0.0, numOfFives = 0.0, numOfFours = 0.0, numOfThrees = 0.0, numOfTwos = 0.0, numOfOnes = 0.0; //Store the number of times each side was rolled
	int comboCount = 0, rareComboCount = 0; //Counts the number of combos and rare combos achieved.
	
	//Store probabilities of each value
	double percentOfSix = 0.00, percentOfFive = 0.00, percentOfFour = 0.00, percentOfThree = 0.00, percentOfTwo = 0.00, percentOfOne = 0.00;

	bool validInput = false; //Used to check if the user input is valid
	bool combos = false; //Used to check if the user got any combos

	//User inputs the number of rolls they want to do.
	std::cout << "Feeling lucky?\n\nType out how many times you want to roll the dice (Maximum of 25) and hit enter:" << std::endl << std::endl;
	std::cin >> numberOfRolls;

	//Make sure input is greater than 0 and less than or equal to 25
	while (validInput != true) {
		if (numberOfRolls > 0 && numberOfRolls <= 25) {
			validInput = true;
		}
		else {
			std::cout << "\nInvalid input detected. Please provide a number greater than 0 and less than or equal to 25:" << std::endl;
			std::cin >> numberOfRolls;
		}
	}

	//Generate random seed
	std::srand(time(NULL));

	//Loop through and "roll the dice" the number of times the user inputted
	for (int x = 1; x <= numberOfRolls; x++) {
		rollValue = rand() % 6 + 1; //rollValue is a random number between 1 and 6

		//Store the total amount of each rollValue rolled
		switch (rollValue) {
		case 1:
			numOfOnes++;
			break;
		case 2:
			numOfTwos++;
			break;
		case 3:
			numOfThrees++;
			break;
		case 4:
			numOfFours++;
			break;
		case 5:
			numOfFives++;
			break;
		case 6:
			numOfSixes++;
			break;
		}

	}


	//Calculate probabilities
	percentOfSix = (numOfSixes / numberOfRolls) * 100;
	percentOfFive = (numOfFives / numberOfRolls) * 100;
	percentOfFour = (numOfFours / numberOfRolls) * 100;
	percentOfThree = (numOfThrees / numberOfRolls) * 100;
	percentOfTwo = (numOfTwos / numberOfRolls) * 100;
	percentOfOne = (numOfOnes / numberOfRolls) * 100;

	//Outputs the number of each possible value rolled, the probability of each value, and mention any combos achieved from roll values
	std::cout << "\n\n-------------------Rolls Concluded-------------------"
		<< "\nResults:\nNumber of 6's rolled: " << numOfSixes << "\nNumber of 5's rolled: " << numOfFives
		<< "\nNumber of 4's rolled: " << numOfFours << "\nNumber of 3's rolled: " << numOfThrees
		<< "\nNumber of 2's rolled: " << numOfTwos << "\nNumber of 1's rolled: " << numOfOnes << std::endl << std::endl;

	std::cout << "Probabilities:\n6's: " << percentOfSix << "%"
		<< "\n5's: " << percentOfFive << "%" 
		<< "\n4's: " << percentOfFour << "%" 
		<< "\n3's: " << percentOfThree << "%" 
		<< "\n2's: " << percentOfTwo << "%" 
		<< "\n1's: " << percentOfOne << "%" 
		<< std::endl << std::endl;

	std::cout << "Combos Achieved: " << std::endl;
	
	//Check for Combos
	if (numOfSixes >= 1 && numOfFives >= 1 && numOfFours >= 1 && numOfThrees >= 1 && numOfTwos >= 1 && numOfOnes >= 1) {
		std::cout << "\tOne of Each" << std::endl;
		combos = true;
		comboCount++;
	}

	if (numOfSixes >= 3 || numOfFives >= 3 || numOfFours >= 3 || numOfThrees >= 3 || numOfTwos >= 3 || numOfOnes >= 3) {
		std::cout << "\tTriple Threat" << std::endl;
		combos = true;
		comboCount++;
	}

	if (numOfOnes >= 1 && numOfTwos >= 1 && numOfThrees >= 1 && numOfFives >= 1) {
		std::cout << "\tFibonacci" << std::endl;
		combos = true;
		comboCount++;
	}

	if (numOfSixes + numOfFives + numOfFours > numberOfRolls / 2) {
		std::cout << "\tHigh Numbers Galore" << std::endl;
		combos = true;
		comboCount++;
	}

	if (numOfThrees + numOfTwos + numOfOnes > numberOfRolls / 2) {
		std::cout << "\tLow Number Frenzy" << std::endl;
		combos = true;
		comboCount++;
	}

	if (numOfFours >= 4 && numOfTwos >= 2) {
		std::cout << "\tThe Meaning Of Life, The Universe, and Everything" << std::endl;
		combos = true;
		comboCount++;
		rareComboCount++;
	}

	if (numOfSixes + numOfFives + numOfFours == numOfThrees + numOfTwos + numOfOnes) {
		std::cout << "\tPerfectly Balanced" << std::endl;
		combos = true;
		comboCount++;
		rareComboCount++;
	}

	//Check to see if any combos were achieved
	if (combos) {
		std::cout << "\nYou achieved " << comboCount << " combos!! Excellent! You win bragging rights!" << std::endl;
		if (rareComboCount > 0) {
			std::cout << "Out of the combos you achieved " << rareComboCount << " of them were rare combos! CONGRATULATIONS! These are hard to get!" 
				<< std::endl << std::endl;
		}
		else {
			std::cout << "You didn't get any rare combos. That's okay! They are rare for a reason." << std::endl << std::endl;
		}
	}

	else {
		std::cout << "No combos were achieved. Better luck next time." << std::endl << std::endl;
	}

	std::cout << "-----------------------------------------------------" << std::endl << std::endl;

	std::cout << "Thank you for playing! Come back again to test your luck!" << std::endl << std::endl; //Obligatory "Thank You" statement at the end.

	return 0;
}