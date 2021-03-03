#include "DataBaseStudy.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    path = "myFile.txt";
    pathLessons = "Lessons.txt";
    pathSubjects = "Subjects.txt";
    pathStudents = "Students.txt";
    pathRatings = "Ratings.txt";
    pathKeys = "Keys.txt";
    pathNames = "Names.txt";
    pathPatronymics = "Patronymics.txt";
    pathbuffSubjects = "BuffSubjects.txt";
    bufferpath = L"\\myFile.txt";          // ��� ����� �� ������� �����
    bufferpathStudents = "BuffStud.txt";
    bufferpathRatings = "BuffRatings.txt";
    bufferpathLessons = "BufferLessons.txt";
    bufferpathKeys = "BufferKeys.txt";
    bufferpathNames = "BufferNames.txt";
    bufferpathPatronymics = "BufferPatronymics.txt";

    SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY | CSIDL_FLAG_CREATE, NULL, SHGFP_TYPE_CURRENT, pathData);  // pathData - ���� � �������� �����

    cout << "������������ ������������. ���� ������ ��������� - �������������� � ����� ������ ��������� � �� ������." << endl;
    cout << "�������� �������� ���� � ������� ��������������� �����" << endl << endl;

    do
    {
        closeallfiles();
        cout << "0 - ������� ���������" << endl
            << "1 - ������� ������" << endl
            << "2 - ������������ ���� � �������" << endl
            << "13 - ��������� � ������" << endl
            << "14 - �������� ������ ��������" << endl
            << "Esc - ��������� � ������� ����"<< endl << endl
            << "������� ����� ��������: ";

        string enteredvalue;
        int maxsize = 0;
        checkinput();
        if (enteredvalue2 == 27) continue;
        enteredvalue = enteredword2;
        // cin >> enteredvalue;


        // �������� �������� ������
        wordsize = enteredvalue.length();
        const char* str = enteredvalue.c_str();	// ��� ������ � ��������  isdigit
        if ((wordsize > 1 || !isdigit(str[0])) && enteredvalue != "10" && enteredvalue != "11" && enteredvalue != "12" && enteredvalue != "13" && enteredvalue != "14")
        {
            system("cls");
            cout << "������ �����: " << enteredvalue << endl << endl;
        }
        else
        {
            if (enteredvalue == "14") showfullinfo(enteredvalue);
            else
            {
                if (enteredvalue == "10") a = 10;
                else if (enteredvalue == "11")  a = 11;
                else if (enteredvalue == "12") a = 12;
                else if (enteredvalue == "13") a = 13;
                else a = enteredvalue[0] - 48;
            }

            subjectscount = 0;
            fin.open(pathLessons);       // ������� ���������� ���������
            if (!fin.is_open()) cout << "������ �������� �����" << endl;
            else
            {
                string str;
                while (!fin.eof())
                {
                    str = "";
                    getline(fin, str);
                    ++subjectscount;
                }
            }
            fin.close();

            pupilcount = 0;
            fin.open(pathStudents);     // ������� ���������� ���������  
            if (!fin.is_open())  cout << "������ �������� �����" << endl;
            else
            {
                string str;
                while (!fin.eof())
                {
                    str = "";
                    getline(fin, str);
                    if (maxsize < str.length()) maxsize = str.length();
                    ++pupilcount;
                }
                maxsize += 5;
            }
            fin.close();
            system("cls");

            if (a == 1 || a == 3)
            {
                fin.open(pathLessons);
                if (!fin.is_open()) cout << "������ �������� �����" << endl;
                else if (a == 1)
                {
                    string str;
                    if (maxsize <= 7)  cout << "\nNum\tSurname\t"; // ���������, ���� ������� �������
                    else if (maxsize <= 16) cout << "\nNum\tSurname\t\t";
                    else cout << "\nNum\tSurname\t\t\t";

                    while (!fin.eof())
                    {
                        str = "";
                        getline(fin, str);
                        cout << str << " ";

                    }
                    cout << endl;
                }
                fin.close();

                fin.open(pathStudents);
                finNames.open(pathNames);
                finRatings.open(pathRatings);
                finKeys.open(pathKeys);
                finPatronymics.open(pathPatronymics);

                if (!fin.is_open() || !finNames.is_open() || !finRatings.is_open() || !finKeys.is_open() || !finPatronymics.is_open()) cout << "������ �������� �����" << endl;
                else
                {
                    string str;
                    string str2;
                    string strKeys;
                    string strname;
                    string strpatronymic;

                    if (a == 3) // ������� �������������� ������ �������� 
                    {
                        string enteredword;
                        bool foundoverlap = false;
                        cout << "������� ����� ��������: ";
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        enteredword = enteredword2;
                        while (!finKeys.eof() && !finRatings.eof() && !fin.eof())
                        {
                            str = "";
                            double first;
                            double summ = 0;
                            getline(finKeys, strKeys);
                            getline(finRatings, str2);
                            getline(fin, str);
                            if (strKeys == enteredword)
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
                                    if (str2[i] == '0') subjectscount--;
                                }
                                cout << endl<<"������� �������������� �������� ���� ������ �� ������� �������� c ��������: " << strname << " = " << summ / subjectscount << "\n\n";
                            }
                        }
                        if (!foundoverlap) cout << "�������� ��� ������� " << enteredword << " �� ����������\n";
                    }
                    else
                    {
                        while (!fin.eof() && !finRatings.eof() && !finKeys.eof())
                        {
                            str = "";
                            getline(finKeys, strKeys);
                            getline(fin, str);          // ��������
                            getline(finNames, strname);
                            getline(finPatronymics, strpatronymic);
                            getline(finRatings, str2);
                            cout << strKeys << "\t";
                            cout << str << " " << strname[0] << "." << strpatronymic[0] << ".";
                            if (maxsize > 7 && maxsize <= 16 && str.length() + 5 > 7) cout << "\t" << str2 << endl;                    // ����� �� ����� � ����������� �� ������ ����� ������� �������
                            else if (maxsize > 7 && maxsize <= 16 && str.length() + 5 <= 7) cout << "\t\t" << str2 << endl;
                            else if (maxsize <= 7) cout << "\t" << str2 << endl;
                            else if (maxsize >= 16 && str.length() + 5 >= 16) cout << "\t" << str2 << endl;
                            else if (maxsize >= 16 && str.length() + 5 <= 16 && str.length() + 5 > 7) cout << "\t\t" << str2 << endl;
                            else if (maxsize >= 16 && str.length() + 5 <= 16 && str.length() + 5 < 7) cout << "\t\t\t" << str2 << endl;
                        }
                        cout << endl << endl;
                    }
                }
                fin.close();
                finNames.close();
                finPatronymics.close();
                finRatings.close();
                finKeys.close();
            }
            else if (a == 2) {
                fin.open(pathLessons);
                fout.open(path);
                finStudents.open(pathStudents);

                if (!fin.is_open() || !fout.is_open() || !finStudents.is_open()) cout << "������ �������� �����" << endl;
                else
                {
                    string strStud;
                    string str;
                    if (maxsize <= 7)  fout << "Num\tSurname\t";
                    else if (maxsize <= 16) fout << "Num\tSurname\t\t";
                    else fout << "Num\tSurname\t\t\t";

                    while (!fin.eof())
                    {
                        str = "";
                        getline(fin, str);
                        fout << str << " ";
                    }
                    fout << endl;
                }
                fin.close();
                fout.close();
                finStudents.close();

                fin.open(pathStudents);
                finRatings.open(pathRatings);
                finKeys.open(pathKeys);
                finNames.open(pathNames);
                finPatronymics.open(pathPatronymics);
                fout.open(path);
                if (!fin.is_open() || !finRatings.is_open() || !finKeys.is_open() || !finNames.is_open() || !finPatronymics.is_open() || !fout.is_open()) cout << "������ �������� �����" << endl;
                else
                {
                    string str;
                    string str2;
                    string strKey;
                    string strname;
                    string strpatronymic;
                    while (!fin.eof() && !finRatings.eof() && !finKeys.eof())
                    {
                        str = "";
                        str2 = "";
                        strKey = "";
                        getline(fin, str);
                        getline(finNames, strname);
                        getline(finPatronymics, strpatronymic);
                        getline(finRatings, str2);
                        getline(finKeys, strKey);

                        fout << strKey << "\t";
                        // fout << str;
                        fout << str << " " << strname[0] << "." << strpatronymic[0] << ".";
                        if (maxsize > 7 && maxsize <= 16 && str.length() + 5 > 7) fout << "\t" << str2 << endl;                    // ����� �� ����� � ����������� �� ������ ����� ������� �������
                        else if (maxsize > 7 && maxsize <= 16 && str.length() + 5 <= 7) fout << "\t\t" << str2 << endl;
                        else if (maxsize <= 7) fout << "\t" << str2 << endl;
                        else if (maxsize >= 16 && str.length() + 5 >= 16) fout << "\t" << str2 << endl;
                        else if (maxsize >= 16 && str.length() + 5 <= 16 && str.length() + 5 > 7) fout << "\t\t" << str2 << endl;
                        else if (maxsize >= 16 && str.length() + 5 <= 16 && str.length() + 5 < 7) fout << "\t\t\t" << str2 << endl;
                    }
                }
                fin.close();
                finRatings.close();
                finKeys.close();
                finNames.close();
                finPatronymics.close();
                fout.close();

                fin.open(path);
                // �������� �� �������� ����� �� ������� �����
                fout.open(pathData + bufferpath);
                if (!fin.is_open() || !fout.is_open()) cout << "������ �������� �����" << endl;
                else
                {
                    fout << fin.rdbuf();
                    cout << "���� ������ �� ������� �����" << endl << endl;
                }
                fin.close();
                fout.close();
            }
            else if (a == 4 || a == 5)
            {
                fin.open(pathLessons);
                fout.open(path);

                if (!fin.is_open() || !fout.is_open())  cout << "������ �������� �����" << endl;
                else
                {
                    {
                        string str;
                        if (a == 4) cout << endl;
                        if (maxsize > 16)
                        {
                            fout << "Num\tSurname\t\t\t";
                            if (a == 4) cout << "Num\tSurname\t\t\t";
                        }
                        else if (maxsize <= 16 && maxsize > 7)
                        {
                            fout << "Num\tSurname\t\t";
                            if (a == 4) cout << "Num\tSurname\t\t";
                        }
                        else if (maxsize <= 7)
                        {
                            fout << "Num\tSurname\t";
                            if (a == 4) cout << "Num\tSurname\t";
                        }

                        while (!fin.eof())
                        {
                            str = "";
                            getline(fin, str);
                            fout << str << " ";
                            if (a == 4) cout << str << " ";

                        }
                    }
                    fin.close();

                    fin.open(pathStudents);
                    finRatings.open(pathRatings);
                    finKeys.open(pathKeys);
                    finNames.open(pathNames);
                    finPatronymics.open(pathPatronymics);
                    if (!fin.is_open() || !finRatings.is_open() || !finKeys.is_open() || !finNames.is_open() || !finPatronymics.is_open())  cout << "������ �������� �����" << endl;
                    else
                    {
                        string str;
                        string str2;
                        string strnames;
                        string strpatronymics;
                        string strKeys;
                        string* pupil = new string[pupilcount];         // ������ ���������
                        string* allratings = new string[pupilcount];    // ������ ������ ���������
                        string* keys = new string[pupilcount];          // ������ ������� ���������
                        string* names = new string[pupilcount];
                        string* patronymics = new string[pupilcount];
                        int pupilnumber = 0;
                        int* ppupilnumber = &pupilnumber;

                        while (!fin.eof() && !finRatings.eof())
                        {
                            str = "";
                            getline(fin, str);      // ��������� ������ �� ������� ��������� � ���������� str
                            getline(finRatings, str2);
                            getline(finNames, strnames);
                            getline(finPatronymics, strpatronymics);
                            getline(finKeys, strKeys);  // ��������� ������ �� ����� � �������� ��������� � ������

                            pupil[pupilnumber] = str;       // ��������� ������ � ��������� � ������
                            allratings[pupilnumber] = str2; // �� ������� ���������
                            keys[pupilnumber] = strKeys;    // � ������� ��������� � ������
                            names[pupilnumber] = strnames;  // �� ������
                            patronymics[pupilnumber] = strpatronymics;  // �� ��������

                            (*ppupilnumber)++;              // ������� ���������� ���������
                        }
                        string buffer;
                        string ratingsbuffer;
                        string keysbuffer;
                        string namesbuffer;
                        string patronymicsbuffer;

                        int nameindex;
                        int quantitysymbolsfirst;
                        int quantitysymbolssecond;      // ���������� �������� � ������ ������������ ���������
                        int necessaryquantitysymbols;
                        bool less = false;
                        fout << endl;
                        if (a == 4) cout << endl;

                        // ���������� �� ��������
                        for (int i = 0; i < pupilcount; i++)     // ���� i ������ ���������� ���������
                        {
                            string minname = pupil[i];          // ������ ������� = ����������� �� ��������
                            quantitysymbolsfirst = pupil[i].length();
                            char minchar = pupil[i][0];         // ������ ����� ������� �������� = ����������� �� ��������
                            nameindex = i;                      // ������ ����� ����� 0

                            string mratings = allratings[i];     // ����������� ������ = 0 ������
                            string mkeys = keys[i];              // ����������� ����� �������� = 0�� ��������
                            string mnames = names[i];
                            string mpatronymics = patronymics[i];

                            for (int j = i + 1; j < pupilcount; j++)    // � ������������ ����� �������� ��������, ���� j ������ ���������� ��������� � ����
                            {
                                quantitysymbolssecond = pupil[j].length();
                                if (quantitysymbolsfirst < quantitysymbolssecond)
                                {
                                    for (int k = 0; k < quantitysymbolsfirst; k++)
                                    {
                                        if (pupil[j][k] < minname[k])      // ���� ������ ����� ���� ������ ������ ���������� ����� ������ ������������, �� ��� � ���� �������� ���������� �����������
                                        {
                                            minchar = pupil[j][0];          // ����������� min ������ ��������
                                            minname = pupil[j];             // ����
                                            mnames = names[j];
                                            mpatronymics = patronymics[j];
                                            mratings = allratings[j];
                                            mkeys = keys[j];
                                            nameindex = j;                  // ������ min ��������
                                            quantitysymbolsfirst = pupil[j].length(); // ������ ��� ������ �����
                                            break;
                                        }
                                        else if (pupil[j][k] > minname[k]) break;
                                    }
                                }
                                else if (quantitysymbolsfirst > quantitysymbolssecond)
                                {
                                    for (int k = 0; k < quantitysymbolssecond; k++)
                                    {
                                        if (pupil[j][k] < minname[k])
                                        {
                                            minchar = pupil[j][0];
                                            minname = pupil[j];
                                            mnames = names[j];
                                            mpatronymics = patronymics[j];
                                            mratings = allratings[j];
                                            mkeys = keys[j];
                                            nameindex = j;
                                            quantitysymbolsfirst = pupil[j].length();
                                            less = false;
                                            break;
                                        }
                                        else if (pupil[j][k] > minname[k])
                                        {
                                            less = false;
                                            break;
                                        }
                                        else if (pupil[j][k] == minname[k]) less = true;
                                    }
                                    if (less)
                                    {
                                        minchar = pupil[j][0];
                                        minname = pupil[j];
                                        mnames = names[j];
                                        mpatronymics = patronymics[j];
                                        mratings = allratings[j];
                                        mkeys = keys[j];
                                        nameindex = j;
                                        quantitysymbolsfirst = pupil[j].length();
                                        less = false;
                                    }
                                }
                                else if (quantitysymbolsfirst == quantitysymbolssecond)
                                {
                                    for (int k = 0; k < quantitysymbolssecond; k++)
                                    {
                                        if (pupil[j][k] < minname[k])
                                        {
                                            minchar = pupil[j][0];
                                            minname = pupil[j];
                                            mnames = names[j];
                                            mpatronymics = patronymics[j];
                                            mratings = allratings[j];
                                            mkeys = keys[j];
                                            nameindex = j;
                                            quantitysymbolsfirst = pupil[j].length();
                                            break;
                                        }
                                        else if (pupil[j][k] > minname[k]) break;
                                    }
                                }
                            }
                            buffer = pupil[i];                   // ����� ��� ���������, ������, ������� ���������(������), �������
                            ratingsbuffer = allratings[i];
                            keysbuffer = keys[i];
                            namesbuffer = names[i];
                            patronymicsbuffer = patronymics[i];

                            pupil[i] = minname;
                            allratings[i] = mratings;
                            keys[i] = mkeys;
                            names[i] = mnames;
                            patronymics[i] = mpatronymics;

                            pupil[nameindex] = buffer;
                            allratings[nameindex] = ratingsbuffer;
                            keys[nameindex] = keysbuffer;
                            names[nameindex] = namesbuffer;
                            patronymics[nameindex] = patronymicsbuffer;

                            fout << keys[i] << "\t";
                            if (a == 4) cout << keys[i] << "\t";

                            if (maxsize > 16 && pupil[i].length() + 5 > 16)
                            {
                                fout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t";
                                fout << allratings[i] << endl;
                                if (a == 4)cout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t";
                                if (a == 4)cout << allratings[i] << endl;
                            }
                            else if (maxsize > 16 && pupil[i].length() + 5 <= 16 && pupil[i].length() + 5 > 7)
                            {
                                fout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t\t";
                                fout << allratings[i] << endl;
                                if (a == 4)cout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t\t";
                                if (a == 4)cout << allratings[i] << endl;
                            }
                            else if (maxsize > 16 && pupil[i].length() + 5 <= 7)
                            {
                                fout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t\t\t";
                                fout << allratings[i] << endl;
                                if (a == 4)cout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t\t\t";
                                if (a == 4) cout << allratings[i] << endl;
                            }
                            else if (maxsize <= 16 && pupil[i].length() + 5 <= 16 && pupil[i].length() + 5 > 7)
                            {
                                fout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t";
                                fout << allratings[i] << endl;
                                if (a == 4)cout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t";
                                if (a == 4)cout << allratings[i] << endl;
                            }
                            else if (maxsize <= 16 && pupil[i].length() + 5 <= 7)
                            {
                                fout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t\t";
                                fout << allratings[i] << endl;
                                if (a == 4)cout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t\t";
                                if (a == 4)cout << allratings[i] << endl;
                            }
                            else if (maxsize <= 7)
                            {
                                fout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t";
                                fout << allratings[i] << endl;
                                if (a == 4)cout << pupil[i] << " " << names[i][0] << "." << patronymics[i][0] << ".\t";
                                if (a == 4)cout << allratings[i] << endl;
                            }
                        }
                        cout << endl;
                        delete[] keys;
                        delete[] pupil;
                        delete[] allratings;
                        delete[] names;
                        delete[] patronymics;
                    }
                    fin.close();
                    finRatings.close();
                    finKeys.close();
                    finNames.close();
                    finPatronymics.close();
                    fout.close();

                    if (a == 5)
                    {
                        string str;
                        fin.open(path);
                        fout.open(bufferpathStudents, ofstream::app);
                        string* infostring = new string[pupilcount + 1];
                        if (!fin.is_open() || !fout.is_open()) cout << "������ �������� �����" << endl;
                        else
                        {
                            for (int i = 0; i < pupilcount + 1; i++)
                            {
                                str = "";
                                getline(fin, str);
                                infostring[i] = str;
                            }
                            fout << infostring[0] << endl;
                            cout << infostring[0] << endl;

                            for (int i = pupilcount; i > 0; i--)
                            {
                                fout << infostring[i] << endl;
                                cout << infostring[i] << endl;
                            }
                            cout << endl;
                        }
                        delete[] infostring;
                        fin.close();
                        fout.close();

                        remove("myFile.txt");
                        rename("BuffStud.txt", "myFile.txt");
                        remove("BuffStud.txt");
                    }
                    fin.open(path);
                    fout.open(pathData + bufferpath);
                    if (!fin.is_open() || !fout.is_open()) cout << "������ �������� �����" << endl;
                    else
                    {
                        fout << fin.rdbuf();
                        cout << "���� ������ �� ������� �����" << endl << endl;
                    }
                    fout << fin.rdbuf();
                }
                fin.close();
                fout.close();
            }
            else if (a == 6)
            {
                fout.open(pathStudents, ofstream::app);    // � ������ ������ ������� ����, app - append - ��������, ��������� ����������� ����� ������ �� ������� ������
                ratingsfout.open(pathRatings, ofstream::app);
                finKeys.open(pathKeys);
                foutKeys.open(pathKeys, ofstream::app);
                foutnames.open(pathNames, ofstream::app);
                foutpatronymics.open(pathPatronymics, ofstream::app);

                if (!fout.is_open() || !ratingsfout.is_open() || !finKeys.is_open() || !foutKeys.is_open() || !foutnames.is_open() || !foutpatronymics.is_open()) cout << "������ �������� �����" << endl;
                else
                {
                    string allsubjects;     // ���������� ��� ������ � ������� ���������, �� ������� ���������� ��������
                    int subjectscount = 0;
                    fin.open(pathLessons);
                    if (!fin.is_open()) cout << "������ �������� �����" << endl;
                    else
                    {
                        string str;
                        while (!fin.eof())
                        {
                            str = "";
                            getline(fin, str);
                            allsubjects = allsubjects + str + " ";
                            subjectscount++;
                        }
                    }
                    fin.close();
                    string newsurname;
                    string newname;
                    string newpatronumic;
                    string newpupilratings;
                    string keystr = "";
                    int lastkey = 0;
                    wordsize = 0;

                    cout << "������� ������� ��������: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    newsurname = enteredword2;
                    // cin >> newsurname;
                    while (newsurname.length() > 19)
                    {
                        cout << "������� �������� ������ ���� ������ 19 ��������. ������� ������� ��� ���: ";
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        newsurname = enteredword2;
                        // cin >> newsurname;
                    }
                    cout << "\n������� ��� ��������: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    newname = enteredword2;
                    // cin >> newname;
                    cout << "\n������� �������� ��������: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    newpatronumic = enteredword2;
                    // cin >> newpatronumic;

                    // �������� ������ ������ ��������
                    while (!finKeys.eof()) getline(finKeys, keystr);     // ������ ��������� ������ �� �����������

                    lastkey = stoi(keystr) + 1;   // ���������� string � int
                    cout << "\n��� ���� ���������: " << allsubjects << "������� ������ ��������: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    newpupilratings = enteredword2;
                    // cin >> newpupilratings;

                    wordsize = newpupilratings.length();			// ��������� ���������� �������� � ������
                    bool err = false;						        // ���� err true, �� ��������� ����� �����������
                    const char* str = newpupilratings.c_str();	    // �������� ������ � ������� char, ��� �� ����� �������� � ��������  isdigit
                    for (int i = 0; i < subjectscount; i++)
                    {
                        if (wordsize > subjectscount || !isdigit(str[i]))
                        {
                            err = true;
                            break;
                        }
                        if (str[i] - 48 < 0 || str[i] - 48 > 5)
                        {
                            err = true;
                            break;
                        }
                    }

                    while (err)
                    {
                        cout << "\n�� ����� ������������ ��������: " << newpupilratings << endl
                            << "���������� ������ � ������� ���������� ���������, ������ ������������� ������ �� 0 �� 5" << endl;
                        cout << "������� ������ �������� �� ��������� " << allsubjects << ": ";
                        checkinput();
                        if (enteredvalue2 == 27) break;
                        newpupilratings = enteredword2;
                        // cin >> newpupilratings;
                        wordsize = newpupilratings.length();
                        err = false;
                        for (int i = 0; i < subjectscount; i++)
                        {
                            if (wordsize > subjectscount || !isdigit(str[i]))
                            {
                                err = true;
                                break;
                            }
                            if (str[i] - 48 < 0 || str[i] - 48 > 5)
                            {
                                err = true;
                                break;
                            }
                        }
                    }
                    if (enteredvalue2 == 27) continue;

                    foutKeys << endl << lastkey;
                    fout << endl << newsurname;
                    foutnames << endl << newname;
                    foutpatronymics << endl << newpatronumic;

                    pupilcount++;
                    ratingsfout << endl;
                    for (int i = 0; i < subjectscount; i++)
                    {
                        ratingsfout << newpupilratings[i];
                        if (i < subjectscount - 1) ratingsfout << "   ";
                    }
                }
                fout.close();
                ratingsfout.close();
                finKeys.close();
                foutKeys.close();
                foutnames.close();
                foutpatronymics.close();
            }
            else if (a == 7)
            {
                fin.open(pathStudents);                 // ��������� �������             
                finRatings.open(pathRatings);           // � ������ �� ������������ ������
                fout.open(bufferpathStudents);          // ��������� ��������� ���� ��� ������ ��������� ��� ����������
                ratingsfout.open(bufferpathRatings);    // � ������ ��� ����� ��������
                finKeys.open(pathKeys);
                foutKeys.open(bufferpathKeys);
                finNames.open(pathNames);
                foutnames.open(bufferpathNames);
                finPatronymics.open(pathPatronymics);
                foutpatronymics.open(bufferpathPatronymics);

                if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open() || !finKeys.is_open() || !foutKeys.is_open() || !finNames.is_open() || !foutnames.is_open() || !finPatronymics.is_open() || !foutpatronymics.is_open())  // ��������, ��������� �� �����
                {
                    cout << "������ �������� �����" << endl;
                    finStudents.close();
                    fin.close();
                    finRatings.close();
                    fout.close();
                    ratingsfout.close();
                    finKeys.close();
                    foutKeys.close();
                    finNames.close();
                    foutnames.close();
                    finPatronymics.close();
                    foutpatronymics.close();
                }
                else
                {
                    string str = "";     // � ��� ������ ������������ ������ �� ������
                    string strlast = "";
                    string* surnames = new string[pupilcount];
                    string* numes = new string[pupilcount];
                    string str2;
                    string strKeys;
                    string strStudent;
                    string penultimateword = "";
                    string penultimateword2 = "";
                    string enteredkey;
                    string allpupils;
                    string strname;
                    string strpatronymic;
                    int countPupilsRatings = 0;
                    string chousenvalue;
                    bool badenteredword = true;
                    string value;

                    // ��������� ������� ���� ��������� � ������ surnames[i]
                    for (int i = 0; !fin.eof(); i++)
                    {
                        str = "";
                        getline(fin, str);
                        surnames[i] = str;
                    }
                    fin.close();
                    // �������� ��� ������ ��������� � ������
                    for (int i = 0; !finKeys.eof(); i++)
                    {
                        str = "";
                        getline(finKeys, str);
                        numes[i] = str;
                    }
                    finKeys.close();

                    cout << "�������� ����� ��������, ���������� � ������� ������ �������: " << endl;
                    for (int i = 0; i < pupilcount; i++) cout << numes[i] << " " << surnames[i] << endl;
                    cout << "������� �����: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    enteredkey = enteredword2;
                    //cin >> enteredkey;


                    fin.open(pathStudents);
                    for (int i = 0; !fin.eof(); i++)        // ��������� ��� ��������, ������� ������������ ���������� ���� ���� ���� �����������
                    {
                        str = "";
                        getline(fin, str);
                        if (enteredkey == numes[i])
                        {
                            strStudent = surnames[i];
                            badenteredword = false;
                            break;
                        }
                    }

                    fin.close();
                    fin.open(pathStudents);

                    while (badenteredword)  // �������� �� ����������� ������ ��������
                    {
                        cout << "������ ��������: " << enteredkey << " ���" << endl << "���������� ��� ���: ";
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        enteredkey = enteredword2;
                        // cin >> enteredkey;
                        for (int i = 0; !fin.eof(); i++)
                        {
                            getline(fin, str);
                            if (enteredkey == numes[i])
                            {
                                strStudent = surnames[i];
                                badenteredword = false;
                                break;
                            }
                        }
                        fin.close();
                        fin.open(pathStudents);
                    }

                    delete[] numes;
                    delete[] surnames;
                    fin.close();

                    finKeys.open(pathKeys);
                    while (!finKeys.eof()) // ��� ������ �������� �� ����� ������� ����� ����������� �������� ��� �������� ������ ����������
                    {
                        getline(finKeys, strlast);
                    }
                    finKeys.close();
                    finKeys.open(pathKeys);
                    while (!finKeys.eof()) // ��� ������ �������� �� ����� ������� ����� ����������� �������� ��� �������� ������ ����������
                    {
                        getline(finKeys, penultimateword2);
                        getline(finKeys, penultimateword);
                    }
                    if (penultimateword > penultimateword2) penultimateword = penultimateword2;
                    finKeys.close();
                    

                    finKeys.close();
                    finKeys.open(pathKeys);


                    ///////////////////////////////////////////////////////// Problem is choise
                    cout << "�� ������������� ������ ������� ������ � ��������: " << strStudent << endl;
                    cout << "y - ��, n - ���";

                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    value = enteredword2;
                    // cin >> value;
                    cout << endl;
                    countPupilsRatings = 0;
                    fin.open(pathStudents);
                    while (value != "y" && value != "n")      // �������� �� ������������
                    {
                        cout << "�������� ����, ��������� �������" << endl;
                        cout << "y -��, n - ���";
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        value = enteredword2;
                        // cin >> value;
                    }
                    if (value == "y")
                    {
                        while (!fin.eof())
                        {
                            countPupilsRatings++;
                            str2 = "";
                            str = "";
                            getline(fin, str);          // ��������� ������� ���������
                            getline(finRatings, str2);  // � ������
                            getline(finKeys, strKeys);  // � ������ ���������
                            getline(finNames, strname); // � �����
                            getline(finPatronymics, strpatronymic); // � ��������

                            if (strKeys != enteredkey && pupilcount != countPupilsRatings && ((strKeys != penultimateword) || ((strKeys == penultimateword) && (enteredkey != strlast))))
                            {
                                fout << str << endl;
                                ratingsfout << str2 << endl;
                                foutKeys << strKeys << endl;
                                foutnames << strname << endl;
                                foutpatronymics << strpatronymic << endl;
                            }
                            else if (strKeys != enteredkey && pupilcount == countPupilsRatings)
                            {
                                fout << str;
                                ratingsfout << str2;
                                foutKeys << strKeys;
                                foutnames << strname;
                                foutpatronymics << strpatronymic;
                            }
                            else if (strKeys != enteredkey && strKeys == penultimateword && enteredkey == strlast)
                            {
                                fout << str;
                                ratingsfout << str2;
                                foutKeys << strKeys;
                                foutnames << strname;
                                foutpatronymics << strpatronymic;
                            }
                        }

                        fin.close();
                        finRatings.close();
                        fout.close();
                        ratingsfout.close();
                        finKeys.close();
                        foutKeys.close();
                        finNames.close();
                        foutnames.close();
                        finPatronymics.close();
                        foutpatronymics.close();

                        remove("Students.txt");                     // ������� ����������� 5 ������
                        remove("Ratings.txt");
                        remove("Keys.txt");
                        remove("Names.txt");
                        remove("Patronymics.txt");

                        rename("BuffStud.txt", "Students.txt");     // �������� ����� 5 ������ � ��������������� �� � ������ ��������
                        rename("BuffRatings.txt", "Ratings.txt");
                        rename("BufferKeys.txt", "Keys.txt");
                        rename("BufferNames.txt", "Names.txt");
                        rename("BufferPatronymics.txt", "Patronymics.txt");

                        remove("BuffStud.txt");                     // ������� �������� ����� 5�� ������
                        remove("BuffRatings.txt");
                        remove("BufferKeys.txt");
                        remove("BufferNames.txt");
                        remove("BufferPatronymics.txt");
                    }
                    else
                    {
                        system("cls");
                        cout << "������ �������� ������ ��������" << endl<<endl;
                        fin.close();
                        finRatings.close();
                        fout.close();
                        ratingsfout.close();
                        finKeys.close();
                        foutKeys.close();
                        finNames.close();
                        foutnames.close();
                        finPatronymics.close();
                        foutpatronymics.close();
                    }

                }
            }
            else if (a == 8)
            {
                int countfineof = 0;
                string lesson;
                string enteredfulllesson;

                finLessons.open(pathLessons);
                fout.open(pathLessons, ofstream::app);              // ��������� ���� � ����������
                ratingsfout.open(bufferpathRatings);                // ��������� �������� ���� � �������� ��� ������
                finRatings.open(pathRatings);                       // ��������� ���� � �������� ��� ������ 
                fin.open(pathStudents);                             // ��������� ���� �� ���������� ��� ����������� ����� ��� ������� �������� �������� ������ �� ������ ��������
                foutSubjects.open(pathSubjects, ofstream::app);

                if (!finLessons.is_open() || !fout.is_open() || !ratingsfout.is_open() || !fin.is_open() || !finRatings.is_open() || !fin.is_open() || !foutSubjects.is_open())
                {
                    cout << "������ �������� �����" << endl;
                    finLessons.close();
                    fout.close();
                    ratingsfout.close();
                    finRatings.close();
                    fin.close();
                    foutSubjects.close();
                }
                else
                {
                    // ���������� ��������
                    string subject;
                    cout << "������� ����������� �������� (3 �������): ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    subject = enteredword2;
                    // cin >> subject;
                    // �������� �������� ������
                    bool err = false;
                    if (subject.length() != 3) err = true;

                    while (err)
                    {
                        cout << "���������� �������� �� ����� 3.\n���������� ��� ���: ";
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        subject = enteredword2;
                        // cin >> subject;
                        if (subject.length() == 3) err = false;
                    }

                    while (!finLessons.eof())
                    {
                        getline(finLessons, lesson);
                        if (subject == lesson)
                        {
                            err = true;
                            break;
                        }
                    }
                    finLessons.close();
                    finLessons.open(pathLessons);
                    while (err)
                    {
                        cout<< "���������� �������� �� ����� 3 ��� ����� �������: " << subject << " ��� ����, ��������� �������:\n";
                        err = false;
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        subject = enteredword2;
                        // cin >> subject;
                        while (!finLessons.eof())
                        {
                            getline(finLessons, lesson);
                            if (subject == lesson || subject.length() != 3)
                            {
                                err = true;
                                break;
                            }
                        }
                        finLessons.close();
                        finLessons.open(pathLessons);
                    }
                    finLessons.close();

                    // ���������� ����������� ������������ ���������� ��������
                    cout << "������� ����������� ������������: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    enteredfulllesson = enteredword2;

                    // std::cin.ignore(INT_MAX, '\n');
                    // getline(cin, enteredfulllesson);

                    string pupilratings;
                    string newpupilratings;
                    string pupil;
                    string* arrratings = new string[pupilcount];

                    while (!fin.eof())
                    {
                        countfineof++;
                        pupilratings = "";
                        pupil = "";
                        newpupilratings = "";
                        getline(fin, pupil);
                        cout << "������� ������ ��������: " << pupil;
                        checkinput();
                        if (enteredvalue2 == 27) break;
                        newpupilratings = enteredword2;
                        // cin >> newpupilratings;

                        while (newpupilratings != "0" && newpupilratings != "1" && newpupilratings != "2" && newpupilratings != "3" && newpupilratings != "4" && newpupilratings != "5")
                        {
                            cout << "�� ����� ������������ ������ ��� ������ �� ������: " << newpupilratings << endl;
                            cout << "��������� �������: ";
                            checkinput();
                            if (enteredvalue2 == 27) continue;
                            newpupilratings = enteredword2;
                            // cin >> newpupilratings;
                        }

                        // getline(finRatings, pupilratings);      // ��������� ������ ��� ������� ��������
                        arrratings[countfineof - 1] = newpupilratings;
                    }
                    if (enteredvalue2 == 27) continue;
                    fin.close();
                    fin.open(pathStudents);
                    countfineof = 0;
                    while (!fin.eof())
                    {
                        getline(finRatings, pupilratings);      // ��������� ������ ��� ������� ��������
                        getline(fin, pupil);        // ��� ����, ��� �� ������� �� ��� ����������
                        countfineof++;
                        if (pupilcount != countfineof) ratingsfout << pupilratings + "   " + arrratings[countfineof - 1] << endl;     // ������� ������ � �������� ���� � ���������� ����� ������
                        else ratingsfout << pupilratings + "   " + arrratings[countfineof - 1];
                    }

                    ratingsfout.close();
                    finRatings.close();
                    fin.close();
                    remove("Ratings.txt");
                    rename("BuffRatings.txt", "Ratings.txt");
                    fout << endl << subject;
                    foutSubjects << endl << enteredfulllesson;
                    foutSubjects.close();
                    fout.close();
                    delete[] arrratings;
                }
            }
            else if (a == 9)
            {
                string ratings;
                string str;
                string fulllesson;
                string lessons = "";
                string enteredlesson = "";
                string result = "";
                int strcount = 0;
                int deletedchars = 0;
                int count = 0;
                bool good = false;
                bool deletelaststr = false;

                fin.open(pathLessons);
                finRatings.open(pathRatings);
                fout.open(bufferpathLessons);
                ratingsfout.open(bufferpathRatings);
                finSubjects.open(pathSubjects);
                foutSubjectsbuf.open(pathbuffSubjects);

                if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open() || !finSubjects.is_open() || !foutSubjectsbuf.is_open())
                {
                    cout << "������ �������� �����" << endl;
                    fin.close();
                    finRatings.close();
                    fout.close();
                    ratingsfout.close();
                    finSubjects.close();
                    foutSubjectsbuf.close();
                }
                else
                {
                    while (!fin.eof())
                    {
                        str = "";
                        getline(fin, str);
                        lessons = lessons + str + " ";
                    }
                    fin.close();
                    fin.open(pathLessons);

                    strcount = 0;
                    cout << "������� ������� �� ������������ � ����: " << lessons;      // ���� ������������ ��������
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    enteredlesson = enteredword2;
                    // cin >> enteredlesson;

                    while (!fin.eof())
                    {
                        strcount++;
                        str = "";
                        getline(fin, str);
                        if (enteredlesson == str)
                        {
                            good = true;
                            if (strcount == subjectscount) deletelaststr = true;
                            break;
                        }
                    }
                    fin.close();
                    fin.open(pathLessons);
                    strcount = 0;

                    while (!good)
                    {
                        strcount = 0;
                        cout << "������ �������� ���, ��������� �������.\n������� ������� �� ������������ � ����: ";
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        enteredlesson = enteredword2;
                        // cin >> enteredlesson;

                        while (!fin.eof())
                        {
                            strcount++;
                            str = "";
                            getline(fin, str);
                            if (enteredlesson == str)
                            {
                                if (strcount == subjectscount) deletelaststr = true;
                                good = true;
                                break;
                            }
                        }
                        fin.close();
                        fin.open(pathLessons);
                    }

                    // ��������, ������������� �� ����� ������� ������ 
                    string choise;
                    cout << "�� ������������� ������ ������� ���������� � �������� " << enteredlesson << "?" << endl;
                    cout << "y - ��, n - ���";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    choise = enteredword2;
                    // cin >> choise;
                    cout << endl;
                    while (choise != "y" && choise != "n")      // �������� �� ������������
                    {
                        cout << "�������� ����, ��������� �������" << endl;
                        cout << "y -��, n - ���" << endl;
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        choise = enteredword2;
                        // cin >> choise;
                    }
                    if (choise == "n")
                    {
                        fin.close();
                        finRatings.close();
                        fout.close();
                        ratingsfout.close();
                        finSubjects.close();
                        foutSubjectsbuf.close();
                        continue;
                    }

                    // �������� ����������� �������� ��� �������� ������������
                    strcount = 0;
                    while (!fin.eof())
                    {
                        str = "";
                        fulllesson = "";
                        getline(fin, str);
                        getline(finSubjects, fulllesson);

                        strcount++;                 // ����������� ������� ��������� �� ����� ������
                        if (enteredlesson != str)  // ���� �������� ������� �� ����� �� ������ �� ���������� � ����
                        {
                            if (strcount != subjectscount && !deletelaststr)
                            {
                                fout << str << endl;    // � ����� ���� �������� ��� �������� ���������, ����� ����, ������� ���� �������   
                                foutSubjectsbuf << fulllesson << endl;
                            }
                            else if (strcount != subjectscount && deletelaststr && strcount != subjectscount - 1)
                            {
                                fout << str << endl;
                                foutSubjectsbuf << fulllesson << endl;
                            }
                            else if (strcount != subjectscount && deletelaststr && strcount == subjectscount - 1)
                            {
                                fout << str;
                                foutSubjectsbuf << fulllesson;
                            }
                            else
                            {
                                fout << str;
                                foutSubjectsbuf << fulllesson;

                            }
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
                            if (i == deletedchars || i == deletedchars - 1 || i == deletedchars - 2 || i == deletedchars - 3) {} // ���� � ������ �� ������ �������
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

                    foutSubjectsbuf.close();
                    finSubjects.close();
                    remove("Subjects.txt");
                    rename("BuffSubjects.txt", "Subjects.txt");
                    remove("BuffSubjects.txt");

                    cout << endl;
                }
            }
            else if (a == 10)
            {
                finLessons.open(pathLessons);
                finSubjects.open(pathSubjects);
                string lesson;
                string subject;
                if (!finLessons.is_open() && !finSubjects.is_open()) cout << "������ �������� �����" << endl;
                else
                {
                    cout << "������ � ���������" << endl;

                    while (!finLessons.eof() && !finSubjects.eof())
                    {
                        lesson = "";
                        subject = "";
                        getline(finLessons, lesson);
                        getline(finSubjects, subject);
                        cout << lesson << " - " << subject << endl;
                    }
                    cout << endl << endl;
                }
                finLessons.close();
                finSubjects.close();
            }
            else if (a == 11)
            {
                string lesson;
                string fulllesson;
                string enteredfulllesson = "";
                string subj;
                bool equal = false;
                int lessonscount = 0;
                int lessonscount2 = 0;
                finLessons.open(pathLessons);
                finSubjects.open(pathSubjects);
                foutSubjects.open(pathbuffSubjects);

                if (!finLessons.is_open() || !finSubjects.is_open() || !foutSubjects.is_open())
                {
                    cout << "������ �������� �����" << endl;
                    finLessons.close();
                    finSubjects.close();
                    foutSubjects.close();
                }
                else
                {
                    while (!finLessons.eof())
                    {
                        getline(finLessons, lesson);
                        cout << lesson << endl;
                    }
                    finLessons.close();
                    finLessons.open(pathLessons);
                    cout << "������� ������������ �������� �� ������������, ����������� ��� �������� ������ ��������: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    subj = enteredword2;
                    // cin >> subj;

                    while (!finLessons.eof())
                    {
                        getline(finLessons, lesson);
                        lessonscount++;
                        if (lesson == subj)
                        {
                            equal = true;
                            break;
                        }
                    }
                    finLessons.close();

                    while (!equal)
                    {
                        finLessons.open(pathLessons);
                        lessonscount = 0;
                        equal = false;
                        cout << "����� ������������ ���. ��������� �������: ";
                        checkinput();
                        if (enteredvalue2 == 27) break;
                        subj = enteredword2;
                        // cin >> subj;
                        while (!finLessons.eof())
                        {
                            getline(finLessons, lesson);
                            lessonscount++;
                            if (lesson == subj)
                            {
                                equal = true;
                                break;
                            }
                        }
                        finLessons.close();
                    }
                    if (enteredvalue2 == 27) continue;

                    cout << "������� ����������� ������������: ";
                    // cin.clear();
                    //std::cin.ignore(INT_MAX, '\n');
                    //getline(cin, enteredfulllesson);
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    enteredfulllesson = enteredword2;

                    while (!finSubjects.eof())
                    {
                        lessonscount2++;
                        getline(finSubjects, fulllesson);
                        if (lessonscount2 == lessonscount && lessonscount2 != subjectscount) foutSubjects << enteredfulllesson << endl;
                        else if (lessonscount2 == lessonscount && lessonscount2 == subjectscount) foutSubjects << enteredfulllesson;
                        else if (lessonscount2 != lessonscount && lessonscount2 != subjectscount) foutSubjects << fulllesson << endl;
                        else if (lessonscount2 != lessonscount && lessonscount2 == subjectscount) foutSubjects << fulllesson;
                    }
                    finLessons.close();
                    finSubjects.close();
                    foutSubjects.close();

                    remove("Subjects.txt");
                    rename("BuffSubjects.txt", "Subjects.txt");
                    remove("BuffSubjects.txt");
                    cout << endl << endl;
                }
            }
            else if (a == 12)
            {
                finKeys.open(pathKeys);
                finRatings.open(pathRatings);
                finLessons.open(pathLessons);
                finStudents.open(pathStudents);
                ratingsfout.open(bufferpathRatings);

                if (!finKeys.is_open() || !finRatings.is_open() || !finLessons.is_open() || !finStudents.is_open() || !ratingsfout.is_open())
                {
                    cout << "������ �������� �����" << endl;
                    finKeys.close();
                    finRatings.close();
                    finLessons.close();
                    finStudents.close();
                    ratingsfout.close();
                }
                else
                {
                    string studentnum;
                    string ratingstr;
                    string newratingstr;
                    string ratingstrforchange;
                    string lesson;
                    string lessonforchange;
                    string enteredlesson;
                    string studentsurname;
                    string foundsurname;
                    char studentvalue;
                    int ratingstrnum = 0;
                    int ratingstrnumforchange;
                    int lessonnumforchange;

                    int lessonnum = 0;
                    bool found = false;

                    // �������� ������ �������� �� ������������� ��������
                    // ���� ������ ��������, ��������, ������ ������ � �������� ���������� ��������
                    string enteredword;         // ���������� ��� ������ ��������
                    bool foundoverlap = false;  // ���� ����� �������� ������������� ����������
                    cout << "������� ����� ��������: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    enteredword = enteredword2;
                    // cin >> enteredword;

                    while (!finKeys.eof())
                    {
                        ratingstrnum++;
                        getline(finKeys, studentnum);
                        getline(finRatings, ratingstr);
                        getline(finStudents, studentsurname);

                        if (studentnum == enteredword)         // ������� ������� � ��������, ������� ������������� ���������� �������� (��� ������)
                        {
                            ratingstrnumforchange = ratingstrnum;
                            ratingstrforchange = ratingstr;     // � ���������� �� � ����������
                            foundsurname = studentsurname;
                            found = true;
                            break;
                        }
                    }
                    finKeys.close();
                    finRatings.close();
                    finStudents.close();

                    ratingstrnum = 0;
                    finKeys.open(pathKeys);
                    finRatings.open(pathRatings);
                    finStudents.open(pathStudents);
                    while (!found)
                    {
                        cout << "��� ������ ������ ��������: " << enteredword << endl;
                        cout << "��������� �������: ";
                        checkinput();
                        if (enteredvalue2 == 27) break;
                        enteredword = enteredword2;
                        // cin >> enteredword;
                        while (!finKeys.eof())
                        {
                            ratingstrnum++;
                            getline(finKeys, studentnum);
                            getline(finRatings, ratingstr);
                            getline(finStudents, studentsurname);

                            if (studentnum == enteredword)
                            {
                                ratingstrnumforchange = ratingstrnum;
                                ratingstrforchange = ratingstr;
                                foundsurname = studentsurname;
                                found = true;
                                break;
                            }
                        }
                    }
                    if (enteredvalue2 == 27) continue;
                    finKeys.close();
                    finRatings.close();
                    finStudents.close();

                    // ���� ��������, � �������� �� ����� ������ ������ ��������
                    while (!finLessons.eof())
                    {
                        getline(finLessons, lesson);
                        cout << lesson << endl;
                    }
                    finLessons.close();

                    cout << "������� ������� �� ������������, ��� �������� ������ �������� ������: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    enteredlesson = enteredword2;
                    // cin >> enteredlesson;

                    finLessons.open(pathLessons);
                    found = false;

                    while (!finLessons.eof())
                    {
                        lessonnum++;
                        getline(finLessons, lesson);

                        if (lesson == enteredlesson)
                        {
                            lessonnumforchange = lessonnum;
                            lessonforchange = lesson;
                            found = true;
                            break;
                        }
                    }
                    finLessons.close();


                    finLessons.open(pathLessons);
                    lessonnum = 0;
                    while (!found)
                    {
                        cout << "��� ������ ��������: " << enteredlesson<<endl;
                        cout << "��������� �������: ";
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        enteredlesson = enteredword2;
                        // cin >> enteredlesson;
                        while (!finLessons.eof())
                        {
                            lessonnum++;
                            getline(finLessons, lesson);

                            if (lesson == enteredlesson)
                            {
                                lessonnumforchange = lessonnum;
                                lessonforchange = lesson;
                                found = true;
                                break;
                            }
                        }
                    }

                    // ���� ������, ������� � ���� ��������� ������ ������� 
                    cout << "������� ����� ������ ��� ��������: " << enteredlesson << " �������� � ��������: " << foundsurname << " � �������: " << enteredword;
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    studentvalue = enteredword2[0];
                    // cin >> studentvalue;

                    while (studentvalue != '0' && studentvalue != '1' && studentvalue != '2' && studentvalue != '3' && studentvalue != '4' && studentvalue != '5')
                    {
                        cout << "�� ����� ������������ ������ ��� ������ �� ������: " << studentvalue << endl;
                        cout << "��������� �������: ";
                        checkinput();
                        if (enteredvalue2 == 27) break;
                        studentvalue = enteredword2[0];
                        //cin >> studentvalue;
                    }
                    if (enteredvalue2 == 27) continue;

                    // ��������� ���������� �� ����� � �������� � ��������� � �������� ���� ���������� ����� � ��������
                    finRatings.open(pathRatings);
                    ratingstrnum = 0;

                    while (!finRatings.eof())
                    {
                        ratingstrnum++;
                        getline(finRatings, ratingstr);
                        // cout << ratingstr << endl;

                        if (ratingstrnum != ratingstrnumforchange) // ������� ������� � ��������, ������� ������������� ���������� �������� (��� ������)
                        {
                            if (ratingstrnum != pupilcount)  ratingsfout << ratingstr << endl;
                            else ratingsfout << ratingstr;
                        }
                        else
                        {
                            for (int i = 0; i < ratingstr.length(); i++)
                            {
                                if (i == 4 * (lessonnumforchange - 1)) newratingstr += studentvalue;
                                else newratingstr += ratingstr[i];
                            }
                            if (ratingstrnum != pupilcount) ratingsfout << newratingstr << endl;
                            else ratingsfout << newratingstr;
                        }
                    }
                    finRatings.close();
                    ratingsfout.close();
                    finLessons.close();

                    remove("Ratings.txt");
                    rename("BuffRatings.txt", "Ratings.txt");
                    remove("BuffRatings.txt");
                }
            }
            else if (a == 13)
            {
                cout << endl << endl << endl
                    << "  1 - \"������� ������\". ����� ������� ������ ��������� � �� ������ �� ������� �� ���� ���������;" << endl
                    << "  2 - \"������������ ���� � �������\". ����� ����������� ���� MyFile.txt �� ������� ����� �� ������� ���������" << endl
                    << "� �� �������� �� ������� �� ���������;" << endl
                    << "  3 -  \"������� ������� �������������� ������ �������� �� �������\". ����� ����� ������ �������� ����� ��������" << endl
                    << "������� �������������� ���� ��� ������. ���� ������ �� �������� ����� ����, �� ����� ������� ����������� �� ��������;" << endl
                    << "  4 - \"������������ ���� �� ���������� � �� ��������, ���������������� �� �������� �� � �� � � ������� ������" << endl
                    << "�� �����\". �������� ���������� �������� 2, �� ����������� ���������� ��������� �� �������� �� � �� �;" << endl << endl
                    << "  5 - \"������������ ���� �� ���������� � �� ��������, ���������������� �� �������� �� � �� � � ������� ������" << endl
                    << "�� �����\". �������� ���������� �������� 4, �� ����������� ���������� ��������� �� �������� �� � �� �;" << endl
                    << "  6 - \"�������� �������� � ��� ������ � ���� ������\". ���������� �������� �������, ���, ��������, ������ ��������." << endl
                    << "����������� ������ ��� ��������, � ������� ���������� ���������. ��������:" << endl
                    << "��� �������� �������� ���������� ������ ������ 4 5 4 5 �� ��������� ��������� Rus Mat Lit Phy ��������������." << endl
                    << "������ Sidorov, ���� Enter, ������ 4545, ���� Enter." << endl
                    << "���� �� ������ ��������� ������, ������� �������� 0 (� �������� �� �����������);\n\n"
                    << "  7 - \"������� ������ � ��������\". ��� �������� ������ � ��������, ���������� ������ ��� �����" << endl
                    << "  8 - \"�������� ������ � ��������\". ���������� �������� ������� ��������, ����� ������������ �� 3� ��������," << endl
                    << "����������� ������������, � ����� ��� ������� �� ��������� ������ ������ �� ��������;" << endl
                    << "  9 - \"������� ������ � �������� � ��� ��������� � ��� ����������\". ���������� ������ ������ ������������" << endl
                    << "�������� (3 �������) �� ������������;" << endl << endl
                    << "  10 - \"������� ������ � ������������ ����������� ���������\". ������� ������ � ����� �������: Rus - ������� ����;" << endl
                    << "  11 - \"�������� ���������� ������������ ��� ��������\". ������� ���������� ������ ������������ �� 3� ��������," << endl
                    << "����� ������ ����������� �������� ��������;" << endl
                    << "  12 - \"�������� ������ ��������\". ���� ����������� �������� ���� ������ ������� �� ����������� ��������;" << endl
                    << "  Esc - \"����� � ������� ����\". �������� ������� �������� � ������ � ������� ����;" << endl
                    << "���� ��������� �������, ����������� � ���������� ��������������"<<endl << endl << endl;     
            }
            else exit(0);
        }
    }
    while (true);
}

