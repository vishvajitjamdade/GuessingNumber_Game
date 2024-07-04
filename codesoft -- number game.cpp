#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // for std::numeric_limits

int main() {
    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(NULL)));
    
    // Generate random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int guess = 0;

    std::cout << "Guess the number (between 1 and 100): ";

    // Loop until the user guesses the correct number
    while (true) {
        std::cin >> guess;

        // Check if input is valid
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 100: ";
            continue;
        }

        if (guess < randomNumber) {
            std::cout << "Too low. Try again: ";
        } else if (guess > randomNumber) {
            std::cout << "Too high. Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the number." << std::endl;
            break;
        }
    }

    return 0;
}

