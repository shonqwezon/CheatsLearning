#include <iostream>
#include <random>

#ifdef NDEBUG
    #ifdef _WIN32
        #include <windows.h>
    #endif
#endif

struct GameConfig {
    int minNumber = 1;
    int maxNumber = 1000;
    int maxAttempts = 5;
};

struct GameState {
    int secretNumber = 0;
    int attempts = 0;
    bool isWinner = false;
};

bool isDebuggerDetected() {
#ifdef NDEBUG
    #ifdef _WIN32
        return IsDebuggerPresent();
    #else
        return false;
    #endif
#else
    return false;
#endif
}

void playGame(std::mt19937 &gen, const GameConfig &config, GameState &state) {
    std::uniform_int_distribution<> dist(config.minNumber, config.maxNumber);

    state.secretNumber = dist(gen);
    state.attempts = 0;
    state.isWinner = false;

    int guess;

    std::cout << "\nGuess the number from "
              << config.minNumber << " to " << config.maxNumber
              << "! You have " << config.maxAttempts << " attempts!\n";

    while (state.attempts < config.maxAttempts && !state.isWinner) {
        if (isDebuggerDetected()) {
            std::cerr << "[ERROR] Debugger detected!\n";
            std::cin.ignore();
            std::cin.get();
            continue;
        }
        state.attempts++;

        std::cout << "Attempt " << state.attempts << ". Enter your number: ";
        std::cin >> guess;

        if (guess > state.secretNumber) {
            std::cout << "The secret number is smaller than your guess!\n";
        }
        else if (guess < state.secretNumber) {
            std::cout << "The secret number is greater than your guess!\n";
        }
        else {
            std::cout << "Congratulations! You guessed the number in "
                      << state.attempts << " attempts!\n";
            state.isWinner = true;
        }
    }

    if (!state.isWinner) {
        std::cout << "\nYou lose! The correct number was "
                  << state.secretNumber << "!\n";
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    GameConfig config;
    GameState state;

    char choice;

    do {
        playGame(gen, config, state);

        std::cout << "\nRestart game? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Good bye...\n";
    return 0;
}