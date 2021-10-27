// Zadavha3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int n, c;
    std::cout << "This program gets array N*N of 1 and 0, and raotates it clockwise 90 degrees \n";
    std::cout << "Enter N\n";
    std::cin >> n;
    while (std::cin.fail() || n <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong n!\n";
        std::cout << "Enter n another time\n";
        std::cin >> n;
    }
    int** array = new int* [n];
    for (int i = 0; i < n; i++)
        array[i] = new int[n];
    std::cout << "Enter elements of the matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> array[i][j];
            // || (array[i][j] != 1 && array[i][j] != 0)
            while (std::cin.fail() || (array[i][j] != 1 && array[i][j] != 0))
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Wrong element's value!\n";
                std::cout << "Enter element № " << (i + 1) << ", " << (j + 1) << "  of the array another time\n";
                std::cin >> array[i][j];
            }
        }
    }

    for (int i = 0; i < (n-1)/2+1; i++)
    {
        for (int j = 0; j < (n-1)/2+1; j++)
        {
            c = array[i][j];
            array[i][j] = array[n - j - 1][i];
            array[n - j - 1][i] = array[n - i - 1][n - j - 1];
            array[n - i - 1][n - j - 1] = array[j][n - i - 1];
            array[j][n - i - 1] = c;
        }
    }

    std::cout << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
