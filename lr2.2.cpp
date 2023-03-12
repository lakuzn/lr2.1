#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int n = 10; //10 карт
    queue<int> a, b; //создаем котейнер очередь
    for (int i = 0, x; i < n / 2; ++i) {
        cin >> x;
        a.push(x);
    }
    for (int i = 0, x; i < n / 2; ++i) {
        cin >> x;
        b.push(x);
    } //вводим наши карты
    int move = 0; // ход
    while (!a.empty() && !b.empty() && move <= 1000000) //пока первая и вторая очереди не пустые, а также счетчик ходов меньше 100000
    {
        int ac = a.front(), bc = b.front(); //переписываем в ас первые элементы a и в bc первые элементы b
        a.pop(); 
        b.pop(); //удаляем их
        queue<int>* win; //создаем указатель на нашу очередь
        if (ac == 0 && bc == n - 1) { //выписываем случаи 0 и 9
            win = &a;
        }
        else {
            if (bc == 0 && ac == n - 1) {
                win = &b;
            }
            else
                if (ac > bc) { //иф для нашей игры, если первый элемент а больше первого элемента b, то а выигрывает
                    win = &a;
                }
                else win = &b;
        }
        win->push(ac); win->push(bc);
        ++move; //увеличиваем счетчик кодов 
    }
    if (a.empty()) //выводим результат
        cout << "second " << move << endl;
    else
        if (b.empty())
            cout << "first " << move << endl;
        else cout << "botva";
}