#ifndef SPELL_WARZ_SPELL_CPP
#define SPELL_WARZ_SPELL_CPP 1

class Spell
{
protected:
    char name[16];
    int type;
    int power;
    int cost;

public:
    static const int NAME_LENGTH = 15;
    static const int TYPE_RESTORATION = 1;
    static const int TYPE_DESTRUCTION = 2;

    Spell(const char *spellName,
          const int spellType,
          int spellPower,
          int spellCost);

    const char *getName();
    int getType();
    int getPower();
    int getCost();
};

#endif