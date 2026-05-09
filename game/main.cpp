#include <iostream>
#include <random>

int main() {
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int secretNumber = dist(gen); // number from 1 to 100
    int guess;
    int attempts = 0;
    bool isWinner = false;

    std::cout << "Guess the number from 1 to 100! You have 5 attempts!" << std::endl;

    do {
        attempts++;
        std::cout << "Attempt " << attempts << ". Enter your number: ";
        std::cin >> guess;

        if (guess > secretNumber) {
            std::cout << "The secret number is smaller than your guess!" << std::endl;
        }
        else if (guess < secretNumber) {
            std::cout << "The secret number is greater than your guess!" << std::endl;
        }
        else {
            std::cout << "Congratulations! You guessed the number in "
                 << attempts << " attempts out of 5!" << std::endl;
            isWinner = true;
        }

    } while (guess != secretNumber && attempts < 5);

    if (!isWinner) {
        std::cout << "\nOh! You lose, the guessed number was " << secretNumber << "!\nTry Again." << std::endl;
    }

    std::cout << "\nPress Enter to restart game...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}