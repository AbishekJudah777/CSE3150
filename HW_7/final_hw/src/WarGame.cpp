#include "WarGame.h"
#include <iostream>

WarGame::WarGame(Deck& deck, const std::string& outputPath) 
    : round_(1), writer_(outputPath) 
{
    auto [a, b] = deck.split();
    playerA_ = std::move(a);
    playerB_ = std::move(b);
}

void WarGame::play() 
{
    std::cout << "Starting War" << std::endl;

    while (!playerA_.empty() && !playerB_.empty()) 
    {
        std::cout << "Round " << round_ << "\n" << std::endl;
        
        playRound();
        
        writer_.writeRound(round_, playerA_, playerB_); 
        round_++;
    }

    std::cout << "Game Over" << std::endl;
    if (playerA_.size() > playerB_.size()) 
    {
        std::cout << "Player A wins with " << playerA_.size() << " cards!" << std::endl;
    } 
     else if (playerB_.size() > playerA_.size()) 
    {
        std::cout << "Player B wins with " << playerB_.size() << " cards!" << std::endl;
    } 
    else 
    {
        std::cout << "It's a tie!" << std::endl;
    }
}

void WarGame::playRound() 
{
    auto cardA = playerA_.draw();
    auto cardB = playerB_.draw();

    if (!cardA || !cardB) return;

    std::cout << "Player A plays: " << *cardA << std::endl;
    std::cout << "Player B plays: " << *cardB << std::endl;

    if (!(*cardA < *cardB)) 
    { 
        playerA_.addToBottom(std::move(cardA));
        playerA_.addToBottom(std::move(cardB));
    }
    else 
    {
        playerB_.addToBottom(std::move(cardB));
        playerB_.addToBottom(std::move(cardA));
    }
}
