#include "head.h"
void Save::initSave(string filename)
{
    cout << "";
}

void Jumper::afterStart()
{
    cout << name << " " << surname << " (" << nationality << ")" << endl;
}

void Jumper::jump()
{
    hill.startup();
    hill.setType();
    wind += randomDouble(comp.windChange[0], comp.windChange[1]);
    windB = wind + normalRandom(0, comp.windFaulty);

    setOtherComponents();
    setTakeoffPower();
    setTakeoffTechnique();
    setFlightTechnique();
    heightWindMeters();
    setGateAndWindMeters();
    
    int rd;

    if (flightStyle > 4)
        flightStyle = 2; //Styl "nowoczesne V 1"
    if (skisPositionS > 14)
        skisPositionS = 10;

    takeoffPowerDiff = (takeoffPower - hill.optimalTakeoffPower);

    if (takeoffPowerDiff < 0)
        (takeoffPowerDiff *= 0.6456);
    else
        takeoffPowerDiff *= 0.44;

    basicDistance();
    land();
    setPoints();
    setToBeat();
}

void Jumper::setTakeoffPower()
{
    if (takeoffPowerS > 120)
        takeoffPowerS = 120;
    if (takeoffPowerS < 1)
        takeoffPowerS = 1;

    takeoffPower = (takeoffPowerS);
    takeoffPower += normalRandom(0, 5);
    takeoffPower = round(takeoffPower);
    if (takeoffPower > 160)
        takeoffPower = 160;
    else if (takeoffPower < 1)
        takeoffPower = 1;
}
void Jumper::setTakeoffTechnique()
{
    if (takeoffTechniqueS > 120)
        takeoffTechniqueS = 120;
    if (takeoffTechniqueS < 1)
        takeoffTechniqueS = 1;

    takeoffTechnique = (takeoffTechniqueS * 0.987) + (form * 1.05);
    takeoffTechnique += normalRandom(0, 7);
    takeoffTechnique += randomInt((comp.importance - 6), 0);
    takeoffTechnique -= trackRain;
    takeoffTechnique = round(takeoffTechnique);
    if (takeoffTechnique > 280)
        takeoffTechnique = 280;
    if (takeoffTechnique < 1)
        takeoffTechnique = 1;
}
void Jumper::setFlightTechnique()
{
    if (flightTechniqueS > 120)
        flightTechniqueS = 120;
    if (flightTechniqueS < 1)
        flightTechniqueS = 1;

    int test1 = 20 - hill.flightStyleMeters[flightStyle] + randomInt(-4, 0);
    flightTechnique = (flightTechniqueS * 0.887) + (form * 1.15);
    if (flightStyle == 0)
        flightTechnique += randomInt(-12, -6);
    else if (flightStyle == 1)
        flightTechnique += randomInt(-2, 2);
    else if (flightStyle == 2)
        flightTechnique += randomInt(-3, 3);
    else if (flightStyle == 3)
        flightTechnique += randomInt(-4, 4);
    else if (flightStyle == 4)
        flightTechnique += randomInt(-5, 5);

    flightTechnique += normalRandom(0, 7);
    flightTechnique += randomInt((comp.importance - 6), 0);
    flightTechnique -= windGusts;
    flightTechnique = round(flightTechnique);
    if (flightTechnique > 280)
        flightTechnique = 280;
    if (flightTechnique < 1)
        flightTechnique = 1;
}

void Jumper::setGateAndWindMeters()
{
    if (hill.gateMeters == (-1))
    {
        hill.gateMeters = (hill.gatePoints / hill.metersPoints);
    }
    if (hill.windMetersBack == (-1))
    {
        hill.windMetersBack = (hill.windMetersBack / hill.metersPoints);
    }
    if (hill.windMetersFront == (-1))
    {
        hill.windMetersFront = (hill.windMetersFront / hill.metersPoints);
    }
}

