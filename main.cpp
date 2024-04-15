#include <iostream>
#include <iomanip>

/*
 *  O Que ele tem que fazer ?
 *  1 - Rodar o jogo - OK
 *  2 - Perguntar para o usuario as posicoes
 *  3 - Desenhar a tabela de pontinhos
 *  ...
 * */

//   1 2 3 4
// 1 ■─■─■─■
//   │A│B│A│
// 2 ■─■─■─■
//
// L = 1, C = 1 == 11
// L = 1, C = 2 == 12
// 23 = ■─■
//
// L = 1, C = 2 == 12
// L = 1, C = 3 == 13
// 24 = ■─■
//
// L = 1, C = 1 == 11
// L = 2, C = 1 == 211
//
// 31 = ■
//      │
//      ■
//

const char PLAYER_NONE = char(149);
const char PLAYER_1 = 'A';
const char PLAYER_2 = 'B';

const int OPTION_GAMEPLAY = 1;
const int OPTION_EXIT_GAME = 2;

const char ARROW_Y = char(179);
const char ARROW_X = char(169);

// L = 1, C = 1
// L = 1, C = 2
// = 23
// L = 1, C = 2
// L = 1, C = 3
// = 25

// Weights fot discovery correct arrow
const int WX_L1_1 = 23, WX_L1_2 = 25;
//wx_l1_3 = ' ', wx_l1_4 = ' ';
//char wx_l2_1 = ' ', wx_l2_2 = ' ', wx_l2_3 = ' ', wx_l2_4 = ' ';
//char wy_1 = char(179), wy_2 = ' ', wy_3 = ' ', wy_4 = ' ';

int main() {

    bool gameInProgress = true;
    bool matchInProgress = false;
    bool canChangePlayer = true;

    char currentPlayer = PLAYER_NONE;

    int option = -1;

    char l1c1 = PLAYER_NONE, l1c2 = PLAYER_NONE;
    char l2c1 = PLAYER_NONE, l2c2 = PLAYER_NONE;
    char player_y1 = PLAYER_NONE;

    // Arrow position X
    char ax_l1_1 = ' ', ax_l1_2 = ' ', ax_l1_3 = ' ', ax_l1_4 = ' ';
    char ax_l2_1 = ' ', ax_l2_2 = ' ', ax_l2_3 = ' ', ax_l2_4 = ' ';

    // Arrow position Y
    char ay_1 = ' ', ay_2 = ' ', ay_3 = ' ', ay_4 = ' ';

    // Players square content
    char square_1 = ' ', square_2 = ' ', square_3 = ' ';

    while (gameInProgress) {

        std::cout << "Menu Options" << std::endl;
        std::cout << " -> 1 - Play" << std::endl;
        std::cout << " -> 2 - Exit game" << std::endl;
        std::cout << "to type here: ";

        std::cin >> option;

        switch (option) {
            case OPTION_GAMEPLAY:
                matchInProgress = true;

                while (matchInProgress) {
                    system("clear");

                    int coordinate_line = -1, coordinate_line_2 = -1;
                    int coordinate_column = -1, coordinate_column_2 = -1;

                    if (canChangePlayer) {
                        if (currentPlayer != PLAYER_1) {
                            currentPlayer = PLAYER_1;
                        } else {
                            currentPlayer = PLAYER_2;
                        }
                    }

                    canChangePlayer = true;

                    std::cout << std::setw(3) << 1 << std::setw(2) << 2 << std::setw(2) << 3 << std::setw(2) << 4 << ' ' << std::endl; // Top
                    std::cout << std::setw(2) << 1 << std::setw(2) << "■" << ax_l1_1 << "■" << ax_l1_2 << "■" << ax_l1_3 << "■" << ax_l1_4 << std::endl; // Line 1 with your columns
                    std::cout << std::setw(3) << ay_1 << square_1 << ay_2 << square_2 << ay_3 << square_3 << ay_4 << std::endl; // Line empty to arrow vertical
                    std::cout << std::setw(2) << 2 << std::setw(2) << "■" << ax_l2_1 << "■" << ax_l2_2 << "■" << ax_l2_3 << "■" << ax_l2_4 << std::endl; // Line 2 with your columns

                    std::cout << std::setw(18) << char(133) << std::endl;
                    std::cout << "Current player: " << currentPlayer << std::endl;
                    std::cout << std::setw(18) << char(133) << std::endl;

                    while (coordinate_line == -1) {
                        std::cout << "[1] Line position: ";
                        std::cin >> coordinate_line;
                        std::cout << std::endl;

                        if (coordinate_line < 1 || coordinate_line > 5) {
                            coordinate_line = -1;
                            std::cout << "To type valid line inside [1 - 5]";
                        }
                    }

                    while (coordinate_column == -1) {
                        std::cout << "[1] Column position: ";
                        std::cin >> coordinate_column;
                        std::cout << std::endl;

                        if (coordinate_column < 1 || coordinate_column > 5) {
                            coordinate_column = -1;
                            std::cout << "To type valid column inside [1 - 5]";
                        }
                    }

                    if (coordinate_line == 1 && coordinate_column == 1) {
                        std::cout << "arrow available :" << std::endl;
                        std::cout << " 1 - (L = 1 , C = 2)" << std::endl;
                        std::cout << " 2 - (L = 2 , C = 1)" << std::endl;
                    } else if (coordinate_line == 1 && coordinate_column == 2) {
                        std::cout << "arrow available :" << std::endl;
                        std::cout << " 1 - (L = 1 , C = 3)" << std::endl;
                        std::cout << " 2 - (L = 2 , C = 2)" << std::endl;
                    }

                    while (coordinate_line_2 == -1) {
                        std::cout << "[2] Line position: ";
                        std::cin >> coordinate_line_2;
                        std::cout << std::endl;

                        if (coordinate_line_2 < 1 || coordinate_line_2 > 5) {
                            coordinate_line_2 = -1;
                            std::cout << "To type valid line inside [1 - 5]";
                        }
                    }

                    while (coordinate_column_2 == -1) {
                        std::cout << "[2] Column position: ";
                        std::cin >> coordinate_column_2;
                        std::cout << std::endl;

                        if (coordinate_column_2 < 1 || coordinate_column_2 > 5) {
                            coordinate_column_2 = -1;
                            std::cout << "To type valid column inside [1 - 5]";
                        }
                    }

                    int weight = ((coordinate_line * 10) + coordinate_column) +
                                 ((coordinate_line_2 * 10) + coordinate_column_2);

                    switch (weight) {
                        // L = 1, C = 1 / L = 1, C = 2 | (11 + 12 = 23)
                        case WX_L1_1:
                            if (ax_l1_1 == ' ') {
                                l1c1 = currentPlayer;
                                ax_l1_1 = ARROW_X;
                            } else {
                                canChangePlayer = false;
                                std::cout << "this coordination attachment the player : " << l1c1 << std::endl;
                            }
                            break;
                        // L = 1, C = 1 / L = 2, C = 1 | (11 + 21 = 32)
                        case 32:
                            if (ay_1 == ' ') {
                                player_y1 = currentPlayer;
                                ay_1 = ARROW_Y;
                            } else {
                                canChangePlayer = false;
                                std::cout << "this coordination attachment the player : " << player_y1 << std::endl;
                            }
                            break;
                    }
                }
                break;

            case OPTION_EXIT_GAME:
                system("clear");
                std::cout << "Game finished with successful" << std::endl;
                gameInProgress = false;
                break;
            default:
                system("clear");
                std::cout << "Invalid option, please selected 1 or 2." << std::endl;
        }
    }

    return 1;
}
