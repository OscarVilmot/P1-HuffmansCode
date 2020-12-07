#ifndef HEADERS_OPTIMISATION_H_
#define HEADERS_OPTIMISATION_H_
	typedef struct Element{
	    Node* data;
	    struct Element* next;
	}Element;

	typedef struct Queue{
	    Element* data_queue;
	}Queue;

	Queue* create_queue();
	int is_empty(Queue* q);
	void enqueue(Queue* q, Node* val);
	Node* dequeue(Queue* q);

	Node* create_common_node(Node* node1, Node* node2);
	Node* create_tree(Node** tab, int n);

	int add_node(Node*** tab, int n, char caractere);
	static void swapElement(ElementOccurrenceLetter* first, ElementOccurrenceLetter* second);
	void bubbleSortListOccurrences(ElementOccurrenceLetter* occurrences, int sizeListOccurrences);
#endif