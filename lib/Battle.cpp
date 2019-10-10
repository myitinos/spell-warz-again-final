#include "Battle.hpp"

std::vector<Spell> Battle::SPELL_BOOK = {
    Spell("FLAG STEAL", Spell::TYPE_DESTRUCTION, 1000000, 1),
    Spell("Blazing Storm", Spell::TYPE_DESTRUCTION, 10, 5),
    Spell("Energy Arrow", Spell::TYPE_DESTRUCTION, 40, 10),
    Spell("Pyro Strike", Spell::TYPE_DESTRUCTION, 90, 15),
    Spell("Seism", Spell::TYPE_DESTRUCTION, 160, 20),
    Spell("Teleport", Spell::TYPE_DESTRUCTION, 250, 25),
    Spell("Beam of Nature's Wrath", Spell::TYPE_DESTRUCTION, 360, 30),
    Spell("Ball of the Molten Core", Spell::TYPE_DESTRUCTION, 490, 35),
    Spell("Wrath of Poison", Spell::TYPE_DESTRUCTION, 640, 40),
    Spell("Extortion Burst", Spell::TYPE_DESTRUCTION, 810, 45),
    Spell("Projection of Sound", Spell::TYPE_DESTRUCTION, 1000, 50),
    Spell("Soul Tempest", Spell::TYPE_DESTRUCTION, 1210, 55),
    Spell("Mystic Nova", Spell::TYPE_DESTRUCTION, 1440, 60),
    Spell("Frostfire Burn", Spell::TYPE_DESTRUCTION, 1690, 65),
    Spell("Torrent", Spell::TYPE_DESTRUCTION, 1960, 70),
    Spell("Windstorm", Spell::TYPE_DESTRUCTION, 2250, 75),
    Spell("Barrier of Redemption", Spell::TYPE_DESTRUCTION, 2560, 80),
    Spell("Burst of the Angels", Spell::TYPE_DESTRUCTION, 2890, 85),
    Spell("Absorption of Chaos", Spell::TYPE_DESTRUCTION, 3240, 90),
    Spell("Decay of Light", Spell::TYPE_DESTRUCTION, 3610, 95),
    Spell("Dispersion of Force", Spell::TYPE_DESTRUCTION, 4000, 100),
    Spell("Solar Barrage", Spell::TYPE_DESTRUCTION, 4410, 105),
    Spell("Death Burn", Spell::TYPE_DESTRUCTION, 4840, 110),
    Spell("Blazing Strike", Spell::TYPE_DESTRUCTION, 5290, 115),
    Spell("Imitate", Spell::TYPE_DESTRUCTION, 5760, 120),
    Spell("Shooting Star", Spell::TYPE_DESTRUCTION, 6250, 125),
    Spell("Seal of Traps", Spell::TYPE_DESTRUCTION, 6760, 130),
    Spell("Flare of the Inferno", Spell::TYPE_DESTRUCTION, 7290, 135),
    Spell("Distraction of Stone", Spell::TYPE_DESTRUCTION, 7840, 140),
    Spell("Concentration of Glory", Spell::TYPE_DESTRUCTION, 8410, 145),
    Spell("Calm of Energy", Spell::TYPE_DESTRUCTION, 9000, 150),
    Spell("Soul Surge", Spell::TYPE_DESTRUCTION, 9610, 155),
    Spell("Moonlight Blaze", Spell::TYPE_DESTRUCTION, 10240, 160),
    Spell("Sunlight Salvo", Spell::TYPE_DESTRUCTION, 10890, 165),
    Spell("Banish Demon", Spell::TYPE_DESTRUCTION, 11560, 170),
    Spell("Hurricane", Spell::TYPE_DESTRUCTION, 12250, 175),
    Spell("Blast of Soul Draining", Spell::TYPE_DESTRUCTION, 12960, 180),
    Spell("Burst of Altered Time", Spell::TYPE_DESTRUCTION, 13690, 185),
    Spell("Incantation of Time", Spell::TYPE_DESTRUCTION, 14440, 190),
    Spell("Demolition Curse", Spell::TYPE_DESTRUCTION, 15210, 195),
    Spell("Protection of Phantoms", Spell::TYPE_DESTRUCTION, 16000, 200),
    Spell("Mage Burst", Spell::TYPE_DESTRUCTION, 16810, 205),
    Spell("Starfire Hail", Spell::TYPE_DESTRUCTION, 17640, 210),
    Spell("Ice Blitz", Spell::TYPE_DESTRUCTION, 18490, 215),
    Spell("Cyclone", Spell::TYPE_DESTRUCTION, 19360, 220),
    Spell("Charge", Spell::TYPE_DESTRUCTION, 20250, 225),
    Spell("Barrier of Exhaustion", Spell::TYPE_DESTRUCTION, 21160, 230),
    Spell("Blessing of Demon Fire", Spell::TYPE_DESTRUCTION, 22090, 235),
    Spell("Illusion Blast", Spell::TYPE_DESTRUCTION, 23040, 240),
    Spell("Fury of Poison", Spell::TYPE_DESTRUCTION, 24010, 245),
    Spell("Plagueing of Fire", Spell::TYPE_DESTRUCTION, 25000, 250),
    Spell("Fiery Eruption", Spell::TYPE_DESTRUCTION, 26010, 255),
    Spell("Thunder Arrow", Spell::TYPE_DESTRUCTION, 27040, 260),
    Spell("Infernal Bomb", Spell::TYPE_DESTRUCTION, 28090, 265),
    Spell("Ignite", Spell::TYPE_DESTRUCTION, 29160, 270),
    Spell("Solidify", Spell::TYPE_DESTRUCTION, 30250, 275),
    Spell("Call of Burning Embers", Spell::TYPE_DESTRUCTION, 31360, 280),
    Spell("Burst of Acid", Spell::TYPE_DESTRUCTION, 32490, 285),
    Spell("Calm of Death", Spell::TYPE_DESTRUCTION, 33640, 290),
    Spell("Annihilation Burst", Spell::TYPE_DESTRUCTION, 34810, 295),
    Spell("Absorption of Strength", Spell::TYPE_DESTRUCTION, 36000, 300),
    Spell("Infernal Explosion", Spell::TYPE_DESTRUCTION, 37210, 305),
    Spell("Lava Blast", Spell::TYPE_DESTRUCTION, 38440, 310),
    Spell("Pyro Spike", Spell::TYPE_DESTRUCTION, 39690, 315),
    Spell("Mind Blast", Spell::TYPE_DESTRUCTION, 40960, 320),
    Spell("Extinguish", Spell::TYPE_DESTRUCTION, 42250, 325),
    Spell("Spell of Obliteration", Spell::TYPE_DESTRUCTION, 43560, 330),
    Spell("Hymn of Havoc", Spell::TYPE_DESTRUCTION, 44890, 335),
    Spell("Consecration Ritual", Spell::TYPE_DESTRUCTION, 46240, 340),
    Spell("Distraction of Perfection", Spell::TYPE_DESTRUCTION, 47610, 345),
    Spell("Delusion of Vulnerabilities", Spell::TYPE_DESTRUCTION, 49000, 350),
    Spell("Static Blaze", Spell::TYPE_DESTRUCTION, 50410, 355),
    Spell("Pyro Whip", Spell::TYPE_DESTRUCTION, 51840, 360),
    Spell("Acid Blitz", Spell::TYPE_DESTRUCTION, 53290, 365),
    Spell("Daydream", Spell::TYPE_DESTRUCTION, 54760, 370),
    Spell("Invigorate", Spell::TYPE_DESTRUCTION, 56250, 375),
    Spell("Hymn of Revival", Spell::TYPE_DESTRUCTION, 57760, 380),
    Spell("Jinx of Health", Spell::TYPE_DESTRUCTION, 59290, 385),
    Spell("Division of Defense", Spell::TYPE_DESTRUCTION, 60840, 390),
    Spell("Abjuration Orb", Spell::TYPE_DESTRUCTION, 62410, 395),
    Spell("Divinity of Life", Spell::TYPE_DESTRUCTION, 64000, 400),
    Spell("Shadow Flash", Spell::TYPE_DESTRUCTION, 65610, 405),
    Spell("Mind Flare", Spell::TYPE_DESTRUCTION, 67240, 410),
    Spell("Unholy Explosion", Spell::TYPE_DESTRUCTION, 68890, 415),
    Spell("Soulburn", Spell::TYPE_DESTRUCTION, 70560, 420),
    Spell("Phantom Form", Spell::TYPE_DESTRUCTION, 72250, 425),
    Spell("Rain of Plagues", Spell::TYPE_DESTRUCTION, 73960, 430),
    Spell("Aura of Shifting Sands", Spell::TYPE_DESTRUCTION, 75690, 435),
    Spell("Purification of Heat", Spell::TYPE_DESTRUCTION, 77440, 440),
    Spell("Purification of Hell", Spell::TYPE_DESTRUCTION, 79210, 445),
    Spell("Purity of SoulsVoid Tempest", Spell::TYPE_DESTRUCTION, 81000, 450),
    Spell("Thunder Hail", Spell::TYPE_DESTRUCTION, 82810, 455),
    Spell("Acid Bolt", Spell::TYPE_DESTRUCTION, 84640, 460),
    Spell("Incinerate", Spell::TYPE_DESTRUCTION, 86490, 465),
    Spell("Slow", Spell::TYPE_DESTRUCTION, 88360, 470),
    Spell("Bolt of Deflection", Spell::TYPE_DESTRUCTION, 90250, 475),
    Spell("Beam of Shadows", Spell::TYPE_DESTRUCTION, 92160, 480),
    Spell("Putrefaction of Blessings", Spell::TYPE_DESTRUCTION, 94090, 485),
    Spell("Exploitation of Force", Spell::TYPE_DESTRUCTION, 96040, 490),
    Spell("Annihilation Ceremony", Spell::TYPE_DESTRUCTION, 98010, 495),
    Spell("Repose of Energy", Spell::TYPE_DESTRUCTION, 100000, 500),
};
Battle::Battle(
    Character &p1,
    Character &p2) : player1(p1), player2(p2)
{
    this->turn = 0;
}

