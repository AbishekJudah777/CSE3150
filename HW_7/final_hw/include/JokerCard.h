#ifndef JOKERCARD_H
#define JOKERCARD_H

#include "Card.h"
#include <string>

class JokerCard final : public Card {
private:
    std::string color_;
public:
    explicit JokerCard(std::string color);
    
    int value() const override; 
    void print(std::ostream& os) const override;
};

#endif
