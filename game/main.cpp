#include <iostream>
#include <random>

void playGame(std::mt19937 &gen) {
    std::uniform_int_distribution<> dist(1, 1000);

    int secretNumber = dist(gen);
    int guess;
    int attempts = 0;
    bool isWinner = false;

    std::cout << "\nGuess the number from 1 to 1000! You have 5 attempts!\n";

    do {
        attempts++;
        std::cout << "Attempt " << attempts << ". Enter your number: ";
        std::cin >> guess;

        if (guess > secretNumber) {
            std::cout << "The secret number is smaller than your guess!\n";
        }
        else if (guess < secretNumber) {
            std::cout << "The secret number is greater than your guess!\n";
        }
        else {
            std::cout << "Congratulations! You guessed the number in "
                      << attempts << " attempts out of 5!\n";
            isWinner = true;
        }

    } while (guess != secretNumber && attempts < 5);

    if (!isWinner) {
        std::cout << "\nOh! You lose, the correct number was " << secretNumber << "!\n";
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    char choice;

    do {
        playGame(gen);

        std::cout << "\nWould you like to restart the game? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Good bye...\n";
    return 0;
}