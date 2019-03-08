#pragma once
#include <iostream>
#include <iomanip>
#include "iterator.h"
#include "queue.h"
#include "list.h"

using namespace std;

template <class T>
class tree{
private:
	class node {
	public:
		char color;
		size_t key;
		T data;
		node*left;
		node*right;
		node*prev;
		node(size_t key, T data);
		~node();
	};
	node*root;
	size_t size;
public:
	tree();
	~tree();
	class BfsIterator : public Iterator<T> {
	private:
	Queue *currentNodes;
	public:
		BfsIterator(node *root) {
			currentNodes = new Queue();
			if (root) currentNodes->pushBack(static_cast<void*>(root));
		}
		void next();
		size_t current_key();
		T current_data();
		char current_color();
		bool hasNext();
	};
	Iterator<T> *createBfsIterator();
	void rotate_left(node*cur);
	void rotate_right(node*cur);
	void insert(size_t ket, T data);
	void insert_case1(node*cur);
	void insert_case2(node*cur);
	void insert_case3(node*cur);
	void insert_case4(node*cur);
	void insert_case5(node*cur);
	void finding(int*check, T*finded, size_t key);
	bool contains(size_t key);
	void remove_one_child(node*cur);
	void remove(size_t key);
	void remove_case1(node*cur);
	void remove_case2(node*cur);
	void remove_case3(node*cur);
	void remove_case4(node*cur);
	void remove_case5(node*cur);
	void remove_case6(node*cur);
	void replace_node(node*cur, node*child);
	void clear();
	list<size_t> get_keys();
	list<T> get_values();
};

template<class T>
Iterator<T> * tree<T>::createBfsIterator() {
	return new BfsIterator(root);
}

template<class T>
void  tree<T>::BfsIterator::next() {
	node* current = static_cast<node*>(currentNodes->front());
	currentNodes->popFront();
	if (current->left) currentNodes->pushBack(static_cast<void*>(current->left));
	if (current->right) currentNodes->pushBack(static_cast<void*>(current->right));
}

template<class T>
size_t tree<T>::BfsIterator::current_key() {
	return (static_cast<node*>(currentNodes->front()))->key;
}

template<class T>
T tree<T>::BfsIterator::current_data() {
	return (static_cast<node*>(currentNodes->front()))->data;
}


template<class T>
char tree<T>::BfsIterator::current_color() {
	return (static_cast<node*>(currentNodes->front()))->color;
}

template<class T>
bool  tree<T>::BfsIterator::hasNext() {
	return !currentNodes->isEmpty();
}

template<class T>
inline tree<T>::node::node(size_t key, T data)
{
	this->key = key;
	this->data = data;
	color = 'r';
	left = NULL;
	right = NULL;
	prev = NULL;
}

template<class T>
inline tree<T>::node::~node()
{
}

template<class T>
inline void tree<T>::rotate_left(node * cur)
{
	node *pivot = cur->right;
	pivot->prev = cur->prev;
	if (cur->prev != NULL) 
	{
		if (cur->prev->left == cur)
			cur->prev->left = pivot;
		else
			cur->prev->right = pivot;
	}
	cur->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->prev = cur;
	cur->prev = pivot;
	pivot->left = cur;
	if (root == cur)
		root = pivot;
}

template<class T>
inline void tree<T>::rotate_right(node * cur)
{
	node *pivot = cur->left;
	pivot->prev = cur->prev;
	if (cur->prev != NULL) {
		if (cur->prev->left == cur)
			cur->prev->left = pivot;
		else
			cur->prev->right = pivot;
	}
	cur->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->prev = cur;
	cur->prev = pivot;
	pivot->right = cur;
	if (root == cur)
		root = pivot;
}

template<class T>
inline tree<T>::tree()
{
	size = 0;
	root = NULL;
}

template<class T>
inline tree<T>::~tree()
{
	clear();
}

template<class T>
inline void tree<T>::insert_case1(node*cur)
{
	if (cur->prev == NULL)
		cur->color = 'b';
	else
		insert_case2(cur);
}

template<class T>
inline void tree<T>::insert_case2(node*cur)
{
	if (cur->prev->color == 'r')
		insert_case3(cur);
}

template<class T>
inline void tree<T>::insert_case3(node*cur)
{
	node*parent = cur->prev;
	node*granny = NULL;
	if (parent != NULL)
		granny = parent->prev;
	node*uncle = NULL;
	if (granny != NULL)
		if (granny->left == parent)
			uncle = granny->right;
		else
			uncle = granny->left;
	if ((uncle != NULL) && (uncle->color == 'r'))
	{
		cur->prev->color = 'b';
		uncle->color = 'b';
		granny->color = 'r';
		insert_case1(granny);
	}
	else
		insert_case4(cur);
}

