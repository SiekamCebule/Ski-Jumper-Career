#pragma once
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

#define APP_VERSION "0.0.1"
#define DEFAULT_SAVEFILENAME "save.sav"
#define cls system("cls")
#define hillsfile hlf
#define jumpersfile jpf
#define trainingconfigfile tcf
#define nationsfile ntf
#define resultsfile rsf

class Jumper
{
public:
    //atrybuty
    string name, surname;
    int height, age;
    string nationality;
    int takeoffPowerS, takeoffTechniqueS;
    int skisPositionS, flightStyle;
    int takeoffPower, takeoffTechnique;
    int flightTechnique, flightTechniqueS;
    int landSkillS, landStyleS, landType;
    double landRating;
    int expernice, condition, readyToJump, form, happiness, injuryResistance;
    int gate, windGusts, trackRain;
    double distance, toBeat;
    double judges[5], minJudge, maxJudge, wind, windB, windBonus, judgeRating, judgesPoints, judgesAll;
    double points, compensationGate, compensationWind;
    bool dsq;
    double takeoffPowerDiff;
    double windSensor[10];
    void afterStart();
    void jump();
    void setTakeoffPower();
    void setTakeoffTechnique();
    void setFlightTechnique();
    void setGateAndWindMeters();
    void setOtherComponents();
    void setPoints();
    void land();
    void heightWindMeters();
    void showResult();
    void showHideInfo();
    void showDistanceAndToBeat();
    void basicDistance();
    void setToBeat();
    void saveResultsToCsvFile(string file);
    void saveResultsToTxtFile(string file);
    vector<string> specials;
};

class Hill
{
public:
    string name, country, type;
    double gatePoints, gateMeters;
    int kpoint, hspoint, pointsForK;
    double maxdist, maxdistRandom;
    double windMetersFront, windMetersBack, windPointsFront, windPointsBack;
    double metersPoints, hsLandDifficulty;
    double startDist, takeoffDist, flightDist, minWindChange, maxWindChange;
    int optimalSkisPosition;
    double skisPositionEffect;
    double takeoffTechniqueMeters, flightTechniqueMeters;
    int optimalTakeoffPower;
    double flightStyleMeters[5];
    double takeoffPowerImportance, judgeDivider;
    void startup();
    void setType();
};
class Competition
{
public:
    string name;
    int importance;
    Hill hill;
    vector<Jumper> jumpers;
    vector<Jumper> sortJumpers;
    int startGate;
    double typicalWind[2], windChange[2], startWind, windFaulty, leaderPoints;
    int windUnstable, trackRain;
    bool gateComp, windComp, isJudges;
    void sortResults();
    void showHideInfo();
    void setLeaderPoints();
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
Competition comp;
vector<Competition> comps;
Jumper trainingJumper;
Save save;
fstream hillsfile, jumpersfile, trainingconfigfile, nationsfile, resultsfile;
int randomInt(int, int);
double randomDouble(double, double);
void colorText(unsigned short color, string text);
double percent(double prc, double num);
double normalRandom(double mid, double a);
void binomalRandom(int up, int chance);
//-----------------------------//
void loadHills();
void loadJumpers(bool ifAge, bool ifForm, bool ifInjuryResistance);
void loadTrainingConfig();
void selectTrainingHill();
void selectTrainingJumper();
void showHillInfo(Hill hl);
void showJumpers();
void defaultClearFile(string file);

vector<Hill> hills;
vector<Jumper> jumpersList;