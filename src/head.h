#pragma once
#include <iostream>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <ctime>
#include <map>
#include <stdlib.h>
#include <list>
#include <locale.h>
using namespace std;
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);

#define APP_VERSION "0.0.1";
#define DEFAULT_SAVEFILENAME "save.sav";
#define cls system("cls");
#define hillsfile hlf;

class Jumper
{
public:
    //atrybuty
    string name, surname;
    int height, age;
    string nationality;
    int takeoffPowerS, takeoffTechniqueS;
    int skisPositionS, flightStyleS, transitionSpeedS;
    int takeoffPower, takeoffTechnique;
    int skisPosition, flightStyle, transitionSpeed;
    int flightTechnique, flightTechniqueS;
    int landSkill, landStyleS;
    int expernice, condition, readyToJump, form, happiness, injuryResistance;
    //skok
    double distance, toBeat;
    double judges[5], minJudge, maxJudge, wind, windBonus, judgeRating, judgesPoints, judgesAll;
    double points, compensationGate, compensationWind;
    bool dsq;
    void jump();
};

class Hill
{
public:
    string name, country;
    double gatePoints, gateMeters;
    int kpoint, hspoint, pointsForK;
    double maxdist;
    double windMetersFront, windMetersBack, windPointsFront, windPointsBack, typicalWind[2];
    double metersPoints, startWind, hsLandDifficulty;
    double startDist, takeoffDist, flightDist, minWindChange, maxWindChange;
    int optimalSkisPosition;
    double skisPositionEffect;
    double takeoffPowerMeters, takeoffTechniqueMeters, flightTechniqueMeters;
};
class Time
{
public:
    int year, month, day;
    void skip(int nmb);
};
class Save
{
public:
    string filename;
    fstream sfile;
    void initSave(string filename);
    void save(string filename);
    void load(string filename);
};
Hill hill;
Save save;
fstream hillsfile;
int randomInt(int, int);
double randomDouble(double, double);
void colorText(unsigned short color, string text);
double percent(double prc, double num);
void loadHills();
void selectTrainingHill();

vector<Hill> hills;
