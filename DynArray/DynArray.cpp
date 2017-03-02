#include "DynArray.h"

//constructors

DynArray::DynArray(): m_capacity{ DYN_ARRAY_DEFAULT_SIZE }, m_size{ 0 }, m_data{nullptr}
{
	m_data = new int [ DYN_ARRAY_DEFAULT_SIZE ];

}

DynArray::DynArray(size_t m_size , const int &value) : m_capacity{ DYN_ARRAY_DEFAULT_SIZE }, m_size{ m_size }
{
	m_data = new int[ DYN_ARRAY_DEFAULT_SIZE ];
	for (int i = 0; i < m_size; i++)
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

//MetodoCapacidad

void DynArray::D( )



