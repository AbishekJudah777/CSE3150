#include <iostream>
#include <exception>
#include "FileReader.h"
#include "WarGame.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./war_game <input_csv> <output_csv>\n";
        return 1;
    }

    try {
        std::string inputPath = argv[1];
        std::string outputPath = argv[2];
        
        Deck initialDeck = FileReader::readDeckFromCSV(inputPath);

        WarGame game(initialDeck, outputPath);

        game.play();

        return 0; 

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
