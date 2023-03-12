#include <iostream>
#include <string>
#include <stack>
 
using namespace std; 

int main() {
    string s;
    getline(cin, s); //вводим нашу строчку
    stack<int> stack; //создаём стек, он мне показался наиболее удобным для выполнения этой задачи
    for (char c : s) // здесь мы переносим копию каждого элемента из нашей строчки в новую переменную 'c'
        if (isdigit(c)) //проверяем является ли 'c' цифрой 
            stack.push(c - '0');
        else if (c != ' ') { //если не является, запоминаем верхний элемент стека в переменной 'a' и затем удаляем его
            const int a = stack.top();
            stack.pop();
            const int b = stack.top(); // то же самое 
            stack.pop();
            if (c == '+') //потом в отличие от знака мы складываем, умножаем или вычитаем 
                stack.push(a + b);
            else if (c == '-')
                stack.push(b - a);
            else
                stack.push(a * b);
        }
    cout << stack.top(); //выводим наш результат
    return 0;
}