void Jumper::setOtherComponents()
{
    trackRain = comp.trackRain + normalRandom(0, (comp.trackRain / 2));

    windGusts = comp.windUnstable + normalRandom(0, (comp.windUnstable / 2));
}

void Jumper::setPoints()
{
    if (comp.windComp == 1)
    {
        if (windB < 0)
            compensationWind = -windB * hill.windPointsBack;
        else if (windB > 0)
            compensationWind = -windB * hill.windPointsFront;
    }
    if (comp.gateComp == 1)
        compensationGate = (comp.startGate - gate) * hill.gatePoints;

    points = (hill.pointsForK + (hill.metersPoints * (distance - hill.kpoint)));
    if (comp.isJudges == 1)
        points += judgesAll;
    if (comp.gateComp == 1)
        points += compensationGate;
    if (comp.windComp == 1)
        points += compensationWind;

    if (points < 0)
        points = 0;
}

void Jumper::land()
{
    int rd, rd1;

    landRating = landSkillS + form / 13 + landStyleS / 25;
    landRating += normalRandom(0, 3);

    if (landRating > 80)
        landRating = 80;
    else if (landRating < 1)
        landRating = 1;

    judgeRating = 4.9;
    judgeRating += (double)landStyleS / 5.5;
    judgeRating += landRating / 20.755;
    judgeRating += ((distance - hill.kpoint) / hill.judgeDivider);

    judgeRating = (round(judgeRating) * 2) / 2;

    rd = randomInt(0, 1000 * 100);
    rd1 = 86950 - (landRating * 550) - (expernice * 300);
    rd1 -= ((hill.maxdist - distance) * 16 * hill.hsLandDifficulty);
    if (rd1 < 0)
        rd1 = randomInt(200, 900);

    //cout << "rd1: " << rd1 << endl;
    //getch();
    if (rd < rd1)
    {
        landType = 4;
        judgeRating -= (9 + (randomInt(1, 1) / 2));
    }
    else
    {
        rd = randomInt(1, 1000 * 100);
        rd1 = 77210 - (landRating * 550) - (expernice * 300);
        rd1 -= ((hill.maxdist - distance) * 18.5 * hill.hsLandDifficulty);
        if (rd1 < 0)
            rd1 = randomInt(250, 950);
        //cout << "rd1: " << rd1 << endl;
        //getch();
        if (rd < rd1)
        {
            landType = 3;
            judgeRating -= (7 + (randomInt(1, 1) / 2));
        }
        else
        {
            rd = randomInt(1, 1000 * 100);
            rd1 = 117039 - (landRating * 550) - (expernice * 300);
            rd1 -= ((hill.maxdist - distance) * 20.7 * hill.hsLandDifficulty);
            if (rd1 < 0)
                rd1 = randomInt(2000, 7000);

            //cout << "rd1: " << rd1 << endl;
            //getch();
            if (rd < rd1)
            {
                landType = 2;
                judgeRating -= randomInt(1, 2);
                rd = randomInt(1, 30);
                if (rd == 1)
                    judgeRating -= 1;
                else
                {
                    landType = 2;
                    judgeRating -= (randomInt(-1, 1) / 2);
                }
            }
            else
                landType = 1;
        }
    }
    if (comp.isJudges == 1)
    {
        for (auto &jdg : judges)
        {
            jdg = judgeRating;
            rd = randomInt(1, 5);
            if (rd == 1)
                jdg += (-0.5);
            if (rd == 2 || rd == 3 || rd == 4)
                jdg += (0);
            if (rd == 5)
                jdg += (0.5);

            rd = (randomInt(1, 20));
            if (rd == 1)
                jdg += (-1);
            if (rd == 2)
                jdg += (1);

            if (jdg > 20)
                jdg = 20;
            else if (jdg < 1)
                jdg = 1;
        }

        minJudge = judges[0];
        maxJudge = judges[0];
        for (auto jg : judges)
        {
            if (jg < minJudge)
                minJudge = jg;
            if (jg > maxJudge)
                maxJudge = jg;
        }
        judgesAll = 0;
        for (auto jg : judges)
        {
            judgesAll += jg;
        }
        judgesAll -= (minJudge + maxJudge);
    }
}

