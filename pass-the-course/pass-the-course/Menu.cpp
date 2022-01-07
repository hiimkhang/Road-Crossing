#include "Menu.h"
#pragma warning(disable : 4267)
extern bool mode;
string Menu::menu() {
    bool stayinMenu = true;
    isSubMenu = 0;
    string result = "";
    while (stayinMenu) {
        clrscr();
        logoMenu(); //tam thoi thoi
        soundStatus = soundON;
        if (soundStatus == 1 && outMenu == true)
            PlaySound(TEXT("Sound\\Undertale.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        ShowConsoleCursor(0);

        int x = 54;
        int y = 22;

        Textcolor(8);
        gotoxy(x + 1, y - 1);
        for (int i = 0; i < 20; ++i)
            cout << UP_BLACK_PIECE;
        for (int i = y - 1; i < y + 10; ++i)
        {
            gotoxy(x, i);
            cout << VERTICAL_BLACK_PIECE;
        }
        for (int i = y - 1; i < y + 10; ++i)
        {
            gotoxy(x + 21, i);
            cout << VERTICAL_BLACK_PIECE;
        }
        gotoxy(x + 1, y + 9);
        for (int i = 0; i < 20; ++i)
            cout << DOWN_BLACK_PIECE;

        Textcolor(DarkYellow);
        gotoxy(x + 2, y + 13);
        cout << "W - S - Arrow: MOVE";
        gotoxy(x + 5, y + 14);
        cout << "Enter: SELECT";

        Textcolor(15);
        gotoxy(x + 7, y + 1); cout << "NEW GAME";
        gotoxy(x + 9, y + 3); cout << "LOAD ";
        gotoxy(x + 7, y + 5); cout << "SETTINGS";
        gotoxy(x + 9, y + 7); cout << "EXIT";

        int cnt = 0;
        while (stayinMenu)
        {
            char choice = _getch();
            Textcolor(15);
            gotoxy(x + 6, y + 1); cout << " NEW GAME ";
            gotoxy(x + 8, y + 3); cout << " LOAD  ";
            gotoxy(x + 6, y + 5); cout << " SETTINGS ";
            gotoxy(x + 8, y + 7); cout << " EXIT ";

            if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
                cnt++;
                if (cnt > 4)
                    cnt = 1;
            }
            if (choice == KEY_UP || choice == 'W' || choice == 'w') {
                cnt--;
                if (cnt < 1)
                    cnt = 4;
            }
            if (choice == KEY_ESC) {
                clrscr();
                exit(0);
            }

            if (cnt == 1) {
                Textcolor(12);
                gotoxy(x + 6, y + 1); cout << " NEW GAME ";
                if (choice == KEY_ENTER) {
                    Textcolor(15);
                    stayinMenu = false;
                    clrscr();
                    //loadingScreen();
                    break;
                }
            }
            if (cnt == 2) {
                Textcolor(12);
                gotoxy(x + 8, y + 3); cout << " LOAD  ";
                if (choice == KEY_ENTER) {
                    Textcolor(15);
                    outMenu = false;
                    result = loadGame(0);
                    return result;
                }
            }
            if (cnt == 3) {
                Textcolor(12);
                gotoxy(x + 6, y + 5); cout << " SETTINGS ";
                if (choice == KEY_ENTER) {
                    Textcolor(15);
                    outMenu = false;
                    setting();
                }
            }
            if (cnt == 4) {
                Textcolor(12);
                gotoxy(x + 8, y + 7); cout << " EXIT ";
                if (choice == KEY_ENTER) {
                    Textcolor(15);
                    clrscr();
                    exit(0);
                }
            }
        }
    }
    return result;
}

void Menu::subMenu(CGame& cg) {
    bool stayinMenu = true;
    string result = "";
    isSubMenu = 1;
    while (stayinMenu) {
        clrscr();
        soundStatus = soundON;
        if (soundStatus == 1 && outMenu == true)
            PlaySound(TEXT("Sound\\Undertale.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

        ShowConsoleCursor(0);

        int x = 54;
        int y = 22;

        Textcolor(8);
        gotoxy(x + 1, y - 1);
        for (int i = 0; i < 20; ++i)
            cout << UP_BLACK_PIECE;
        for (int i = y - 1; i < y + 10; ++i)
        {
            gotoxy(x, i);
            cout << VERTICAL_BLACK_PIECE;
        }
        for (int i = y - 1; i < y + 10; ++i)
        {
            gotoxy(x + 21, i);
            cout << VERTICAL_BLACK_PIECE;
        }
        gotoxy(x + 1, y + 9);
        for (int i = 0; i < 20; ++i)
            cout << DOWN_BLACK_PIECE;

        Textcolor(DarkYellow);
        gotoxy(x + 2, y + 13);
        cout << "W - S - Arrow: MOVE";
        gotoxy(x + 5, y + 14);
        cout << "Enter: SELECT";

        Textcolor(15);
        gotoxy(x + 9, y + 1); cout << "SAVE ";
        gotoxy(x + 9, y + 3); cout << "LOAD ";
        gotoxy(x + 7, y + 5); cout << " RESUME";
        gotoxy(x + 9, y + 7); cout << "EXIT";

        int cnt = 0;
        while (stayinMenu)
        {
            char choice = _getch();
            Textcolor(15);
            gotoxy(x + 8, y + 1); cout << " SAVE  ";
            gotoxy(x + 8, y + 3); cout << " LOAD  ";
            gotoxy(x + 6, y + 5); cout << "  RESUME ";
            gotoxy(x + 8, y + 7); cout << " EXIT ";

            if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
                cnt++;
                if (cnt > 4)
                    cnt = 1;
            }
            if (choice == KEY_UP || choice == 'W' || choice == 'w') {
                cnt--;
                if (cnt < 1)
                    cnt = 4;
            }
            if (choice == KEY_ESC) {
                clrscr();
                exit(0);
            }

            if (cnt == 1) {
                Textcolor(12);
                gotoxy(x + 8, y + 1); cout << " SAVE ";
                if (choice == KEY_ENTER) {
                    Textcolor(15);
                    stayinMenu = false;
                    //loadingScreen();
                    clrscr();
                    string dir = "";
                    int x = 38;
                    int y = 17;

                    Textcolor(DarkYellow);
                    gotoxy(x + 5, y + 9);
                    cout << "Example: save1";
                    gotoxy(x + 3, y + 7);
                    cout << (char)175 << " The directory will become: Save/save1.dat";

                    Textcolor(8);
                    gotoxy(x, y);
                    for (int i = 0; i < 50; ++i)
                        cout << UP_BLACK_PIECE;

                    gotoxy(x, y + 2);
                    for (int i = 0; i < 50; ++i)
                        cout << DOWN_BLACK_PIECE;

                    for (int i = 0; i < 3; ++i) {
                        gotoxy(x - 1, y + i);
                        cout << VERTICAL_BLACK_PIECE;
                    }
                    for (int i = 0; i < 3; ++i) {
                        gotoxy(x + 50, y + i);
                        cout << VERTICAL_BLACK_PIECE;
                    }

                    gotoxy(x - 1, y - 2); cout << "Enter name of file to save";
                    gotoxy(x + 2, y + 1);
                    getline(cin, dir);
                    cg.saveGame(dir + ".dat");
                    gotoxy(x + 14, y + 5); cout << "Saving...";
                    Sleep(2000);
                    clrscr();
                    break;
                }
            }
            if (cnt == 2) {
                Textcolor(12);
                gotoxy(x + 8, y + 3); cout << " LOAD  ";
                if (choice == KEY_ENTER) {
                    Textcolor(15);
                    stayinMenu = false;
                    result = loadGame(0);
                    if (result != "") {
                        cg.loadGame(result);
                    }
                    break;
                }
            }
            if (cnt == 3) {
                Textcolor(12);
                gotoxy(x + 6, y + 5); cout << "  RESUME ";
                if (choice == KEY_ENTER) {
                    Textcolor(15);
                    stayinMenu = false;
                    outMenu = false;
                    break;
                }
            }
            if (cnt == 4) {
                Textcolor(12);
                gotoxy(x + 8, y + 7); cout << " EXIT ";
                if (choice == KEY_ENTER) {
                    Textcolor(15);
                    clrscr();
                    exit(0);
                }
            }
        }
    }
}
string Menu::loadGame(int status) {
    clearMenu();
    int x = 58;
    int y = 20;
    Textcolor(White);
    vector<string> lof;
    int c1 = 0;
    string path = filesystem::current_path().string() + "\\Save";
    for (const auto& file : filesystem::directory_iterator(filesystem::path(path)))
    {
        lof.push_back(file.path().filename().string());
    }

    int a = 12, b = 23;
    Textcolor(DarkYellow);
    gotoxy(a, b++); cout << R"( __       ______   ______   _____    )";
    gotoxy(a, b++); cout << R"(/\ \     /\  __ \ /\  __ \ /\  __-\. )";
    gotoxy(a, b++); cout << R"(\ \ \____\ \ \/\ \\ \  __ \\ \ \/\ \ )";
    gotoxy(a, b++); cout << R"( \ \_____\\ \_____\\ \_\ \_\\ \____/.)";
    gotoxy(a, b++); cout << R"(  \/_____/ \/_____/ \/_/\/_/ \/____/ )";

    gotoxy(61, 37);
    cout << "ESC: Exit";

    Textcolor(8);

    gotoxy(x - 3, y - 1);
    for (int i = 0; i < 23; ++i) {
        cout << UP_BLACK_PIECE;
    }
    gotoxy(x - 4, y - 1); cout << VERTICAL_BLACK_PIECE;
    gotoxy(x + 20, y - 1); cout << VERTICAL_BLACK_PIECE;

    for (int i = 0; i < lof.size(); i++)
    {
        gotoxy(x - 4, y + i);
        cout << VERTICAL_BLACK_PIECE;
        gotoxy(x + 20, y + i);
        cout << VERTICAL_BLACK_PIECE;
        gotoxy(x, y + i);
        cout << lof[i];
    }
    gotoxy(x - 4, y + lof.size()); cout << VERTICAL_BLACK_PIECE;
    gotoxy(x + 20, y + lof.size()); cout << VERTICAL_BLACK_PIECE;
    gotoxy(x - 3, y + lof.size());
    for (int i = 0; i < 23; ++i) {
        cout << DOWN_BLACK_PIECE;
    }
    Textcolor(7);

    char choice = '0';
    do
    {
        if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
            c1++;
            if (c1 >= lof.size() )
                c1 = 0;
        }
        if (choice == KEY_UP || choice == 'W' || choice == 'w') {
            c1--;
            if (c1 < 0)
                c1 = (int)lof.size()-1;
        }
        if (int(choice) == 27) {
            isLoad = false;
            if (status == 0) {
                menu();
                return "";
            }
            else if (status == 1)
                return "";
            break;
        }
        Textcolor(White);
        for (int i = 0; i < lof.size(); i++)
        {
            gotoxy(x, y + i);
            cout << lof[i];
        }

        Textcolor(Red);
        gotoxy(x, y + c1);
        cout << lof[c1];
        
    } while ((choice = toupper(_getch())) != 13);
    string temp = lof[c1];
    lof.clear();
    return temp;
    //for (int i = 56; i < 77; ++i) {
    //    gotoxy(i, 35); cout << " ";
    //    gotoxy(i, 36); cout << " ";
    //}

    //Textcolor(DarkYellow);
    //gotoxy(x + 5, y + 10);
    //cout << "Example: save1";
    //gotoxy(x + 3, y + 11);
    //cout << (char)175 << " The directory will become: Data/save1.txt";

    //Textcolor(8);
    //gotoxy(x, y);
    //for (int i = 0; i < 50; ++i)
    //    cout << UP_BLACK_PIECE;

    //gotoxy(x, y + 2);
    //for (int i = 0; i < 50; ++i)
    //    cout << DOWN_BLACK_PIECE;

    //for (int i = 0; i < 3; ++i) {
    //    gotoxy(x - 1, y + i);
    //    cout << VERTICAL_BLACK_PIECE;
    //}
    //for (int i = 0; i < 3; ++i) {
    //    gotoxy(x + 50, y + i);
    //    cout << VERTICAL_BLACK_PIECE;
    //}


    /*string file;
    getline(cin, file);
    string filename = "Data/";
    filename += file + ".txt";*/

    //ifstream f(filename.c_str());

    // Check if the input file name exists
    /*if (!f.good()) {
        gotoxy(x + 1, y + 4);
        cout << "Can't find " + filename;
        ShowConsoleCursor(0);
        Sleep(2000);

        gotoxy(x + 1, y + 4);
        for (unsigned i = 0; i < 12 + filename.length(); ++i)
            cout << " ";
        menu();
    }*/

    // map.loadGame(filename);
    isLoad = true;
    // newGame();
}

void Menu::setting() {
    ShowConsoleCursor(0);
    clearMenu();
    int x = 54;
    int y = 23;

    Textcolor(8);
    gotoxy(x + 1, y - 1);
    for (int i = 0; i < 20; ++i)
        cout << UP_BLACK_PIECE;
    for (int i = y - 1; i < y + 8; ++i)
    {
        gotoxy(x, i);
        cout << VERTICAL_BLACK_PIECE;
    }
    for (int i = y - 1; i < y + 8; ++i)
    {
        gotoxy(x + 21, i);
        cout << VERTICAL_BLACK_PIECE;
    }
    gotoxy(x + 1, y + 7);
    for (int i = 0; i < 20; ++i)
        cout << DOWN_BLACK_PIECE;

    Textcolor(15);
    gotoxy(x + 6, y + 1); cout << "MODE:";
    if (mode == false) {
        gotoxy(x + 12, y + 1); cout << "EASY";
    }
    else {
        gotoxy(x + 12, y + 1); cout << "HARD";
    }

    gotoxy(x + 6, y + 3); cout << "SOUND:";
    if (soundStatus == 1) {
        gotoxy(x + 13, y + 3); cout << "ON";
    }
    else {
        gotoxy(x + 13, y + 3); cout << "OFF";
    }
    gotoxy(x + 9, y + 5); cout << "BACK";

    int cnt = 0;
    while (true)
    {
        char choice = _getch();
        Textcolor(15);
        gotoxy(x + 6, y + 1); cout << "MODE:";
        gotoxy(x + 6, y + 3); cout << "SOUND:";
        gotoxy(x + 8, y + 5); cout << " BACK ";

        if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
            cnt++;
            if (cnt > 3)
                cnt = 1;
        }
        if (choice == KEY_UP || choice == 'W' || choice == 'w') {
            cnt--;
            if (cnt < 1)
                cnt = 3;
        }
        if (cnt == 1) {
            Textcolor(12);
            gotoxy(x + 6, y + 1); cout << "MODE:";
            if (choice == KEY_ENTER) {
                if (mode == 1)
                    mode = 0;
                else
                    mode = 1;

                if (mode == 1) {
                    Textcolor(15);
                    gotoxy(x + 12, y + 1); cout << "HARD";
                }
                else {
                    Textcolor(15);
                    gotoxy(x + 12, y + 1); cout << "EASY";
                }
            }
        }
        if (cnt == 2) {
            Textcolor(12);
            gotoxy(x + 6, y + 3); cout << "SOUND:";
            if (choice == KEY_ENTER) {
                if (soundStatus == 0)
                    soundStatus = 1;
                else
                    soundStatus = 0;

                if (soundStatus == 1) {
                    Textcolor(15);
                    gotoxy(x + 13, y + 3); cout << "ON ";
                    // play sound here
                    PlaySound(TEXT("Sound\\Undertale.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                }
                else {
                    Textcolor(15);
                    gotoxy(x + 13, y + 3); cout << "OFF";
                    // turn off sound here
                    PlaySound(NULL, NULL, SND_ASYNC);
                }
            }
        }
        if (cnt == 3) {
            Textcolor(12);
            gotoxy(x + 8, y + 5); cout << " BACK ";
            if (choice == KEY_ENTER) {
                clearMenu();
                Textcolor(8);
                gotoxy(x + 1, y - 2);
                for (int i = 0; i < 20; ++i)
                    cout << UP_BLACK_PIECE;
                for (int i = y - 2; i < y + 9; ++i)
                {
                    gotoxy(x, i);
                    cout << VERTICAL_BLACK_PIECE;
                }
                for (int i = y - 2; i < y + 9; ++i)
                {
                    gotoxy(x + 21, i);
                    cout << VERTICAL_BLACK_PIECE;
                }
                gotoxy(x + 1, y + 8);
                for (int i = 0; i < 20; ++i)
                    cout << DOWN_BLACK_PIECE;

                Textcolor(DarkYellow);
                gotoxy(x + 2, y + 12);
                cout << "W - S - Arrow: MOVE";
                gotoxy(x + 5, y + 13);
                cout << "Enter: SELECT";

                Textcolor(15);
                if (isSubMenu) {
                    gotoxy(x + 8, y); cout << " SAVE ";
                }
                else {
                    gotoxy(x + 7, y); cout << "NEW GAME";
                }
                gotoxy(x + 9, y + 2); cout << "LOAD";

                Textcolor(12);
                gotoxy(x + 6, y + 4); 
                if (isSubMenu) cout << "  RESUME ";
                else cout << " SETTINGS ";
                Textcolor(15);
                gotoxy(x + 9, y + 6); cout << "EXIT";
                return;
            }
        }
    }
}

void Menu::clearMenu() {
    Textcolor(15);
    for (int i = 16; i < 33; ++i) {
        gotoxy(54, i);
        for (int j = 0; j < 22; ++j) {
            cout << " ";
        }
    }
}

void Menu::logoMenu() {
    ifstream in;
    char g;

    in.open(".//Logo/logoMenu.txt");
    if (in.is_open()) {
        while (in >> noskipws >> g) {
            if (g > '0' && g < '9') {
                Textcolor(g - '0');
                cout << " ";
            }
            else cout << g;
        }
    }
    else throw "Can't open file logoMenu.txt\n";
}

void Menu::logoWin() {
    ifstream in;
    char g;

    in.open(".//Logo/logoWin.txt");
    if (in.is_open()) {
        while (in >> noskipws >> g) {
            if (g > '0' && g < '9') {
                int color = rand() % 5 + 9;
                Textcolor(color);
                cout << " ";
            }
            else cout << g;
        }
        in.close();
    }
    else throw "Can't open file logoWin.txt\n";
}

void Menu::printWin() {
    clrscr();
    if (soundON)
        PlaySound(TEXT("Sound\\gta.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Menu::logoWin();
    /*Display win logo*/
    for (int i = 0; i < 15; ++i) {
        ShowConsoleCursor(0);
        clrscr();
        Menu::logoWin();
        Sleep(100);
    }
    Textcolor(DarkYellow);
    gotoxy(50, 30);		cout << " PRESS ANY KEY TO CONTINUE... ";
    Textcolor(15);
    while (_kbhit())
        if (_getch() == 32 || _getch() == 13)
            return;
}

void Menu::logoLose() {
    ifstream in;
    char g;

    in.open(".//Logo/logoLose.txt");
    if (in.is_open()) {
        while (in >> noskipws >> g) {
            if (g > '0' && g < '9') {
                int color = rand() % 5 + 9;
                Textcolor(color);
                cout << " ";
            }
            else cout << g;
        }
        in.close();
    }
    else throw "Can't open file logoLose.txt\n";
}

void Menu::printLose() {
    clrscr();
    if (soundON)
        PlaySound(TEXT("Sound\\lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Menu::logoLose();
    /*Display win logo*/
    for (int i = 0; i < 15; ++i) {
        ShowConsoleCursor(0);
        clrscr();
        Menu::logoLose();
        Sleep(100);
    }
    
    Textcolor(DarkYellow);
    //gotoxy(54, 30);		cout << " PRESS ANY KEY TO CONTINUE... ";
    int x = 40;
    int y = 20;

    // collide animation
    gotoxy(x + 5, y + 7); cout << "Do you want to continue where you have dead?";
    gotoxy(x + 23, y + 9); cout << "Y: Yes";
    gotoxy(x + 17, y + 11); cout << "Any other key: Return";
    Textcolor(15);
    while (_kbhit())
        if (_getch() == 32 || _getch() == 13)
            return;
}

void Menu::loadingScreen() {
    int x = 50;
    int y = 19;

    clrscr();
    Textcolor(8);
    gotoxy(x + 4, y);
    cout << "Cho mot xiu nhaa...";

    unsigned char a = 177, b = 219;

    // Darker progess bar
    gotoxy(x + 3, y + 3);
    for (int i = 0; i <= 21; i++)
        cout << a;
    cout << "\r";

    // Progess bar
    for (int i = 0; i <= 20; i++) {
        gotoxy(x - 2, y + 3);
        cout << i * 100 / 20 << "%";
        gotoxy(x + i + 3, y + 3);
        if (i < 14) {
            cout << b;
            Sleep(150);
        }
        else if (i == 14) {
            Sleep(600);
            cout << b;
        }
        else {
            cout << b << b;
            Sleep(150);
        }
    }

    // Clear progress bar
    for (int j = 0; j < 5; ++j) {
        gotoxy(x - 3, y + j);
        for (int i = 0; i <= 30; i++)
            cout << " ";
    }

    Textcolor(7);
}

void Menu::levelLogo(int x, int y, int color) {
    Textcolor(color);
    gotoxy(x, y++); cout << R"( _    _____  __   _______  _     )";
    gotoxy(x, y++); cout << R"(/\\  /\  __\/\ \ / /\  __\/\\    )";
    gotoxy(x, y++); cout << R"(\ \\_\ \  _\\ \ \'/\ \  _\\ \\__ )";
    gotoxy(x, y++); cout << R"( \ \__\ \____\ \__| \ \____\ \__\)";
    gotoxy(x, y++); cout << R"(  \/__/\/____/\/_/   \/____/\/__/)";
}

void Menu::levelupLogo(int x, int y, int color) {
    Textcolor(color);
    gotoxy(x, y++); cout << R"( __       ______   __   __ ______   __           __  __   ______ )";
    gotoxy(x, y++); cout << R"(/\ \     /\  ___\ /\ \ / //\  ___\ /\ \         /\ \/\ \ /\  == \)";
    gotoxy(x, y++); cout << R"(\ \ \____\ \  __\ \ \ \'/ \ \  __\ \ \ \____    \ \ \_\ \\ \  _-/)";
    gotoxy(x, y++); cout << R"( \ \_____\\ \_____\\ \__|  \ \_____\\ \_____\    \ \_____\\ \_\  )";
    gotoxy(x, y++); cout << R"(  \/_____/ \/_____/ \/_/    \/_____/ \/_____/     \/_____/ \/_/  )";
}

void Menu::oneLogo(int x, int y, int color) {
    Textcolor(color);
    gotoxy(x, y++); cout << R"( _____        )";
    gotoxy(x, y++); cout << R"(/\__  \       )";
    gotoxy(x, y++); cout << R"(\/_/\  \      )";
    gotoxy(x, y++); cout << R"(   \ \  \     )";
    gotoxy(x, y++); cout << R"(   _\_\  \___ )";
    gotoxy(x, y++); cout << R"( /\__________\)";
    gotoxy(x, y++); cout << R"( \/__________/)";
}

void Menu::twoLogo(int x, int y, int color) {
    Textcolor(color);
    gotoxy(x, y++); cout << R"( __________     )";
    gotoxy(x, y++); cout << R"(/\______   \    )";
    gotoxy(x, y++); cout << R"(\/_____ \   \   )";
    gotoxy(x, y++); cout << R"(    ___\/    \  )";
    gotoxy(x, y++); cout << R"(   /     ____/  )";
    gotoxy(x, y++); cout << R"(  /\    /___/__ )";
    gotoxy(x, y++); cout << R"(  \ \__________\)";
    gotoxy(x, y++); cout << R"(   \/__________/)";
}

void Menu::threeLogo(int x, int y, int color) {
    Textcolor(color);
    gotoxy(x, y++); cout << R"( __________      )";
    gotoxy(x, y++); cout << R"(/\______   \     )";
    gotoxy(x, y++); cout << R"(\/______\   \    )";
    gotoxy(x, y++); cout << R"(     /\___   \   )";
    gotoxy(x, y++); cout << R"(     \/__/\   \  )";
    gotoxy(x, y++); cout << R"(    _____\_\   \ )";
    gotoxy(x, y++); cout << R"(   /\___________\)";
    gotoxy(x, y++); cout << R"(   \/___________/)";
}

void Menu::fourLogo(int x, int y, int color) {
    Textcolor(color);
    gotoxy(x, y++); cout << R"( ___    ___      )";
    gotoxy(x, y++); cout << R"(/\  \  /\  \     )";
    gotoxy(x, y++); cout << R"(\ \  \ \ \  \    )";
    gotoxy(x, y++); cout << R"( \ \  \_\_\  \__ )";
    gotoxy(x, y++); cout << R"(  \ \____    ___\)";
    gotoxy(x, y++); cout << R"(   \/___/\   \__/)";
    gotoxy(x, y++); cout << R"(        \ \___\  )";
    gotoxy(x, y++); cout << R"(         \/___/  )";
}

void Menu::HP(int x, int y, int color) {
    Textcolor(color);
    gotoxy(x, y++); cout << R"( _  _  ___  _ )";
    gotoxy(x, y++); cout << R"(| || || _ \(_))";
    gotoxy(x, y++); cout << R"(| __ ||  _/ _ )";
    gotoxy(x, y++); cout << R"(|_||_||_|  (_))";
}



void Menu::info(CGame& cg) {
    int a = 93, b = 7;
    levelLogo(a, b, 6);

    a += 11, b += 6;

    switch (cg.getLevel()) {
    case 1: 
        oneLogo(a, b, 3);
        break;
    case 2:
        twoLogo(a - 1, b, 11);
        break;
    case 3:
        threeLogo(a - 1, b, 13);
        break;
    case 4:
        fourLogo(a - 1, b, 12);
        break;
    }
    a -= 10, b += 11;

    HP(a, b, 3);

    for (int i = 0; i < 5; ++i) {
        gotoxy(a + 15 + i, b);
        cout << "               ";
    }
    for (int i = 0; i <= cg.getPeople().life; ++i) 
        cg.drawHeart(a + 15 + i*6, b, 12);

    b += 7; a += 4;

    Textcolor(DarkYellow);
    gotoxy(a, b);
    cout << "P: Pause";
    gotoxy(a + 12, b);
    cout << "ESC: Menu";
    gotoxy(a, b + 2);
    cout << "T: Load";
    gotoxy(a + 12, b + 2);
    cout << "L: Save";
    gotoxy(a, b + 4);
    cout << "M: Sound On/Off";
}