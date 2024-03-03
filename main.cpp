#include <iostream>

void drawBoard(char *spaces);
void playerMove(char *spaces, char playerCharacter);
void computerMove(char *spaces, char computerCharacter);

bool checkRows(char *spaces, char playerCharacter);
bool checkColumns(char *spaces, char playerCharacter);
bool checkDiagonals(char *spaces, char playerCharacter);

bool checkForWinner(char *spaces, char playerCharacter, char computerCharacter);
bool checkForTie(char *spaces);

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

        if (checkForWinner(spaces, playerCharacter, computerCharacter))
        {
            gameActive = false;
            break;
        }
        else if (checkForTie(spaces))
        {
            gameActive = false;
            break;
        }

        computerMove(spaces, computerCharacter);
        drawBoard(spaces);

        if (checkForWinner(spaces, playerCharacter, computerCharacter))
        {
            gameActive = false;
            break;
        }
        else if (checkForTie(spaces))
        {
            gameActive = false;
            break;
        }
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

void computerMove(char *spaces, char computeCharacter)
{
    int number;
    srand(time(NULL));

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == '-')
        {
            spaces[number] = computeCharacter;
            break;
        }
    }
}

bool checkRows(char *spaces, char playerCharacter)
{
    for (int i = 0; i < 9; i += 3)
    {
        if ((spaces[i] != '-') && (spaces[i] == spaces[i + 1]) && (spaces[i + 1] == spaces[i + 2]))
        {
            return spaces[i] == playerCharacter;
        }
    }
    return false;
}

bool checkColumns(char *spaces, char playerCharacter)
{
    for (int i = 0; i < 3; ++i)
    {
        if ((spaces[i] != '-') && (spaces[i] == spaces[i + 3]) && (spaces[i + 3] == spaces[i + 6]))
        {
            return spaces[i] == playerCharacter;
        }
    }
    return false;
}

bool checkDiagonals(char *spaces, char playerCharacter)
{
    if ((spaces[0] != '-') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {
        return spaces[0] == playerCharacter;
    }
    else if ((spaces[2] != '-') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {
        return spaces[2] == playerCharacter;
    }
    return false;
}

bool checkForWinner(char *spaces, char playerCharacter, char computerCharacter)
{
    if (checkRows(spaces, playerCharacter) || checkColumns(spaces, playerCharacter) || checkDiagonals(spaces, playerCharacter))
    {
        std::cout << "Player Wins!\n";
        return true;
    }
    else if (checkRows(spaces, computerCharacter) || checkColumns(spaces, computerCharacter) || checkDiagonals(spaces, computerCharacter))
    {
        std::cout << "Computer Wins!\n";
        return true;
    }
    return false;
}

bool checkForTie(char *spaces)
{
    for (int i = 0; i < 9; ++i)
    {
        if (spaces[i] == '-')
        {
            return false;
        }
    }

    std::cout << "It's a tie!\n";
    return true;
}
