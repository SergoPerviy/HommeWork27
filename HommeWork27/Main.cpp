#include <iostream>
#include <string>

/*
Задание
Создайте структуру Movie, которая обладает следующим набором полей:
● std::string title – название фильма;
● int year – год выхода фильма;
● std::string genre – жанр фильма;
● unsigned int duration – продолжительность фильма в
минутах;
● unsigned int price – цена за диск фильма.
*/

struct Movie {
	std::string title; 
	int year{};
	std::string genre;
	unsigned int duration{};
	unsigned int price{};
};

/*
Задача 1
Создайте функцию print_movie, которая принимает объект структуры и выводит всю информацию о нём (т. е. выводит значения полей объекта).
*/

void print_movie(const Movie& M) {
	std::cout << "1. Название: " << M.title << ';' << std::endl;
	std::cout << "2. Год выхода: " << M.year << ';' << std::endl;
	std::cout << "3. Жанр: " << M.genre << ';' << std::endl;
	std::cout << "4. Продолжительность (мин): " << M.duration << ';' << std::endl;
	std::cout << "5. Цена за диск (руб): " << M.price << '.' << "\n\n";
}

//Функция для вывода списка фильмов для Задачи №3
void print_title(Movie arr[], const int length) {
	std::cout << "Список фильмов:\n";
	for (int i = 0; i < length; ++i) {
		std::cout << i + 1 << '.' << arr[i].title << std::endl;
	}
	std::cout << "\n";
}

/*
Задача 2
Создайте функцию expensive, которая принимает массив объектов структуры и его длину, после чего возвращает ОБЪЕКТ из массива с самой высокой 
ценой за диск. Чтобы вернуть объект, необходимо при создании функции использовать структуру Movie как тип возвращаемого значения.
*/

Movie expensive(Movie films[], const int length) {
	Movie expensiveMovie = films[0];
	for (int i = 1; i < length; ++i) {
		if (films[i].price > expensiveMovie.price) {
			expensiveMovie = films[i];
		}
	}
	return expensiveMovie;
}

/*
Задача 3
Создайте функцию update_info, которая принимает объект структуры и позволяет поменять какую-нибудь информацию об этом объекте. 
Для решения данной задачи необходимо в качестве параметра функции использовать указатель или ссылку на объект.
*/

void update_info(Movie& M) {
	int key{};
	do {
		std::cout << "Какой пункт изменить?(введите от 1-5 или ""0"" для выхода из меню изменений) -> ";
		std::cin >> key;
		std::cin.ignore();
		switch (key) {
		case 1: 
			std::cout << "Новое название -> ";
			std::getline(std::cin, M.title);
			break;

		case 2: 
			std::cout << "Новая дата выхода -> ";
			std::cin >> M.year; 
			break;

		case 3: 
			std::cout << "Новый жанр -> ";
			std::getline(std::cin, M.genre);
			break;

		case 4: 
			std::cout << "Новое время -> ";
			std::cin >> M.duration; 
			break;

		case 5: 
			std::cout << "Новая цена -> ";
			std::cin >> M.price; 
			break;

		case 0: 
			std::cout << "Завершение процесса без изменений\n\n";
			break;
		}
		if(key != 0 && key <6) std::cout << "Изменения внесены!\n\n";

	} while (key != 0 );
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	//Создание структур ТОП 3 фильма, по моей версии и демонстрация работы функции print_movie
	std::cout << "Задача №1.\nФильмы:\n";
	Movie film1{ "Матрица", 1999, "Фантастика, боевик", 136, 999 };
	print_movie(film1);
	
	Movie film2{ "Властелин колец II Две крепости", 2002, "Фэнтези, приключения", 179, 888 };
	print_movie(film2);

	Movie film3{ "Терминатор", 1984, "Фантастика, боевик", 108, 777 };
	print_movie(film3);

	//Демонстрация работы функции expensive, которая опрелеояет фильм с самой высокой стоимость за диск.
	const int size = 3;
	Movie films[size]{ film1, film2, film3};
	std::cout << "Задача№2\nФильм с наибольшей стоимостью за диск: " << expensive(films, size).title << ".\n\n";
	
	//Демонстрация работы функции update_info, которая позволяет вносить изменения в поля структуры.
	std::cout << "Задача №3\n";
	int key{};
	print_title(films, size); //Демонстрация вспомогательной функции для вывода списка фильмов
	do {
		std::cout << "Выбирете фильм из списка, чтобы внести изменения, или нажмите ""0"" для завершения работы: ";
		std::cin >> key;
		std::cin.ignore();
		switch (key) {
		case 1:
			print_movie(film1);
			update_info(film1); 
			break;

		case 2:
			print_movie(film2);
			update_info(film2); 
			break;

		case 3:
			print_movie(film3);
			update_info(film3); 
			break;
		};
	} while (key != 0);

	return 0;
}