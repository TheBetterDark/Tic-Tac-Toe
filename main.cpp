#include <iostream>

void drawBoard(char *spaces);
void playerMove(char *spaces, char playerCharacter);
void computerMove(char *spaces, char computerCharacter);
bool checkForWinner(char *spaces, char playerCharacter, char computerCharacter);
bool checkTie(char *spaces);

int main()
{
    char spaces[9];
    std::fill(std::begin(spaces), std::end(spaces), '-');

    char playerCharacter = 'X';
    char computerCharacter = 'O';
    bool gameActive = true;

    drawBoard(spaces);

    while (gameActive)
    {
        playerMove(spaces, playerCharacter);
        drawBoard(spaces);
        computerMove(spaces, computerCharacter);
        drawBoard(spaces);
    }

    return 0;
};

void drawBoard(char *spaces)
{
    system("cls");
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "-----|-----|-----" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "-----|-----|-----" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
}

void playerMove(char *spaces, char playerCharacter)
{
    int number;
    do
    {
        std::cout << "Enter a position to place a marker (1-9): ";
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        number--;

        if (number >= 0 && number < 9 && spaces[number] == '-')
        {
            spaces[number] = playerCharacter;
            break;
        }
        else
        {
            std::cout << "Invalid position, please enter a number between 1 and 9 where the space is not already occupied.\n";
        }
    } while (true);
}

void computerMove(char *spaces, char computeCharacterr)
{
}
bool checkForWinner(char *spaces, char playerCharacter, char computerCharacter)
{
    return 0;
}
bool checkTie(char *spaces)
{
    return 0;
}