void Battle::battleStartAnnounce()
{
    std::cout << " === BATTLE START === \n"
              << "  " << player1.getName() << "\n"
              << "          vs  \n"
              << "  " << player2.getName() << "\n"
              << " === ============ === \n"
              << std::flush;
}

void Battle::battleEndAnnouce()
{
    std::cout << " === BATTLE END === \n"
              << " Winner: " << ((winner == 1) ? player1.getName() : player2.getName()) << "\n"
              << std::flush;
}

void Battle::start()
{
    int choiceInt;
    char buff[64] = {0};

    this->battleStartAnnounce();
    while ((player1.isAlive() && player2.isAlive()) && this->turn <= Battle::MAX_TURN)
    {
        std::cout << "Turn " << this->turn << " of " << Battle::MAX_TURN << "\n"
                  << "Your spell book:\n";
        for (size_t i = 1; i < SPELL_BOOK.size() && i <= (player1.getLevel()); i++)
        {
            std::cout << "[" << i << "] " << SPELL_BOOK.at(i).getName() << "\n";
        }
        std::cout << std::flush;

        choiceInt = UserInterface::getNumber(
            "What are you gonna cast this turn?\n>", 0,
            player1.getLevel() > SPELL_BOOK.size() ? SPELL_BOOK.size() : player1.getLevel());

        if (player1.canCastSpell(SPELL_BOOK.at(choiceInt)))
        {
            player1.castSpell(SPELL_BOOK.at(choiceInt), player2);
            snprintf(buff, 63, "%s cast %s...\n", player1.getName(), SPELL_BOOK.at(choiceInt).getName());
            UserInterface::print(buff);
            memset(buff, 0, 64);
            snprintf(buff, 63, "%s took %d damage...\n", player2.getName(), SPELL_BOOK.at(choiceInt).getPower());
            UserInterface::print(buff);
            memset(buff, 0, 64);
        }
        else
        {
            snprintf(buff, 63, "%s failed to cast %s!\n", player1.getName(), SPELL_BOOK.at(choiceInt).getName());
            UserInterface::print(buff);
        }

        choiceInt = (this->turn % (player2.getLevel() < SPELL_BOOK.size() ? player2.getLevel() : SPELL_BOOK.size())) + 1;
        if (player2.canCastSpell(SPELL_BOOK.at(choiceInt)))
        {
            player2.castSpell(SPELL_BOOK.at(choiceInt), player1);
            snprintf(buff, 63, "%s cast %s...\n", player2.getName(), SPELL_BOOK.at(choiceInt).getName());
            UserInterface::print(buff);
            memset(buff, 0, 64);
            snprintf(buff, 63, "%s took %d damage...\n", player1.getName(), SPELL_BOOK.at(choiceInt).getPower());
            UserInterface::print(buff);
            memset(buff, 0, 64);
        }
        else
        {
            snprintf(buff, 63, "%s failed to cast %s!\n", player2.getName(), SPELL_BOOK.at(choiceInt).getName());
            UserInterface::print(buff);
        }
        this->turn++;
    }

    this->winner = (player1.isAlive() && (player1.getCurHP() >= player2.getCurHP())) ? 1 : 2;
    this->battleEndAnnouce();
}

int Battle::getWinner()
{
    return this->winner;
}
