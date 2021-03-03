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
    bufferpath = L"\\myFile.txt";          // Имя файла на рабочем столе
    bufferpathStudents = "BuffStud.txt";
    bufferpathRatings = "BuffRatings.txt";
    bufferpathLessons = "BufferLessons.txt";
    bufferpathKeys = "BufferKeys.txt";
    bufferpathNames = "BufferNames.txt";
    bufferpathPatronymics = "BufferPatronymics.txt";

    SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY | CSIDL_FLAG_CREATE, NULL, SHGFP_TYPE_CURRENT, pathData);  // pathData - путь к рабочему столу

    cout << "Здравствуйте пользователь. Цель данной программы - взаимодействие с базой данных студентов и их оценок." << endl;
    cout << "Выберите действие ниже и введите соответствующую цифру" << endl << endl;

    do
    {
        closeallfiles();
        cout << "0 - Закрыть программу" << endl
            << "1 - Вывести данные" << endl
            << "2 - Сформировать файл с данными" << endl
            << "13 - Подсказки и помощь" << endl
            << "14 - Показать больше действий" << endl
            << "Esc - Вернуться в главное меню"<< endl << endl
            << "Введите номер действия: ";

        string enteredvalue;
        int maxsize = 0;
        checkinput();
        if (enteredvalue2 == 27) continue;
        enteredvalue = enteredword2;
        // cin >> enteredvalue;


        // Проверка вводимых данных
        wordsize = enteredvalue.length();
        const char* str = enteredvalue.c_str();	// Для работы с функцией  isdigit
        if ((wordsize > 1 || !isdigit(str[0])) && enteredvalue != "10" && enteredvalue != "11" && enteredvalue != "12" && enteredvalue != "13" && enteredvalue != "14")
        {
            system("cls");
            cout << "Ошибка ввода: " << enteredvalue << endl << endl;
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
            fin.open(pathLessons);       // Считаем количество предметов
            if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
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
            fin.open(pathStudents);     // Считаем количиство студентов  
            if (!fin.is_open())  cout << "Ошибка открытия файла" << endl;
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
                if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
                else if (a == 1)
                {
                    string str;
                    if (maxsize <= 7)  cout << "\nNum\tSurname\t"; // Табуляция, если длинная фамилия
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

                if (!fin.is_open() || !finNames.is_open() || !finRatings.is_open() || !finKeys.is_open() || !finPatronymics.is_open()) cout << "Ошибка открытия файла" << endl;
                else
                {
                    string str;
                    string str2;
                    string strKeys;
                    string strname;
                    string strpatronymic;

                    if (a == 3) // Средняя арифметическая оценка студента 
                    {
                        string enteredword;
                        bool foundoverlap = false;
                        cout << "Введите номер студента: ";
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
                                cout << endl<<"Среднее орифметическое значение всех оценок за семестр студента c фамилией: " << strname << " = " << summ / subjectscount << "\n\n";
                            }
                        }
                        if (!foundoverlap) cout << "Студента под номером " << enteredword << " не существует\n";
                    }
                    else
                    {
                        while (!fin.eof() && !finRatings.eof() && !finKeys.eof())
                        {
                            str = "";
                            getline(finKeys, strKeys);
                            getline(fin, str);          // Студенты
                            getline(finNames, strname);
                            getline(finPatronymics, strpatronymic);
                            getline(finRatings, str2);
                            cout << strKeys << "\t";
                            cout << str << " " << strname[0] << "." << strpatronymic[0] << ".";
                            if (maxsize > 7 && maxsize <= 16 && str.length() + 5 > 7) cout << "\t" << str2 << endl;                    // Вывод на экран в зависимости от длинны самой длинной фамилии
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

                if (!fin.is_open() || !fout.is_open() || !finStudents.is_open()) cout << "Ошибка открытия файла" << endl;
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
                if (!fin.is_open() || !finRatings.is_open() || !finKeys.is_open() || !finNames.is_open() || !finPatronymics.is_open() || !fout.is_open()) cout << "Ошибка открытия файла" << endl;
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
                        if (maxsize > 7 && maxsize <= 16 && str.length() + 5 > 7) fout << "\t" << str2 << endl;                    // Вывод на экран в зависимости от длинны самой длинной фамилии
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
                // Проверка на открытие файла на рабочем столе
                fout.open(pathData + bufferpath);
                if (!fin.is_open() || !fout.is_open()) cout << "Ошибка открытия файла" << endl;
                else
                {
                    fout << fin.rdbuf();
                    cout << "Файл создан на рабочем столе" << endl << endl;
                }
                fin.close();
                fout.close();
            }
            else if (a == 4 || a == 5)
            {
                fin.open(pathLessons);
                fout.open(path);

                if (!fin.is_open() || !fout.is_open())  cout << "Ошибка открытия файла" << endl;
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
                    if (!fin.is_open() || !finRatings.is_open() || !finKeys.is_open() || !finNames.is_open() || !finPatronymics.is_open())  cout << "Ошибка открытия файла" << endl;
                    else
                    {
                        string str;
                        string str2;
                        string strnames;
                        string strpatronymics;
                        string strKeys;
                        string* pupil = new string[pupilcount];         // Массив студентов
                        string* allratings = new string[pupilcount];    // Массив оценок студентов
                        string* keys = new string[pupilcount];          // Массив номеров студентов
                        string* names = new string[pupilcount];
                        string* patronymics = new string[pupilcount];
                        int pupilnumber = 0;
                        int* ppupilnumber = &pupilnumber;

                        while (!fin.eof() && !finRatings.eof())
                        {
                            str = "";
                            getline(fin, str);      // Считывает данные из Фамилий студентов в переменную str
                            getline(finRatings, str2);
                            getline(finNames, strnames);
                            getline(finPatronymics, strpatronymics);
                            getline(finKeys, strKeys);  // Считываем данные из файла с номерами студентов в строку

                            pupil[pupilnumber] = str;       // Записываю данные о студентах в массив
                            allratings[pupilnumber] = str2; // об оценках студентов
                            keys[pupilnumber] = strKeys;    // о номерах студентов в массив
                            names[pupilnumber] = strnames;  // об именах
                            patronymics[pupilnumber] = strpatronymics;  // об очествах

                            (*ppupilnumber)++;              // считает количество студентов
                        }
                        string buffer;
                        string ratingsbuffer;
                        string keysbuffer;
                        string namesbuffer;
                        string patronymicsbuffer;

                        int nameindex;
                        int quantitysymbolsfirst;
                        int quantitysymbolssecond;      // Количество символов в именах сравниваемых студентов
                        int necessaryquantitysymbols;
                        bool less = false;
                        fout << endl;
                        if (a == 4) cout << endl;

                        // Сортировка по алфавиту
                        for (int i = 0; i < pupilcount; i++)     // если i меньше количества студентов
                        {
                            string minname = pupil[i];          // Первый студент = минимальный по алфавиту
                            quantitysymbolsfirst = pupil[i].length();
                            char minchar = pupil[i][0];         // Первая буква первого студента = минимальной по алфавиту
                            nameindex = i;                      // Индекс имени равен 0

                            string mratings = allratings[i];     // Минимальная оценка = 0 оценке
                            string mkeys = keys[i];              // Минимальный номер студента = 0му студенту
                            string mnames = names[i];
                            string mpatronymics = patronymics[i];

                            for (int j = i + 1; j < pupilcount; j++)    // С последующего после нулевого студента, пока j меньше количества студентов в базе
                            {
                                quantitysymbolssecond = pupil[j].length();
                                if (quantitysymbolsfirst < quantitysymbolssecond)
                                {
                                    for (int k = 0; k < quantitysymbolsfirst; k++)
                                    {
                                        if (pupil[j][k] < minname[k])      // если каждый какой либо символ любого следующего слова меньше минимального, то имя с этим символом становится минимальным
                                        {
                                            minchar = pupil[j][0];          // Присваиваем min новому элементу
                                            minname = pupil[j];             // Тоже
                                            mnames = names[j];
                                            mpatronymics = patronymics[j];
                                            mratings = allratings[j];
                                            mkeys = keys[j];
                                            nameindex = j;                  // Индекс min элемента
                                            quantitysymbolsfirst = pupil[j].length(); // Теперь это первое слово
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
                            buffer = pupil[i];                   // Буфер для студентов, оценок, номеров студентов(ключей), отчеств
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
                        if (!fin.is_open() || !fout.is_open()) cout << "Ошибка открытия файла" << endl;
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
                    if (!fin.is_open() || !fout.is_open()) cout << "Ошибка открытия файла" << endl;
                    else
                    {
                        fout << fin.rdbuf();
                        cout << "Файл создан на рабочем столе" << endl << endl;
                    }
                    fout << fin.rdbuf();
                }
                fin.close();
                fout.close();
            }
            else if (a == 6)
            {
                fout.open(pathStudents, ofstream::app);    // В первый запуск создаст файл, app - append - добавить, позволяет добавляться новые данные не затирая старые
                ratingsfout.open(pathRatings, ofstream::app);
                finKeys.open(pathKeys);
                foutKeys.open(pathKeys, ofstream::app);
                foutnames.open(pathNames, ofstream::app);
                foutpatronymics.open(pathPatronymics, ofstream::app);

                if (!fout.is_open() || !ratingsfout.is_open() || !finKeys.is_open() || !foutKeys.is_open() || !foutnames.is_open() || !foutpatronymics.is_open()) cout << "Ошибка открытия файла" << endl;
                else
                {
                    string allsubjects;     // Переменная для вывода в консоль предметов, по которым занимаются студенты
                    int subjectscount = 0;
                    fin.open(pathLessons);
                    if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
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

                    cout << "Введите фамилию студента: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    newsurname = enteredword2;
                    // cin >> newsurname;
                    while (newsurname.length() > 19)
                    {
                        cout << "Фамилия студента должна быть короче 19 символов. Введите фамилию еще раз: ";
                        checkinput();
                        if (enteredvalue2 == 27) continue;
                        newsurname = enteredword2;
                        // cin >> newsurname;
                    }
                    cout << "\nВведите имя студента: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    newname = enteredword2;
                    // cin >> newname;
                    cout << "\nВведите отчество студента: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    newpatronumic = enteredword2;
                    // cin >> newpatronumic;

                    // Добавляю индекс нового студента
                    while (!finKeys.eof()) getline(finKeys, keystr);     // Нахожу последний индекс по возрастанию

                    lastkey = stoi(keystr) + 1;   // Преобразую string в int
                    cout << "\nДля этих предметов: " << allsubjects << "введите оценки студента: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    newpupilratings = enteredword2;
                    // cin >> newpupilratings;

                    wordsize = newpupilratings.length();			// Вычисляем количество символов в строке
                    bool err = false;						        // Если err true, то введенное число некорректно
                    const char* str = newpupilratings.c_str();	    // Приводим строку к массиву char, что бы далее работать с функцией  isdigit
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
                        cout << "\nВы ввели неправильные значения: " << newpupilratings << endl
                            << "Необходимо слитно в порядке выведенных предметов, ввести целочисленные оценки от 0 до 5" << endl;
                        cout << "Введите оценки студента по предметам " << allsubjects << ": ";
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
                fin.open(pathStudents);                 // Считываем фамилии             
                finRatings.open(pathRatings);           // и оценки из существующих файлов
                fout.open(bufferpathStudents);          // Открываем буфферные фалы для записи студентов без удаленного
                ratingsfout.open(bufferpathRatings);    // и оценок для этого студента
                finKeys.open(pathKeys);
                foutKeys.open(bufferpathKeys);
                finNames.open(pathNames);
                foutnames.open(bufferpathNames);
                finPatronymics.open(pathPatronymics);
                foutpatronymics.open(bufferpathPatronymics);

                if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open() || !finKeys.is_open() || !foutKeys.is_open() || !finNames.is_open() || !foutnames.is_open() || !finPatronymics.is_open() || !foutpatronymics.is_open())  // Проверка, открылись ли файлы
                {
                    cout << "Ошибка открытия файла" << endl;
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
                    string str = "";     // В эти строки записываются данные из файлов
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

                    // Записываю фамилии всех студентов в массив surnames[i]
                    for (int i = 0; !fin.eof(); i++)
                    {
                        str = "";
                        getline(fin, str);
                        surnames[i] = str;
                    }
                    fin.close();
                    // Записывю все номера студентов в массив
                    for (int i = 0; !finKeys.eof(); i++)
                    {
                        str = "";
                        getline(finKeys, str);
                        numes[i] = str;
                    }
                    finKeys.close();

                    cout << "Выберите номер студента, информацию о котором хотите удалить: " << endl;
                    for (int i = 0; i < pupilcount; i++) cout << numes[i] << " " << surnames[i] << endl;
                    cout << "Введите номер: ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    enteredkey = enteredword2;
                    //cin >> enteredkey;


                    fin.open(pathStudents);
                    for (int i = 0; !fin.eof(); i++)        // Записываю имя студента, которое соответсвует введенному коду если есть соответсвие
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

                    while (badenteredword)  // Проверка на корректость номера студента
                    {
                        cout << "Номера студента: " << enteredkey << " нет" << endl << "Попробуйте еще раз: ";
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
                    while (!finKeys.eof()) // Для отмены перехода на новую строчку после предыдущего элемента при удалении самого последнего
                    {
                        getline(finKeys, strlast);
                    }
                    finKeys.close();
                    finKeys.open(pathKeys);
                    while (!finKeys.eof()) // Для отмены перехода на новую строчку после предыдущего элемента при удалении самого последнего
                    {
                        getline(finKeys, penultimateword2);
                        getline(finKeys, penultimateword);
                    }
                    if (penultimateword > penultimateword2) penultimateword = penultimateword2;
                    finKeys.close();
                    

                    finKeys.close();
                    finKeys.open(pathKeys);


                    ///////////////////////////////////////////////////////// Problem is choise
                    cout << "Вы действительно хотите удалить данные о студенте: " << strStudent << endl;
                    cout << "y - да, n - нет";

                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    value = enteredword2;
                    // cin >> value;
                    cout << endl;
                    countPupilsRatings = 0;
                    fin.open(pathStudents);
                    while (value != "y" && value != "n")      // Проверка на корректность
                    {
                        cout << "Неверный ввод, повторите попытку" << endl;
                        cout << "y -да, n - нет";
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
                            getline(fin, str);          // Считывает фамилии студентов
                            getline(finRatings, str2);  // и оценки
                            getline(finKeys, strKeys);  // и номера студентов
                            getline(finNames, strname); // и имена
                            getline(finPatronymics, strpatronymic); // и отчества

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

                        remove("Students.txt");                     // Удалить изначальные 5 файлов
                        remove("Ratings.txt");
                        remove("Keys.txt");
                        remove("Names.txt");
                        remove("Patronymics.txt");

                        rename("BuffStud.txt", "Students.txt");     // Копируем новые 5 файлов и переименовываем их в старые названия
                        rename("BuffRatings.txt", "Ratings.txt");
                        rename("BufferKeys.txt", "Keys.txt");
                        rename("BufferNames.txt", "Names.txt");
                        rename("BufferPatronymics.txt", "Patronymics.txt");

                        remove("BuffStud.txt");                     // Удалить оригинал новых 5ти файлов
                        remove("BuffRatings.txt");
                        remove("BufferKeys.txt");
                        remove("BufferNames.txt");
                        remove("BufferPatronymics.txt");
                    }
                    else
                    {
                        system("cls");
                        cout << "Отмена удаления данных студента" << endl<<endl;
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
                fout.open(pathLessons, ofstream::app);              // Открываем файл с предметами
                ratingsfout.open(bufferpathRatings);                // Открываем буферный файл с оценками для записи
                finRatings.open(pathRatings);                       // Открываем файл с оценками для чтения 
                fin.open(pathStudents);                             // Открываем файл со студентами для составления цикла для каждого студента добавить оценку по новому предмету
                foutSubjects.open(pathSubjects, ofstream::app);

                if (!finLessons.is_open() || !fout.is_open() || !ratingsfout.is_open() || !fin.is_open() || !finRatings.is_open() || !fin.is_open() || !foutSubjects.is_open())
                {
                    cout << "Ошибка открытия файла" << endl;
                    finLessons.close();
                    fout.close();
                    ratingsfout.close();
                    finRatings.close();
                    fin.close();
                    foutSubjects.close();
                }
                else
                {
                    // Добавление предмета
                    string subject;
                    cout << "Введите абривиатуру предмета (3 символа): ";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    subject = enteredword2;
                    // cin >> subject;
                    // Проверка вводимых данных
                    bool err = false;
                    if (subject.length() != 3) err = true;

                    while (err)
                    {
                        cout << "Количество символов не равно 3.\nПопробуйте еще раз: ";
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
                        cout<< "Количество символов не равно 3 или такой предмет: " << subject << " уже есть, повторите попытку:\n";
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

                    // Добавление расшифровки аббревиатуры введенного предмета
                    cout << "Введите расшифровку аббревиатуры: ";
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
                        cout << "Введите оценку студента: " << pupil;
                        checkinput();
                        if (enteredvalue2 == 27) break;
                        newpupilratings = enteredword2;
                        // cin >> newpupilratings;

                        while (newpupilratings != "0" && newpupilratings != "1" && newpupilratings != "2" && newpupilratings != "3" && newpupilratings != "4" && newpupilratings != "5")
                        {
                            cout << "Вы ввели неправильную оценку или вообще не оценку: " << newpupilratings << endl;
                            cout << "Повторите попытку: ";
                            checkinput();
                            if (enteredvalue2 == 27) continue;
                            newpupilratings = enteredword2;
                            // cin >> newpupilratings;
                        }

                        // getline(finRatings, pupilratings);      // Считываем оценки для каждого студента
                        arrratings[countfineof - 1] = newpupilratings;
                    }
                    if (enteredvalue2 == 27) continue;
                    fin.close();
                    fin.open(pathStudents);
                    countfineof = 0;
                    while (!fin.eof())
                    {
                        getline(finRatings, pupilratings);      // Считываем оценки для каждого студента
                        getline(fin, pupil);        // Для того, что бы счетчик не был бесконечен
                        countfineof++;
                        if (pupilcount != countfineof) ratingsfout << pupilratings + "   " + arrratings[countfineof - 1] << endl;     // Выводим данные в буферный файл и прибавляем новую оценку
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
                    cout << "Ошибка открытия файла" << endl;
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
                    cout << "Введите предмет из существующих в базе: " << lessons;      // Ввод аббревиатуры предмета
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
                        cout << "Такого предмета нет, повторите попытку.\nВведите предмет из существующих в базе: ";
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

                    // Проверка, действительно ли хочет удалить данные 
                    string choise;
                    cout << "Вы действительно хотите удалить информацию о предмете " << enteredlesson << "?" << endl;
                    cout << "y - да, n - нет";
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    choise = enteredword2;
                    // cin >> choise;
                    cout << endl;
                    while (choise != "y" && choise != "n")      // Проверка на корректность
                    {
                        cout << "Неверный ввод, повторите попытку" << endl;
                        cout << "y -да, n - нет" << endl;
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

                    // Удаление расшифровки предмета при удалении аббревиатуры
                    strcount = 0;
                    while (!fin.eof())
                    {
                        str = "";
                        fulllesson = "";
                        getline(fin, str);
                        getline(finSubjects, fulllesson);

                        strcount++;                 // Увеличиваем счетчик переходов на новую строку
                        if (enteredlesson != str)  // Если введеный предмет не равен ни одному из хранящихся в базе
                        {
                            if (strcount != subjectscount && !deletelaststr)
                            {
                                fout << str << endl;    // В новый файл добавляю все названия предметов, кроме того, который хочу удалить   
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
                        else deletedchars = (strcount - 1) * 4;   // Если предмет = предмету в базе данных
                    }

                    while (!finRatings.eof())       // Добавление оценок в новый файл без оценок удаленного предмета
                    {
                        count++;
                        ratings = "";
                        result = "";
                        getline(finRatings, ratings);
                        //cout << ratings.length() << endl;
                        for (int i = 0; i < ratings.length(); i++)
                        {
                            // если положение текущей оценки = положению символа удаленного предмета, то удаляем оценку и 3 символа пред ним( после с случае, кода первый символ нулевой)
                            if (i == deletedchars || i == deletedchars - 1 || i == deletedchars - 2 || i == deletedchars - 3) {} // Если я удаляю не первый предмет
                            else if (deletedchars != 0) ratingsfout << ratings[i];

                            if (i == deletedchars || i == deletedchars + 1 || i == deletedchars + 2 || i == deletedchars + 3) {}  // Если я удаляю первый предмет
                            else if (deletedchars == 0) ratingsfout << ratings[i];
                        }
                        if (pupilcount != count) ratingsfout << endl;
                    }
                    fout.close();
                    fin.close();
                    remove("Lessons.txt");
                    rename("BufferLessons.txt", "Lessons.txt");
                    remove("BufferLessons.txt");                // Изменил предметы

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
                if (!finLessons.is_open() && !finSubjects.is_open()) cout << "Ошибка открытия файла" << endl;
                else
                {
                    cout << "Данные о предметах" << endl;

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
                    cout << "Ошибка открытия файла" << endl;
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
                    cout << "Введите аббревиатуру предмета из предложенных, расшифровку для которого хотите написать: ";
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
                        cout << "Такой аббревиатуры нет. Повторите попытку: ";
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

                    cout << "Введите расшифровку аббревиатуры: ";
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
                    cout << "Ошибка открытия файла" << endl;
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

                    // Изменить оценку студента по определенному предмету
                    // Ввод номера студента, проверка, запись строки с оценками выбранного студента
                    string enteredword;         // Переменная для номера студента
                    bool foundoverlap = false;  // Если номер студента соответствует введенному
                    cout << "Введите номер студента: ";
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

                        if (studentnum == enteredword)         // Находим строчку с оценками, которая соответствует введенному студенту (его номеру)
                        {
                            ratingstrnumforchange = ratingstrnum;
                            ratingstrforchange = ratingstr;     // И записываем ее в переменную
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
                        cout << "Нет такого номера студента: " << enteredword << endl;
                        cout << "Повторите попытку: ";
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

                    // Ввод предмета, у которого мы будем менять оценку студента
                    while (!finLessons.eof())
                    {
                        getline(finLessons, lesson);
                        cout << lesson << endl;
                    }
                    finLessons.close();

                    cout << "Введите предмет из предложенных, для которого хотите изменить оценку: ";
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
                        cout << "Нет такого предмета: " << enteredlesson<<endl;
                        cout << "Повторите попытку: ";
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

                    // Ввод оценки, которую я хочу присвоить вместо текущей 
                    cout << "Введите новую оценку для предмета: " << enteredlesson << " студента с фамилией: " << foundsurname << " и номером: " << enteredword;
                    checkinput();
                    if (enteredvalue2 == 27) continue;
                    studentvalue = enteredword2[0];
                    // cin >> studentvalue;

                    while (studentvalue != '0' && studentvalue != '1' && studentvalue != '2' && studentvalue != '3' && studentvalue != '4' && studentvalue != '5')
                    {
                        cout << "Вы ввели неправильную оценку или вообще не оценку: " << studentvalue << endl;
                        cout << "Повторите попытку: ";
                        checkinput();
                        if (enteredvalue2 == 27) break;
                        studentvalue = enteredword2[0];
                        //cin >> studentvalue;
                    }
                    if (enteredvalue2 == 27) continue;

                    // Считываем информацию из файла с оценками и добавляем в буферный файл измененную сроку с оценками
                    finRatings.open(pathRatings);
                    ratingstrnum = 0;

                    while (!finRatings.eof())
                    {
                        ratingstrnum++;
                        getline(finRatings, ratingstr);
                        // cout << ratingstr << endl;

                        if (ratingstrnum != ratingstrnumforchange) // Находим строчку с оценками, которая соответствует введенному студенту (его номеру)
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
                    << "  1 - \"Вывести данные\". Будет выведен список студентов и их оценок за семестр по всем предметам;" << endl
                    << "  2 - \"Сформировать файл с данными\". Будет сформирован файл MyFile.txt на рабочем столе со списком студентов" << endl
                    << "и их оценками за семестр по предметам;" << endl
                    << "  3 -  \"Вывести среднюю арифметическую оценку студента за семестр\". После ввода номера студента будет выведено" << endl
                    << "среднее арифметическое всех его оценок. Если оценка по предмету равна нулю, то такой предмет исключается из расчетов;" << endl
                    << "  4 - \"Сформировать файл со студентами и их оценками, отсортированными по алфавиту от А до Я и вывести данные" << endl
                    << "на экран\". Действие аналогично действию 2, за исключением сортировки студентов по алфавиту от А до Я;" << endl << endl
                    << "  5 - \"Сформировать файл со студентами и их оценками, отсортированными по алфавиту от Я до А и вывести данные" << endl
                    << "на экран\". Действие аналогично действию 4, за исключением сортировки студентов по алфавиту от Я до А;" << endl
                    << "  6 - \"Добавить студента и его оценки в базу данных\". Необходимо добавить фамилию, имя, отчество, оценки студента." << endl
                    << "Добавляейте оценки без пробелов, в порядке выведенных предметов. Например:" << endl
                    << "для студента Сидорова необходимо ввести оценки 4 5 4 5 по следующим предметам Rus Mat Lit Phy соответственно." << endl
                    << "Вводим Sidorov, жмем Enter, вводим 4545, жмем Enter." << endl
                    << "Если не хотите добавлять оценку, введите значение 0 (в расчетах не учитывается);\n\n"
                    << "  7 - \"Удалить данные о студенте\". Для удаления данных о студенте, достаточно ввести его номер" << endl
                    << "  8 - \"Добавить данные о предмете\". Необходимо добавить предмет обучения, введя аббривиатуру из 3х символов," << endl
                    << "расшифровку аббривиатуры, а также для каждого из студентов ввести оценку за четверть;" << endl
                    << "  9 - \"Удалить данные о предмете и всю связанную с ним информацию\". Необходимо ввести только аббривиатуру" << endl
                    << "предмета (3 символа) из предложенных;" << endl << endl
                    << "  10 - \"Вывести данные с расшифровкой аббревиатур предметов\". Выведет данные в таком формате: Rus - Русский язык;" << endl
                    << "  11 - \"Добавить рашифровку аббревиатуры для предмета\". Сначала необходимо ввести аббревиатуру из 3х символов," << endl
                    << "затем ввести расшифровку предмета обучения;" << endl
                    << "  12 - \"Изменить оценку студента\". Дает возможность изменить одну оценку ученика по конкретному предмету;" << endl
                    << "  Esc - \"Выйти в главное меню\". Завершит текущее действие и выйдет в главное меню;" << endl
                    << "Если возникнут вопросы, обращайтесь к системному администратору"<<endl << endl << endl;     
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
        if(badword)  cout << "Я не поняла того, что вы написали: " << enteredvalue << endl << endl;

        cout << "Выберите действие ниже и введите соответствующую цифру" << endl << endl;
        cout << "0 - Закрыть программу" << endl
            << "1 - Вывести данные" << endl
            << "2 - Сформировать файл с данными" << endl
            << "3 - Вывести среднюю арифметическую оценку студента за семестр" << endl
            << "4 - Сформировать файл со студентами и их оценками, отсортированными по алфавиту от А до Я и вывести данные на экран" << endl
            << "5 - Сформировать файл со студентами и их оценками, отсортированными по алфавиту от Я до А и вывести данные на экран" << endl
            << "6 - Добавить студента и его оценки в базу данных" << endl
            << "7 - Удалить данные о студенте" << endl
            << "8 - Добавить данные о предмете" << endl
            << "9 - Удалить данные о предмете и всю связанную с ним информацию" << endl
            << "10 - Вывести данные с расшифровкой аббревиатур предметов" << endl
            << "11 - Добавить рашифровку аббревиатуры для предмета" << endl
            << "12 - Изменить оценку студента" << endl
            << "13 - Подсказки и помощь" << endl << endl
            << "Введите номер действия: ";
        cin >> enteredvalue;
        wordsize = enteredvalue.length();
        const char* str = enteredvalue.c_str();
        if ((wordsize > 1 || !isdigit(str[0])) && enteredvalue != "10" && enteredvalue != "11" && enteredvalue != "12" && enteredvalue != "13")
        {
            system("cls");
            cout << "Я не поняла того, что вы написали: " << enteredvalue << endl << endl;
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
    do  // цикл всей программы
    {
        enteredvalue2 = _getch();
        if (enteredvalue2 == 27)    // Если = Esc
        {
            system("cls");
            break;      

        }
        else if (enteredvalue2 == 13)  break;  // Если = Enter
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
