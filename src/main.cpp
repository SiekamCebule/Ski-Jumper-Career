#include "head.cpp"

int main()
{
    SetConsoleTextAttribute(hcon, 15);
    Jumper testjumper;
    loadHills();
    loadJumpers(true);

    char choice;
    string choice1;
    /*cout << "Ski Jumper Perspective " << APP_VERSION;
    cout << "\nOpcje: \n1. Nowy zapis gry (niedostepne)\n2. Wczytaj istniej¥cy zapis gry (niedostepne)\n3. Wy˜wietl wczytane zasoby (niedostepne)\n4. Pojedyäczy skok\n";
    choice = getch();
    cls;*/
    choice  = '4';
    switch (choice)
    {
    case '1':
    {
        cout << "Podaj nazw© pliku (bez rozszerzenia): ";
        save.initSave(choice1 + ".sav");
    }
    case '4':
    {
        cls;
        for (;;)
        {
            for (;;)
            {
                selectTrainingHill();
                loadTrainingConfig();
                comp.jumpers = jumpersList;
                cout << "Belka startowa: ";
                cin >> comp.startGate;
                comp.startWind = randomDouble(comp.typicalWind[0], comp.typicalWind[1]);
                cls;
                cout<<"Lista startowa: "<<endl;
                showJumpers();
                getch();
                cls;
                for (auto &jp : comp.jumpers)
                {
                    jp.wind = comp.startWind;
                    cls;
                    jp.afterStart();
                    cout << "Belka: ";
                    cin >> jp.gate;
                    //comp.setLeaderPoints();
                    jp.jump();
                    jp.showDistanceAndToBeat();
                    jp.showResult();
                    cout << endl;
                    //jp.showHideInfo();
                    getch();
                    cls;
                }
            }
            getch();
        }
    }
    }

    getch();
}