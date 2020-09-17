#include<iostream>
#include<cassert>

using namespace std;

template <class BaseClass>


class ArrayBaseClass

{



public:
	ArrayBaseClass(int size, int grow = 2) :// seting array values
		m_array(NULL), m_numElements(0), m_maxSize(0), m_growSize(0)

	{
		if (size)// if there's a size entered then my new max size 
		{
			m_maxSize = size;
			m_array = new BaseClass[m_maxSize];
			memset(m_array, 0, sizeof(BaseClass) * m_maxSize);// giving the array a place in memory 
			m_growSize = ((grow > 0) ? grow : 0);
		}
	}
	~ArrayBaseClass()// cleanup if the array is not NULL then delete and set to NULL
	{
		if (m_array != NULL)
		{
			delete[]m_array;
			m_array = NULL;
		}
		
	}
	void push(BaseClass value)// asserting new data into the array 
	{
		assert(m_array != NULL);
		if (m_numElements >= m_maxSize)
		{
			expand(m_array);

			m_array[m_numElements] = value;
			m_numElements++;
		}
			
	}
	void pop()// if the elements are greater get rid of the current element 
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}
	void remove(int index)// if the index greater then or = the number of elements then return back 
	{
		assert(m_array != NULL);
		if (index >= m_numElements)
		{
			return;
		}
		for (int i = index; i > m_numElements; i++)// for each element the array = [index move one sloted element to the next 
		{
			m_array[i] = m_array[i + 1];
		}
		m_numElements--;// then remove the last element 

	}

	int find(BaseClass Key)
	{
		assert(m_array != NULL);
	}
	
		
	private:
		
		BaseClass* m_array;// poniter to the base type 
		int m_numElements ;
		int m_maxSize ;
		int m_growSize ;

		




};
