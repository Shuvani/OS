#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *next;
};

void insert_node(struct node *head,int v){
	struct node *p = head;
	while(p->next != NULL)p=p->next; //go to the last node!
	p->next = malloc(sizeof(struct node));//allocate memory
	p->next->next = NULL; //new end of list
	p->next->value = v; //set value
}

struct node * delete_node(struct node *head, int pos){
	struct node * p = head;
	struct node * q = NULL;
	if (pos == 0){
		p = head->next;
		free(head);
		head = p;
	}
	else{
		for (int i = 0; i < pos-1; i++){ //note one less
			p = p->next;
		}
		q = p->next; //I need to bypass q
		p->next = q->next; //bypass q
		free(q);
	}
	return head;
}

void print_list(struct node *head){
	struct node *p = head;
	printf("%d ", head->value);
	while(p->next != NULL){
		printf("%d ", p->next->value);
		p=p->next;
	}
	printf("%c", '\n');
}

int main(){
	struct node *head = NULL; //we now have a link list head point to NULL for an empty list
	//create a first node
	head = malloc(sizeof(struct node)); 
	head->value = 1; //set the value of the head to 1
	head->next = NULL; //it now points to nothing (NULL)
	
	//let's try to insert nodes
	insert_node(head, 2);
	insert_node(head, 4);
	insert_node(head, 8);
	insert_node(head, 16);
	//let's try to print the list
	print_list(head);
	
	//let's try to delete node
	head = delete_node(head, 0);
	//let's try to print the list
	print_list(head);

	
	return 0;
}