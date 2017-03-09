#include "DynArray.h"

//constructors

DynArray::DynArray():
	m_capacity{ DYN_ARRAY_DEFAULT_SIZE },
	m_size{ 0 },
	m_data(new int[m_capacity])
{
}

DynArray::DynArray(size_t size , const int &value) : 
	m_capacity(size),
	m_size(size),
	m_data(new int[size])
{
	//fill(begin(), end(), value); És menys òptim ja que has de fer tres crides.
	for (int i = 0; i < size; i++)
	{
		m_data[i] = value;
	}
}

//destructor

DynArray::~DynArray()
{
	delete[] m_data;
	m_data = nullptr;
}

void DynArray::fill(int *first, int*last, int value)
{
	while (first != last)
	{
		*first = value; //Contenido de first
		++first; //Direcció de first
	}
}



void DynArray::push(const int &val)
{
	//1. if m_capacity i m_size son =, no hi ha espai i no podem fer push pk la matriu esta plena llavors hem de fer resize *
	//2. Resize, tenim que demanar una zona de memoria nova per tal de contenir tots aquests elements que ja tinc, més el que li faig el push.*
	//3.Copiar tots els valors de l'aray antiga al nou espai de memoria amb els espais adecuats per encabir-ho tot.*
	//4. Fer el push ficant l'element uq evolem pushejar a la nova array on hi ha tots els valors antics copiats.*
	//5. Liberar espacio, fer un delte de l'array antiga i redirigir el punter cap de l objecte cap a l'array nova, es a dir actualitzar punter.*
	//6 Actualitzar el size i capacity de lobjecte array.*


	if (m_capacity == m_size)
	{
		int *punterTemporal;
		punterTemporal = new int[m_capacity + 1];

		for (int c = 0; c < m_capacity; c++)
		{
			punterTemporal[c] == m_data[c];

		}
		punterTemporal[m_size] = val;
		delete m_data;
		m_data = nullptr;
		m_data = punterTemporal;
		m_size++;
		

		m_data[m_size + 1] = val;

		


}

void pop(void);
{

}




