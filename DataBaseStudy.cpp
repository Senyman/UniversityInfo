#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Данная программа работает с базой данных учеников и их оценками в школе Сколково" << endl;

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
        cout<< "0 - Подсказки и помощь" << endl
            << "1 - Вывести данные" << endl
            << "2 - Сформировать файл с данными" << endl
            << "3 - Вывести среднюю арифметическую оценку учащегося за четверть" << endl
            << "4 - Сформировать файл с учениками и их оценками, отсортированными по алфавиту" << endl
            << "5 - Добавить учащегося и его оценки в базу данных" << endl
            << "6 - Удалить данные об ученике. Сначала рекомендуется выполнить действие 1 (узнать номер ученика)" << endl
            << "7 - Добавить данные о предмете" << endl
            << "8 - Удалить данные о предмете и всю связанную с ним информацию" << endl
            << "9 - Закрыть программу" << endl<<endl
            << "Введите номер действия: ";

        int maxsize = 0;
        // Проверка вводимых данных
        cin >> enteredvalue;                    
        size = enteredvalue.length();			// Вычисляем количество символов в строке
        bool err = false;						// Если err true, то введенное число некорректно
        const char* str = enteredvalue.c_str();	// Приводим строку к массиву char, что бы далее работать с функцией  isdigit
        if (size > 1 || !isdigit(str[0])) err = true;       // Если неправильно ввел данные

        if (err) cout << "Я не поняла того, что вы написали: " << enteredvalue <<endl<<endl;
        else
        {
            a = enteredvalue[0]-48;
            // cout << "Вы ввели правильное число: " << enteredvalue << endl;
            subjectscount = 0;
            fin.open(pathLessons);       // Считаем количество предметов
            if (!fin.is_open())
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                string str;
                while (!fin.eof())
                {
                    str = "";
                    getline(fin, str);      // Если этого не будет, то цикл while бесконечен
                    ++subjectscount;
                }
                fin.close();
            }

            pupilcount = 0;
            fin.open(pathStudents);     // Считаем количиство студентов  
            if (!fin.is_open())
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                string str;
                while (!fin.eof())
                {
                    str = "";
                    getline(fin, str);      // Если этого не будет, то цикл while бесконечен
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
                if (!fin.is_open())  // Проверка, открылся ли файл
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else if (a == 1)
                {
                    string str;
                    if (maxsize<8)  cout << "\n\nNum\tSurname\t";// Табуляция, если длинная фамилия
                    else
                    {
                        cout << "\n\nNum\tSurname\t\t";
                    }
                    
                    while (!fin.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);      // Считывает данные из fin в переменную str
                        cout << str << " ";

                    }
                    cout << endl;
                }
                fin.close();
                fin.open(pathStudents);      //Считываем фамилии и оценки
                finRatings.open(pathRatings);
                finKeys.open(pathKeys);
                if (!fin.is_open() || !finRatings.is_open() ||!finKeys.is_open())  // Проверка, открылся ли файл
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    //cout << "Файл успешно открыт!" << endl;
                    string str;
                    string str2;
                    string strKeys;
                    string strname;
    
                    if (a == 3)       // Средняя оценка ученика 
                    {
                        string enteredword;
                        bool foundoverlap = false;
                        cout << "Введите номер ученика: ";
                        //while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
                        //{
                        //    str = "";
                        //    getline(fin, str);      // Считывает данные из fin в переменную str
                        //    cout << str << endl;
                        //}

                        //fin.close();                // Это нужно, потому что если происходит eof, то следующий eof не произойдет, так как он будет считывать пустые данные после данных
                        //fin.open(pathStudents);
                        //finRatings.close();
                        //finRatings.open(pathRatings);

                        cin >> enteredword;
                        while (!finKeys.eof() && !finRatings.eof() && !fin.eof())      // Пока есть какие либо данные 
                        {
                            str = "";
                            double first;
                            double summ = 0;        // Сумма всех оценок
                            getline(finKeys, strKeys);      // Считывает данные из fin в переменную str
                            getline(finRatings, str2);
                            getline(fin, str);
                            if (strKeys == enteredword)         // Выводим среднюю оценку по фамилии
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
                                cout << "Оценка ученика c фамилией: " << strname << " = " << summ / subjectscount << " балла\n\n";
                            }
                        }
                        if (!foundoverlap) cout << "Ученика под номером: " << enteredword << " не существует\n";
                    }
                    else
                    {
                        while (!fin.eof() && !finRatings.eof()&&!finKeys.eof())      // Пока есть какие либо данные 
                        {
                            str = "";
                            getline(finKeys, strKeys);
                            getline(fin, str);      // Считывает данные из fin в переменную str
                            getline(finRatings, str2);
                            cout << strKeys << "\t";
                            cout << str;
                            if (maxsize > 7 && str.length()>7) cout << "\t" << str2 << endl;                    // Вывод на экран в зависимости от длинны самой длинной фамилии
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
                
                if (!fin.is_open() && !fout.is_open()&& !finStudents.is_open())  // Проверка, открылся ли файл
                {
                    cout << "Ошибка открытия файла" << endl;
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
                    
                    while (!fin.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);      // Считывает данные из fin в переменную str
                        fout << str << " ";    // Выводим данные из переменной str в файл myFail объекта fout

                    }
                    fout << endl;
                    fin.close();
                    finStudents.close();
                }
                finKeys.open(pathKeys);
                fin.open(pathStudents);      //Считыывем фамилии и оценки
                finRatings.open(pathRatings);
                if (!fin.is_open() || !finRatings.is_open()||!finKeys.is_open())  // Проверка, открылся ли файл
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    string str;
                    string str2;
                    string strKey;
                    while (!fin.eof() && !finRatings.eof() && !finKeys.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        str2 = "";
                        strKey = "";
                        getline(fin, str);      // Считывает данные из fin в переменную str
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
                cout << "Файл готов" << endl << endl;
            }
            else if (a == 4)
            {
                fin.open(pathLessons);
                fout.open(path);
                if (!fin.is_open() || !fout.is_open())  // Проверка, открылся ли файл
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    cout << "Файл успешно открыт!" << endl;
                    string str;

                    if (maxsize < 8) fout << "Num\tSurname\t";
                    else fout << "Num\tSurname\t\t";
                    while (!fin.eof())          // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);      // Считывает данные из fin в переменную str
                        fout << str << " ";    // Выводим данные из переменной str в файл myFail объекта fout

                    }
                    // fout << endl;
                    fin.close();
                }

                fin.open(pathStudents);
                finRatings.open(pathRatings);
                finKeys.open(pathKeys);
                if (!fin.is_open() || !finRatings.is_open() || !finKeys.is_open())  // Проверка, открылся ли файл
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    //cout << "Файл успешно открыт!" << endl;
                    string str;
                    string str2;
                    string strKeys;
                    string* pupil = new string[pupilcount];         // Массив учеников ///////////////////////////////////////////////////////////////////////////////////////////
                    string* allratings = new string[pupilcount];    // Массив оценок учеников  ////////////////////////
                    string* keys = new string[pupilcount];          // Массив номеров учеников
                    int pupilnumber = 0;
                    int* ppupilnumber = &pupilnumber;

                    while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);      // Считывает данные из Фамилий студентов в переменную str
                        getline(finRatings, str2);
                        getline(finKeys, strKeys);  // Считываем данные из файла с номерами студентов в строку

                        //fout << str << "\t";
                        //fout << str2 << endl;
                        pupil[pupilnumber] = str;   // Записываю данные об учениках в массив
                        allratings[pupilnumber] = str2;
                        keys[pupilnumber] = strKeys;    // Записываю данные об номерах учеников в массив
                        // cout << allratings[pupilnumber] << endl;

                        (*ppupilnumber)++;
                    }
                    string buffer;
                    string ratingsbuffer;
                    string keysbuffer;
                    int nameindex;
                    fout << endl;

                    for (int i = 0; i < pupilcount; i++)              // Сортировка по алфавиту
                    {
                        string minname = pupil[i];           // Сортировка фамилий
                        char minchar = pupil[i][0];
                        nameindex = i;
                        string mratings = allratings[i];     // Сортировка оценок
                        string mkeys = keys[i];

                        for (int j = i + 1; j < pupilcount; j++)
                        {
                            if (pupil[j][0] < minchar)       // если первый символ любого следующего слова меньше минимального, то имя с этим символом становится минимальным
                            {
                                minchar = pupil[j][0];        // Присваиваем min новому элементу
                                minname = pupil[j];            // Тоже
                                mratings = allratings[j];
                                mkeys = keys[j];
                                nameindex = j;               // Индекс min элемента
                            }
                        }
                        buffer = pupil[i];                   // Буфер для учеников и оценок
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

                fout.open(pathStudents, ofstream::app);    // В первый запуск создаст файл, app - append - добавить, позволяет добавляться новые данные не затирая старые
                ratingsfout.open(pathRatings, ofstream::app);
                finKeys.open(pathKeys);
                foutKeys.open(pathKeys,ofstream::app);


                if (!fout.is_open() || !ratingsfout.is_open()||!foutKeys.is_open()||!finKeys.is_open())  // Проверка, открылись ли файлы
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    string allsubjects;     // Переменная для вывода в консоль предметов, по которым занимаются ученики
                    int subjectscount = 0;
                    fin.open(pathLessons);
                    if (!fin.is_open())  // Проверка, открылся ли файл
                    {
                        cout << "Ошибка открытия файла" << endl;
                    }
                    else
                    {
                        string str;
                        while (!fin.eof())      // Пока есть какие либо данные 
                        {
                            str = "";
                            getline(fin, str);      // Считывает данные из fin в переменную str
                            allsubjects = allsubjects + str + " ";
                            subjectscount++;
                        }
                        fin.close();
                    }
                    string newsurname;
                    string newpupilratings;
                    string keystr;
                    int lastkey = 0;
                    cout << "Введите фамилию ученика: ";
                    
                    cin >> newsurname;
                    while (newsurname.length()>15)
                    {
                        cout << "Фамилия ученика не должна быть короче 15 символов. Введите фамилию еще раз: ";
                        cin >> newsurname;
                    }
                    
                    // Добавляю индекс нового ученика
                    while (!finKeys.eof())      // Нахожу последний индекс по возрастанию
                    {
                        getline(finKeys, keystr);
                    }
                    
                    lastkey = stoi(keystr)+1;   // Преобразую string в int
                    foutKeys <<endl<<lastkey;


                    fout << endl << newsurname;
                    cout << "Введите оценки ученика по предметам " << allsubjects << ": ";
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
                fin.open(pathStudents);                 // Считываем фамилии 
                finRatings.open(pathRatings);           // и оценки из существующих файлов
                fout.open(bufferpathStudents);          // Открываем буфферные фалы для записи студентов без удаленного
                ratingsfout.open(bufferpathRatings);    // и оценок для этого студента
                finKeys.open(pathKeys);
                foutKeys.open(bufferpathKeys);

                if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open() || !finKeys.is_open())  // Проверка, открылись ли файлы
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    string str;     // В эти строки записываются данные из файлов
                    string str2;
                    string strKeys;
                    string penultimateword;
                    string enteredword;
                    string enteredkey;
                    string allpupils;
                    int countPupilsRatings = 0;

                    while (!fin.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);
                        allpupils = allpupils + str + " ";
                    }
                    cout << "Выберите фамилию ученика из существующих в базе: " << endl << allpupils << endl;      // Которого хотите удалить
                    cout << "Введите ее: ";
                    cin >> enteredword;
                    cout << "Введите номер ученика" << endl; // Фамилии могут быть одинаковыми, но код разный у каждого, вводим и фамилию для исключения ошибки случайным введение не той фамилии
                    cin >>enteredkey;

                    fin.close();
                    fin.open(pathStudents);
                    while (!fin.eof()) // Для отмены перехода на новую строчку после предыдущего элемента при удалении самого последнего
                    {
                        getline(fin, penultimateword );
                        getline(fin, str);
                    }


                    fin.close();
                    fin.open(pathStudents);
                    finKeys.close();
                    finKeys.open(pathKeys);

                    while (!fin.eof() && !finRatings.eof() && !finKeys.eof())      // Пока есть какие либо данные 
                    {
                        countPupilsRatings++;
                        str2 = "";
                        str = "";
                        getline(fin, str);          // Считывает фамилии студентов
                        getline(finRatings, str2);  // и оценки
                        getline(finKeys, strKeys);  // и номера студентов

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
                        // Для отмены перехода на новую строчку после предыдущего элемента при удалении самого последнего
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

                    remove("Students.txt");                     // Удалить старые 3 файла 
                    remove("Ratings.txt");
                    remove("Keys.txt");
                    rename("BuffStud.txt", "Students.txt");     // Копируем новые 3 файла переименовать в старые
                    rename("BuffRatings.txt", "Ratings.txt");
                    rename("BufferKeys.txt", "Keys.txt");
                    remove("BuffStud.txt");                     // Удалить новые 3 файла 
                    remove("BuffRatings.txt");
                    remove("BufferKeys.txt");
                    
                }
            }
            else if (a == 7)
            {
                int countfineof = 0;
                ratingsfout.open(bufferpathRatings);                // Открываем буферный файл с оценками для записи
                finRatings.open(pathRatings);                       // Открываем файл с оценками для чтения 
                fin.open(pathStudents);                             // Открываем файл с учениками для составления цикла для каждого студента добавить оценку по новому предмету
                fout.open(pathLessons, ofstream::app);         // Открываем файл с предметами
                if (!fout.is_open() || !ratingsfout.is_open() || !fin.is_open() || !finRatings.is_open())
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    // Добавление предмета
                    string subject;                                     
                    cout << "Введите абривиатуру предмета (3 буквы)" << endl;
                    cin >> subject;
                    // Проверка вводимых данных
                    bool err = false;						
                    if (subject.length() > 3) err = true;      

                    if (err)
                    {
                        while (err)
                        {
                            cout << "Аббривиатура должна быть не более 3х символов\nПопробуйте еще раз: ";
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
                            cout << "Введите оценку ученика: " << pupil << endl;
                            cin >> newpupilratings;

                            getline(finRatings, pupilratings);      // Считываем оценки для каждого ученика
                            if (pupilcount != countfineof) ratingsfout << pupilratings + "   " + newpupilratings << endl;     // Выводим данные в буферный файл и прибавляем новую оценку
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
                if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open())  cout << "Ошибка открытия файла" << endl;
                else
                {
                    cout << "Введите предмет из существующих в базе: " << lessons << endl;
                    cin >> enteredlesson;
                    while (!fin.eof())
                    {
                        str = "";
                        getline(fin, str);          // Записываем в str название предмета
                        strcount++;                 // Увеличиваем счетчик переходов на новую строку
                        if (enteredlesson != str)  // Если введеный предмет не равен ни одному из хранящихся в базе
                        {
                            if (strcount != subjectscount)
                            {
                                fout << str << endl;    // В новый файл добавляю все названия предметов, кроме того, который хочу удалить   
                            }
                            else fout << str;
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
                            if (i == deletedchars || i == deletedchars - 1 || i == deletedchars - 2 || i == deletedchars - 3)   // Если я удаляю не первый предмет
                            {
                            }
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
                    cout << endl;
                }
            }
            else if (a == 0)
            {
            cout <<endl<<endl<<endl
                << "Действие 1 - 'Вывести данные'. Программа выведет список учеников и их оценки за четверть по предметам;" << endl
                << "Действие 2 - 'Сформировать файл с данными'. Программа создаст файл со списком учеников и их оценками за год по предметам;" << endl
                << "Действие 4 аналогично действию 2, за исключением сортировки учеников по алфавиту от А до Я;" << endl<<endl
                << "Выбрав действиее 5, добавляейте оценки без пробелов, в порядке выведенных предметов. Например:" << endl
                << "для ученика Сидорова необходимо ввести оценки 4 5 4 5 по следующим предметам Rus Mat Lit Phy соответственно." << endl
                << "Вводим Sidorov, жмем Enter, вводим 4545, жмем Enter." << endl<<endl
                << "Для удаления данных об ученике (действие 6), достаточно ввести его номер. Номер можно узнать, выбрав действие 1 (первый столбец Num);" << endl
                << "Выбрав действие 7, необходимо добавить предмет обучения, введя аббривиатуру из 3х символов, а также для каждого из ученкиков ввести оценку за четверть;" << endl
                << "Выбрав действие 8 нужно ввести только аббривиатуру предмета (3 символа) из предложенных, далее программа все сделает сама;" << endl
                << "Если возникнут вопросы, обращайтесь к системному администратору" << endl<<endl<<endl;
            }
            else exit(9);
        }  
    }
    while (a || !a);
}
