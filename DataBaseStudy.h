#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <shlobj.h> // Для MAX_PATH и SHGetFolderPath

using namespace std;


string path;
string pathLessons;
string pathSubjects;
string pathStudents;
string pathRatings;
string pathKeys;
string pathNames;
string pathPatronymics;
string pathbuffSubjects;
//string bufferpath;
string bufferpathStudents;
string bufferpathRatings;
string bufferpathLessons;
string bufferpathKeys;
string bufferpathNames;
string bufferpathPatronymics;

wstring bufferpath;

ofstream fout;
ofstream ratingsfout;
ofstream foutKeys;
ofstream foutSubjects;
ofstream foutSubjectsbuf;
ofstream foutnames;
ofstream foutpatronymics;

ifstream fin;
ifstream finRatings;
ifstream finStudents;
ifstream finKeys;
ifstream finLessons;
ifstream finSubjects;
ifstream finNames;
ifstream finPatronymics;

TCHAR  pathData[MAX_PATH];   // Для адреса к рабочему столу

int a = 1;	// Введенное пользователем число
int subjectscount = 0;
double pupilcount = 0;
int wordsize = 0;
bool badword = false;

int showfullinfo(string& enteredvalue);