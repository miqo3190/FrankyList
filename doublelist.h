#include <iostream>

template <class T>
class List
{
public:
	void push_back(T data)
	{
		if(head == nullptr)
		{
			head = new node;
			head->m_data = data;
			asc = desc = tail = head;
		}
		else
		{
			node* tmp = new node;
			tmp->m_data = data;
			tmp->m_prev = tail;
			tail->m_next = tmp;
			tail = tmp;
			tail->m_next = nullptr;
			putSort(tail);
		}
	}
	void push_front(T data)
	{
		if (head == nullptr)
		{
			head = new node;
			head->m_data = data;
			head->m_next = nullptr;
			head->m_prev = nullptr;
			tail = asc = desc = head;
		}
		else
		{
			node* tmp = new node;
			tmp->m_data = data;
			tmp->m_prev = nullptr;
			tmp->m_next = head;
			head->m_prev = tmp;
			head = tmp;
			putSort(head);
		}
	}
	void pop_back()
	{
		node* tmp = tail;
		tail = tail->m_prev;
		tail->m_next = nullptr;
		delete tmp;
	}
	void pop_front()
	{
		node* tmp = head;
		head = head->m_next;
		head->m_prev = nullptr;
		delete tmp;
	}
	T front() 
	{
		return head->m_data; 
	}
	T back() 
	{
		return tail->m_data;
	}
	int getSize()
	{
		int size = 0;
		node* curr = head;
		while (curr != nullptr)
		{
			curr = curr->m_next;
			size++;
		}
		return size;
	}
	void insert(int id, T data)
	{
		if (id < 0 || id > getSize())
		{
			throw std::invalid_argument("throw");
		}
		else if (id == 0)
		{
			push_front(data);
		}
		else if (id == getSize())
		{
			push_back(data);
		}
		else
		{
			node* curr = head;
			while (id--)
			{
				curr = curr->m_next;
			}
			node* currPrev = curr->m_prev;
			node* tmp = new node;
			tmp->m_data = data;
			tmp->m_next = curr;
			curr->m_prev = tmp;
			currPrev->m_next = tmp;
			tmp->m_prev = currPrev;
			putSort(tmp);
		}
	}
	void print()
	{
		node* tmp = asc;
		while (tmp)
		{
			std::cout << tmp->m_data<<" ";
			tmp = tmp->m_desc;
		}
	}
private:
	struct node
	{
		T m_data = 0;
		node* m_next{};
		node* m_prev{};
		node* m_asc{};
		node* m_desc{};
	};
	void putSort(node* lhs)
	{
		node* tmp;
		if (lhs->m_data > desc->m_data)
		{
			desc->m_desc = lhs;
			lhs->m_asc = desc;
			lhs->m_desc = nullptr;
			desc = lhs;
		}
		else if (lhs->m_data < asc->m_data)
		{
			asc->m_asc = lhs;
			lhs->m_desc = asc;
			lhs->m_asc = nullptr;
			asc = lhs;
		}
		else
		{
			tmp = asc;
			while (lhs->m_data > tmp->m_data)
			{
				tmp = tmp->m_desc;
			}
			lhs->m_desc = tmp;
			lhs->m_asc = tmp->m_asc;
			tmp->m_asc->m_desc = lhs;
			tmp->m_asc = lhs;
		}

	}
	node* head{};
	node* tail{};
	node* asc{};
	node* desc{};
};