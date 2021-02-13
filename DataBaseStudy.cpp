#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        cout << "Здравствуйте пользователь. Меня зовут Анна и сегодня я помогу Вам разобраться с данной программой для взаимодействия с базой данных студентов и их оценок" << endl;
        cout << "Выберите действие ниже и введите соответствующую цифру" << endl << endl;
        string path = "myFile.txt";
        string pathLessons = "Lessons.txt";
        string pathSubjects = "Subjects.txt";
        string pathSubjects3 = "Subjects3.txt";
        string pathStudents = "Students.txt";
        string pathRatings = "Ratings.txt";
        string bufferpath = "C:\\Users\\User\\Desktop\\myFile1.txt";          // Путь на рабочий стол
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
        cout<< "0 - Подсказки и помощь" << endl
            << "1 - Вывести данные" << endl
            << "2 - Сформировать файл с данными" << endl
            << "3 - Вывести среднюю арифметическую оценку студента за семестр" << endl
            << "4 - Сформировать файл со студентами и их оценками, отсортированными по алфавиту от А до Я и вывести данные на экран" << endl
            << "5 - Сформировать файл со студентами и их оценками, отсортированными по алфавиту от Я до А и вывести данные на экран" << endl
            << "6 - Добавить студента и его оценки в базу данных" << endl
            << "7 - Удалить данные о студенте. Сначала рекомендуется выполнить действие 1 (узнать номер студента)" << endl
            << "8 - Добавить данные о предмете" << endl
            << "9 - Удалить данные о предмете и всю связанную с ним информацию" << endl
            << "10 - Вывести данные с расшифровкой аббревиатур предметов"<<endl
            << "11 - Добавить рашифровку аббревиатуры для предмета"<<endl
            << "12 - Закрыть программу"<<endl<<endl
            << "Введите номер действия: ";

        int maxsize = 0;
        // Проверка вводимых данных
        cin >> enteredvalue;                    
        size = enteredvalue.length();			// Вычисляем количество символов в строке
        bool err = false;						// Если err true, то введенное число некорректно
        const char* str = enteredvalue.c_str();	// Приводим строку к массиву char, что бы далее работать с функцией  isdigit
        if ((size > 1 || !isdigit(str[0])) && enteredvalue != "10" && enteredvalue != "11" && enteredvalue != "12") err = true;       // Если неправильно ввел данные

        if (err)
        {
            system("cls");
            cout << "Я не поняла того, что вы написали: " << enteredvalue << endl << endl;
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
            // cout << "Вы ввели правильное число: " << enteredvalue << endl;
            subjectscount = 0;
            fin.open(pathLessons);       // Считаем количество предметов
            if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
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
            system("cls");
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
    
                    if (a == 3)       // Средняя арифметическая оценка студента 
                    {
                        string enteredword;
                        bool foundoverlap = false;
                        cout << "Введите номер студента: ";
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
                                    if (str2[i] == '0') subjectscount--;
                                }
                                cout << "Среднее орифметическое значение всех оценок за семестр студента c фамилией: " << strname << " = " << summ / subjectscount << "\n\n";
                            }
                        }
                        if (!foundoverlap) cout << "Студента под номером: " << enteredword << " не существует\n";
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
                cout << "Файл создан на рабочем столе" << endl << endl;
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
                if (!fin.is_open() || !fout.is_open())  // Проверка, открылся ли файл
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    //cout << "Файл успешно открыт!" << endl;
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
                    
                    while (!fin.eof())          // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);      // Считывает данные из fin в переменную str
                        fout << str << " ";    // Выводим данные из переменной str в файл myFail объекта fout
                        if (a == 4) cout << str << " ";     //****1

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
                    string* pupil = new string[pupilcount];         // Массив студентов ///////////////////////////////////////////////////////////////////////////////////////////
                    string* allratings = new string[pupilcount];    // Массив оценок студентов  ////////////////////////
                    string* keys = new string[pupilcount];          // Массив номеров студентов
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
                        pupil[pupilnumber] = str;       // Записываю данные о студентах в массив
                        allratings[pupilnumber] = str2; // об оценках студентов
                        keys[pupilnumber] = strKeys;    // о номерах студентов в массив
                        // cout << allratings[pupilnumber] << endl;

                        (*ppupilnumber)++;              // считает количество студентов
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


                    // Сортировка по алфавиту//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    for (int i = 0; i < pupilcount; i++)     // если i меньше количества студентов
                    {
                        string minname = pupil[i];          // Первый студент = минимальный по алфавиту
                        quantitysymbolsfirst = pupil[i].length();
                        char minchar = pupil[i][0];         // Первая буква первого студента = минимальной по алфавиту
                        nameindex = i;                      // Индекс имени равен 0

                        string mratings = allratings[i];     // Минимальная оценка = 0 оценке
                        string mkeys = keys[i];              // Минимальный номер студента = 0му студенту


                        for (int j = i + 1; j < pupilcount; j++)    // С последующего после нулевого студента, пока j меньше количества студентов в базе
                        { 
                            quantitysymbolssecond = pupil[j].length();
                            if (quantitysymbolsfirst< quantitysymbolssecond)
                            {
                                for (int k = 0; k < quantitysymbolsfirst; k++)
                                {
                                    if (pupil[j][k] < minname[k])      // если каждый какой либо символ любого следующего слова меньше минимального, то имя с этим символом становится минимальным
                                    {
                                        minchar = pupil[j][0];      // Присваиваем min новому элементу
                                        minname = pupil[j];         // Тоже
                                        mratings = allratings[j];
                                        mkeys = keys[j];
                                        nameindex = j;              // Индекс min элемента
                                        quantitysymbolsfirst = pupil[j].length(); // Теперь это первое слово
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
                                    if (pupil[j][k] < minname[k])      // если каждый какой либо символ любого следующего слова меньше минимального, то имя с этим символом становится минимальным
                                    {
                                        minchar = pupil[j][0];      // Присваиваем min новому элементу
                                        minname = pupil[j];         // Тоже
                                        mratings = allratings[j];
                                        mkeys = keys[j];
                                        nameindex = j;              // Индекс min элемента
                                        quantitysymbolsfirst = pupil[j].length(); // Теперь это первое слово
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
                                    minchar = pupil[j][0];      // Присваиваем min новому элементу
                                    minname = pupil[j];         // Тоже
                                    mratings = allratings[j];
                                    mkeys = keys[j];
                                    nameindex = j;              // Индекс min элемента
                                    quantitysymbolsfirst = pupil[j].length(); // Теперь это первое слово
                                    less = false;
                                }
                            }
                            else if (quantitysymbolsfirst == quantitysymbolssecond)
                            {
                                for (int k = 0; k < quantitysymbolssecond; k++)
                                {
                                    if (pupil[j][k] < minname[k])      // если каждый какой либо символ любого следующего слова меньше минимального, то имя с этим символом становится минимальным
                                    {
                                        minchar = pupil[j][0];      // Присваиваем min новому элементу
                                        minname = pupil[j];         // Тоже
                                        mratings = allratings[j];
                                        mkeys = keys[j];
                                        nameindex = j;              // Индекс min элемента
                                        quantitysymbolsfirst = pupil[j].length(); // Теперь это первое слово
                                        break;
                                    }
                                    else if (pupil[j][k] > minname[k])
                                    {
                                        break;
                                    }
                                }
                            }                           
                        }
                        buffer = pupil[i];                   // Буфер для студентов и оценок
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
                    if (!fin.is_open() || !fout.is_open())  // Проверка, открылся ли файл
                    {
                        cout << "Ошибка открытия файла" << endl;
                    }
                    else
                    {
                        for (int i = 0; i< pupilcount + 1; i++)
                        {
                            str = "";
                            getline(fin, str);      // Считывает данные из fin в переменную str
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
                cout << "Файл создан на рабочем столе"<<endl;
                fin.open(path);
                fout.open(bufferpath);
                fout << fin.rdbuf();
                fin.close();
                fout.close();
            }
            else if (a == 6)
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
                    string allsubjects;     // Переменная для вывода в консоль предметов, по которым занимаются студенты
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
                    int size = 0;
                    cout << "Введите фамилию студента: ";
                    
                    cin >> newsurname;
                    while (newsurname.length()>15)
                    {
                        cout << "Фамилия студента не должна быть короче 15 символов. Введите фамилию еще раз: ";
                        cin >> newsurname;
                    }
                    
                    // Добавляю индекс нового студента
                    while (!finKeys.eof())      // Нахожу последний индекс по возрастанию
                    {
                        getline(finKeys, keystr);
                    }
                    
                    lastkey = stoi(keystr)+1;   // Преобразую string в int
                    


                    
                    cout << "Для этих предметов: " << allsubjects << "введите оценки студента: ";
                    cin >> newpupilratings;

                    size = newpupilratings.length();			// Вычисляем количество символов в строке
                    bool err = false;						// Если err true, то введенное число некорректно
                    const char* str = newpupilratings.c_str();	// Приводим строку к массиву char, что бы далее работать с функцией  isdigit
                    for (int i = 0; i < subjectscount; i++)
                    {
                        if (size > subjectscount || !isdigit(str[i]))
                        {
                            err = true;
                            break;
                        }

                        if (str[i]-48 < 0 || str[i] - 48 > 5)
                        {
                            err = true;       // Если неправильно ввел данные
                            break;
                        }
                    }
                    
                    while (err)
                    {
                        cout << "Вы ввели неправильные значения: " << newpupilratings << endl
                            << "Необходимо слитно в порядке выведенных предметов, ввести целочисленные оценки от 0 до 5"<<endl;
                        cout << "Введите оценки студента по предметам " << allsubjects << ": ";
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

                    for (int i = 0; !fin.eof(); i++) // Пока есть какие либо данные 
                    {
                        
                        str = "";
                        getline(fin, str);
                        surnames[i] = str;
                        allpupils = allpupils + str + " ";
                    }
                    fin.close();
                    fin.open(pathStudents);
                    cout << "Выберите фамилию студента из существующих в базе: " << endl << allpupils << endl;      // Которого хотите удалить
                    cout << "Введите ее: ";
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
                        cout << "Вы ввели несуществующее имя " << enteredword << endl << "Попробуйте еще раз: ";
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

                    ////////////////////////////////////////////////////////////////////////////// Номер (код студента)
                    for (int i = 0; !finKeys.eof(); i++) // Пока есть какие либо данные 
                    {

                        str = "";
                        getline(finKeys, str);
                        numes[i] = str;
                    }
                    finKeys.close();
                    finKeys.open(pathKeys);

                    cout << "Выберите код стдуента соответствующий фамилии: " << endl;

                    for (int i = 0; i < pupilcount; i++)
                    {
                        cout << numes[i] << " " << surnames[i] << endl;
                    }
                    cout << "Введите код: ";
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
                        cout << "Значение " << enteredkey <<" не соответстует введенной фамилии "<< endl << "Попробуйте еще раз: ";
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
            else if (a == 8)
            {
                int countfineof = 0;
                string lesson;
                finLessons.open(pathLessons);
                ratingsfout.open(bufferpathRatings);                // Открываем буферный файл с оценками для записи
                finRatings.open(pathRatings);                       // Открываем файл с оценками для чтения 
                fin.open(pathStudents);                             // Открываем файл со студентами для составления цикла для каждого студента добавить оценку по новому предмету
                fout.open(pathLessons, ofstream::app);         // Открываем файл с предметами
                if (!fout.is_open() || !ratingsfout.is_open() || !fin.is_open() || !finRatings.is_open())
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    // Добавление предмета
                    string subject;                                     
                    cout << "Введите абривиатуру предмета (3 буквы): ";
                    cin >> subject;
                    // Проверка вводимых данных
                    bool err = false;						
                    if (subject.length() > 3) err = true;      

                    while (err)
                    {
                        cout << "Аббривиатура должна быть не более 3х символов\nПопробуйте еще раз: ";
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
                        cout << "Такой предмет: " << subject << " уже есть, придумайте новый и повторите попытку\n";
                        cout << "Введите абривиатуру предмета (3 буквы): ";
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
                        cout << "Введите оценку студента: " << pupil << endl;
                        cin >> newpupilratings;

                        while (newpupilratings != "0" && newpupilratings != "1" && newpupilratings != "2" && newpupilratings != "3" && newpupilratings != "4" && newpupilratings != "5")
                        {
                            cout << "Вы ввели неправильную оценку или вообще не оценку: " << newpupilratings<<endl;
                            cout << "Повторите попытку: ";
                            cin >> newpupilratings;
                        }

                        getline(finRatings, pupilratings);      // Считываем оценки для каждого студента
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
                if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open())  cout << "Ошибка открытия файла" << endl;
                else
                {
                    strcount = 0;
                    cout << "Введите предмет из существующих в базе: " << lessons << endl;
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
                        cout << "Такого предмета нет, повторите попытку.\nВведите предмет из существующих в базе: ";
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
                        getline(fin, str);          // Записываем в str название предмета
                        strcount++;                 // Увеличиваем счетчик переходов на новую строку
                        if (enteredlesson != str)  // Если введеный предмет не равен ни одному из хранящихся в базе
                        {
                            if (strcount != subjectscount && !deletelaststr)
                            {
                                fout << str << endl;    // В новый файл добавляю все названия предметов, кроме того, который хочу удалить   
                            }
                            else if (strcount != subjectscount && deletelaststr && strcount!= subjectscount-1)
                            {
                                fout << str << endl;
                            }
                            else if (strcount != subjectscount && deletelaststr && strcount == subjectscount - 1) fout << str;
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
            cout << endl << endl << endl
                << "Действие 1 - 'Вывести данные'. Программа выведет список студентов и их оценки за четверть по предметам;" << endl
                << "Действие 2 - 'Сформировать файл с данными'. Программа создаст файл со списком студентов и их оценками за год по предметам;" << endl
                << "Действие 4 аналогично действию 2, за исключением сортировки студентов по алфавиту от А до Я;" << endl << endl
                << "Выбрав действиее 5, добавляейте оценки без пробелов, в порядке выведенных предметов. Например:" << endl
                << "для студента Сидорова необходимо ввести оценки 4 5 4 5 по следующим предметам Rus Mat Lit Phy соответственно." << endl
                << "Вводим Sidorov, жмем Enter, вводим 4545, жмем Enter." << endl << "0 - означает отсутствие данных. Такие значения в расчетх опускаются\n\n"
                << "Для удаления данных об студенте (действие 6), достаточно ввести его номер. Номер можно узнать, выбрав действие 1 (первый столбец Num);" << endl
                << "Выбрав действие 7, необходимо добавить предмет обучения, введя аббривиатуру из 3х символов, а также для каждого из студентов ввести оценку за четверть;" << endl
                << "Выбрав действие 8 нужно ввести только аббривиатуру предмета (3 символа) из предложенных, далее программа все сделает сама;" << endl
                << "Если возникнут вопросы, обращайтесь к системному администратору" << endl<<endl<<endl;
            }
            else if (a == 10)
            {
                finLessons.open(pathLessons);
                finSubjects.open(pathSubjects);
                string lesson;
                string subject;
                cout << endl << endl;
                cout << "Данные о предметах" << endl;
                if (!finLessons.is_open() && !finSubjects.is_open()) cout << "Ошибка открытия файла" << endl;
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