void Jumper::heightWindMeters()
{

    // cout << height << endl;

    double wm1 = 1, wm2 = 1;
    wm1 += ((height - 178) * 0.15);
    hill.windMetersFront += wm1;
    wm2 += ((178 - height) * 0.15);
    hill.windMetersBack -= wm1;

    //cout << "1: " << wm1 << " 2: " << wm2 << endl;

    //cout << "Front: " << hill.windMetersFront << "Back: " << hill.windMetersBack << endl;
}

void Jumper::showResult()
{
    cout << name << " " << surname << " (" << nationality << ")" << endl;
    cout << "OdlegàoòÜ: " << distance << "m"
         << " (Belka " << gate << " (";
    int test1 = gate - comp.startGate;
    if (test1 > 0)
    {
        colorText(2, "+");
        colorText(2, to_string(test1));
    }
    if (test1 == 0)
    {
        colorText(7, "+0");
    }
    if (test1 < 0)
    {
        colorText(4, to_string(test1));
    }
    SetConsoleTextAttribute(hcon, 15);
    cout << "))" << endl;

    if (comp.isJudges == 1)
    {
        cout << "| ";
        for (auto jdg : judges)
        {
            cout << jdg << " | ";
            Sleep(300);
        }
        cout << endl;
    }

    if (windB < 0)
    {
        colorText(12, "Wiatr: ");
        colorText(12, to_string(windB));
    }

    else if (windB > 0)
    {
        colorText(10, "Wiatr: ");
        colorText(10, to_string(windB));
    }
    else
    {
        colorText(7, "Wiatr: ");
        colorText(7, to_string(windB));
    }
    cout << endl;
    if (compensationGate < 0)
    {
        colorText(12, "Za belk©: ");
        colorText(12, to_string(compensationGate));
    }
    else if (compensationGate > 0)
    {
        colorText(10, "Za belk©: ");
        colorText(10, to_string(compensationGate));
    }
    else
    {
        colorText(7, "Za belk©: ");
        colorText(7, to_string(compensationGate));
    }
    cout << endl;
    if (compensationWind < 0)
    {
        colorText(12, "Za wiatr: ");
        colorText(12, to_string(compensationWind));
    }
    else if (compensationWind > 0)
    {
        colorText(10, "Za wiatr: ");
        colorText(10, to_string(compensationWind));
    }
    else
    {
        colorText(7, "Za wiatr: ");
        colorText(7, to_string(compensationWind));
    }
    cout << endl;
    if ((compensationWind + compensationGate) < 0)
    {
        colorText(12, "ù•cznie: ");
        colorText(12, to_string((compensationWind + compensationGate)));
    }
    else if ((compensationWind + compensationGate) > 0)
    {
        colorText(10, "ù•cznie: ");
        colorText(10, to_string((compensationWind + compensationGate)));
    }
    else
    {
        colorText(7, "ù•cznie: ");
        colorText(7, to_string((compensationWind + compensationGate)));
    }

    SetConsoleTextAttribute(hcon, 15);
    cout << "\nPunkty: " << points << endl;

    cout << "Skok zako‰czony ";
    if (landType == 1)
        colorText(11, "telemarkiem");
    else if (landType == 2)
        colorText(3, "l•dowaniem na dwie nogi");
    else if (landType == 3)
        colorText(5, "podp¢rk•");
    else if (landType == 4)
        colorText(12, "upadkiem");

    SetConsoleTextAttribute(hcon, 15);
}

void Jumper::showHideInfo()
{
    cout << "Moc wybicia: " << takeoffPower << ", Technika wybicia: " << takeoffTechnique << ", Technika lotu: " << flightTechnique << endl;
}

