#ifndef SPELL_WARZ_CHARACTER_HPP
#define SPELL_WARZ_CHARACTER_HPP 1

#include <cstring>

#include "Spell.hpp"

class Character
{
protected:
    static const long MAX_LVL;
    static const long MAX_EXP;

    char name[32];
    long level;
    long experience;
    long maxHP;
    long maxMP;
    long curHP;
    long curMP;

    void restoreHP(int);
    void restoreMP(int);
    void reduceHP(int);
    void reduceMP(int);

public:
    Character(const char *characterName,
              long characterLevel);

    Character(const char *characterName,
              long characterLevel,
              long characterHP,
              long characterMP);

    bool castSpell(Spell &src, Character &dst);
    bool canCastSpell(Spell &src);

    const char *getName();
    long getLevel();
    long getExperience();
    long getMaxHP();
    long getMaxMP();
    long getCurHP();
    long getCurMP();
    long toNextLevel();

    bool readytoLevelUp();
    bool isAlive();
    void levelUp();
    void kill();
    void rest();
    void revive();
    void increaseExperience(int n);
};

#endif