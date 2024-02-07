#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <Windows.h>

using namespace std;

string swapFirstAndLastSentence(const string& input);
int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите строку, состоящую из нескольких предложений:\n";
    string line;
    getline(cin, line);
    if (line.empty() || line.find_first_not_of(" ") == string::npos)
    {
        cout << "Ошибка ввода!";
        return 0;
    }
    else
    {
        cout << "Исходная строка:\n" << line << "\n";
    }
    string swap = swapFirstAndLastSentence(line);
    cout << "Полученная строка:\n" << swap;
    return 0;
}
string swapFirstAndLastSentence(const string& line)
{
    // Разделим строку на предложения
    vector<string> sentences;
    istringstream iss(line);
    string sentence;
    while (getline(iss, sentence, '.')) {
        if (!sentence.empty()) {
            sentences.push_back(sentence);
        }
    }
    // Если предложений меньше 2, вернуть исходную строку
    if (sentences.size() < 2) {
        cout << "Минимальное количество предложений - 2!\n";
        return 0;
    }
    // Поменяем местами первое и последнее предложение
    swap(sentences[0], sentences[sentences.size() - 1]);
    // Склеим предложения в одну строку
    string line2;
    for (const auto& s : sentences) {
        line2 += s + ". ";
    }
    return line2;
}
