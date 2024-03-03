#include <iostream>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char spaces[9];
    for (int i = 1; i <= 9; i++)
    {
        spaces[i] = '-';
    }

    char playerCharacter = 'X';
    char computerCharacter = 'O';
    bool gameActive = true;

    drawBoard(spaces);

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

void playerMove(char *spaces, char player)
{
}
void computerMove(char *spaces, char computer)
{
}
bool checkWinner(char *spaces, char player, char computer)
{
    return 0;
}
bool checkTie(char *spaces)
{
    return 0;
}