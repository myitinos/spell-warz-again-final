#ifndef SPELL_WARZ_USER_INTERFACE_HPP
#define SPELL_WARZ_USER_INTERFACE_HPP 1

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <cstring>

#include "Character.hpp"
#include "Spell.hpp"

class UserInterface
{
protected:
    static const int INTERVAL;      // in ms
    static const int MINI_INTERVAL; // in ms
    static const int MAX_DAY;
    static const int MAX_MONTH;
    static const int MAX_YEAR;

    static std::vector<std::string> dayName;
    static std::vector<std::string> monthName;

    static int day;
    static int month;
    static int year;

    static bool gameOver;

public:
    static void print(std::string);
    static void print(const char *);
    static void println(std::string);
    static void println(const char *);
    static void printByChar(std::string);
    static void printByChar(const char *);

    static void welcomeMessage();
    static void epilogue();
    static void menu();
    static void nextDay();
    static void characterInfo(Character &);
    static void enemiesInfo(std::vector<Character> &);

    static std::string dateString();
    static int getNumber(std::string, int, int);
    static const char *chooseName(char *);

    static bool isGameOver();
};

#endif