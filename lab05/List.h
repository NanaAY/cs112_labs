/* List.h
 * Name: Nana Osei Asiedu Yirenkyi
 * Date: Oct 9 2018
 * Lab05
 */
#ifndef LIST_H_
#define LIST_H_

typedef double Item;

class List {
public:
	List();
	~List();
	void append(Item it);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	List(const List& original);
	List& operator=(const List& original);



private:
	struct Node{
		Node();
		~Node();
		Node(Item it, Node* next);
		Item myItem;
		Node* myNext;

	};
	unsigned mySize;
	Node* myFirst;
	Node* myLast;

	void makeCopyOf(const List& original);

	friend class ListTester;

};

#endif /* LIST_H_ */
