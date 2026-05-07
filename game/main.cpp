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

    std::cout << "Guess the number from 1 to 100!" << std::endl;

    do {
        std::cout << "Enter your number: ";
        std::cin >> guess;

        attempts++;

        if (guess > secretNumber) {
            std::cout << "The secret number is smaller than your guess!" << std::endl;
        }
        else if (guess < secretNumber) {
            std::cout << "The secret number is greater than your guess!" << std::endl;
        }
        else {
            std::cout << "Congratulations! You guessed the number in "
                 << attempts << " attempts!" << std::endl;
        }

    } while (guess != secretNumber);

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}