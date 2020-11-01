#include <iostream>
#include "BitsPrinter.h"
#include <limits>



int main() // “очка входу в программу, так ќ— понимает откуда надо начинать выполнение программы
{
	// “ипы данных
	{
		BitsPrinter<char>::PrintBits(5);
		BitsPrinter<signed char>::PrintBits(-127);
		BitsPrinter<unsigned char>::PrintBits(129);
		BitsPrinter<float>::PrintBits(-59.7);
		BitsPrinter<int>::PrintBits(59);

		double a = 69.4;
		double b = 79.4;
		b -= 10;
		if (std::abs(a - b) < std::numeric_limits<double>::epsilon())
		{
			std::cout << "equal\n";
		}
		;
	}
	// stack
	{
		char first_var = 5; // ћы выдел€ем на стеке 1 байт под переменную first_var и записываем 
							// по этому адресу значение 5. ¬ контексте €зыка c++ мы можем говорить,
							// что мы инициализировали переменную first_var числом 5

		char* first_var_addr = &first_var; // переменна€ first_var_addr- это указатель типа char. 
										   // first_var_addr хранит в себе адрес по которому находитс€ 
										   // переменна€ first_var

		// ¬ыведем информацию в консоль
		std::cout << "=============================" << std::endl;
		std::cout << "first_var: \nvalue stored: " << static_cast<short>(first_var)
			<< "\nfirst_var was allocated on stack\nfirst_var address: "
			<< std::hex << reinterpret_cast<size_t>(first_var_addr)
			<< "\nfirst_var size: " << std::dec << sizeof(first_var)
			<< "\nfirst_var_addr size: " << sizeof(first_var_addr) << std::endl;
		std::cout << "=============================" << std::endl;
	}
	// heap
	{
		int* second_var; // объ€вл€ем указатель типа int
		second_var = new int; // запрашиваем у ќ— 4 байта пам€ти
		*second_var = 5; // разыменовываем указатель (считай обращаемс€ к участку пам€ти на который указывает
						 // указатель second_var), далее записываем в этот участок пап€ти число 5


		// ¬ыведем информацию в консоль
		std::cout << "=============================" << std::endl;
		std::cout << "second_var: \nvalue stored: " << *second_var
			<< "\nfirst_var was allocated on heap\nsecond_var address: "
			<< std::hex << reinterpret_cast<size_t>(second_var)
			<< "\n*second_var size: " << std::dec << sizeof(*second_var)
			<< "\nsecond_var size: " << sizeof(second_var) << std::endl;
		std::cout << "=============================" << std::endl;
		delete second_var; // освобождаем пам€ть
	}

	return 0;
}