#include <cstring>

#include "Spell.hpp"

Spell::Spell(const char *spellName,
             const int spellType,
             int spellPower,
             int spellCost) : type(spellType), name("")
{
    this->power = spellPower;
    this->cost = spellCost;
    strcpy(this->name, spellName);
}

int Spell::getType()
{
    return this->type;
}

int Spell::getPower()
{
    return this->power;
}

int Spell::getCost()
{
    return this->cost;
}

const char *Spell::getName()
{
    return this->name;
}
