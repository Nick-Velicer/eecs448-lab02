/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;
	//checking if we are searching an empty list
	if (m_front == nullptr) {
		isFound = false;
	}
	//checking if the front has the correct value
	else if (temp->getValue() == value) {
		isFound = true;
	}
	//iterating through the list and checking for the correct value at each node
	else if (temp->getNext() != nullptr) {
		while (temp->getNext() != nullptr) {
			temp = temp->getNext();
			if (temp->getValue() == value) {
				isFound = true;
			}
		}
	}
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;
	//checking if the list is already empty
	if (m_size == 0) {
		isRemoved = false;
	}
	//if the list is size 1, delete the front
	else if (m_size == 1) {
		delete m_front;
		m_size = 0;
		isRemoved = true;
	}
	//if the list is size 2, delete the second element
	else if (m_size == 2) {
		delete m_front->getNext();
		m_size = 1;
		isRemoved = true;
	}
	//if the list is size 3+, iterate through and find the second to last node, then delete the last one
	else {
		secondintoLast = m_front;
		for (int i = 0; i < (m_size-1); i++) {
			secondintoLast = secondintoLast->getNext();
		}
		lastNode = secondintoLast->getNext();
		secondintoLast->setNext(nullptr);
		delete lastNode;
		m_size -= 1;
		isRemoved = true;
	}
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
