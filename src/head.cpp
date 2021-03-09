#include "head.h"
void Save::initSave(string filename)
{
    cout << "";
}

void Jumper::jump()
{
    int rd;
    if (takeoffPowerS > 120)
        takeoffPowerS = 120;
    if (takeoffTechniqueS > 120)
        takeoffTechniqueS = 120;
    if (flightStyleS > 3)
        flightStyle = 1; //Styl V
    if (skisPositionS > 14)
        skisPositionS = 10;
    if (transitionSpeedS > 120)
        transitionSpeed = 120;
    distance = 0;
    takeoffPower = (takeoffPowerS);
    rd = randomInt(1, 8480);
    if (rd <= 1)
        takeoffPower += 20;
    else if (rd <= 3)
        takeoffPower += 19;
    else if (rd <= 10)
        takeoffPower += 18;
    else if (rd <= 20)
        takeoffPower += 17;
    else if (rd <= 34)
        takeoffPower += 16;
    else if (rd <= 51)
        takeoffPower += 15;
    else if (rd <= 71)
        takeoffPower += 14;
    else if (rd <= 97)
        takeoffPower += 13;
    else if (rd <= 123)
        takeoffPower += 12;
    else if (rd <= 160)
        takeoffPower += 11;
    else if (rd <= 205)
        takeoffPower += 10;
    else if (rd <= 270)
        takeoffPower += 9;
    else if (rd <= 369)
        takeoffPower += 8;
    else if (rd <= 490)
        takeoffPower += 7;
    else if (rd <= 650)
        takeoffPower += 6;
    else if (rd <= 846)
        takeoffPower += 5;
    else if (rd <= 1120)
        takeoffPower += 4;
    else if (rd <= 1440)
        takeoffPower += 3;
    else if (rd <= 1880)
        takeoffPower += 2;
    else if (rd <= 2700)
        takeoffPower += 1;
    else if (rd <= 4800)
        takeoffPower += 0;
    else if (rd <= 6700)
        takeoffPower += -1;
    else if (rd <= 7950)
        takeoffPower += -2;
    else if (rd <= 8845)
        takeoffPower += -3;
    else if (rd <= 9420)
        takeoffPower += -4;
    else if (rd <= 9900)
        takeoffPower += -5;
    else if (rd <= 10150)
        takeoffPower += -6;
    else if (rd <= 10330)
        takeoffPower += -7;
    else if (rd <= 10450)
        takeoffPower += -8;
    else if (rd <= 10500)
        takeoffPower += -9;
    else if (rd <= 10554)
        takeoffPower += -10;
    else if (rd <= 10574)
        takeoffPower += -11;
    else if (rd <= 10589)
        takeoffPower += -12;
    else if (rd <= 10597)
        takeoffPower += -13;
    else if (rd <= 10604)
        takeoffPower += -14;
    else if (rd <= 10609)
        takeoffPower += -15;
    else if (rd <= 10713)
        takeoffPower += -16;
    else if (rd <= 10716)
        takeoffPower += -17;
    else if (rd <= 10718)
        takeoffPower += -18;
    else if (rd <= 10719)
        takeoffPower += -19;

    takeoffTechnique = (takeoffTechniqueS * 0.987) + (form * 1.05);
    rd = randomInt(1, 10838);

    if (rd <= 1)
        takeoffTechnique += 40;
    else if (rd <= 3)
        takeoffTechnique += 39;
    else if (rd <= 10)
        takeoffTechnique += 38;
    else if (rd <= 20)
        takeoffTechnique += 37;
    else if (rd <= 25)
        takeoffTechnique += 36;
    else if (rd <= 46)
        takeoffTechnique += 35;
    else if (rd <= 71)
        takeoffTechnique += 34;
    else if (rd <= 103)
        takeoffTechnique += 33;
    else if (rd <= 142)
        takeoffTechnique += 32;
    else if (rd <= 190)
        takeoffTechnique += 31;
    else if (rd <= 247)
        takeoffTechnique += 30;
    else if (rd <= 295)
        takeoffTechnique += 29;
    else if (rd <= 351)
        takeoffTechnique += 28;
    else if (rd <= 412)
        takeoffTechnique += 27;
    else if (rd <= 480)
        takeoffTechnique += 26;
    else if (rd <= 555)
        takeoffTechnique += 25;
    else if (rd <= 640)
        takeoffTechnique += 24;
    else if (rd <= 737)
        takeoffTechnique += 23;
    else if (rd <= 847)
        takeoffTechnique += 22;
    else if (rd <= 980)
        takeoffTechnique += 21;
    else if (rd <= 1116)
        takeoffTechnique += 20;
    else if (rd <= 1285)
        takeoffTechnique += 19;
    else if (rd <= 1470)
        takeoffTechnique += 18;
    else if (rd <= 1680)
        takeoffTechnique += 17;
    else if (rd <= 1915)
        takeoffTechnique += 16;
    else if (rd <= 2180)
        takeoffTechnique += 15;
    else if (rd <= 2476)
        takeoffTechnique += 14;
    else if (rd <= 2786)
        takeoffTechnique += 13;
    else if (rd <= 3126)
        takeoffTechnique += 12;
    else if (rd <= 3486)
        takeoffTechnique += 11;
    else if (rd <= 3871)
        takeoffTechnique += 10;
    else if (rd <= 4273)
        takeoffTechnique += 9;
    else if (rd <= 4753)
        takeoffTechnique += 8;
    else if (rd <= 5273)
        takeoffTechnique += 7;
    else if (rd <= 5833)
        takeoffTechnique += 6;
    else if (rd <= 6435)
        takeoffTechnique += 5;
    else if (rd <= 7100)
        takeoffTechnique += 4;
    else if (rd <= 7860)
        takeoffTechnique += 3;
    else if (rd <= 8740)
        takeoffTechnique += 2;
    else if (rd <= 9738)
        takeoffTechnique += 1;
    else if (rd <= 10838)
        takeoffTechnique += 0;

    /*if (rd <= 1)
        takeoffTechnique += 20;
    else if (rd <= 3)
        takeoffTechnique += 19;
    else if (rd <= 10)
        takeoffTechnique += 18;
    else if (rd <= 20)
        takeoffTechnique += 17;
    else if (rd <= 34)
        takeoffTechnique += 16;
    else if (rd <= 51)
        takeoffTechnique += 15;
    else if (rd <= 71)
        takeoffTechnique += 14;
    else if (rd <= 97)
        takeoffTechnique += 13;
    else if (rd <= 123)
        takeoffTechnique += 12;
    else if (rd <= 160)
        takeoffTechnique += 11;
    else if (rd <= 205)
        takeoffTechnique += 10;
    else if (rd <= 270)
        takeoffTechnique += 9;
    else if (rd <= 369)
        takeoffTechnique += 8;
    else if (rd <= 490)
        takeoffTechnique += 7;
    else if (rd <= 650)
        takeoffTechnique += 6;
    else if (rd <= 846)
        takeoffTechnique += 5;
    else if (rd <= 1120)
        takeoffTechnique += 4;
    else if (rd <= 1440)
        takeoffTechnique += 3;
    else if (rd <= 1880)
        takeoffTechnique += 2;
    else if (rd <= 2700)
        takeoffTechnique += 1;
    else if (rd <= 4800)
        takeoffTechnique += 0;
    else if (rd <= 6700)
        takeoffTechnique += -1;
    else if (rd <= 7950)
        takeoffTechnique += -2;
    else if (rd <= 8845)
        takeoffTechnique += -3;
    else if (rd <= 9420)
        takeoffTechnique += -4;
    else if (rd <= 9900)
        takeoffTechnique += -5;
    else if (rd <= 10150)
        takeoffTechnique += -6;
    else if (rd <= 10330)
        takeoffTechnique += -7;
    else if (rd <= 10450)
        takeoffTechnique += -8;
    else if (rd <= 10500)
        takeoffTechnique += -9;
    else if (rd <= 10554)
        takeoffTechnique += -10;
    else if (rd <= 10574)
        takeoffTechnique += -11;
    else if (rd <= 10589)
        takeoffTechnique += -12;
    else if (rd <= 10597)
        takeoffTechnique += -13;
    else if (rd <= 10604)
        takeoffTechnique += -14;
    else if (rd <= 10609)
        takeoffTechnique += -15;
    else if (rd <= 10713)
        takeoffTechnique += -16;
    else if (rd <= 10716)
        takeoffTechnique += -17;
    else if (rd <= 10718)
        takeoffTechnique += -18;
    else if (rd <= 10719)
        takeoffTechnique += -19;*/

    flightTechnique = (flightTechniqueS * 0.887) + (form * 1.15);
    rd = randomInt(1, 10838);
        if (rd <= 1)
        flightTechnique += 40;
    else if (rd <= 3)
        flightTechnique += 39;
    else if (rd <= 10)
        flightTechnique += 38;
    else if (rd <= 20)
        flightTechnique += 37;
    else if (rd <= 25)
        flightTechnique += 36;
    else if (rd <= 46)
        flightTechnique += 35;
    else if (rd <= 71)
        flightTechnique += 34;
    else if (rd <= 103)
        flightTechnique += 33;
    else if (rd <= 142)
        flightTechnique += 32;
    else if (rd <= 190)
        flightTechnique += 31;
    else if (rd <= 247)
        flightTechnique += 30;
    else if (rd <= 295)
        flightTechnique += 29;
    else if (rd <= 351)
        flightTechnique += 28;
    else if (rd <= 412)
        flightTechnique += 27;
    else if (rd <= 480)
        flightTechnique += 26;
    else if (rd <= 555)
        flightTechnique += 25;
    else if (rd <= 640)
        flightTechnique += 24;
    else if (rd <= 737)
        flightTechnique += 23;
    else if (rd <= 847)
        flightTechnique += 22;
    else if (rd <= 980)
        flightTechnique += 21;
    else if (rd <= 1116)
        flightTechnique += 20;
    else if (rd <= 1285)
        flightTechnique += 19;
    else if (rd <= 1470)
        flightTechnique += 18;
    else if (rd <= 1680)
        flightTechnique += 17;
    else if (rd <= 1915)
        flightTechnique += 16;
    else if (rd <= 2180)
        flightTechnique += 15;
    else if (rd <= 2476)
        flightTechnique += 14;
    else if (rd <= 2786)
        flightTechnique += 13;
    else if (rd <= 3126)
        flightTechnique += 12;
    else if (rd <= 3486)
        flightTechnique += 11;
    else if (rd <= 3871)
        flightTechnique += 10;
    else if (rd <= 4273)
        flightTechnique += 9;
    else if (rd <= 4753)
        flightTechnique += 8;
    else if (rd <= 5273)
        flightTechnique += 7;
    else if (rd <= 5833)
        flightTechnique += 6;
    else if (rd <= 6435)
        flightTechnique += 5;
    else if (rd <= 7100)
        flightTechnique += 4;
    else if (rd <= 7860)
        flightTechnique += 3;
    else if (rd <= 8740)
        flightTechnique += 2;
    else if (rd <= 9738)
        flightTechnique += 1;
    else if (rd <= 10838)
        flightTechnique += 0;

    distance = hill.startDist;
    distance += takeoffPower * hill.takeoffPowerMeters;
    distance += takeoffTechnique * hill.takeoffTechniqueMeters;
    distance += flightTechnique * hill.flightTechniqueMeters;

    cout << "Moc wybicia: " << takeoffPower << ", Technika wybicia: "
         << ", Technika lotu: " << flightTechnique << ", Odleglosc: " << distance << endl;
}

