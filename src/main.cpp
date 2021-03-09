#include "head.cpp"

int main()
{
    Jumper testjumper;
    loadHills();

    cout << "Skoczek (MW, TW, F, TL): ";
    cin >> testjumper.takeoffPowerS >> testjumper.takeoffTechniqueS >> testjumper.form >> testjumper.flightTechniqueS;
    char choice;
    string choice1;
    cout << "Ski Jumper Perspective " << APP_VERSION;
    cout << "\nOpcje: \n1. Nowy zapis gry\n2. Wczytaj istniejacy zapis gry\n3. Wyswietl wczytane zasoby\n4. Pojedynczy skok\n";
    cin >> choice;
    switch (choice)
    {
    case '1':
    {
        cout << "Podaj nazwe pliku (bez rozszerzenia): ";
        save.initSave(choice1 + ".sav");
    }
    case '4':
    {
        selectTrainingHill();
        for (;;)
        {
            testjumper.jump();
            getch();
        }
    }
    }

    system("pause");
}