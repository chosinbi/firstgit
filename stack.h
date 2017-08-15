#pragma once
// cx8-5.h
// Code Example 8-5: Declaration of a Stack using a list
#include<assert.h>

#ifndef __MB_CX8_5__
#define __MB_CX8_5__
//#include "dslib.h"

template < class StackElementType >
class Stack {
public:
	Stack();
	void push(StackElementType e);
	StackElementType pop(); //stackElement type�� ��������� �Ѵ�.
							//�����͸� ����
	StackElementType top();  //�����͸� �������� �ʴ´�.
	bool isEmpty();
private:
	struct Node;
	typedef Node * Link;
	struct Node {
		StackElementType data;
		Link next;
	};
	Link head;
};
//Head�� insert = push
#endif

template < class StackElementType>
Stack < StackElementType >::Stack()
{
	head = 0;
}
template < class StackElementType >
void
Stack < StackElementType >::push(StackElementType e)
{
	Link addedNode = new Node;  //1
	assert(addedNode);
	addedNode->data = e;  //2
	addedNode->next = head; //3
	head = addedNode; //4
}  //head�� insert�ϴ� �ڵ�
   //pop top�� ����







template < class StackElementType >
bool
Stack < StackElementType >::isEmpty()
{
	//head�����Ͱ� null���� �ƴ���
	return bool(head == NULL); //head�� ��������� 0(null)�̹Ƿ� ture����
}
template < class StackElementType >
StackElementType
Stack < StackElementType >::top()
{
	StackElementType e = head->data;
	return e;
}
template < class StackElementType >
StackElementType
Stack < StackElementType >::pop()
{

	StackElementType e = head->data;
	Link delNode(head);
	head = head->next;
	delete delNode;
	return e;
}
