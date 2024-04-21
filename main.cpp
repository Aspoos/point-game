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
const int WX_L1_1 = 23, WX_L1_2 = 25, WX_L1_3 = 28, WX_L1_4 = 29; // First line with x
const int WX_L2_1 = 43, WX_L2_2 = 45, WX_L2_3 = 47, WX_L2_4 = 49; // Secound line with x

const int WY_L1_1 = 32, WY_L1_3 = 36, WY_L1_4 = 38, WY_L1_2 = 34, WY_L1_5 = 40; // First line with Y

int main() {
    bool gameInProgress = true;
    bool matchInProgress = false;

    char cachePlayerBusy = PLAYER_NONE;
    char currentPlayer = PLAYER_NONE;

    int option = -1;

    char player_l1_y1 = PLAYER_NONE, player_l1_y2 = PLAYER_NONE, player_l1_y3 = PLAYER_NONE, player_l1_y4 = PLAYER_NONE;
    char player_l2_y1 = PLAYER_NONE, player_l2_y2 = PLAYER_NONE, player_l2_y3 = PLAYER_NONE, player_l2_y4 = PLAYER_NONE;
    char player_l3_y1 = PLAYER_NONE, player_l3_y2 = PLAYER_NONE, player_l3_y3 = PLAYER_NONE, player_l3_y4 = PLAYER_NONE;
    char player_l4_y1 = PLAYER_NONE, player_l4_y2 = PLAYER_NONE, player_l4_y3 = PLAYER_NONE, player_l4_y4 = PLAYER_NONE;

    char player_l1_x1 = PLAYER_NONE, player_l1_x2 = PLAYER_NONE, player_l1_x3 = PLAYER_NONE, player_l1_x4 = PLAYER_NONE;
    char player_l2_x1 = PLAYER_NONE, player_l2_x2 = PLAYER_NONE, player_l2_x3 = PLAYER_NONE, player_l2_x4 = PLAYER_NONE, player_l2_x5 = PLAYER_NONE;
    char player_l3_x1 = PLAYER_NONE, player_l3_x2 = PLAYER_NONE, player_l3_x3 = PLAYER_NONE, player_l3_x4 = PLAYER_NONE, player_l3_x5 = PLAYER_NONE;
    char player_l4_x1 = PLAYER_NONE, player_l4_x2 = PLAYER_NONE, player_l4_x3 = PLAYER_NONE, player_l4_x4 = PLAYER_NONE, player_l4_x5 = PLAYER_NONE;
    char player_l5_x1 = PLAYER_NONE, player_l5_x2 = PLAYER_NONE, player_l5_x3 = PLAYER_NONE, player_l5_x4 = PLAYER_NONE, player_l5_x5 = PLAYER_NONE;

    // Arrow position X
    char ax_l1_1 = ' ', ax_l1_2 = ' ', ax_l1_3 = ' ', ax_l1_4 = ' ';
    char ax_l2_1 = ' ', ax_l2_2 = ' ', ax_l2_3 = ' ', ax_l2_4 = ' ';
    char ax_l3_1 = ' ', ax_l3_2 = ' ', ax_l3_3 = ' ', ax_l3_4 = ' ';
    char ax_l4_1 = ' ', ax_l4_2 = ' ', ax_l4_3 = ' ', ax_l4_4 = ' ';
    char ax_l5_1 = ' ', ax_l5_2 = ' ', ax_l5_3 = ' ', ax_l5_4 = ' ';


    // Arrow position Y (Empty line squad draw inside lines X above up and below)
    char ay_el1_1 = ' ', ay_el1_2 = ' ', ay_el1_3 = ' ', ay_el1_4 = ' ', ay_el1_5 = ' ';
    char ay_el2_1 = ' ', ay_el2_2 = ' ', ay_el2_3 = ' ', ay_el2_4 = ' ', ay_el2_5 = ' ';
    char ay_el3_1 = ' ', ay_el3_2 = ' ', ay_el3_3 = ' ', ay_el3_4 = ' ', ay_el3_5 = ' ';
    char ay_el4_1 = ' ', ay_el4_2 = ' ', ay_el4_3 = ' ', ay_el4_4 = ' ', ay_el4_5 = ' ';

    // Players square content
    char square_el1_1 = ' ', square_el1_2 = ' ', square_el1_3 = ' ', square_el1_4 = ' '; // line empty 1
    char square_el2_1 = ' ', square_el2_2 = ' ', square_el2_3 = ' ', square_el2_4 = ' '; // line empty 2
    char square_el3_1 = ' ', square_el3_2 = ' ', square_el3_3 = ' ', square_el3_4 = ' '; // line empty 3
    char square_el4_1 = ' ', square_el4_2 = ' ', square_el4_3 = ' ', square_el4_4 = ' '; // line empty 4

    while (gameInProgress) {
        std::cout << square_el1_1 << std::endl;
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
                    std::cout << std::endl;
                    std::cout << std::setw(5) << "1" << std::setw(2) << "2" << std::setw(2) << "3" << std::setw(2) << "4" << std::setw(2) << "5" << ' ' << std::endl; // Top

                    std::cout << std::setw(2) << 1 << std::setw(3) << BLOCK << ax_l1_1 << BLOCK << ax_l1_2 << BLOCK << ax_l1_3 << BLOCK << ax_l1_4 << BLOCK << std::endl; // Line 1 with your columns
                    std::cout << std::setw(5) << ay_el1_1 << square_el1_1 << ay_el1_2 << square_el1_2 << ay_el1_3 << square_el1_3 << ay_el1_4 << square_el1_4 << ay_el1_5 << std::endl; // Line empty to arrow vertical
                    std::cout << std::setw(2) << 2 << std::setw(3) << BLOCK << ax_l2_1 << BLOCK << ax_l2_2 << BLOCK << ax_l2_3 << BLOCK << ax_l2_4 << BLOCK << std::endl; // Line 2 with your columns

                    std::cout << std::setw(5) << ay_el2_1 << square_el2_1 << ay_el2_2 << square_el2_2 << ay_el2_3 << square_el2_3 << ay_el2_4 << square_el2_4 << ay_el2_5 << std::endl; // Line empty to arrow vertical
                    std::cout << std::setw(2) << 3 << std::setw(3) << BLOCK << ax_l3_1 << BLOCK << ax_l3_2 << BLOCK << ax_l3_3 << BLOCK << ax_l3_4 << BLOCK << std::endl; // Line 2 with your columns

                    std::cout << std::setw(5) << ay_el3_1 << square_el3_1 << ay_el3_2 << square_el3_2 << ay_el3_3 << square_el3_3 << ay_el3_4 << square_el3_4 << ay_el3_5 << std::endl; // Line empty to arrow vertical
                    std::cout << std::setw(2) << 4 << std::setw(3) << BLOCK << ax_l4_1 << BLOCK << ax_l4_2 << BLOCK << ax_l4_3 << BLOCK << ax_l4_4 << BLOCK << std::endl; // Line 2 with your columns

                    std::cout << std::setw(5) << ay_el4_1 << square_el4_1 << ay_el4_2 << square_el4_2 << ay_el4_3 << square_el4_3 << ay_el4_4 << square_el4_4 << ay_el4_5 << std::endl; // Line empty to arrow vertical
                    std::cout << std::setw(2) << 5 << std::setw(3) << BLOCK << ax_l5_1 << BLOCK << ax_l5_2 << BLOCK << ax_l5_3 << BLOCK << ax_l5_4 << BLOCK << std::endl; // Line 2 with your columns
                    std::cout << std::endl;

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
                        if (ax_l1_1 == ' ' || ay_el1_1 == ' ') {
                            std::cout << "arrow available :" << std::endl;
                            if (ax_l1_1 == ' ') std::cout << " 1 - (L = 1 , C = 2)" << std::endl;
                            if (ay_el1_1 == ' ') std::cout << " 2 - (L = 2 , C = 1)" << std::endl;
                        } else {
                            cachePlayerBusy = ax_l1_1;
                            std::cout << "posibilities not release, to type new position" << std::endl;
                            system("pause");
                            continue;
                        }
                    } else if (coordinate_line == 1 && coordinate_column == 2) {
                        if (ax_l1_2 == ' ' || ay_el1_2 == ' ') {
                            std::cout << "arrow available :" << std::endl;
                            if (ax_l1_2 == ' ') std::cout << " 1 - (L = 1 , C = 3)" << std::endl;
                            if (ay_el1_2 == ' ')std::cout << " 2 - (L = 2 , C = 2)" << std::endl;
                        } else {
                            cachePlayerBusy = ax_l1_2;
                            std::cout << "posibilities not release, to type new position" << std::endl;
                            system("pause");
                            continue;
                        }
                    } else if (coordinate_line == 1 && coordinate_column == 3) {
                        if (ax_l1_1 == ' ' || ay_el1_3 == ' ' || ax_l1_3 == ' ') {
                            std::cout << "arrow available :" << std::endl;
                            if (ax_l1_1 == ' ') std::cout << " 1 - (L = 1 , C = 2)" << std::endl;
                            if (ax_l1_3 == ' ') std::cout << " 2 - (L = 1 , C = 4)" << std::endl;
                            if (ay_el1_3 == ' ' )std::cout << " 3 - (L = 2 , C = 3)" << std::endl;
                        } else {
                            cachePlayerBusy = player_l1_y3;
                            std::cout << "posibilities not release, to type new position" << std::endl;
                            system("pause");
                            continue;
                        }
                    } else if (coordinate_line == 1 && coordinate_column == 4) {
                        if (ax_l1_4 == ' ' || ay_el1_4 == ' ' || ax_l1_3 == ' ') {
                            std::cout << "arrow available :" << std::endl;
                            if (ax_l1_3 == ' ') std::cout << " 1 - (L = 1 , C = 3)" << std::endl;
                            if (ax_l1_4 == ' ') std::cout << " 2 - (L = 1 , C = 5)" << std::endl;
                            if (ay_el1_4 == ' ' )std::cout << " 3 - (L = 2 , C = 4)" << std::endl;
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
                        /*
                         * LINE 1
                         */
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

                        /*
                         * LINE 2
                         */
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
                        /*
                         * LINE 3
                         */

                        // L = 3, C = 1 / L = 3 , C = 2 | 31 + 32 = 63 | right
                        case 63:
                            if (ax_l3_1 == ' ') {
                                player_l3_x1 = currentPlayer;
                                ax_l3_1 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l3_x1;
                            }
                            break;
                        // L = 3, C = 1 / L = 2 , C = 1 | 31 + 21 = 52 | above
                        case 52:
                            if (ay_el2_1 == ' ') {
                                player_l2_y1 = currentPlayer;
                                ay_el2_1 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l2_y1;
                            }
                            break;
                        // L = 3, C = 1 / L = 4 , C = 1 | 31 + 41 = 72 | below
                        case 72:
                            if (ay_el3_1 == ' ') {
                                player_l3_y1 = currentPlayer;
                                ay_el3_1 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l3_y1;
                            }
                            break;
                        // L = 3, C = 2 / L = 3 , C = 3 | 32 + 33 = 65 | right
                        case 65:
                            if (ax_l3_2 == ' ') {
                                player_l3_x2 = currentPlayer;
                                ax_l3_2 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l3_x2;
                            }
                            break;
                        // L = 3, C = 2 / L = 2 , C = 2 | 32 + 22 = 54 | above
                        case 54:
                            if (ay_el2_2 == ' ') {
                                player_l2_y2 = currentPlayer;
                                ay_el2_2 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l2_y2;
                            }
                            break;
                        // L = 3, C = 2 / L = 4 , C = 2 | 32 + 42 = 74 | below
                        case 74:
                            if (ay_el3_2 == ' ') {
                                player_l3_y2 = currentPlayer;
                                ay_el3_2 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l3_y2;
                            }
                            break;
                        // L = 3, C = 3 / L = 3 , C = 4 | 33 + 34 = 67 | right
                        case 67:
                            if (ax_l3_3 == ' ') {
                                player_l3_x3 = currentPlayer;
                                ax_l3_3 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l3_x3;
                            }
                            break;
                        // L = 3, C = 3 / L = 2 , C = 3 | 33 + 23 = 56 | above
                        case 56:
                            if (ay_el2_3 == ' ') {
                                player_l2_y3 = currentPlayer;
                                ay_el2_3 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l2_y3;
                            }
                            break;
                        // L = 3, C = 3 / L = 4 , C = 3 | 33 + 43 = 76 | below
                        case 76:
                            if (ay_el3_3 == ' ') {
                                player_l3_y3 = currentPlayer;
                                ay_el3_3 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l3_y3;
                            }
                            break;
                        // L = 3, C = 4 / L = 3 , C = 5 | 34 + 35 = 69 | right
                        case 69:
                            if (ax_l3_4 == ' ') {
                                player_l3_x4 = currentPlayer;
                                ax_l3_4 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l3_x4;
                            }
                            break;
                        // L = 3, C = 4 / L = 2 , C = 4 | 34 + 24 = 58 | above
                        case 58:
                            if (ay_el2_4 == ' ') {
                                player_l2_y4 = currentPlayer;
                                ay_el2_4 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l2_y4;
                            }
                            break;
                        // L = 3, C = 4 / L = 4 , C = 4 | 34 + 44 = 78 | below
                        case 78:
                            if (ay_el3_4 == ' ') {
                                player_l3_y4 = currentPlayer;
                                ay_el3_4 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l3_y4;
                            }
                            break;
                        // L = 3, C = 5 / L = 2 , C = 5 | 35 + 25 = 60 | above
                        case 60:
                            if (ay_el2_5 == ' ') {
                                player_l2_x5 = currentPlayer;
                                ay_el2_5 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l2_x5;
                            }
                            break;
                        // L = 3, C = 5 / L = 4 , C = 5 | 35 + 45 = 80 | below
                        case 80:
                            if (ay_el3_5 == ' ') {
                                player_l3_x5 = currentPlayer;
                                ay_el3_5 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l3_x5;
                            }
                            break;
                        /*
                         * LINE 4
                         */

                        // L = 4, C = 1 / L = 4 , C = 2 | 41 + 42 = 83 | right
                        case 83:
                            if (ax_l4_1 == ' ') {
                                player_l4_x1 = currentPlayer;
                                ax_l4_1 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l4_x1;
                            }
                            break;
                        // L = 4, C = 1 / L = 5 , C = 1 | 41 + 51 = 92 | below
                        case 92:
                            if (ay_el4_1 == ' ') {
                                player_l4_y1 = currentPlayer;
                                ay_el4_1 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l4_y1;
                            }
                            break;
                        // L = 4, C = 2 / L = 4 , C = 3 | 42 + 43 = 85 | right
                        case 85:
                            if (ax_l4_2 == ' ') {
                                player_l4_x2 = currentPlayer;
                                ax_l4_2 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l4_x2;
                            }
                            break;
                        // L = 4, C = 2 / L = 5 , C = 2 | 42 + 52 = 94 | below
                        case 94:
                            if (ay_el4_2 == ' ') {
                                player_l4_y2 = currentPlayer;
                                ay_el4_2 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l4_y2;
                            }
                            break;
                        // L = 4, C = 3 / L = 4 , C = 4 | 43 + 44 = 87 | right
                        case 87:
                            if (ax_l4_3 == ' ') {
                                player_l4_x3 = currentPlayer;
                                ax_l4_3 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l4_x3;
                            }
                            break;
                        // L = 4, C = 3 / L = 5 , C = 3 | 43 + 53 = 96 | below
                        case 96:
                            if (ay_el4_3 == ' ') {
                                player_l4_y3 = currentPlayer;
                                ay_el4_3 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l4_y3;
                            }
                            break;
                        // L = 4, C = 4 / L = 4 , C = 5 | 44 + 45 = 89 | right
                        case 89:
                            if (ax_l4_4 == ' ') {
                                player_l4_x4 = currentPlayer;
                                ax_l4_4 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l4_x4;
                            }
                            break;
                        // L = 4, C = 4 / L = 5 , C = 4 | 44 + 54 = 98 | below
                        case 98:
                            if (ay_el4_4 == ' ') {
                                player_l4_y4 = currentPlayer;
                                ay_el4_4 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l4_y4;
                            }
                            break;
                        // L = 4, C = 5 / L = 5 , C = 5 | 45 + 55 = 100 | below
                        case 100:
                            if (ay_el4_5 == ' ') {
                                player_l5_x5 = currentPlayer;
                                ay_el4_5 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l5_x5;
                            }
                            break;
                        /*
                        * LINE 5
                        */
                        // L = 5, C = 1 / L = 5 , C = 2 | 51 + 52 = 103 | right/left
                        case 103:
                            if (ax_l5_1 == ' ') {
                                player_l5_x1 = currentPlayer;
                                ax_l5_1 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l5_x1;
                            }
                            break;
                        // L = 5, C = 2 / L = 5 , C = 3 | 52 + 53 = 105 | right/left
                        case 105:
                            if (ax_l5_2 == ' ') {
                                player_l5_x2 = currentPlayer;
                                ax_l5_2 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l5_x2;
                            }
                            break;
                        // L = 5, C = 3 / L = 5 , C = 4 | 53 + 54 = 107 | right/left
                        case 107:
                            if (ax_l5_3 == ' ') {
                                player_l5_x3 = currentPlayer;
                                ax_l5_3 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l5_x3;
                            }
                            break;
                        // L = 5, C = 4 / L = 5 , C = 5 | 54 + 55 = 109 | right/left
                        case 109:
                            if (ax_l5_4 == ' ') {
                                player_l5_x4 = currentPlayer;
                                ax_l5_4 = ARROW_X;
                            } else {
                                cachePlayerBusy = player_l5_x4;
                            }
                            break;
                        // L = 1, C = 3 / L = 2, C = 3 | 13 + 23 = 36
                        case WY_L1_3:
                            if (ay_el1_3 == ' ') {
                                player_l1_y3 = currentPlayer;
                                ay_el1_3 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l1_y3;
                            }
                            break;
                        /*
                         * Empty Line 1
                         */
                        // L = 1, C, 4 / L = 2, C = 4 | 14 + 24 = 38
                        case WY_L1_4:
                            if (ay_el1_4 == ' ') {
                                player_l1_y4 = currentPlayer;
                                ay_el1_4 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l1_y4;
                            }
                            break;
                        // L = 1, C = 1 / L = 2, C = 1 | (11 + 21 = 32)
                        case WY_L1_1:
                            if (ay_el1_1 == ' ') {
                                player_l1_y1 = currentPlayer;
                                ay_el1_1 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l1_y1;
                            }
                            break;
                        // L = 1, C = 2 / L = 2, C = 2 | 12 + 22 = 34
                        case WY_L1_2:
                            if (ay_el1_2 == ' ') {
                                player_l1_y2 = currentPlayer;
                                ay_el1_2 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l1_y2;
                            }
                            break;
                        // L = 1, C = 5 / L = 2, C = 5 | 15 + 25 = 40
                        case WY_L1_5:
                            if (ay_el1_5 == ' ') {
                                player_l2_x5 = currentPlayer;
                                ay_el1_5 = ARROW_Y;
                            } else {
                                cachePlayerBusy = player_l2_x5;
                            }
                        break;
                        default:
                            std::cout << "Invalid weight, please type valid weight." << std::endl;
                    }

                    if (player_l1_x1 != PLAYER_NONE && player_l1_x1 == player_l2_x1 && player_l1_x1 == player_l1_y1 && player_l1_y1 == player_l1_y2) {
                        square_el1_1 = player_l2_x1;
                    } else if (player_l1_x2 != PLAYER_NONE && player_l1_x2 == player_l2_x2 && player_l1_x2 == player_l1_y1 && player_l1_y1 == player_l1_y2) {
                        square_el1_2 = player_l2_x2;
                    } else if (player_l1_x3 != PLAYER_NONE && player_l1_x3 == player_l2_x3 && player_l1_x3 == player_l1_y3 && player_l1_y3 == player_l2_x5) {
                        square_el1_3 = player_l2_x3;
                    } else if (player_l1_x4 != PLAYER_NONE && player_l1_x4 == player_l2_x4 && player_l1_x4 == player_l1_y4 && player_l1_y4 == player_l2_x5) {
                        square_el1_4 = player_l2_x4;
                    } else if (player_l2_x1 != PLAYER_NONE && player_l2_x1 == player_l3_x1 && player_l2_x1 == player_l2_y1 && player_l2_y1 == player_l2_y2) {
                        square_el2_1 = player_l3_x1;
                    } else if (player_l2_x2 != PLAYER_NONE && player_l2_x2 == player_l3_x2 && player_l2_x2 == player_l2_y1 && player_l2_y1 == player_l2_y2) {
                        square_el2_2 = player_l3_x2;
                    } else if (player_l2_x3 != PLAYER_NONE && player_l2_x3 == player_l3_x3 && player_l2_x3 == player_l2_y3 && player_l2_y3 == player_l3_x5) {
                        square_el2_3 = player_l3_x3;
                    } else if (player_l2_x4 != PLAYER_NONE && player_l2_x4 == player_l3_x4 && player_l2_x4 == player_l2_y4 && player_l2_y4 == player_l3_x5) {
                        square_el2_4 = player_l3_x4;
                    } else if (player_l3_x1 != PLAYER_NONE && player_l3_x1 == player_l4_x1 && player_l3_x1 == player_l3_y1 && player_l3_y1 == player_l3_y2) {
                        square_el3_1 = player_l4_x1;
                    } else if (player_l3_x2 != PLAYER_NONE && player_l3_x2 == player_l4_x2 && player_l3_x2 == player_l3_y1 && player_l3_y1 == player_l3_y2) {
                        square_el3_2 = player_l4_x2;
                    } else if (player_l3_x3 != PLAYER_NONE && player_l3_x3 == player_l4_x3 && player_l3_x3 == player_l3_y3 && player_l3_y3 == player_l4_x5) {
                        square_el3_3 = player_l4_x3;
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