template<class T>
inline void tree<T>::insert_case4(node*cur)
{
	node*parent =cur->prev;
	node*granny = NULL;
	if (parent != NULL)
		granny = parent->prev;
	if ((cur == cur->prev->right) && (cur->prev == granny->left))
	{
		rotate_left(parent);
		cur = cur->left;
	}
	else if ((cur == cur->prev->left) && (cur->prev == granny->right))
	{
		rotate_right(parent);
		cur = cur->right;
	}
	insert_case5(cur);
}

template<class T>
inline void tree<T>::insert_case5(node*cur)
{
	node*parent = cur->prev;
	node*granny = NULL;
	if (parent != NULL)
		granny = parent->prev;
	cur->prev->color = 'b';
	granny->color = 'r';
	if ((cur == cur->prev->left) && (cur->prev == granny->left))
		rotate_right(granny);
	else
		rotate_left(granny);
}

template<class T>
inline void tree<T>::insert(size_t key, T data)
{
	node*cur;
	if (root == NULL)
	{
		root = new node(key, data);
		cur = root;
		cur->left = new node(key, data);
		cur->left->color = 'n';
		cur->left->prev = cur;
		cur->left->left == NULL;
		cur->left->right = NULL;
		cur->right = new node(key, data);
		cur->right->color = 'n';
		cur->right->prev = cur;
		cur->right->left = NULL;
		cur->right->right = NULL;
	}
	else
	{
		cur = root;
		node*prev = NULL;
		while (cur->color != 'n')
		{
			prev = cur;
			if (key < (cur->key))
				cur = cur->left;
			else
				cur = cur->right;
		}
		if (key < (prev->key))
		{
			prev->left->key = key;
			prev->left->data = data;
			prev->left->color = 'r';
			prev->left->left = new node(key, data);
			prev->left->left->color = 'n';
			prev->left->left->prev = prev->left;
			prev->left->left->left = NULL;
			prev->left->left->right = NULL;
			prev->left->right = new node(key, data);
			prev->left->right->color = 'n';
			prev->left->right->prev = prev->left;
			prev->left->right->left = NULL;
			prev->left->right->right = NULL;
			(prev->left)->prev = prev;
			cur = prev->left;
		}
		else
		{
			prev->right->key = key;
			prev->right->data = data;
			prev->right->color = 'r';
			prev->right = new node(key, data);
			prev->right->left = new node(key, data);
			prev->right->left->color = 'n';
			prev->right->left->prev = prev->right;
			prev->right->left->left = NULL;
			prev->right->left->right = NULL;
			prev->right->right = new node(key, data);
			prev->right->right->color = 'n';
			prev->right->right->prev = prev->right;
			prev->right->right->left = NULL;
			prev->right->right->right = NULL;
			(prev->right)->prev = prev;
			cur = prev->right;
		}
	}
	insert_case1(cur);
	size++;
}

template<class T>
inline void tree<T>::finding(int * check, T * finded, size_t key)
{
	node*cur = root;
	while ((cur != NULL) && (cur->key != key))
	{
		if (key < (cur->key))
			cur = cur->left;
		else
			cur = cur->right;
	}
	if (cur != NULL)
		*finded = cur->data;
	if ((cur != NULL) && (cur->color != 'n'))
		*check = 1;
	else
		*check = -1;
}

template<class T>
inline bool tree<T>::contains(size_t key)
{
	int check;
	T finded;
	finding(&check, &finded, key);
	if (check == 1)
		return true;
	return false;
}

template<class T>
inline void tree<T>::remove_one_child(node * cur)
{
	node*child;
	if (cur->left->color != 'n')
		child = cur->left;
	else
		child = cur->right;
	replace_node(cur, child);
	if ((cur->color == 'b') || (cur->color == 'n'))
	{
		if (child->color == 'r')
			child->color = 'b';
		else
			remove_case1(child);
	}
}

template<class T>
inline void tree<T>::remove_case1(node * cur)
{
	if (cur->prev != NULL)
		remove_case2(cur);
}

template<class T>
inline void tree<T>::remove_case2(node * cur)
{
	node*parent = cur->prev;
	node*brother = NULL;
	if (parent != NULL)
		if (cur == parent->left)
			brother = parent->right;
		else
			brother = parent->left;
	if (brother!=NULL)
		if (brother->color == 'r')
		{
			parent->color = 'r';
			brother->color = 'b';
			if (cur == parent->left)
				rotate_left(parent);
			else
				rotate_right(parent);
		}
	remove_case3(cur);
}