void Jumper::showDistanceAndToBeat()
{
    for (int i = 0; i <= distance; i++)
    {
        // cout << "To Beat: " << toBeat << endl;
        if (i == distance)
        {
            cout << "| " << i << "m |" << endl;
        }
        else
            cout << i << "m" << endl;

        if (distance - i < 5 + (randomInt(-12, 12)))
            Sleep(86);
        else if (distance - i < 10 + (randomInt(-12, 12)))
            Sleep(76);
        else if (distance - i < 25 + (randomInt(-12, 12)))
            Sleep(64);
        else if (distance - i < 45 + (randomInt(-12, 12)))
            Sleep(51);
        else if (distance - i < 70 + (randomInt(-12, 12)))
            Sleep(34);
        else if (distance - i < 100 + (randomInt(-12, 12)))
            Sleep(20);
        else if (distance - i < 150 + (randomInt(-12, 12)))
            Sleep(15);
        else
            Sleep(10);

        cls;
    }
    cls;
}

void Jumper::basicDistance()
{
    distance = hill.startDist;
    distance += (gate * hill.gateMeters);

    if (windB > 0)
        distance += (windB * hill.windMetersFront);
    else if (windB < 0)
        distance += (windB * hill.windMetersBack);

    distance += (takeoffPowerDiff * hill.takeoffPowerImportance);
    distance += takeoffTechnique * hill.takeoffTechniqueMeters;
    distance += flightTechnique * hill.flightTechniqueMeters;

    for (int i = 0; i < 5; i++)
    {
        if (flightStyle == i)
        {
            distance += hill.flightStyleMeters[i];
        }
    }

    if (distance > hill.maxdist)
        distance = hill.maxdist + normalRandom(0, hill.maxdistRandom);
    distance = round(distance * 2) / 2;
}

void Jumper::setToBeat()
{
    toBeat = comp.leaderPoints - hill.pointsForK;
    if (comp.isJudges == 1)
        toBeat -= 54;

    if (comp.gateComp == 1)
        toBeat -= compensationGate;

    if (comp.windComp == 1)
        toBeat -= compensationWind;

    toBeat /= hill.metersPoints;
    toBeat += hill.kpoint;
    toBeat = ceil(toBeat * 2) / 2;
}
void Competition::setLeaderPoints()
{
    double top = jumpers[0].points;
    for (auto &jp : jumpers)
    {
        if (jp.points > top)
            top = jp.points;
    }
}

void Jumper::saveResultsToCsvFile(string file)
{
    rsf.open(file, ios::out | ios::app);
    rsf << name << ";" << surname << ";" << nationality << ";" << distance << ";" << gate << ";" << wind << ";" << compensationGate + compensationWind;
    if (comp.isJudges == 1)
    {
        rsf << "|";
        for (auto jg : judges)
        {
            rsf << jg << "|";
        }
        rsf << ";" << judgesAll;
    }
    rsf << ";" << points << endl;
    rsf.close();
}
void Jumper::saveResultsToTxtFile(string file)
{
    rsf.open(file, ios::out | ios::app);
    rsf << name << " " << surname << " (" << nationality << ") , " << distance << "m, Belka " << gate << ", Wiatr: " << wind << ", Rekompensata: " << compensationGate + compensationWind;
    if (comp.isJudges == 1)
    {
        rsf << ", Noty: |";
        for (auto jg : judges)
        {
            rsf << jg << "|";
        }
        rsf << ", ù•cznie: " << judgesAll;
    }
    rsf << ", Punkty: " << points << "pts" << endl;
    rsf.close();
}
void defaultClearFile(string file)
{
    rsf.open(file, ios::out);
    rsf.clear();
    rsf.close();
}

