#include <iostream>
#include <fstream> //подключение библиотеки хранящий в себе, классы для работы с файловыми потоками
#include <string>
bool statistic(std::string str) {
	std::oftream out;
	out.open("stats.txt", std::ios::app);
	if (out.is_open()) {
		out << str << ' ' << str.length() << '\n';
		out.close();
		return true;
	}
	return false;
}

void print_file(std::string paht) {
	static std::ifstream in;
	in.open(paht);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();
	}
}

void clear_file(std::sting paht) {
	static std::ofstream out;
	out.open(paht);
	if (out.is_open())
		out.close;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string path = "file.txt";//любые расширения файлы
	//Запись в файл ofstream
	
	//std::ofstream out(path);//открытие файла
	std::ofstream out;//создание файла в случает его отсутсвия, либо записывает
	out.open(path, std::ios::app); 

	if (out.is_open()) {//открытие файла
		std::cout << "Файл открыт для записи.\n";

		std::cout << "Введите строку: ";
		std::string str;
		std::getline(std::cin, str);
		out << str << '\n';//запись в файл, обязательно нужна пустая cтрока

		out.close();//закрытие файла
	}
	else
		std::cout << "Ошибка открытия файла\n";

	//Чтение из файла ofstream
	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "Содержимое файла:\n";
		//Посимвольное считывание
		//char sym;
		//while (in.get(sym))
		//	std::cout << sym;

		//Пословное считывание 
		//std::string word;
		//while (!in.eof()) {
			//std::string word;
			//in >> word;
			//std::cout << word << std::endl;
		//}

		//Построчное считывание
		std::string str;
		while (std::getline(in, str)) 
			std::cout << str << std::endl;
		

		in.close();
	}
	else
		std::cout << "Ошибка открытия файла!\n";
	//Удаление файла
	if (remove(path.c_str()) == 0) //удаляется файл, полностью
		std::cout << "Файл удален!\n";
	else
		std::cout << "Ошибка удаления файла!\n";

	//Задача 1
	std::cout << "Задача 1.\nВведите строку:";
	std::string str1;
	std::getlin(std::cin, str1);
	if (statistic(str1))
		std::cout << "запись добавлена.\n\n";
	else
		std::cout << "Ошибка!\n\n";

	//Задача 2 усл.
	std::cout << "Задача 2.\n";
	int operation;
	do {
		std::cout << "Выберите действие:\n\n";
		std::cout << "1. Добавить содержимое файла;\n";
		std::cout << "2.Вывести содержимое;\n";
		std::cout << "3.Очистить файл;\n";
		std::cout << "4.Завершить работу;\n";
		std::cout << "Ввод -> ";
		std::cin >> operation;

		switch (operation) {
		case 1: {
			std::cout << "Введите строку:\n";
			std::con.ignore;
			std::string str2;
			std::getline(std::cin, str2);
			statistic(str2);
			std::cout << "Статистика внесена.\n\n";
			break;
		}
		case 2:
			std::cout << "Содержимое файла:\n";
			print_file("stats.txt");
			break;
		}
		case 3: {
			std::cout << "Вы уверены что хотите очистить файл? (y/n)";
			char answer;
			std::cin >> answer;
			if (answer == 'y') {
				clear_file("stats.txt");
				std::cout << "Файл очещен\n\n":
			}
			else
				std::cout << "Отмена операции!";
			break;
		}
		case 4:
			std::cout << "Завершение работы...\n";
			break;
		default:
			std::cout << "Ошибка ввода!\n\n";

	}while(operation != 4)




	return 0;
}