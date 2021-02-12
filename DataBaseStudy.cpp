#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "������ ��������� �������� � ����� ������ �������� � �� �������� � ����� ��������" << endl;

    string path = "myFile.txt";
    string pathLessons = "Lessons.txt";
    string pathStudents = "Students.txt";
    string pathRatings = "Ratings.txt";
    string bufferpathStudents = "BuffStud.txt";
    string bufferpathRatings = "BuffRatings.txt";
    string bufferpathLessons = "BufferLessons.txt";
    string bufferpathKeys = "BufferKeys.txt";
    string pathKeys = "Keys.txt";
    string enteredvalue;

    ofstream fout;   
    ofstream ratingsfout;
    ofstream foutKeys;

    ifstream fin;
    ifstream finRatings;
    ifstream finStudents;
    ifstream finKeys;

    
    int a = 1;
    int subjectscount = 0;
    int pupilcount = 0;
    int size;
    

    do
    {
        cout<< "0 - ��������� � ������" << endl
            << "1 - ������� ������" << endl
            << "2 - ������������ ���� � �������" << endl
            << "3 - ������� ������� �������������� ������ ��������� �� ��������" << endl
            << "4 - ������������ ���� � ��������� � �� ��������, ���������������� �� ��������" << endl
            << "5 - �������� ��������� � ��� ������ � ���� ������" << endl
            << "6 - ������� ������ �� �������. ������� ������������� ��������� �������� 1 (������ ����� �������)" << endl
            << "7 - �������� ������ � ��������" << endl
            << "8 - ������� ������ � �������� � ��� ��������� � ��� ����������" << endl
            << "9 - ������� ���������" << endl<<endl
            << "������� ����� ��������: ";

        int maxsize = 0;
        // �������� �������� ������
        cin >> enteredvalue;                    
        size = enteredvalue.length();			// ��������� ���������� �������� � ������
        bool err = false;						// ���� err true, �� ��������� ����� �����������
        const char* str = enteredvalue.c_str();	// �������� ������ � ������� char, ��� �� ����� �������� � ��������  isdigit
        if (size > 1 || !isdigit(str[0])) err = true;       // ���� ����������� ���� ������

        if (err) cout << "� �� ������ ����, ��� �� ��������: " << enteredvalue <<endl<<endl;
        else
        {
            a = enteredvalue[0]-48;
            // cout << "�� ����� ���������� �����: " << enteredvalue << endl;
            subjectscount = 0;
            fin.open(pathLessons);       // ������� ���������� ���������
            if (!fin.is_open())
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                string str;
                while (!fin.eof())
                {
                    str = "";
                    getline(fin, str);      // ���� ����� �� �����, �� ���� while ����������
                    ++subjectscount;
                }
                fin.close();
            }

            pupilcount = 0;
            fin.open(pathStudents);     // ������� ���������� ���������  
            if (!fin.is_open())
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                string str;
                while (!fin.eof())
                {
                    str = "";
                    getline(fin, str);      // ���� ����� �� �����, �� ���� while ����������
                    if (maxsize<str.length())
                    {
                        maxsize = str.length();
                    }
                    
                    ++pupilcount;
                }
                fin.close();
            }

            if (a == 1 || a == 3)
            {
                fin.open(pathLessons);
                if (!fin.is_open())  // ��������, �������� �� ����
                {
                    cout << "������ �������� �����" << endl;
                }
                else if (a == 1)
                {
                    string str;
                    if (maxsize<8)  cout << "\n\nNum\tSurname\t";// ���������, ���� ������� �������
                    else
                    {
                        cout << "\n\nNum\tSurname\t\t";
                    }
                    
                    while (!fin.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        cout << str << " ";

                    }
                    cout << endl;
                }
                fin.close();
                fin.open(pathStudents);      //��������� ������� � ������
                finRatings.open(pathRatings);
                finKeys.open(pathKeys);
                if (!fin.is_open() || !finRatings.is_open() ||!finKeys.is_open())  // ��������, �������� �� ����
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    //cout << "���� ������� ������!" << endl;
                    string str;
                    string str2;
                    string strKeys;
                    string strname;
    
                    if (a == 3)       // ������� ������ ������� 
                    {
                        string enteredword;
                        bool foundoverlap = false;
                        cout << "������� ����� �������: ";
                        //while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                        //{
                        //    str = "";
                        //    getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        //    cout << str << endl;
                        //}

                        //fin.close();                // ��� �����, ������ ��� ���� ���������� eof, �� ��������� eof �� ����������, ��� ��� �� ����� ��������� ������ ������ ����� ������
                        //fin.open(pathStudents);
                        //finRatings.close();
                        //finRatings.open(pathRatings);

                        cin >> enteredword;
                        while (!finKeys.eof() && !finRatings.eof() && !fin.eof())      // ���� ���� ����� ���� ������ 
                        {
                            str = "";
                            double first;
                            double summ = 0;        // ����� ���� ������
                            getline(finKeys, strKeys);      // ��������� ������ �� fin � ���������� str
                            getline(finRatings, str2);
                            getline(fin, str);
                            if (strKeys == enteredword)         // ������� ������� ������ �� �������
                            {
                                foundoverlap = true;
                                for (int i = 0; i < str2.length(); i++)
                                {
                                    if (str2[i] != ' ')
                                    {
                                        first = (double)str2[i] - 48;
                                        summ += first;
                                        strname = str;
                                    }
                                }
                                cout << "������ ������� c ��������: " << strname << " = " << summ / subjectscount << " �����\n\n";
                            }
                        }
                        if (!foundoverlap) cout << "������� ��� �������: " << enteredword << " �� ����������\n";
                    }
                    else
                    {
                        while (!fin.eof() && !finRatings.eof()&&!finKeys.eof())      // ���� ���� ����� ���� ������ 
                        {
                            str = "";
                            getline(finKeys, strKeys);
                            getline(fin, str);      // ��������� ������ �� fin � ���������� str
                            getline(finRatings, str2);
                            cout << strKeys << "\t";
                            cout << str;
                            if (maxsize > 7 && str.length()>7) cout << "\t" << str2 << endl;                    // ����� �� ����� � ����������� �� ������ ����� ������� �������
                            else if (maxsize > 7 && str.length() <= 7) cout << "\t\t" << str2 << endl;
                            else if (maxsize<=7) cout << "\t" << str2 << endl;

                        }
                        cout << endl << endl;
                    }
                    fin.close();
                    finRatings.close();
                    finKeys.close();
                }
            }
            else if (a == 2)
            {
                fin.open(pathLessons);
                fout.open(path);
                finStudents.open(pathStudents);
                
                if (!fin.is_open() && !fout.is_open()&& !finStudents.is_open())  // ��������, �������� �� ����
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    string strStud;
                    string str;

                        
                    while (!finStudents.eof())
                    {
                        strStud = "";
                        getline(finStudents, strStud);
                        if (maxsize < strStud.length())
                        {
                            maxsize = strStud.length();
                        }
                    }
                    
                    if (maxsize<8) fout << "Num\tSurname\t";
                    else fout << "Num\tSurname\t\t";
                    
                    while (!fin.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        fout << str << " ";    // ������� ������ �� ���������� str � ���� myFail ������� fout

                    }
                    fout << endl;
                    fin.close();
                    finStudents.close();
                }
                finKeys.open(pathKeys);
                fin.open(pathStudents);      //��������� ������� � ������
                finRatings.open(pathRatings);
                if (!fin.is_open() || !finRatings.is_open()||!finKeys.is_open())  // ��������, �������� �� ����
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    string str;
                    string str2;
                    string strKey;
                    while (!fin.eof() && !finRatings.eof() && !finKeys.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        str2 = "";
                        strKey = "";
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        getline(finRatings, str2);
                        getline(finKeys, strKey);

                        fout << strKey << "\t";
                        fout << str;

                        if (maxsize > 7 && str.length() > 7) fout << "\t"<<str2 << endl;
                        else if (maxsize > 7 && str.length() <= 7) fout << "\t\t" << str2 << endl;
                        else if (maxsize <= 7) fout << "\t" << str2 << endl;
                    }

                    fin.close();
                    finRatings.close();
                    fout.close();
                    finKeys.close();
                }
                cout << "���� �����" << endl << endl;
            }
            else if (a == 4)
            {
                fin.open(pathLessons);
                fout.open(path);
                if (!fin.is_open() || !fout.is_open())  // ��������, �������� �� ����
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    cout << "���� ������� ������!" << endl;
                    string str;

                    if (maxsize < 8) fout << "Num\tSurname\t";
                    else fout << "Num\tSurname\t\t";
                    while (!fin.eof())          // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        fout << str << " ";    // ������� ������ �� ���������� str � ���� myFail ������� fout

                    }
                    // fout << endl;
                    fin.close();
                }

                fin.open(pathStudents);
                finRatings.open(pathRatings);
                finKeys.open(pathKeys);
                if (!fin.is_open() || !finRatings.is_open() || !finKeys.is_open())  // ��������, �������� �� ����
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    //cout << "���� ������� ������!" << endl;
                    string str;
                    string str2;
                    string strKeys;
                    string* pupil = new string[pupilcount];         // ������ �������� ///////////////////////////////////////////////////////////////////////////////////////////
                    string* allratings = new string[pupilcount];    // ������ ������ ��������  ////////////////////////
                    string* keys = new string[pupilcount];          // ������ ������� ��������
                    int pupilnumber = 0;
                    int* ppupilnumber = &pupilnumber;

                    while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);      // ��������� ������ �� ������� ��������� � ���������� str
                        getline(finRatings, str2);
                        getline(finKeys, strKeys);  // ��������� ������ �� ����� � �������� ��������� � ������

                        //fout << str << "\t";
                        //fout << str2 << endl;
                        pupil[pupilnumber] = str;   // ��������� ������ �� �������� � ������
                        allratings[pupilnumber] = str2;
                        keys[pupilnumber] = strKeys;    // ��������� ������ �� ������� �������� � ������
                        // cout << allratings[pupilnumber] << endl;

                        (*ppupilnumber)++;
                    }
                    string buffer;
                    string ratingsbuffer;
                    string keysbuffer;
                    int nameindex;
                    fout << endl;

                    for (int i = 0; i < pupilcount; i++)              // ���������� �� ��������
                    {
                        string minname = pupil[i];           // ���������� �������
                        char minchar = pupil[i][0];
                        nameindex = i;
                        string mratings = allratings[i];     // ���������� ������
                        string mkeys = keys[i];

                        for (int j = i + 1; j < pupilcount; j++)
                        {
                            if (pupil[j][0] < minchar)       // ���� ������ ������ ������ ���������� ����� ������ ������������, �� ��� � ���� �������� ���������� �����������
                            {
                                minchar = pupil[j][0];        // ����������� min ������ ��������
                                minname = pupil[j];            // ����
                                mratings = allratings[j];
                                mkeys = keys[j];
                                nameindex = j;               // ������ min ��������
                            }
                        }
                        buffer = pupil[i];                   // ����� ��� �������� � ������
                        ratingsbuffer = allratings[i];
                        keysbuffer = keys[i];

                        pupil[i] = minname;
                        allratings[i] = mratings;
                        keys[i] = mkeys;

                        pupil[nameindex] = buffer;
                        allratings[nameindex] = ratingsbuffer;
                        keys[nameindex] = keysbuffer;

                        fout << keys[i] << "\t";

                        if (maxsize < 8)
                        {
                            fout << pupil[i] << "\t";
                            fout << allratings[i] << endl;
                        }
                        else 
                        {
                            if (pupil[i].length() < 8) 
                            {
                                fout << pupil[i] << "\t\t";
                                fout << allratings[i] << endl;
                            }
                            else
                            {
                                fout << pupil[i] << "\t";
                                fout << allratings[i] << endl;
                            }
                        }
                    }
                    delete[] keys;
                    delete[] pupil;
                    delete[] allratings;

                    fin.close();
                    finRatings.close();
                    fout.close();
                    finKeys.close();
                }
            }
            else if (a == 5)
            {

                fout.open(pathStudents, ofstream::app);    // � ������ ������ ������� ����, app - append - ��������, ��������� ����������� ����� ������ �� ������� ������
                ratingsfout.open(pathRatings, ofstream::app);
                finKeys.open(pathKeys);
                foutKeys.open(pathKeys,ofstream::app);


                if (!fout.is_open() || !ratingsfout.is_open()||!foutKeys.is_open()||!finKeys.is_open())  // ��������, ��������� �� �����
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    string allsubjects;     // ���������� ��� ������ � ������� ���������, �� ������� ���������� �������
                    int subjectscount = 0;
                    fin.open(pathLessons);
                    if (!fin.is_open())  // ��������, �������� �� ����
                    {
                        cout << "������ �������� �����" << endl;
                    }
                    else
                    {
                        string str;
                        while (!fin.eof())      // ���� ���� ����� ���� ������ 
                        {
                            str = "";
                            getline(fin, str);      // ��������� ������ �� fin � ���������� str
                            allsubjects = allsubjects + str + " ";
                            subjectscount++;
                        }
                        fin.close();
                    }
                    string newsurname;
                    string newpupilratings;
                    string keystr;
                    int lastkey = 0;
                    cout << "������� ������� �������: ";
                    
                    cin >> newsurname;
                    while (newsurname.length()>15)
                    {
                        cout << "������� ������� �� ������ ���� ������ 15 ��������. ������� ������� ��� ���: ";
                        cin >> newsurname;
                    }
                    
                    // �������� ������ ������ �������
                    while (!finKeys.eof())      // ������ ��������� ������ �� �����������
                    {
                        getline(finKeys, keystr);
                    }
                    
                    lastkey = stoi(keystr)+1;   // ���������� string � int
                    foutKeys <<endl<<lastkey;


                    fout << endl << newsurname;
                    cout << "������� ������ ������� �� ��������� " << allsubjects << ": ";
                    cin >> newpupilratings;
                    pupilcount++;
                    ratingsfout << endl;
                    for (int i = 0; i < subjectscount; i++)
                    {
                        ratingsfout << newpupilratings[i];
                        if (i < subjectscount - 1)
                        {
                            ratingsfout << "   ";
                        }
                    }
                }
                fout.close();
                ratingsfout.close();
                finKeys.close();
                foutKeys.close();
            }
            else if (a == 6)
            {
                fin.open(pathStudents);                 // ��������� ������� 
                finRatings.open(pathRatings);           // � ������ �� ������������ ������
                fout.open(bufferpathStudents);          // ��������� ��������� ���� ��� ������ ��������� ��� ����������
                ratingsfout.open(bufferpathRatings);    // � ������ ��� ����� ��������
                finKeys.open(pathKeys);
                foutKeys.open(bufferpathKeys);

                if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open() || !finKeys.is_open())  // ��������, ��������� �� �����
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    string str;     // � ��� ������ ������������ ������ �� ������
                    string str2;
                    string strKeys;
                    string penultimateword;
                    string enteredword;
                    string enteredkey;
                    string allpupils;
                    int countPupilsRatings = 0;

                    while (!fin.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);
                        allpupils = allpupils + str + " ";
                    }
                    cout << "�������� ������� ������� �� ������������ � ����: " << endl << allpupils << endl;      // �������� ������ �������
                    cout << "������� ��: ";
                    cin >> enteredword;
                    cout << "������� ����� �������" << endl; // ������� ����� ���� �����������, �� ��� ������ � �������, ������ � ������� ��� ���������� ������ ��������� �������� �� ��� �������
                    cin >>enteredkey;

                    fin.close();
                    fin.open(pathStudents);
                    while (!fin.eof()) // ��� ������ �������� �� ����� ������� ����� ����������� �������� ��� �������� ������ ����������
                    {
                        getline(fin, penultimateword );
                        getline(fin, str);
                    }


                    fin.close();
                    fin.open(pathStudents);
                    finKeys.close();
                    finKeys.open(pathKeys);

                    while (!fin.eof() && !finRatings.eof() && !finKeys.eof())      // ���� ���� ����� ���� ������ 
                    {
                        countPupilsRatings++;
                        str2 = "";
                        str = "";
                        getline(fin, str);          // ��������� ������� ���������
                        getline(finRatings, str2);  // � ������
                        getline(finKeys, strKeys);  // � ������ ���������

                        if ((str != enteredword || strKeys != enteredkey )&& pupilcount != countPupilsRatings && str != penultimateword)
                        {
                            fout << str << endl;
                            ratingsfout << str2 << endl;
                            foutKeys << strKeys<<endl;
                        }
                        else if ((str != enteredword || strKeys != enteredkey) && pupilcount == countPupilsRatings )
                        {
                            fout << str;
                            ratingsfout << str2;
                            foutKeys << strKeys;
                        }
                        // ��� ������ �������� �� ����� ������� ����� ����������� �������� ��� �������� ������ ����������
                        else if ((str != enteredword || strKeys != enteredkey) && str == penultimateword && pupilcount == countPupilsRatings + 1)
                        {
                            fout << str;
                            ratingsfout << str2;
                            foutKeys << strKeys;
                        }
                        
                    }

                    fin.close();
                    finRatings.close();
                    fout.close();
                    ratingsfout.close();
                    finKeys.close();
                    foutKeys.close();

                    remove("Students.txt");                     // ������� ������ 3 ����� 
                    remove("Ratings.txt");
                    remove("Keys.txt");
                    rename("BuffStud.txt", "Students.txt");     // �������� ����� 3 ����� ������������� � ������
                    rename("BuffRatings.txt", "Ratings.txt");
                    rename("BufferKeys.txt", "Keys.txt");
                    remove("BuffStud.txt");                     // ������� ����� 3 ����� 
                    remove("BuffRatings.txt");
                    remove("BufferKeys.txt");
                    
                }
            }
            else if (a == 7)
            {
                int countfineof = 0;
                ratingsfout.open(bufferpathRatings);                // ��������� �������� ���� � �������� ��� ������
                finRatings.open(pathRatings);                       // ��������� ���� � �������� ��� ������ 
                fin.open(pathStudents);                             // ��������� ���� � ��������� ��� ����������� ����� ��� ������� �������� �������� ������ �� ������ ��������
                fout.open(pathLessons, ofstream::app);         // ��������� ���� � ����������
                if (!fout.is_open() || !ratingsfout.is_open() || !fin.is_open() || !finRatings.is_open())
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    // ���������� ��������
                    string subject;                                     
                    cout << "������� ����������� �������� (3 �����)" << endl;
                    cin >> subject;
                    // �������� �������� ������
                    bool err = false;						
                    if (subject.length() > 3) err = true;      

                    if (err)
                    {
                        while (err)
                        {
                            cout << "������������ ������ ���� �� ����� 3� ��������\n���������� ��� ���: ";
                            cin >> subject;
                        }
                        
                    }

                    else
                    {
                        fout << endl << subject;
                        fout.close();

                        string pupilratings;
                        string newpupilratings;
                        string pupil;
                        while (!fin.eof())
                        {
                            countfineof++;
                            pupilratings = "";
                            pupil = "";
                            newpupilratings = "";
                            getline(fin, pupil);
                            cout << "������� ������ �������: " << pupil << endl;
                            cin >> newpupilratings;

                            getline(finRatings, pupilratings);      // ��������� ������ ��� ������� �������
                            if (pupilcount != countfineof) ratingsfout << pupilratings + "   " + newpupilratings << endl;     // ������� ������ � �������� ���� � ���������� ����� ������
                            else ratingsfout << pupilratings + "   " + newpupilratings;
                        }
                        ratingsfout.close();
                        finRatings.close();
                        fin.close();
                        remove("Ratings.txt");
                        rename("BuffRatings.txt", "Ratings.txt");
                    } 
                }
            }
            else if (a == 8)
            {
                fin.open(pathLessons);
                finRatings.open(pathRatings);
                fout.open(bufferpathLessons);
                ratingsfout.open(bufferpathRatings);

                string ratings;
                string str;
                string lessons = "";
                string enteredlesson = "";
                string result = "";
                int strcount = 0;
                int deletedchars = 0;
                int count = 0;

                while (!fin.eof())
                {
                    str = "";
                    getline(fin, str);
                    lessons = lessons + str + " ";
                }
                fin.close();
                fin.open(pathLessons);
                if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open())  cout << "������ �������� �����" << endl;
                else
                {
                    cout << "������� ������� �� ������������ � ����: " << lessons << endl;
                    cin >> enteredlesson;
                    while (!fin.eof())
                    {
                        str = "";
                        getline(fin, str);          // ���������� � str �������� ��������
                        strcount++;                 // ����������� ������� ��������� �� ����� ������
                        if (enteredlesson != str)  // ���� �������� ������� �� ����� �� ������ �� ���������� � ����
                        {
                            if (strcount != subjectscount)
                            {
                                fout << str << endl;    // � ����� ���� �������� ��� �������� ���������, ����� ����, ������� ���� �������   
                            }
                            else fout << str;
                        }
                        else deletedchars = (strcount - 1) * 4;   // ���� ������� = �������� � ���� ������
                    }

                    while (!finRatings.eof())       // ���������� ������ � ����� ���� ��� ������ ���������� ��������
                    {
                        count++;
                        ratings = "";
                        result = "";
                        getline(finRatings, ratings);
                        //cout << ratings.length() << endl;
                        for (int i = 0; i < ratings.length(); i++)
                        {
                            // ���� ��������� ������� ������ = ��������� ������� ���������� ��������, �� ������� ������ � 3 ������� ���� ���( ����� � ������, ���� ������ ������ �������)
                            if (i == deletedchars || i == deletedchars - 1 || i == deletedchars - 2 || i == deletedchars - 3)   // ���� � ������ �� ������ �������
                            {
                            }
                            else if (deletedchars != 0) ratingsfout << ratings[i];

                            if (i == deletedchars || i == deletedchars + 1 || i == deletedchars + 2 || i == deletedchars + 3) {}  // ���� � ������ ������ �������
                            else if (deletedchars == 0) ratingsfout << ratings[i];
                        }
                        if (pupilcount != count) ratingsfout << endl;

                    }
                    fout.close();
                    fin.close();
                    remove("Lessons.txt");
                    rename("BufferLessons.txt", "Lessons.txt");
                    remove("BufferLessons.txt");                // ������� ��������

                    ratingsfout.close();
                    finRatings.close();
                    remove("Ratings.txt");
                    rename("BuffRatings.txt", "Ratings.txt");
                    remove("BuffRatings.txt");
                    cout << endl;
                }
            }
            else if (a == 0)
            {
            cout <<endl<<endl<<endl
                << "�������� 1 - '������� ������'. ��������� ������� ������ �������� � �� ������ �� �������� �� ���������;" << endl
                << "�������� 2 - '������������ ���� � �������'. ��������� ������� ���� �� ������� �������� � �� �������� �� ��� �� ���������;" << endl
                << "�������� 4 ���������� �������� 2, �� ����������� ���������� �������� �� �������� �� � �� �;" << endl<<endl
                << "������ ��������� 5, ����������� ������ ��� ��������, � ������� ���������� ���������. ��������:" << endl
                << "��� ������� �������� ���������� ������ ������ 4 5 4 5 �� ��������� ��������� Rus Mat Lit Phy ��������������." << endl
                << "������ Sidorov, ���� Enter, ������ 4545, ���� Enter." << endl<<endl
                << "��� �������� ������ �� ������� (�������� 6), ���������� ������ ��� �����. ����� ����� ������, ������ �������� 1 (������ ������� Num);" << endl
                << "������ �������� 7, ���������� �������� ������� ��������, ����� ������������ �� 3� ��������, � ����� ��� ������� �� ��������� ������ ������ �� ��������;" << endl
                << "������ �������� 8 ����� ������ ������ ������������ �������� (3 �������) �� ������������, ����� ��������� ��� ������� ����;" << endl
                << "���� ��������� �������, ����������� � ���������� ��������������" << endl<<endl<<endl;
            }
            else exit(9);
        }  
    }
    while (a || !a);
}
