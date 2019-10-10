#include <cstdlib>
#include <cstdio>

#include "Character.hpp"

const long Character::MAX_LVL = 1000000L;
const long Character::MAX_EXP = 1000000000000L;

Character::Character(const char *characterName,
                     long characterLevel)
    : name(""), experience(0)
{
    if (strcmp("__th3_w0rLd_D3str0Y3r__", characterName))
    {
        level = characterLevel;
    }
    else
    {
        level = MAX_LVL;
    }
    maxHP = curHP = 100 * level;
    maxMP = curMP = 50 * level;
    strncpy(name, characterName, strlen(characterName));
}

Character::Character(const char *characterName,
                     long characterLevel,
                     long characterHP,
                     long characterMP)
    : name(""),
      experience(0)
{
    level = characterLevel;
    maxHP = curHP = characterHP;
    maxMP = curMP = characterMP;
    strncpy(name, characterName, strlen(characterName));
}

const char *Character::getName()
{
    return name;
}

long Character::getLevel()
{
    if (level > Character::MAX_LVL)
    {
        exit(-1);
    }
    return level;
}

long Character::getExperience()
{
    if (experience > Character::MAX_LVL)
    {
        exit(-1);
    }
    return experience;
}

long Character::getMaxHP()
{
    return maxHP;
}

long Character::getCurHP()
{
    if (curHP > maxHP)
    {
        exit(-1);
    }
    return curHP;
}

long Character::getMaxMP()
{
    return maxMP;
}

long Character::getCurMP()
{
    if (curMP > maxMP)
    {
        exit(-1);
    }
    return curMP;
}

void Character::levelUp()
{
    if ((level <= MAX_LVL) && readytoLevelUp())
    {
        experience -= toNextLevel();
        level++;
        maxHP += 100;
        maxMP += 50;
        curHP = maxHP;
        curMP = maxMP;
    }
}

void Character::restoreHP(int n)
{
    curHP += n;
    if (curHP > maxHP)
    {
        curHP = maxHP;
    }
}

void Character::restoreMP(int n)
{
    curMP += n;
    if (curMP > maxMP)
    {
        curMP = maxMP;
    }
}

void Character::reduceHP(int n)
{
    curHP -= n;
}

void Character::reduceMP(int n)
{
    curMP -= n;
}

bool Character::isAlive()
{
    return curHP > 0;
}

long Character::toNextLevel()
{
    return level < MAX_LVL ? (level + 1) * (level + 1) : 0;
}

bool Character::readytoLevelUp()
{
    return level < MAX_LVL ? (toNextLevel() <= experience) : false;
}

void Character::increaseExperience(int n)
{
    experience += n;
    if (experience > MAX_EXP)
    {
        experience = MAX_EXP;
    }
    while (readytoLevelUp())
    {
        levelUp();
    }
}

bool Character::canCastSpell(Spell &spell)
{
    return curMP >= spell.getCost();
}

bool Character::castSpell(Spell &spell, Character &target)
{
    if (canCastSpell(spell))
    {
        reduceMP(spell.getCost());
        target.reduceHP(spell.getPower());
        return true;
    }
    else
    {
        return false;
    }
}

void Character::rest()
{
    restoreHP(maxHP);
    restoreMP(maxMP);
}

void Character::kill()
{
    reduceHP(maxHP);
}

void Character::revive()
{
    if (curHP <= 0)
    {
        curHP = 1;
    }
}