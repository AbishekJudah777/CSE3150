#include "PlayingCard.h"

PlayingCard::PlayingCard(std::string suit, int rank) : suit_(suit), rank_(rank) {}

int PlayingCard::value() const { 
    return rank_; 
}

std::string PlayingCard::rankToString(int r) const {
    switch(r) {
        case 1:  return "A";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return std::to_string(r);
    }
}

void PlayingCard::print(std::ostream& os) const {
    os << rankToString(rank_) << " of " << suit_;
}
