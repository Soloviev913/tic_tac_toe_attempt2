#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
#include <string>

using namespace std;

void Output(const string *, int);
string CheckWin(const vector<string> &, const vector<string> &);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    const int row = 3;
    bool isRestart = true;
    while (isRestart)
    {
        vector<string> arrVec;
        vector<string> vecQueue;

        string arr[row][row] = {{"%", "%", "%"},
                                {"%", "%", "%"},
                                {"%", "%", "%"}};
        Output(&arr[0][0], row);

        bool isRun = true;
        int countMt = 0;

        string *ptrArr = &arr[0][0];
        const int COUNT = 9;
        while (countMt < COUNT)
        {
            string motion;
            cout << "Введите символ и позицию от 1 до 9 \n";
            std::cin >> motion;
            string pos = motion.substr(motion.size() - 1);
            if (vecQueue.empty() == false && motion.substr(0, 1) == vecQueue.back())
            {
                cout << "Нельзя сходить 2 раза подряд \n";
            }
            else if (find(arrVec.begin(), arrVec.end(), pos) == arrVec.end() &&
                     motion.substr(motion.size() - 1) != "0")
            {
                string symbol = motion.substr(0, 1);
                vecQueue.push_back(symbol);
                arrVec.push_back(pos);
                ptrArr[stoi(pos) - 1] = symbol;
                Output(ptrArr, row);
                string win = CheckWin(arrVec, vecQueue);
                if (win != "")
                {
                    cout << "Победил игрок  " + win << endl;
                    break;
                }
                countMt++;
            }
            else
            {
                cout << "Ошибка: введите символ и позицию от 1 до 9 \n";
            }
        }
        const int NINE = 9;
        if (countMt == NINE)
        {
            cout << "Ничья\n";
        }

        cout << "Введите 1, чтобы начать заново, 0 - завершить игру" << endl;
        int restart;
        std::cin >> restart;
        isRestart = (restart == 1) ? true : false;
    }
}

void Output(const string *arr, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << arr[i * row + j] << " ";
        }
        cout << "\n";
    }
}

string CheckWin(const vector<string> &arrVec, const vector<string> &vecQueue)
{
    const int WIN_COUNT = 8;
    const string ARR_WINS[WIN_COUNT] = {"123", "456", "789", "147", "258", "369", "159", "357"};

    int iter = 0;

    while (iter != 2)
    {
        int i = iter;
        string underStr = "";

        while (i < arrVec.size())
        {
            underStr += arrVec[i];
            i += 2;
        }

        for (int i = 0; i < WIN_COUNT; i++)
        {
            bool isWin = true;

            const int THREE = 3;
            for (int j = 0; j < THREE; j++)
            {
                if (underStr.find(ARR_WINS[i][j]) == string::npos)
                {
                    isWin = false;
                    break;
                }
            }

            if (isWin)
            {
                return vecQueue[iter];
            }
        }
        iter++;
    }
    return "";
}