#pragma once
#include <type_traits>
#include <string>
#include <iostream>

template <typename T, bool is_basic_type = std::is_scalar<T>::value>
class BitsPrinter
{
public:
	static void PrintBits(const T& val);
};


template <typename T>
class BitsPrinter<T, false>
{
public:
	static void PrintBits(const T& val);
};

template <typename T>
class BitsPrinter<T, true>
{
public:
	static void PrintBits(const T& val);
};

template<typename T>
inline void BitsPrinter<T, false>::PrintBits(const T& val)
{
	std::cout << "unable to print bits (wrong type)" << std::endl;
}

template<typename T>
inline void BitsPrinter<T, true>::PrintBits(const T& val)
{
	std::cout << "=============================\n";
	std::cout << "Typename: " << typeid(T).name() << '\n';
	std::cout << "Value: ";
	if (sizeof(T) - 1)
	{
		std::cout << val << '\n';
	}
	else
	{
		std::cout << static_cast<short>(val) << '\n';
	}
	
	std::cout << "Bits: ";
	size_t sz = sizeof(T) << 3;
	for (int i = sz - 1; i >= 0; --i)
	{
		std::cout << ((val >> i) & 1);
	}
	std::cout << '\n';
	std::cout << "=============================" << std::endl;
}



template<>
inline void BitsPrinter<float, true>::PrintBits(const float& val)
{
	std::cout << "=============================\n";
	std::cout << "Typename: " << typeid(float).name() << '\n';
	std::cout << "Value: " << val << '\n';
	

	std::cout << "Bits: ";
	size_t sz = sizeof(float) << 3;
	
	union
	{
		float f;
		int v;
	}converter;
	converter.f = val;

	for (int i = sz - 1; i >= 0; --i)
	{
		std::cout << ((converter.v >> i) & 1);
	}
	std::cout << '\n';
	std::cout << "=============================" << std::endl;
}

template<>
inline void BitsPrinter<double, true>::PrintBits(const double& val)
{
	std::cout << "=============================\n";
	std::cout << "Typename: " << typeid(double).name() << '\n';
	std::cout << "Value: " << val << '\n';


	std::cout << "Bits: ";
	size_t sz = sizeof(double) << 3;
	union
	{
		double f;
		long long int v;
	}converter;
	converter.f = val;

	for (int i = sz - 1; i >= 0; --i)
	{
		std::cout << ((converter.v >> i) & 1);
	}
	std::cout << '\n';
	std::cout << "=============================" << std::endl;
}
