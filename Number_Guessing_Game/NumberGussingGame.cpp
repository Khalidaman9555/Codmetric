#include <iostream>
#include <cstdlib>      // For rand() and srand()
#include <ctime>        // For time()
#include <limits>       // For input validation

using namespace std;

// Function declarations
int RandomNumber(int range);
string SuccessMessage(int numberOfTries, const string &winnerName);

// Difficulty settings: {Difficulty Index, Max Range, Max Guesses}
const string DifficultiesInWords[] = {"Easy", "Medium", "Hard"};
const int Difficulties[][3] = {{0, 100, 10}, {1, 50, 5}, {2, 20, 3}};

int main() {
    int Difficulty, maxGuesses, secretNumber, userGuess;
    string userName;

    // Seed rand with current time
    srand(static_cast<unsigned int>(time(0)));

    cout << "\nWelcome to the Number Guessing Game!\n";

    cout << "Enter your name: ";
    cin >> userName;

    // Show difficulty options
    cout << "\nChoose a difficulty level:\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ") " << DifficultiesInWords[Difficulties[i][0]] << endl;
    }

    // Get valid difficulty
    cout << "Select (1-3): ";
    do {
        cin >> Difficulty;
        if (cin.fail() || Difficulty < 1 || Difficulty > 3) {
            cout << "Invalid choice. Please choose again (1-3): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (Difficulty < 1 || Difficulty > 3);

    maxGuesses = Difficulties[Difficulty - 1][2];
    int maxRange = Difficulties[Difficulty - 1][1];
    secretNumber = RandomNumber(maxRange);

    cout << "\nGuess a number between 1 and " << maxRange << ". You have " << maxGuesses << " attempts.\n";

    int i;
    for (i = 1; i <= maxGuesses; i++) {
        do {
            cout << "Attempt " << i << " - Enter your guess: ";
            cin >> userGuess;

            if (cin.fail() || userGuess < 1 || userGuess > maxRange) {
                cout << "Invalid input. Try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                userGuess = -1; // force re-entry
            }
        } while (userGuess == -1);

        if (userGuess == secretNumber) break;

        if (userGuess > secretNumber) {
            cout << "Too high!\n";
            if (i < maxGuesses) cout << " Try a smaller number.\n";
        } else {
            cout << "Too low!\n";
            if (i < maxGuesses) cout << " Try a bigger number.\n";
        }
    }

    // Final result
    if (i <= maxGuesses) {
        if ((maxGuesses == 3 && i == 3) || (maxGuesses == 5 && i == 5))
            cout << "\n" << SuccessMessage(11, userName);
        else
            cout << "\n" << SuccessMessage(i, userName);
    } else {
        cout << "\nSorry, " << userName << "! You've used all your attempts.\n";
        cout << "The correct number was: " << secretNumber << endl;
    }

    return 0;
}

// Generate random number in range [1, range]
int RandomNumber(int range) {
    return rand() % range + 1;
}

// Return appropriate win message
string SuccessMessage(int numberOfTries, const string &winnerName) {
    const string messages[] = {
        "**MIND BLOWN, " + winnerName + "!!** You won in just ONE guess?!  Unbelievable!",
        "WOW, " + winnerName + ", you cracked it in only TWO guesses!  That's impressive!",
        "Amazing job, " + winnerName + "! You figured it out in just THREE guesses!",
        "Impressive win, " + winnerName + "! You solved it in FOUR guesses!",
        "Great victory, " + winnerName + "! It took you FIVE guesses, a solid win!",
        "Congrats, " + winnerName + "! You won in SIX guesses! Keep up the strategic thinking!",
        "Well done, " + winnerName + "! You achieved victory in SEVEN guesses!",
        "Nice win, " + winnerName + "! You figured it out in EIGHT guesses!",
        "Congratulations, " + winnerName + "! You won in NINE guesses! Persistence pays off!",
        winnerName + ", you won! It took you TEN guesses, but a win is a win!",
        "**Clutch victory, " + winnerName + "!** You saved the day with your final guess! That was an epic last-guess win!"};

    return messages[numberOfTries - 1];
}
