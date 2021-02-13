#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        cout << "������������ ������������. ���� ����� ���� � ������� � ������ ��� ����������� � ������ ���������� ��� �������������� � ����� ������ ��������� � �� ������" << endl;
        cout << "�������� �������� ���� � ������� ��������������� �����" << endl << endl;
        string path = "myFile.txt";
        string pathLessons = "Lessons.txt";
        string pathSubjects = "Subjects.txt";
        string pathSubjects3 = "Subjects3.txt";
        string pathStudents = "Students.txt";
        string pathRatings = "Ratings.txt";
        string bufferpath = "C:\\Users\\User\\Desktop\\myFile1.txt";          // ���� �� ������� ����
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
        ifstream finLessons;
        ifstream finSubjects;
        int a = 1;
        int subjectscount = 0;
        int pupilcount = 0;
        int size;
    
    do
    {
        cout<< "0 - ��������� � ������" << endl
            << "1 - ������� ������" << endl
            << "2 - ������������ ���� � �������" << endl
            << "3 - ������� ������� �������������� ������ �������� �� �������" << endl
            << "4 - ������������ ���� �� ���������� � �� ��������, ���������������� �� �������� �� � �� � � ������� ������ �� �����" << endl
            << "5 - ������������ ���� �� ���������� � �� ��������, ���������������� �� �������� �� � �� � � ������� ������ �� �����" << endl
            << "6 - �������� �������� � ��� ������ � ���� ������" << endl
            << "7 - ������� ������ � ��������. ������� ������������� ��������� �������� 1 (������ ����� ��������)" << endl
            << "8 - �������� ������ � ��������" << endl
            << "9 - ������� ������ � �������� � ��� ��������� � ��� ����������" << endl
            << "10 - ������� ������ � ������������ ����������� ���������"<<endl
            << "11 - �������� ���������� ������������ ��� ��������"<<endl
            << "12 - ������� ���������"<<endl<<endl
            << "������� ����� ��������: ";

        int maxsize = 0;
        // �������� �������� ������
        cin >> enteredvalue;                    
        size = enteredvalue.length();			// ��������� ���������� �������� � ������
        bool err = false;						// ���� err true, �� ��������� ����� �����������
        const char* str = enteredvalue.c_str();	// �������� ������ � ������� char, ��� �� ����� �������� � ��������  isdigit
        if ((size > 1 || !isdigit(str[0])) && enteredvalue != "10" && enteredvalue != "11" && enteredvalue != "12") err = true;       // ���� ����������� ���� ������

        if (err)
        {
            system("cls");
            cout << "� �� ������ ����, ��� �� ��������: " << enteredvalue << endl << endl;
        }
        else
        {
            if (size>1 && enteredvalue == "12")
            {
                a = 12;
            }
            else if(size > 1 && enteredvalue == "11")
            {
                a = 11;
            }
            else if (size > 1 && enteredvalue == "10")
            {
                a = 10;
            }
            else a = enteredvalue[0]-48;
            // cout << "�� ����� ���������� �����: " << enteredvalue << endl;
            subjectscount = 0;
            fin.open(pathLessons);       // ������� ���������� ���������
            if (!fin.is_open()) cout << "������ �������� �����" << endl;
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
            system("cls");
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
    
                    if (a == 3)       // ������� �������������� ������ �������� 
                    {
                        string enteredword;
                        bool foundoverlap = false;
                        cout << "������� ����� ��������: ";
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
                                    if (str2[i] == '0') subjectscount--;
                                }
                                cout << "������� �������������� �������� ���� ������ �� ������� �������� c ��������: " << strname << " = " << summ / subjectscount << "\n\n";
                            }
                        }
                        if (!foundoverlap) cout << "�������� ��� �������: " << enteredword << " �� ����������\n";
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
                cout << "���� ������ �� ������� �����" << endl << endl;
                fin.open(path);
                fout.open(bufferpath);
                fout << fin.rdbuf();
                fin.close();
                fout.close();
            }
            else if (a == 4 || a==5)
            {
                fin.open(pathLessons);
                fout.open(path);
                if (!fin.is_open() || !fout.is_open())  // ��������, �������� �� ����
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    //cout << "���� ������� ������!" << endl;
                    string str;
                    if (a == 4)cout << endl << endl; 
                    if (maxsize < 8)
                    {
                        fout << "Num\tSurname\t";
                       if(a == 4) cout << "Num\tSurname\t";
                    }
                    else
                    {
                        
                        fout << "Num\tSurname\t\t";
                        if (a == 4)cout << "Num\tSurname\t\t";
                    }
                    
                    while (!fin.eof())          // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        fout << str << " ";    // ������� ������ �� ���������� str � ���� myFail ������� fout
                        if (a == 4) cout << str << " ";     //****1

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
                    string* pupil = new string[pupilcount];         // ������ ��������� ///////////////////////////////////////////////////////////////////////////////////////////
                    string* allratings = new string[pupilcount];    // ������ ������ ���������  ////////////////////////
                    string* keys = new string[pupilcount];          // ������ ������� ���������
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
                        pupil[pupilnumber] = str;       // ��������� ������ � ��������� � ������
                        allratings[pupilnumber] = str2; // �� ������� ���������
                        keys[pupilnumber] = strKeys;    // � ������� ��������� � ������
                        // cout << allratings[pupilnumber] << endl;

                        (*ppupilnumber)++;              // ������� ���������� ���������
                    }
                    string buffer;
                    string ratingsbuffer;
                    string keysbuffer;

                    int nameindex;
                    int quantitysymbolsfirst;
                    int quantitysymbolssecond;
                    int necessaryquantitysymbols;
                    bool less = false;
                    fout << endl; 
                    if (a == 4) cout << endl;


                    // ���������� �� ��������//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    for (int i = 0; i < pupilcount; i++)     // ���� i ������ ���������� ���������
                    {
                        string minname = pupil[i];          // ������ ������� = ����������� �� ��������
                        quantitysymbolsfirst = pupil[i].length();
                        char minchar = pupil[i][0];         // ������ ����� ������� �������� = ����������� �� ��������
                        nameindex = i;                      // ������ ����� ����� 0

                        string mratings = allratings[i];     // ����������� ������ = 0 ������
                        string mkeys = keys[i];              // ����������� ����� �������� = 0�� ��������


                        for (int j = i + 1; j < pupilcount; j++)    // � ������������ ����� �������� ��������, ���� j ������ ���������� ��������� � ����
                        { 
                            quantitysymbolssecond = pupil[j].length();
                            if (quantitysymbolsfirst< quantitysymbolssecond)
                            {
                                for (int k = 0; k < quantitysymbolsfirst; k++)
                                {
                                    if (pupil[j][k] < minname[k])      // ���� ������ ����� ���� ������ ������ ���������� ����� ������ ������������, �� ��� � ���� �������� ���������� �����������
                                    {
                                        minchar = pupil[j][0];      // ����������� min ������ ��������
                                        minname = pupil[j];         // ����
                                        mratings = allratings[j];
                                        mkeys = keys[j];
                                        nameindex = j;              // ������ min ��������
                                        quantitysymbolsfirst = pupil[j].length(); // ������ ��� ������ �����
                                        break;
                                    }
                                    else if (pupil[j][k] > minname[k])
                                    {
                                        break;
                                    }
                                }

                            }
                            else if (quantitysymbolsfirst > quantitysymbolssecond)
                            {
                                for (int k = 0; k < quantitysymbolssecond; k++)
                                {
                                    if (pupil[j][k] < minname[k])      // ���� ������ ����� ���� ������ ������ ���������� ����� ������ ������������, �� ��� � ���� �������� ���������� �����������
                                    {
                                        minchar = pupil[j][0];      // ����������� min ������ ��������
                                        minname = pupil[j];         // ����
                                        mratings = allratings[j];
                                        mkeys = keys[j];
                                        nameindex = j;              // ������ min ��������
                                        quantitysymbolsfirst = pupil[j].length(); // ������ ��� ������ �����
                                        less = false;
                                        break;
                                    }
                                    else if (pupil[j][k] > minname[k])
                                    {
                                        less = false;
                                        break;
                                    }
                                    else if (pupil[j][k] == minname[k])
                                    {
                                        less = true;
                                    }
                                }
                                if (less)
                                {
                                    minchar = pupil[j][0];      // ����������� min ������ ��������
                                    minname = pupil[j];         // ����
                                    mratings = allratings[j];
                                    mkeys = keys[j];
                                    nameindex = j;              // ������ min ��������
                                    quantitysymbolsfirst = pupil[j].length(); // ������ ��� ������ �����
                                    less = false;
                                }
                            }
                            else if (quantitysymbolsfirst == quantitysymbolssecond)
                            {
                                for (int k = 0; k < quantitysymbolssecond; k++)
                                {
                                    if (pupil[j][k] < minname[k])      // ���� ������ ����� ���� ������ ������ ���������� ����� ������ ������������, �� ��� � ���� �������� ���������� �����������
                                    {
                                        minchar = pupil[j][0];      // ����������� min ������ ��������
                                        minname = pupil[j];         // ����
                                        mratings = allratings[j];
                                        mkeys = keys[j];
                                        nameindex = j;              // ������ min ��������
                                        quantitysymbolsfirst = pupil[j].length(); // ������ ��� ������ �����
                                        break;
                                    }
                                    else if (pupil[j][k] > minname[k])
                                    {
                                        break;
                                    }
                                }
                            }                           
                        }
                        buffer = pupil[i];                   // ����� ��� ��������� � ������
                        ratingsbuffer = allratings[i];
                        keysbuffer = keys[i];

                        pupil[i] = minname;
                        allratings[i] = mratings;
                        keys[i] = mkeys;

                        pupil[nameindex] = buffer;
                        allratings[nameindex] = ratingsbuffer;
                        keys[nameindex] = keysbuffer;

                        fout << keys[i] << "\t";
                        if (a == 4) cout << keys[i] << "\t";            //*****1

                        if (maxsize < 8)
                        {
                            fout << pupil[i] << "\t";
                            fout << allratings[i] << endl;
                            if (a == 4) cout << pupil[i] << "\t";
                            if (a == 4) cout << allratings[i] << endl;
                        }
                        else 
                        {
                            if (pupil[i].length() < 8) 
                            {
                                fout << pupil[i] << "\t\t";
                                fout << allratings[i] << endl;
                                if (a == 4) cout << pupil[i] << "\t\t";
                                if (a == 4) cout << allratings[i] << endl;
                            }
                            else
                            {
                                fout << pupil[i] << "\t";
                                fout << allratings[i] << endl;
                                if (a == 4) cout << pupil[i] << "\t";
                                if (a == 4) cout << allratings[i] << endl;
                            }
                        }
                    }
                    cout << endl << endl;
                    delete[] keys;
                    delete[] pupil;
                    delete[] allratings;

                    fin.close();
                    finRatings.close();
                    fout.close();
                    finKeys.close();
                }
                if (a == 5) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                {
                    string str;
                    fin.open(path);
                    fout.open(bufferpathStudents,ofstream::app);
                    string *infostring = new string[pupilcount+1];
                    if (!fin.is_open() || !fout.is_open())  // ��������, �������� �� ����
                    {
                        cout << "������ �������� �����" << endl;
                    }
                    else
                    {
                        for (int i = 0; i< pupilcount + 1; i++)
                        {
                            str = "";
                            getline(fin, str);      // ��������� ������ �� fin � ���������� str
                            infostring[i] = str;
                        }

                        fout << infostring[0]<<endl;
                        cout << infostring[0]<<endl;


                        for (int i = pupilcount; i >0; i--)
                        {
                            fout << infostring[i]<<endl;
                            cout << infostring[i] << endl;
                        }
                        cout << endl << endl;
                    }
                    delete[] infostring;
                    fin.close();
                    fout.close();

                    remove("myFile.txt");
                    rename("BuffStud.txt", "myFile.txt");
                    remove("BuffStud.txt");                     
                }
                cout << "���� ������ �� ������� �����"<<endl;
                fin.open(path);
                fout.open(bufferpath);
                fout << fin.rdbuf();
                fin.close();
                fout.close();
            }
            else if (a == 6)
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
                    string allsubjects;     // ���������� ��� ������ � ������� ���������, �� ������� ���������� ��������
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
                    int size = 0;
                    cout << "������� ������� ��������: ";
                    
                    cin >> newsurname;
                    while (newsurname.length()>15)
                    {
                        cout << "������� �������� �� ������ ���� ������ 15 ��������. ������� ������� ��� ���: ";
                        cin >> newsurname;
                    }
                    
                    // �������� ������ ������ ��������
                    while (!finKeys.eof())      // ������ ��������� ������ �� �����������
                    {
                        getline(finKeys, keystr);
                    }
                    
                    lastkey = stoi(keystr)+1;   // ���������� string � int
                    


                    
                    cout << "��� ���� ���������: " << allsubjects << "������� ������ ��������: ";
                    cin >> newpupilratings;

                    size = newpupilratings.length();			// ��������� ���������� �������� � ������
                    bool err = false;						// ���� err true, �� ��������� ����� �����������
                    const char* str = newpupilratings.c_str();	// �������� ������ � ������� char, ��� �� ����� �������� � ��������  isdigit
                    for (int i = 0; i < subjectscount; i++)
                    {
                        if (size > subjectscount || !isdigit(str[i]))
                        {
                            err = true;
                            break;
                        }

                        if (str[i]-48 < 0 || str[i] - 48 > 5)
                        {
                            err = true;       // ���� ����������� ���� ������
                            break;
                        }
                    }
                    
                    while (err)
                    {
                        cout << "�� ����� ������������ ��������: " << newpupilratings << endl
                            << "���������� ������ � ������� ���������� ���������, ������ ������������� ������ �� 0 �� 5"<<endl;
                        cout << "������� ������ �������� �� ��������� " << allsubjects << ": ";
                        cin >> newpupilratings;
                        size = newpupilratings.length();
                        err = false;
                        for (int i = 0; i < subjectscount; i++)
                        {
                            if (size > subjectscount || !isdigit(str[i]))
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

                    foutKeys << endl << lastkey;
                    fout << endl << newsurname;
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
            else if (a == 7)
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
                    string* surnames = new string[pupilcount];
                    string* numes = new string[pupilcount];
                    string str2;
                    string strKeys;
                    string penultimateword;
                    string enteredword;
                    string enteredkey;
                    string allpupils;
                    int countPupilsRatings = 0;
                    bool badenteredword = true;

                    for (int i = 0; !fin.eof(); i++) // ���� ���� ����� ���� ������ 
                    {
                        
                        str = "";
                        getline(fin, str);
                        surnames[i] = str;
                        allpupils = allpupils + str + " ";
                    }
                    fin.close();
                    fin.open(pathStudents);
                    cout << "�������� ������� �������� �� ������������ � ����: " << endl << allpupils << endl;      // �������� ������ �������
                    cout << "������� ��: ";
                    cin >> enteredword;

                    for (int i =0; !fin.eof(); i++)
                    {
                        getline(fin, str);
                        if (enteredword == surnames[i])
                        {
                           badenteredword = false;
                        }
                    }
                    fin.close();
                    fin.open(pathStudents);

                    while (badenteredword)
                    {
                        badenteredword == false;
                        cout << "�� ����� �������������� ��� " << enteredword << endl << "���������� ��� ���: ";
                            cin >> enteredword;
                            for (int i = 0; !fin.eof(); i++)
                            {
                                getline(fin, str);
                                if (enteredword == surnames[i])
                                {
                                    badenteredword = false;
                                }
                            }
                            fin.close();
                            fin.open(pathStudents);
                    }
                    badenteredword = true;

                    ////////////////////////////////////////////////////////////////////////////// ����� (��� ��������)
                    for (int i = 0; !finKeys.eof(); i++) // ���� ���� ����� ���� ������ 
                    {

                        str = "";
                        getline(finKeys, str);
                        numes[i] = str;
                    }
                    finKeys.close();
                    finKeys.open(pathKeys);

                    cout << "�������� ��� �������� ��������������� �������: " << endl;

                    for (int i = 0; i < pupilcount; i++)
                    {
                        cout << numes[i] << " " << surnames[i] << endl;
                    }
                    cout << "������� ���: ";
                    cin >> enteredkey;

                    for (int i = 0; !fin.eof(); i++)
                    {
                        getline(fin, str);
                        if (enteredkey == numes[i] && enteredword == surnames[i])
                        {
                            badenteredword = false;
                        }
                    }
                    finKeys.close();
                    finKeys.open(pathKeys);
                    fin.close();
                    fin.open(pathStudents);

                    while (badenteredword)
                    {
                        badenteredword = true;
                        cout << "�������� " << enteredkey <<" �� ������������ ��������� ������� "<< endl << "���������� ��� ���: ";
                        cin >> enteredkey;
                        for (int i = 0; !fin.eof(); i++)
                        {
                            getline(fin, str);
                            if (enteredkey == numes[i] && enteredword == surnames[i])
                            {
                                badenteredword = false;
                                break;
                            }
                        }
                        fin.close();
                        fin.open(pathStudents);
                        finKeys.close();
                        finKeys.open(pathKeys);
                    }


                    delete[] numes;
                    delete[] surnames;

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
            else if (a == 8)
            {
                int countfineof = 0;
                string lesson;
                finLessons.open(pathLessons);
                ratingsfout.open(bufferpathRatings);                // ��������� �������� ���� � �������� ��� ������
                finRatings.open(pathRatings);                       // ��������� ���� � �������� ��� ������ 
                fin.open(pathStudents);                             // ��������� ���� �� ���������� ��� ����������� ����� ��� ������� �������� �������� ������ �� ������ ��������
                fout.open(pathLessons, ofstream::app);         // ��������� ���� � ����������
                if (!fout.is_open() || !ratingsfout.is_open() || !fin.is_open() || !finRatings.is_open())
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    // ���������� ��������
                    string subject;                                     
                    cout << "������� ����������� �������� (3 �����): ";
                    cin >> subject;
                    // �������� �������� ������
                    bool err = false;						
                    if (subject.length() > 3) err = true;      

                    while (err)
                    {
                        cout << "������������ ������ ���� �� ����� 3� ��������\n���������� ��� ���: ";
                        cin >> subject;
                        if (subject.length() < 4) err = false;
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
                        cout << "����� �������: " << subject << " ��� ����, ���������� ����� � ��������� �������\n";
                        cout << "������� ����������� �������� (3 �����): ";
                        err = false;
                        cin >> subject;
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

                    }
                    finLessons.close();
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
                        cout << "������� ������ ��������: " << pupil << endl;
                        cin >> newpupilratings;

                        while (newpupilratings != "0" && newpupilratings != "1" && newpupilratings != "2" && newpupilratings != "3" && newpupilratings != "4" && newpupilratings != "5")
                        {
                            cout << "�� ����� ������������ ������ ��� ������ �� ������: " << newpupilratings<<endl;
                            cout << "��������� �������: ";
                            cin >> newpupilratings;
                        }

                        getline(finRatings, pupilratings);      // ��������� ������ ��� ������� ��������
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
            else if (a == 9)
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
                bool good = false;
                bool deletelaststr = false;

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
                    strcount = 0;
                    cout << "������� ������� �� ������������ � ����: " << lessons << endl;
                    cin >> enteredlesson;

                    while (!fin.eof())
                    {
                        strcount++;
                        str = "";
                        getline(fin, str);          
                        if (enteredlesson == str) 
                        {
                            good = true;
                            if (strcount == subjectscount)
                            {
                                deletelaststr = true;
                            }
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
                        cin >> enteredlesson;

                        while (!fin.eof())
                        {
                            strcount++;
                            str = "";
                            getline(fin, str);
                            if (enteredlesson == str)
                            {
                                if (strcount == subjectscount)
                                {
                                    deletelaststr = true;
                                }
                                good = true;
                                break;
                            }
                        }
                        fin.close();
                        fin.open(pathLessons);
                    }

                    
                    strcount = 0;
                    while (!fin.eof())
                    {
                        str = "";
                        getline(fin, str);          // ���������� � str �������� ��������
                        strcount++;                 // ����������� ������� ��������� �� ����� ������
                        if (enteredlesson != str)  // ���� �������� ������� �� ����� �� ������ �� ���������� � ����
                        {
                            if (strcount != subjectscount && !deletelaststr)
                            {
                                fout << str << endl;    // � ����� ���� �������� ��� �������� ���������, ����� ����, ������� ���� �������   
                            }
                            else if (strcount != subjectscount && deletelaststr && strcount!= subjectscount-1)
                            {
                                fout << str << endl;
                            }
                            else if (strcount != subjectscount && deletelaststr && strcount == subjectscount - 1) fout << str;
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
            cout << endl << endl << endl
                << "�������� 1 - '������� ������'. ��������� ������� ������ ��������� � �� ������ �� �������� �� ���������;" << endl
                << "�������� 2 - '������������ ���� � �������'. ��������� ������� ���� �� ������� ��������� � �� �������� �� ��� �� ���������;" << endl
                << "�������� 4 ���������� �������� 2, �� ����������� ���������� ��������� �� �������� �� � �� �;" << endl << endl
                << "������ ��������� 5, ����������� ������ ��� ��������, � ������� ���������� ���������. ��������:" << endl
                << "��� �������� �������� ���������� ������ ������ 4 5 4 5 �� ��������� ��������� Rus Mat Lit Phy ��������������." << endl
                << "������ Sidorov, ���� Enter, ������ 4545, ���� Enter." << endl << "0 - �������� ���������� ������. ����� �������� � ������� ����������\n\n"
                << "��� �������� ������ �� �������� (�������� 6), ���������� ������ ��� �����. ����� ����� ������, ������ �������� 1 (������ ������� Num);" << endl
                << "������ �������� 7, ���������� �������� ������� ��������, ����� ������������ �� 3� ��������, � ����� ��� ������� �� ��������� ������ ������ �� ��������;" << endl
                << "������ �������� 8 ����� ������ ������ ������������ �������� (3 �������) �� ������������, ����� ��������� ��� ������� ����;" << endl
                << "���� ��������� �������, ����������� � ���������� ��������������" << endl<<endl<<endl;
            }
            else if (a == 10)
            {
                finLessons.open(pathLessons);
                finSubjects.open(pathSubjects);
                string lesson;
                string subject;
                cout << endl << endl;
                cout << "������ � ���������" << endl;
                if (!finLessons.is_open() && !finSubjects.is_open()) cout << "������ �������� �����" << endl;
                else
                {
                    while (!finLessons.eof() && !finSubjects.eof())
                    {
                        lesson = "";
                        subject = "";
                        getline(finLessons, lesson);
                        getline(finSubjects, subject);
                        cout << lesson << " - " << subject << endl;
                    }
                }
                finLessons.close();
                finSubjects.close();
                cout << endl << endl;
            }
            else exit(12);
          
        }
    }
    while (true);
}