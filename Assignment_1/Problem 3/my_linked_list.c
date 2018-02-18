#include <stdio.h>
#include <stdlib.h>
#include "_LINKED_LIST.h"

List* create_list(){
	List* temp = (List*) malloc(sizeof(List));
	if(temp == NULL){
		return NULL;
	}else{
		temp -> head = NULL;
		temp -> tail = NULL;
		temp -> size = 0;
		return temp;
	}
}

Node* create_node(Element* data){
	Node* temp = (Node*) malloc(sizeof(Node));
	if(temp == NULL){
		return NULL;
	}else{
		temp -> ele = data;
		temp -> next = NULL;
		return temp;
	}
}

List* insert_in_order(List* list, Element* data){
	Node* current;
	Node* new_node = create_node(data);
    if (list -> size == 0){
        list -> head = new_node;
        list -> tail = new_node;
        list -> size ++;
    }else if(list -> head -> ele -> frequency <= new_node -> ele -> frequency){
    	new_node -> next = list -> head;
    	list -> head = new_node;
    	list -> size ++;
    }else{
        current = list -> head;
        while (current -> next != NULL && current -> next -> ele -> frequency > new_node -> ele -> frequency){
            current = current -> next;
        }
        new_node -> next = current -> next;
        current -> next = new_node;
        if(current -> next == NULL){
        	list -> tail = new_node;
        }
        list -> size ++;
    }
}

List* delete_from_end(List* list){
	Node* del_node = list -> tail;
	Node* temp = list -> head;

	if(list -> size == 0){
		return NULL;
	}else if(list -> size == 1){
		list -> head = NULL;
		list -> tail = NULL;
		free(del_node);
	}else{
		while(temp -> next -> next != NULL){
			temp = temp -> next;
		}

		temp -> next = NULL;
		list -> tail = temp;
		free(del_node);
	}
	list -> size --;

	return list;
}

List* delete_from_front(List* list){
	Node* del_node = list -> head;

	if(list -> size == 0){
		return NULL;
	}else if(list -> size == 1){
		list -> head = NULL;
		list -> tail = NULL;
		free(del_node);
	}else{
		list -> head = list -> head -> next;
		free(del_node);
	}
	list -> size --;

	return list;
}

bool is_empty(List* list){
	if(list -> size == 0){
		return true;
	}else{
		return false;
	}
}

void print_list(List* list){
	Node* temp = list -> head;
	while(temp != NULL){
		printf("%d::%s\n", temp -> ele -> frequency, temp -> ele -> doc_name);
		temp = temp -> next;
	}
	printf("\n");
}

List* mergeLists(List* list1, List* list2)
{

//pls insert merging code here!!
return list1;

}

/*
int main(){

	Element* data = (Element*) malloc(sizeof(Element));
	Element* data1 = (Element*) malloc(sizeof(Element));
	Element* data2 = (Element*) malloc(sizeof(Element));

	data -> frequency = 1;
	data1 -> frequency = 2;
	data2 -> frequency = 3;

	List* list = create_list();
	list = insert_in_order(list, data);
	list = insert_in_order(list, data1);
	list = insert_in_order(list, data2);
	print_list(list);


	return 0;
}*/