int randomInt(int a, int b)
{
    /*int r1, r2[3000], r3;
    random_device dev;
    uniform_int_distribution<int> rd(a, b);
    uniform_int_distribution<int> rd1(0, 2999);
    r1 = rd1(dev);
    for (auto rr : r2)
    {
        rr = rd(dev);
    }
    r3 = r2[r1];
    return r3;*/
    random_device dev;
    uniform_int_distribution<int> rd(a, b);
    return rd(dev);
}

double randomDouble(double min, double max)
{
    srand(time(NULL));
    double rr[50];
    int rrr = randomInt(0, 49);
    for (int i = 0; i <= 49; i++)
    {
        rr[i] = ((double)rand() / RAND_MAX) * (max - min) + min;
    }
    return rr[rrr];
}

void colorText(unsigned short color, string text)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    cout << text;
}

double percent(double prc, double num)
{
    double sum;
    sum = (prc / 100) * num;
    return sum;
}

void selectTrainingHill()
{
    int i = 1, c;
    for (auto hill : hills)
    {
        cout << i << ". " << hill.name << " (" << hill.country << ") " << hill.kpoint << " " << hill.hspoint << endl;
        i++;
    }
    cout << "Skocznia: ";
    cin >> c;
    hill = hills[c - 1];
}

void loadHills()
{
    Hill vechill;
    string tmp;
    hlf.open("../resources/hills.csv", ios::in);
    if (hlf.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku. Zamykam program...";
        Sleep(2500);
        exit(0);
    }
    while (getline(hlf, vechill.name, ','))
    {
        getline(hlf, vechill.country, ',');
        getline(hlf, tmp, ',');
        vechill.kpoint = stoi(tmp);
        getline(hlf, tmp, ',');
        vechill.hspoint = stoi(tmp);
        getline(hlf, tmp, ',');
        vechill.gatePoints = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.gateMeters = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.windPointsFront = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.windMetersFront = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.windPointsBack = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.windMetersBack = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.maxdist = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.startDist = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.hsLandDifficulty = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.optimalSkisPosition = stoi(tmp);
        getline(hlf, tmp, ',');
        vechill.skisPositionEffect = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.takeoffPowerMeters = stod(tmp);
        getline(hlf, tmp);
        vechill.takeoffTechniqueMeters = stod(tmp);
        hills.push_back(vechill);
    }
    hlf.close();
}
