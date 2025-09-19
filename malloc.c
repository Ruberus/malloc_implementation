#include <stdio.h>
#include <unistd.h>

struct free_list_metadata{
	struct free_list_metadata* prev;
	struct free_list_metadata* next;
	size_t  size;
	char status;
};

struct free_list_metadata* head=NULL;

void * malloc(size_t size_req){
	void *var sbrk();
	struct free_list_metadata* temp=head;
	while (temp!=NULL){
		if(temp->size>=size_req){
			if(temp->size>sizeof(struct free_list_metadata)){
					//split the free_list block
					struct free_list_metadata* split_block=(char *)temp+size_req+sizeof(struct free_list_metadata); //had to convert it to (char*)temp to add bytes specifically
					split_block->size=temp->size-(size_req+sizeof(struct free_list_metadata));
					temp->size=size_req;
					split_block->prev=temp->prev;
					split_block->next=temp->next;
			}

					#allocating the block
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
					temp->next->prev=temp->prev;
					}
				
		    
		}

		temp=temp->next;
	}
	if(temp==NULL){
	}
}


