
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <random>
#include <fstream>
#include <unistd.h>

#include "lib/Character.hpp"
#include "lib/Spell.hpp"
#include "lib/UserInterface.hpp"
#include "lib/Battle.hpp"

std::string loadFlag()
{
    std::string flagString;
    std::ifstream flagFile("flag.txt");
    flagFile >> flagString;
    flagFile.close();
    return flagString;
}

int main()
{
    srand(time(0));
    alarm(600);

    std::string flag = loadFlag();
    char playerName[64] = {0};
    UserInterface::chooseName(playerName);
    Character player = Character(playerName, 1);
    Character archMage = Character("Arch-Mage", 10000);
    std::vector<Character> enemies = {
        Character("Uraneus", 1),
        Character("Ekey", 2),
        Character("Wekius", 3),
        Character("Dhemaex", 4),
        Character("Uravras", 5),
    };

    UserInterface::welcomeMessage();
    UserInterface::epilogue();

    while (player.isAlive() && !UserInterface::isGameOver())
    {
        int choiceInt = -1;
        char choiceChar = -1;
        UserInterface::menu();
        choiceInt = UserInterface::getNumber(
            "What are you gonna do today?\n>",
            0, 6);
        switch (choiceInt)
        {
        case 0:
            UserInterface::print("You commit sudoku...\n");
            UserInterface::print("Was it supposed to be seppuku?\n");
            UserInterface::print("Nevermind, you killed yourself.\n");
            player.kill();
            break;
        case 1:
            UserInterface::print("You spend the whole day sleeping...\n");
            UserInterface::print("HP and MP restored.\n");
            player.rest();
            break;
        case 2:
            UserInterface::print("You practice your magic in the yard...\n");
            UserInterface::print("You gained some experience.\n");
            printf("%ld\n", player.getLevel());
            fflush(stdout);
            player.increaseExperience((rand() % player.getLevel()) + 1);
            break;
        case 3:
            UserInterface::print("List of your classmates:\n");
            UserInterface::enemiesInfo(enemies);
            choiceInt = UserInterface::getNumber("Who would you prefer to train with?\n>", 0, enemies.size());
            UserInterface::print("You are going to spar with:\n");
            UserInterface::characterInfo(enemies.at(choiceInt));
            UserInterface::print("Are you sure? (y/N)\n>");
            std::cin >> choiceChar;
            if (choiceChar == 'y' || choiceChar == 'Y')
            {
                Character enemy = Character(enemies.at(choiceInt));
                Battle battle = Battle(player, enemy);
                battle.start();
                if (battle.getWinner() == 1)
                {
                    UserInterface::print("You win, you get more experience...\n");
                    player.increaseExperience(enemies.at(choiceInt).getLevel());
                }
                else
                {
                    UserInterface::print("You lose, but you still get some experience...\n");
                    player.revive();
                    player.increaseExperience(enemies.at(choiceInt).getLevel() / 2);
                }
            }
            else
            {
                UserInterface::print("On second thought, you decide to sleep in your room instead...\n");
                player.rest();
            }

            break;
        case 4:
            UserInterface::print("You are going to challenge the Arch-Mage...\n");
            UserInterface::print("Are you sure? (y/N)\n>");
            std::cin >> choiceChar;
            if (choiceChar == 'y' || choiceChar == 'Y')
            {
                Battle battle = Battle(player, archMage);
                battle.start();
                if (battle.getWinner() == 1)
                {
                    UserInterface::print("You win, you get more experience...\n");
                    player.increaseExperience(enemies.at(choiceInt).getLevel());
                    UserInterface::print("You win against the Arch-Mage!\n");
                    UserInterface::print("He let you take a glimpse to the scroll that you always wanted...\n");
                    UserInterface::print("Turns out the content is just some meaningless word...\n");
                    UserInterface::print("Here is the content:\n");
                    UserInterface::print(flag + "\n");
                }
                else
                {
                    UserInterface::print("You lose...\n");
                    UserInterface::print("Sadly his spell was to powerful,\n");
                    UserInterface::print("You got killed by the arch-mage...\n");
                }
            }
            else
            {
                UserInterface::print("On second thought, you decide to sleep in your room instead...\n");
                player.rest();
            }
            break;
        case 5:
            UserInterface::print("You found some info about the arch-mage:\n");
            UserInterface::characterInfo(archMage);
            break;
        case 6:
            UserInterface::print("You meditate and got some insight to your ability:\n");
            UserInterface::characterInfo(player);
            break;
        }
        UserInterface::nextDay();
    }
}
