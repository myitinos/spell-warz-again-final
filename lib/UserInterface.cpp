#include "UserInterface.hpp"

const int UserInterface::INTERVAL = 0;
const int UserInterface::MINI_INTERVAL = 0;
const int UserInterface::MAX_DAY = 28;
const int UserInterface::MAX_MONTH = 12;
const int UserInterface::MAX_YEAR = 100;

int UserInterface::day = 1;
int UserInterface::month = 1;
int UserInterface::year = 90;

bool UserInterface::gameOver = false;

std::vector<std::string> UserInterface::dayName = {
    "Morndas",
    "Tirdas",
    "Middas",
    "Turdas",
    "Fredas",
    "Loredas",
    "Sundas",
};

std::vector<std::string> UserInterface::monthName = {
    "Morning Star",
    "Sun's Dawn",
    "First Seed",
    "Rain's Hand",
    "Second Seed",
    "Mid Year",
    "Sun's Height",
    "Last Seed",
    "Hearthfire",
    "Frostfall",
    "Sun's Dusk",
    "Evening Star",
};

void UserInterface::print(std::string msg)
{
    std::cout << msg << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(UserInterface::INTERVAL));
}

void UserInterface::print(const char *msg)
{
    std::cout << msg << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(UserInterface::INTERVAL));
}

void UserInterface::println(std::string msg)
{
    std::cout << msg << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(UserInterface::INTERVAL));
}

void UserInterface::println(const char *msg)
{
    std::cout << msg << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(UserInterface::INTERVAL));
}

void UserInterface::printByChar(const char *msg)
{
    int len = strlen(msg);
    for (size_t i = 0; i < len; i++)
    {
        std::cout << msg[i] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(UserInterface::MINI_INTERVAL));
    }
}

void UserInterface::welcomeMessage()
{
    std::cout << "+++++++++++++++++++++++++++++++++++++++++\n"
              << "+ Welcome to Spell-Warz-Again-Final !!! +\n"
              << "+++++++++++++++++++++++++++++++++++++++++\n"
              << std::flush;
}

const char *UserInterface::chooseName(char *buffer)
{
    char choice = 0;
    while (choice != 'y' && choice != 'Y')
    {
        printf("Who should we call you?\n>");
        fflush(stdout);
        scanf("%63s", buffer);

        printf("So you are a young mage named \"%s\" correct? (y/N)\n>", buffer);
        fflush(stdout);
        scanf("%1s", &choice);
    }

    return buffer;
}

void UserInterface::epilogue()
{
    UserInterface::printByChar(
        "I'm tired of making epilogue...\n"
        "You are a young mage, defeat the damn arch-mage...\n"
        "F*ck, I'm tired of this...\n"
        "Do you know I just finished this sh*t at October 10th?\n"
        "Good luck and defeat the arch-mage.\n"
        "Trust me, you gonna need the \'Good Luck\' ...\n");
}

std::string UserInterface::dateString()
{
    char date[5] = {0};

    if (UserInterface::day < 21)
    {
        switch (UserInterface::day)
        {
        case 1:
            sprintf(date, "1st");
            break;
        case 2:
            sprintf(date, "2nd");
            break;
        case 3:
            sprintf(date, "3rd");
            break;
        default:
            sprintf(date, "%dth", UserInterface::day);
            break;
        }
    }
    else
    {
        switch (UserInterface::day % 10)
        {
        case 1:
            sprintf(date, "%dst", UserInterface::day);
            break;
        case 2:
            sprintf(date, "%dnd", UserInterface::day);
            break;
        case 3:
            sprintf(date, "%drd", UserInterface::day);
            break;
        default:
            sprintf(date, "%dth", UserInterface::day);
            break;
        }
    }

    return std::string(
        UserInterface::dayName.at(((UserInterface::day - 1) % 7)) + ", " +
        date + " of " + UserInterface::monthName.at(UserInterface::month - 1) +
        ", Year " + std::to_string(UserInterface::year));
}

void UserInterface::menu()
{
    std::cout << "=======================================\n"
              << UserInterface::dateString() << "\n"
              << "=======================================\n"
              << "Available action:\n"
              << "[1] Take a rest\n"
              << "[2] Practice magic\n"
              << "[3] Spar against classmate\n"
              << "[4] Challenge the new Arch-Mage\n"
              << "[5] Gather info about the new Arch-Mage\n"
              << "[6] Meditate to your inner-self\n"
              << "[0] Commit sudoku\n"
              << std::flush;
}

void UserInterface::enemiesInfo(std::vector<Character> &enemies)
{
    for (int i = 0; i < enemies.size(); i++)
    {
        std::cout << "[" << i << "] " << enemies.at(i).getName() << " (Lv." << enemies.at(i).getLevel() << ")\n";
    }
    std::cout << std::flush;
}

int UserInterface::getNumber(std::string msg, int min, int max)
{
    int buffer = max + 1;
    do
    {
        std::cout << msg << std::flush;
        if (std::cin.failbit || std::cin.eofbit)
        {
            std::cin.clear();
            std::cin.ignore(1);
        }
    } while (std::cin >> buffer && !(buffer <= max && buffer >= min));
    return buffer;
}

void UserInterface::nextDay()
{
    if (UserInterface::day++ >= UserInterface::MAX_DAY)
    {
        day = 1;
        if (UserInterface::month++ >= UserInterface::MAX_MONTH)
        {
            month = 1;
            if (UserInterface::year++ >= UserInterface::MAX_YEAR)
            {
                UserInterface::gameOver = true;
            }
        }
    }
}

bool UserInterface::isGameOver()
{
    return gameOver;
}

void UserInterface::characterInfo(Character &c)
{
    std::cout << "++++++++++++++++++++++++"
              << "\nName: " << c.getName()
              << "\n  HP: " << c.getCurHP() << "/" << c.getMaxHP()
              << "\n  MP: " << c.getCurMP() << "/" << c.getMaxMP()
              << "\n  Lv: " << c.getLevel()
              << "\n  Xp: " << c.getExperience()
              << "\n  next: " << c.toNextLevel()
              << "\n++++++++++++++++++++++++" << std::endl;
}