template<class T>
inline void tree<T>::remove_case3(node * cur)
{
	node*parent = cur->prev;
	node*brother = NULL;
	if (parent != NULL)
		if (cur == parent->left)
			brother = parent->right;
		else
			brother = parent->left;
	if ((parent != NULL) && (brother != NULL) && (brother->left != NULL) && (brother->right != NULL))
		if ((parent->color == 'b') && (brother->color == 'b') && ((brother->left->color == 'b') || (brother->left->color == 'n')) && ((brother->right->color == 'b') || (brother->right->color == 'n')))
		{
			brother->color = 'r';
			remove_case1(parent);
		}
		else
			remove_case4(cur);
}

template<class T>
inline void tree<T>::remove_case4(node * cur)
{
	node*parent = cur->prev;
	node*brother = NULL;
	if (parent != NULL)
		if (cur == parent->left)
			brother = parent->right;
		else
			brother = parent->left;
	if ((parent != NULL) && (brother != NULL) && (brother->left != NULL) && (brother->right != NULL))
		if ((parent->color == 'r') && (brother->color == 'b') && ((brother->left->color == 'b') || (brother->left->color == 'n')) && ((brother->right->color == 'b') || (brother->right->color == 'n')))
		{
			brother->color = 'r';
			parent->color = 'b';
		}
		else
			remove_case5(cur);
}

template<class T>
inline void tree<T>::remove_case5(node * cur)
{
	node*parent = cur->prev;
	node*brother = NULL;
	if (parent != NULL)
		if (cur == parent->left)
			brother = parent->right;
		else
			brother = parent->left;
	if (brother!=NULL)
		if (brother->color == 'b')
		{
			if ((cur == parent->left) && (brother->right->color == 'b') && (brother->left->color == 'r')) 
			{ 
				brother->color = 'r';
				brother->left->color = 'b';
				rotate_right(brother);
			}
			else if ((cur == parent->right) && (brother->left->color == 'b') && (brother->right->color == 'r'))
			{
				brother->color = 'r';
				brother->right->color = 'b';
				rotate_left(brother);
			}
		}
	remove_case6(cur);
}

template<class T>
inline void tree<T>::remove_case6(node * cur)
{
	node*parent = cur->prev;
	node*brother = NULL;
	if (parent != NULL)
		if (cur == parent->left)
			brother = parent->right;
		else
			brother = parent->left;
	brother->color = parent->color;
	parent->color = 'b';
	if (cur == parent->left) 
	{
		brother->right->color = 'b';
		rotate_left(parent);
	}
	else
	{
		brother->left->color = 'b';
		rotate_right(parent);
	}

}

template<class T>
inline void tree<T>::replace_node(node*cur, node*child)
{
	child->prev = cur->prev;
	if (cur->prev != NULL)
		if (cur->prev->left == cur)
			cur->prev->left = child;
		else
			cur->prev->right = child;
	child->prev = cur->prev;
	if (cur == root)
		root = child;
	delete cur;
	size--;
}

template<class T>
inline void tree<T>::clear()
{
	while (size > 0)
		remove(root->key);
}

template<class T>
inline list<size_t> tree<T>::get_keys()
{
	list<size_t> list_keys;
	for (Iterator<T> *tmp = createBfsIterator(); tmp->hasNext(); tmp->next())
	{
		if (tmp->current_color() != 'n')
			list_keys.push_back(tmp->current_key());
	}
	return list_keys;
}

template<class T>
inline list<T> tree<T>::get_values()
{
	list<T> list_data;
	for (Iterator<T> *tmp = createBfsIterator(); tmp->hasNext(); tmp->next())
	{
		if (tmp->current_color() != 'n')
			list_data.push_back(tmp->current_data());
	}
	return list_data;
}


template<class T>
inline void tree<T>::remove(size_t key)
{
	node*cur;
	node*child;
	node*copy_cur;
	node*copy_prev;
	while (contains(key) == true)
	{
		cur = root;
		while (cur->key != key)
			if (cur->key > key)
				cur = cur->left;
			else
				cur = cur->right;
		copy_prev = cur;
		copy_cur = cur->left;
		while (copy_cur->color != 'n')
		{
			copy_prev = copy_cur;
			copy_cur = copy_cur->right;
		}
		cur->key = copy_prev->key;
		cur->data = copy_prev->data;
		remove_one_child(copy_prev);
	}
}