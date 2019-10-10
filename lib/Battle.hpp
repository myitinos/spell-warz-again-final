#ifndef SPELL_WARZ_BATTLE_HPP
#define SPELL_WARZ_BATTLE_HPP 1

#include <iostream>
#include <thread>
#include <chrono>

#include "Character.hpp"
#include "Spell.hpp"
#include "UserInterface.hpp"

class Battle
{
protected:
    static const int MAX_TURN = 100;
    static std::vector<Spell> SPELL_BOOK;
    int turn;
    int winner;

    Character &player1;
    Character &player2;

    void battleStartAnnounce();
    void battleEndAnnouce();
    void clearBuff();

public:
    Battle(Character &p1, Character &p2);
    int getWinner();
    void start();
};

#endif