int showfullinfo(string &enteredvalue)
{
    do
    {
        system("cls");
        if(badword)  cout << "� �� ������ ����, ��� �� ��������: " << enteredvalue << endl << endl;

        cout << "�������� �������� ���� � ������� ��������������� �����" << endl << endl;
        cout << "0 - ������� ���������" << endl
            << "1 - ������� ������" << endl
            << "2 - ������������ ���� � �������" << endl
            << "3 - ������� ������� �������������� ������ �������� �� �������" << endl
            << "4 - ������������ ���� �� ���������� � �� ��������, ���������������� �� �������� �� � �� � � ������� ������ �� �����" << endl
            << "5 - ������������ ���� �� ���������� � �� ��������, ���������������� �� �������� �� � �� � � ������� ������ �� �����" << endl
            << "6 - �������� �������� � ��� ������ � ���� ������" << endl
            << "7 - ������� ������ � ��������" << endl
            << "8 - �������� ������ � ��������" << endl
            << "9 - ������� ������ � �������� � ��� ��������� � ��� ����������" << endl
            << "10 - ������� ������ � ������������ ����������� ���������" << endl
            << "11 - �������� ���������� ������������ ��� ��������" << endl
            << "12 - �������� ������ ��������" << endl
            << "13 - ��������� � ������" << endl << endl
            << "������� ����� ��������: ";
        cin >> enteredvalue;
        wordsize = enteredvalue.length();
        const char* str = enteredvalue.c_str();
        if ((wordsize > 1 || !isdigit(str[0])) && enteredvalue != "10" && enteredvalue != "11" && enteredvalue != "12" && enteredvalue != "13")
        {
            system("cls");
            cout << "� �� ������ ����, ��� �� ��������: " << enteredvalue << endl << endl;
            badword = true;
        }
        else
        {
            badword = false;
            if (enteredvalue == "10") a = 10;
            else if (enteredvalue == "11")  a = 11;
            else if (enteredvalue == "12") a = 12;
            else if (enteredvalue == "13") a = 13;
            else a = enteredvalue[0] - 48;
            return a;
        }
    } while (badword);
}
void checkinput()
{


    enteredvalue2 = 8;
    enteredword2 = "";
    cout << endl;
    do  // ���� ���� ���������
    {
        enteredvalue2 = _getch();
        if (enteredvalue2 == 27)    // ���� = Esc
        {
            system("cls");
            break;      

        }
        else if (enteredvalue2 == 13)  break;  // ���� = Enter
        else if (enteredvalue2 == 8)
        {
            if (enteredword2.length() > 0)
            {
                enteredword2.pop_back();
                cout << "\r";
                for (int i = 0; i < enteredword2.length() + 1; i++) cout << " ";
                cout << "\r";
                cout << enteredword2;
            }
        }
        else
        {
            enteredword2 += enteredvalue2;
            cout << enteredvalue2;
        }

    } while (true);
    cout << endl;

}
void closeallfiles()
{
    fout.close();
    ratingsfout.close();
    foutKeys.close();
    foutSubjects.close();
    foutSubjectsbuf.close();
    foutnames.close();
    foutpatronymics.close();
    fin.close();
    finRatings.close();
    finStudents.close();
    finKeys.close();
    finLessons.close();
    finSubjects.close();
    finNames.close();
    finPatronymics.close();

    remove("BufferKeys.txt");
    remove("BufferLessons.txt");
    remove("BufferNames.txt");
    remove("BufferPatronymics.txt");
    remove("BuffRatings.txt");
    remove("BuffStud.txt");
    remove("BuffSubjects.txt");

}
