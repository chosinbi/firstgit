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
	StackElementType pop(); //stackElement type을 리턴해줘야 한다.
							//데이터를 제거
	StackElementType top();  //데이터를 제거하지 않는다.
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
//Head에 insert = push
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
}  //head에 insert하는 코드
   //pop top이 없다







template < class StackElementType >
bool
Stack < StackElementType >::isEmpty()
{
	//head포인터가 null인지 아닌지
	return bool(head == NULL); //head가 비어있으면 0(null)이므로 ture리턴
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
