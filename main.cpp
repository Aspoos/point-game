#include <functional>
#include <iostream>
#include <iomanip>

const char BLOCK = char(254);
// const char BLOCK = char(79);
const char PLAYER_NONE = char(149);
const char PLAYER_1 = 'A';
const char PLAYER_2 = 'B';

const int OPTION_GAMEPLAY = 1;
const int OPTION_EXIT_GAME = 2;

// const char ARROW_Y = char(124);
// const char ARROW_X = char(45);

const char ARROW_Y = char(186);
const char ARROW_X = char(205);

// Weights fot discovery correct arrow
const int WX_L1_1 = 23, WX_L1_2 = 25, WX_L1_3 = 28, WX_L1_4 = 29;
const int WX_L2_1 = 43, WX_L2_2 = 45, WX_L2_3 = 47, WX_L2_4 = 49;

const int WY_L1_1 = 32, WY_L1_3 = 36, WY_L1_4 = 38;
const int WY_L2_2 = 34, WY_L2_5 = 40;

int main() {
    bool gameInProgress = true;
    bool matchInProgress = false;

    char cachePlayerBusy = PLAYER_NONE;

    char currentPlayer = PLAYER_NONE;

    int option = -1;

    char player_l1_y1 = PLAYER_NONE,
            player_l1_y3 = PLAYER_NONE,
            player_l2_y1 = PLAYER_NONE,
            player_l1_y4 = PLAYER_NONE;

    char player_l1_x1 = PLAYER_NONE,
            player_l1_x2 = PLAYER_NONE,
            player_l1_x3 = PLAYER_NONE,
            player_l1_x4 = PLAYER_NONE;

    char player_l2_x1 = PLAYER_NONE,
         player_l2_x2 = PLAYER_NONE,
         player_l2_x3 = PLAYER_NONE,
         player_l2_x4 = PLAYER_NONE,
         player_l2_x5 = PLAYER_NONE;

    // Arrow position X
    char ax_l1_1 = ' ', ax_l1_2 = ' ', ax_l1_3 = ' ', ax_l1_4 = ' ';
    char ax_l2_1 = ' ', ax_l2_2 = ' ', ax_l2_3 = ' ', ax_l2_4 = ' ';

    // Arrow position Y
    char ay_1 = ' ', ay_2 = ' ', ay_3 = ' ', ay_4 = ' ', ay_5 = ' ';

    // Players square content
    char square_1 = ' ', square_2 = ' ', square_3 = ' ', square_4 = ' ';

    while (gameInProgress) {
        std::cout << square_1 << std::endl;
        std::cout << "Menu Options" << std::endl;
        std::cout << " -> 1 - Play" << std::endl;
        std::cout << " -> 2 - Exit game" << std::endl;
        std::cout << "to type here: ";

        std::cin >> option;

        switch (option) {
            case OPTION_GAMEPLAY:
                matchInProgress = true;

                while (matchInProgress) {
                    system("cls");

                    int coordinate_line = -1, coordinate_line_2 = -1;
                    int coordinate_column = -1, coordinate_column_2 = -1;

                    if (cachePlayerBusy == PLAYER_NONE) {
                        if (currentPlayer != PLAYER_1) {
                            currentPlayer = PLAYER_1;
                        } else {
                            currentPlayer = PLAYER_2;
                        }
                    } else {
                        std::cout << "this coordination attachment the player : " << cachePlayerBusy << std::endl;
                    }

                    cachePlayerBusy = PLAYER_NONE;

                    std::cout << "Current player: " << currentPlayer << std::endl;
                    std::cout << std::setw(5) << "1" << std::setw(2) << "2" << std::setw(2) << "3" << std::setw(2) << "4" << std::setw(2) << "5" << ' ' << std::endl; // Top
                    std::cout << std::setw(2) << 1 << std::setw(3) << BLOCK << ax_l1_1 << BLOCK << ax_l1_2 << BLOCK << ax_l1_3 << BLOCK << ax_l1_4 << BLOCK << std::endl; // Line 1 with your columns
                    std::cout << std::setw(5) << ay_1 << square_1 << ay_2 << square_2 << ay_3 << square_3 << ay_4 << square_4 << ay_5 << std::endl; // Line empty to arrow vertical
                    std::cout << std::setw(2) << 2 << std::setw(3) << BLOCK << ax_l2_1 << BLOCK << ax_l2_2 << BLOCK << ax_l2_3 << BLOCK << ax_l2_4 << BLOCK << std::endl; // Line 2 with your columns

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
                        if (ax_l1_1 == ' ' || ay_1 == ' ') {
                            std::cout << "arrow available :" << std::endl;
                            if (ax_l1_1 == ' ') std::cout << " 1 - (L = 1 , C = 2)" << std::endl;
                            if (ay_1 == ' ') std::cout << " 2 - (L = 2 , C = 1)" << std::endl;
                        } else {
                            cachePlayerBusy = ax_l1_1;
                            std::cout << "posibilities not release, to type new position" << std::endl;
                            system("pause");
                            continue;
                        }
                    } else if (coordinate_line == 1 && coordinate_column == 2) {
                        if (ax_l1_2 == ' ' || ay_2 == ' ') {
                            std::cout << "arrow available :" << std::endl;
                            if (ax_l1_2 == ' ') std::cout << " 1 - (L = 1 , C = 3)" << std::endl;
                            if (ay_2 == ' ')std::cout << " 2 - (L = 2 , C = 2)" << std::endl;
                        } else {
                            cachePlayerBusy = ax_l1_2;
                            std::cout << "posibilities not release, to type new position" << std::endl;
                            system("pause");
                            continue;
                        }
                    } else if (coordinate_line == 1 && coordinate_column == 3) {
                        if (ax_l1_1 == ' ' || ay_3 == ' ' || ax_l1_3 == ' ') {
                            std::cout << "arrow available :" << std::endl;
                            if (ax_l1_1 == ' ') std::cout << " 1 - (L = 1 , C = 2)" << std::endl;
                            if (ax_l1_3 == ' ') std::cout << " 2 - (L = 1 , C = 4)" << std::endl;
                            if (ay_3 == ' ' )std::cout << " 3 - (L = 2 , C = 3)" << std::endl;
                        } else {
                            cachePlayerBusy = player_l1_y3;
                            std::cout << "posibilities not release, to type new position" << std::endl;
                            system("pause");
                            continue;
                        }
                    } else if (coordinate_line == 1 && coordinate_column == 4) {
                        if (ax_l1_4 == ' ' || ay_4 == ' ' || ax_l1_3 == ' ') {
                            std::cout << "arrow available :" << std::endl;
                            if (ax_l1_3 == ' ') std::cout << " 1 - (L = 1 , C = 3)" << std::endl;
                            if (ax_l1_4 == ' ') std::cout << " 2 - (L = 1 , C = 5)" << std::endl;
                            if (ay_4 == ' ' )std::cout << " 3 - (L = 2 , C = 4)" << std::endl;
                        } else {
                            cachePlayerBusy = player_l1_y3;
                            std::cout << "posibilities not release, to type new position" << std::endl;
                            system("pause");
                            continue;
                        }
                    } else {
                        std::cout << "sugestion not implemented to L: "<< coordinate_line << " C: " << coordinate_column << std::endl;
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
                    std::cout << "Weight: " << weight << std::endl;
                    system("pause");
                    switch (weight) {
                        // L = 1, C = 1 / L = 1, C = 2 | (11 + 12 = 23)
                        case WX_L1_1:
                            if (ax_l1_1 == ' ') {
                                player_l1_x1 = currentPlayer;
                                ax_l1_1 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l1_x1;
                            }
                            break;
                        // L = 1, C = 2 / L = 1, C = 3 | 12 + 13 = 25
                        case WX_L1_2:
                            if (ax_l1_2 == ' ') {
                                player_l1_x2 = currentPlayer;
                                ax_l1_2 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l1_x2;
                            }
                            break;
                        // L = 1, C = 3 / L = 1, C = 4 | 13 + 14 = 28
                        // L = 1, C = 4 / L = 1, C = 3 | 14 + 13 = 27
                        case WX_L1_3:
                        case WX_L1_3 - 1:
                            if (ax_l1_3 == ' ') {
                                ax_l1_3 = ARROW_X;
                                player_l1_x3 = currentPlayer;
                            } else {
                                cachePlayerBusy = player_l1_x3;
                            }
                            break;
                        // L = 1, C = 4 / L = 1, C = 5 | 14 + 15 = 29
                        case WX_L1_4:
                            if (ax_l1_4 == ' ') {
                                player_l1_x4 = currentPlayer;
                                ax_l1_4 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l1_x4;
                            }
                            break;
                        // L = 2, C = 1 / L = 2, C = 2 | 21 + 22 = 43
                        case WX_L2_1:
                            if (ax_l2_1 == ' ') {
                                player_l2_x1 = currentPlayer;
                                ax_l2_1 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l2_x1;
                            }
                        break;
                        // L = 2, C = 2 / L = 2, C = 3 | 22 + 23 = 45
                        case WX_L2_2:
                            if (ax_l2_2 == ' ') {
                                player_l2_x2 = currentPlayer;
                                ax_l2_2 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l2_x2;
                            }
                            break;
                        // L = 2, C = 3 / L = 2, C = 4 | 23 + 24 = 47
                        case WX_L2_3:
                            if (ax_l2_3 == ' ') {
                                player_l2_x3 = currentPlayer;
                                ax_l2_3 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l2_x3;
                            }
                        break;
                        // L = 2, C = 4 / L = 2, C = 5 | 24 + 25 = 49
                        case WX_L2_4:
                            if (ax_l2_4 == ' ') {
                                player_l2_x4 = currentPlayer;
                                ax_l2_4 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l2_x4;
                            }
                        break;
                        // L = 1, C = 3 / L = 2, C = 3 | 13 + 23 = 36
                        case WY_L1_3:
                            if (ay_3 == ' ') {
                                player_l1_y3 = currentPlayer;
                                ay_3 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l1_y3;
                            }
                            break;
                        // L = 1, C, 4 / L = 2, C = 4 | 14 + 24 = 38
                        case WY_L1_4:
                            if (ay_4 == ' ') {
                                player_l1_y4 = currentPlayer;
                                ay_4 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l1_y4;
                            }
                            break;
                        // L = 1, C = 1 / L = 2, C = 1 | (11 + 21 = 32)
                        case WY_L1_1:
                            if (ay_1 == ' ') {
                                player_l1_y1 = currentPlayer;
                                ay_1 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l1_y1;
                            }
                            break;
                        // L = 1, C = 2 / L = 2, C = 2 | 12 + 22 = 34
                        case WY_L2_2:
                            if (ay_2 == ' ') {
                                player_l2_y1 = currentPlayer;
                                ay_2 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l2_y1;
                            }
                            break;
                        // L = 1, C = 5 / L = 2, C = 5 | 15 + 25 = 40
                        case WY_L2_5:
                            if (ay_5 == ' ') {
                                player_l2_x5 = currentPlayer;
                                ay_5 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l2_x5;
                            }
                        break;
                        default:
                            std::cout << "Invalid weight, please type valid weight." << std::endl;
                    }

                    if (player_l1_x1 != PLAYER_NONE && player_l1_x1 == player_l2_x1 &&
                        player_l1_x1 == player_l1_y1 && player_l1_y1 == player_l2_y1) {
                        square_1 = player_l2_x1;
                    } else if (player_l1_x2 != PLAYER_NONE && player_l1_x2 == player_l2_x2 &&
                               player_l1_x2 == player_l1_y1 && player_l1_y1 == player_l2_y1) {
                        square_2 = player_l2_x2;
                    } else if (player_l1_x3 != PLAYER_NONE && player_l1_x3 == player_l2_x3 &&
                               player_l1_x3 == player_l1_y3 && player_l1_y3 == player_l2_x5) {
                        square_3 = player_l2_x3;
                    } else if (player_l1_x4 != PLAYER_NONE && player_l1_x4 == player_l2_x4 &&
                               player_l1_x4 == player_l1_y4 && player_l1_y4 == player_l2_x5) {
                        square_4 = player_l2_x4;
                    }
                }
                break;
            case OPTION_EXIT_GAME:
                system("cls");
                std::cout << "Game finished with successful" << std::endl;
                gameInProgress = false;
                break;
            default:
                system("cls");
                std::cout << "Invalid option, please selected 1 or 2." << std::endl;
        }
    }

    return 1;
}
