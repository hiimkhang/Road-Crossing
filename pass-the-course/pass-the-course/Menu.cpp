#include "Menu.h"

string Menu::menu() {
    bool stayinMenu = true;
    string result = "";
    while (stayinMenu) {
        clrscr();
        logoMenu(); //tam thoi thoi
        soundStatus = 0;
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
                    loadingScreen();
                    break;
                }
            }
            if (cnt == 2) {
                Textcolor(12);
                gotoxy(x + 8, y + 3); cout << " LOAD  ";
                if (choice == KEY_ENTER) {
                    Textcolor(15);
                    outMenu = false;
                    result = loadGame();
                    if (result != "")
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

string Menu::loadGame() {
    clearMenu();
    int x = 38;
    int y = 17;
    Textcolor(White);
    vector<string> lof;
    int c1 = 0;
    string path = filesystem::current_path().string() + "\\Save";
    for (const auto& file : filesystem::directory_iterator(filesystem::path(path)))
    {
        lof.push_back(file.path().filename().string());
    }

    for (int i = 0; i < lof.size(); i++)
    {
        gotoxy(x, y + i);
        cout << lof[i];
    }
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
                c1 = lof.size()-1;
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
    return lof[c1];
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
                gotoxy(x + 7, y); cout << "NEW GAME";
                gotoxy(x + 9, y + 2); cout << "LOAD";

                Textcolor(12);
                gotoxy(x + 6, y + 4); cout << " SETTINGS ";
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

void Menu::loadingScreen() {
    int x = 50;
    int y = 19;

    clearMenu();

    gotoxy(x + 4, y);

    Textcolor(8);
    cout << "Cho mot xiu nhaa...";

    ShowConsoleCursor(0);
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
