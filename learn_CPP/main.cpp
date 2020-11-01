#include <iostream>
#include "BitsPrinter.h"
#include <limits>



int main() // ����� ����� � ���������, ��� �� �������� ������ ���� �������� ���������� ���������
{
	// ���� ������
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
		char first_var = 5; // �� �������� �� ����� 1 ���� ��� ���������� first_var � ���������� 
							// �� ����� ������ �������� 5. � ��������� ����� c++ �� ����� ��������,
							// ��� �� ���������������� ���������� first_var ������ 5

		char* first_var_addr = &first_var; // ���������� first_var_addr- ��� ��������� ���� char. 
										   // first_var_addr ������ � ���� ����� �� �������� ��������� 
										   // ���������� first_var

		// ������� ���������� � �������
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
		int* second_var; // ��������� ��������� ���� int
		second_var = new int; // ����������� � �� 4 ����� ������
		*second_var = 5; // �������������� ��������� (������ ���������� � ������� ������ �� ������� ���������
						 // ��������� second_var), ����� ���������� � ���� ������� ������ ����� 5


		// ������� ���������� � �������
		std::cout << "=============================" << std::endl;
		std::cout << "second_var: \nvalue stored: " << *second_var
			<< "\nfirst_var was allocated on heap\nsecond_var address: "
			<< std::hex << reinterpret_cast<size_t>(second_var)
			<< "\n*second_var size: " << std::dec << sizeof(*second_var)
			<< "\nsecond_var size: " << sizeof(second_var) << std::endl;
		std::cout << "=============================" << std::endl;
		delete second_var; // ����������� ������
	}

	return 0;
}