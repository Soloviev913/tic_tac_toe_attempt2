#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
#include <string>

using namespace std;

void Output(const string *, int);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    const int row = 3;
    vector<string> arrVec;

    string arr[row][row] = {{"%", "%", "%"},
                            {"%", "%", "%"},
                            {"%", "%", "%"}};
    Output(&arr[0][0], row);
    bool isRun = true;
    int countMt = 0;

    string* ptrArr = &arr[0][0];
    const int COUNT = 9;
    while (countMt < COUNT)
    {
        string motion;
        cout << "Введите символ и позицию от 1 до 9 \n";
        cin >> motion;
        if (find(arrVec.begin(), arrVec.end(), motion.substr(motion.size() - 1)) == arrVec.end() &&
            motion.substr(motion.size() - 1) != "0")
        {
            string pos = motion.substr(motion.size() - 1);
            arrVec.push_back(pos);
            ptrArr[stoi(pos) - 1] = motion.substr(0, 1);
            Output(ptrArr, row);
            countMt++;
        }
        else
        {
            cout << "Ошибка: введите символ и позицию от 1 до 9 \n";
        }
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
