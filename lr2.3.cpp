﻿#include<iostream>
#include<string>
using namespace std;

int main()
{
    string st = ""; //вводим и идентифицируем нашу строчку
    int i = 0;
    cin >> st;
    for (;;) //перебираем нашу скобочную последовательность начиная с i=0 и делаем i++
    {
        i = 0;
        while (st[i] != '\0') //пока строчка не пустая:
        {

            if (st[i] == '[' && st[i + 1] == ']' ||
                st[i] == '(' && st[i + 1] == ')' ||
                st[i] == '{' && st[i + 1] == '}') //если этот элемент и следующий — одинаковые скобки, то мы их удаляем
            {
                st.erase(i, 2);
                break;
            }
            i++;
        }
        if (st[i] == '\0') //если в итоге получается пустая строчка, то скобочная последовательность была правильной 
        {
            if (st.size() == 0)
                cout << "yes";
            else
                cout << "no";

            break;
        }
    }
    return 0;
}
    