void Hill::startup()
{
    pointsForK = 60;
    if (kpoint <= 25)
        metersPoints = 4.8;
    else if (hill.kpoint <= 30)
        metersPoints = 4.4;
    else if (hill.kpoint <= 34)
        metersPoints = 4;
    else if (hill.kpoint <= 39)
        metersPoints = 3.6;
    else if (hill.kpoint <= 49)
        metersPoints = 3.2;
    else if (hill.kpoint <= 59)
        metersPoints = 2.8;
    else if (hill.kpoint <= 69)
        metersPoints = 2.4;
    else if (hill.kpoint <= 79)
        metersPoints = 2.2;
    else if (hill.kpoint <= 99)
        metersPoints = 2.0;
    else if (hill.kpoint <= 169)
        metersPoints = 1.8;
    else if (hill.kpoint >= 170)
    {
        metersPoints = 1.2;
        hill.pointsForK = 120;
    }
}

void Hill::setType()
{
    if (kpoint <= 0)
        type = "brak danych";
    if (kpoint <= 44)
        type = "maàa";
    if (kpoint <= 74)
        type = "òrednia";
    if (kpoint <= 99)
        type = "normalna";
    if (kpoint <= 169)
        type = "duæa";
    else
        type = "mamucia";
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

double normalRandom(double mid, double a)
{
    srand(time(NULL));
    default_random_engine gen;
    normal_distribution<double> ndist(mid, a);
    double result, min, max;
    double rd[1000];
    int nr = randomInt(0, 999);

    for (int i = 0; i < 1000; i++)
    {
        rd[i] = ndist(gen);
        if (i == 0)
        {
            min = rd[i];
            max = rd[i];
        }
        if (rd[i] > max)
            max = rd[i];
        else if (rd[i] < min)
            min = rd[i];
    }

    return rd[nr];
}
void binomalRandom(int up, int chance)
{
    default_random_engine gen;
    binomial_distribution<int> bdist(up, chance);

    for (int i = 0; i <= 100; i++)
    {
        cout << i + 1 << ". " << bdist(gen) << endl;
    }
}

void selectTrainingHill()
{
    int i = 1, c;
    for (auto hill : hills)
    {
        cout << i << ". " << hill.name << " (" << hill.country << ") "
             << "K" << hill.kpoint << " HS" << hill.hspoint << endl;
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
        vechill.maxdistRandom = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.startDist = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.hsLandDifficulty = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[0] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[1] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[2] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[3] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[4] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.optimalTakeoffPower = stoi(tmp);
        getline(hlf, tmp, ',');
        vechill.takeoffPowerImportance = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.takeoffTechniqueMeters = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightTechniqueMeters = stod(tmp);
        getline(hlf, tmp);
        vechill.judgeDivider = stod(tmp);
        hills.push_back(vechill);
    }
    hlf.close();
}

void loadJumpers(bool ifAge, bool ifForm, bool ifInjuryResistance)
{
    Jumper jp;
    string tmp;
    jpf.open("../resources/jumpers.csv", ios::in);
    while (getline(jpf, jp.name, ','))
    {
        //cout << jp.name << endl;
        getline(jpf, jp.surname, ',');
        //cout << jp.surname << endl;
        getline(jpf, jp.nationality, ',');
        //cout << jp.nationality << endl;
        if (ifAge == true)
        {
            getline(jpf, tmp, ',');
            jp.age = stoi(tmp);
            //cout << jp.age << endl;
        }
        getline(jpf, tmp, ',');
        jp.height = stoi(tmp);
        //cout << jp.height << endl;
        getline(jpf, tmp, ',');
        jp.takeoffPowerS = stoi(tmp);
        //cout << jp.takeoffPowerS << endl;
        getline(jpf, tmp, ',');
        //cout << tmp << endl;
        jp.takeoffTechniqueS = stoi(tmp);
        getline(jpf, tmp, ',');
        jp.flightTechniqueS = stoi(tmp);
        //cout << jp.flightTechniqueS << endl;
        getline(jpf, tmp, ',');
        jp.flightStyle = stoi(tmp);
        //cout << jp.flightStyle << endl;
        getline(jpf, tmp, ',');
        jp.landSkillS = stoi(tmp);
        //cout << jp.landSkillS << endl;
        getline(jpf, tmp, ',');
        jp.landStyleS = stoi(tmp);
        //cout << jp.landStyleS << endl;
        if (ifForm == 0)
            getline(jpf, tmp);
        else
            getline(jpf, tmp, ',');
        jp.expernice = stoi(tmp);
        //cout << jp.expernice << endl;
        if (ifForm == true)
        {
            if (ifInjuryResistance == 0)
                getline(jpf, tmp);
            else
                getline(jpf, tmp, ',');
            jp.form = stoi(tmp);
            //cout << jp.form << endl;
        }
        if (ifInjuryResistance == true)
        {
            getline(jpf, tmp);
            jp.injuryResistance = stoi(tmp);
            //cout << jp.injuryResistance << endl;
        }
        jumpersList.push_back(jp);
    }
    jpf.close();
}

void loadTrainingConfig()
{
    string tmp;
    ;
    tcf.open("../resources/trainingconfig.csv", ios::in);
    getline(tcf, tmp, ',');
    comp.importance = stoi(tmp);
    getline(tcf, tmp, ',');
    comp.windFaulty = stod(tmp);
    getline(tcf, tmp, ',');
    comp.typicalWind[0] = stod(tmp);
    getline(tcf, tmp, ',');
    comp.typicalWind[1] = stod(tmp);
    getline(tcf, tmp, ',');
    comp.windChange[0] = stod(tmp);
    getline(tcf, tmp, ',');
    comp.windChange[1] = stod(tmp);
    getline(tcf, tmp, ',');
    comp.gateComp = stoi(tmp);
    getline(tcf, tmp, ',');
    comp.windComp = stoi(tmp);
    getline(tcf, tmp, ',');
    comp.isJudges = stoi(tmp);
    getline(tcf, tmp, ',');
    comp.windUnstable = stoi(tmp);
    getline(tcf, tmp);
    comp.trackRain = stoi(tmp);
    tcf.close();
}

void selectTrainingJumper()
{
    int i = 1;
    int c;
    for (auto jp : jumpersList)
    {
        cout << i << ". " << jp.name << " " << jp.surname << " (" << jp.nationality << ") (" << jp.age << " lat ) "
             << "(Forma: " << jp.form << ")" << endl;
        i++;
    }
    Sleep(300);
    cout << "Skoczek: ";
    cin >> c;
    trainingJumper = jumpersList[c - 1];
}

void showHillInfo(Hill hl)
{
    cout << hl.name << " (" << hl.country << ") K" << hl.kpoint << " HS" << hl.hspoint << " (" << percent(95, hl.hspoint) << ") " << endl;
    cout << "Punkty za belke: " << hl.gatePoints << endl;
    cout << "Punkty za wiatr przedni: " << hl.windPointsFront << endl;
    cout << "Punkty za wiatr tylni: " << hl.windPointsBack << endl
         << "Punkty za punkt K: " << hl.pointsForK << endl
         << "Punkty za metr: " << hl.metersPoints << endl;
}

void showJumpers()
{
    int i = 1;
    for (auto jp : jumpersList)
    {
        cout << i << ". " << jp.name << " " << jp.surname << " (" << jp.nationality << ")" << endl;
        i++;
    }
}

void Competition::showHideInfo()
{
    cout << "Przeliczniki za belke: " << (bool)comp.gateComp << endl
         << "Przeliczniki za wiatr: " << (bool)comp.windComp << endl
         << "Noty s©dziowskie: " << (bool)comp.isJudges << endl
         << "Zakres wiatru: " << typicalWind[0] << " - " << typicalWind[1] << endl
         << "Podstawowy wiatr: " << startWind << endl
         << "Falszywosc przelicznik¢w: " << windFaulty << endl;
}