#include <stdio.h>
#include <unistd.h>

struct free_list_metadata{
	struct free_list *prev;
	struct free_list *next;
	size_t  size;
	char status;
};

void * malloc(size_t size_req){
	void *var sbrk();
	struct free_list_metadata* temp=head;
	while (temp!=NULL){
		if(temp->size==size_required){
			if(temp->prev==NULL){
			temp->next->prev=NULL;
			temp->status=1;
			}
			else if(temp->next==NULL){
			temp->prev->next=NULL;
			temp->status=1;
			}
			else{
			temp->status=1;	
			temp->prev->next=temp->next;
			}
		}
		else if(temp->size>size_required){
			if(temp->size>sizeof(free_list_metadata){
				//split the free_list block
				struct free_list_metadata* split_block=temp+size_req+sizeof(struct free_list_metadata);
				split_block->size=temp->size-(size_req+sizeof(struct free_list_metadata);
				temp->size=size_req;
				split_block->prev=temp->prev;
				split_block->next=temp->next;
			}
		}
		temp=temp->next;
	}
	if(temp==NULL){
	}
}

struct free_list * head=NULL;

