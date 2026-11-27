#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;


void showHeader() {
    cout << "==========================================" << endl;
    cout << "         SECRET PIN GUESSING GAME         " << endl;
    cout << "==========================================" << endl;
}


void showRules() {
 
    showHeader();
    cout << "\n--- GAME RULES ---\n";
    cout << "1. The computer generates a random 4-digit secret PIN (1000 - 9999).\n";
    cout << "2. You have only 5 attempts to guess the correct PIN.\n";
    cout << "3. After each wrong guess, you will receive a hint showing how many\n";
    cout << "   digits are in the correct position.\n";
    cout << "4. Correctly positioned digits will be revealed (e.g., [ 4 ] [ _ ] [ 2 ] [ _ ]).\n\n";

}


void playGame() {
   
    int secretPin = rand() % 9000 + 1000;
    
   
    int secretDigits[4];
    int temp = secretPin;
    for (int i = 3; i >= 0; i--) {
        secretDigits[i] = temp % 10;
        temp = temp / 10;
    }

    int maxAttempts = 5;
    int guess;
    bool isWon = false;


    showHeader();
    cout << "\nThe computer has locked a 4-digit Secret PIN!\n";
    cout << "You have 5 attempts to crack it. Good luck!\n";

    
    for (int attempt = 1; attempt <= maxAttempts; attempt++) {
        cout << "\n------------------------------------------\n";
        cout << "Attempt " << attempt << " of " << maxAttempts << endl;

    
        do {
            cout << "Enter your 4-digit PIN guess (1000-9999): ";
            cin >> guess;

            if (guess < 1000 || guess > 9999) {
                cout << "Invalid input! Please enter a valid 4-digit number.\n";
            }
        } while (guess < 1000 || guess > 9999);

    
        if (guess == secretPin) {
            isWon = true;
            cout << "\n******************************************\n";
            cout << "   CONGRATULATIONS! PIN UNLOCKED!         \n";
            cout << "   You cracked it in " << attempt << " attempt(s)!        \n";
            cout << "******************************************\n";
            break; // Exit the loop immediately upon winning
        }

    
        int guessDigits[4];
        int tempGuess = guess;
        for (int i = 3; i >= 0; i--) {
            guessDigits[i] = tempGuess % 10;
            tempGuess = tempGuess / 10;
        }

    
        int correctPosCount = 0;
        cout << "Hint (Correctly Positioned Digits): ";
        for (int i = 0; i < 4; i++) {
            if (guessDigits[i] == secretDigits[i]) {
                cout << "[ " << guessDigits[i] << " ] ";
                correctPosCount++;
            } else {
                cout << "[ _ ] ";
            }
        }
        cout << "\nTotal digits in the correct position: " << correctPosCount << " / 4\n";
    }

    
    if (!isWon) {
        cout << "\n==========================================\n";
        cout << "   GAME OVER! You ran out of attempts.    \n";
        cout << "   The Secret PIN was: " << secretPin << endl;
        cout << "==========================================\n";
    }

    cout << "\n";

}

int main() {
    
    srand(time(0));

    int choice;

    
    do {

        showHeader();
        cout << "\n1. Play Game\n";
        cout << "2. How to Play (Rules)\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                showRules();
                break;
            case 3:
                cout << "\nThank you for playing! Goodbye.\n";
                break;
            default:
                cout << "\nInvalid choice! Please select 1, 2, or 3.\n";

        }
    } while (choice != 3);

    return 0;
}
