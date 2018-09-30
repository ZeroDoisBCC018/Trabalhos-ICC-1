#include <stdlib.h>
#include <stddef.h>
#include "no_leak.h"

void** ptrs;

void start_pointer_storage(void){
	ptrs = (void**) malloc(500*sizeof(void*));
	for(int i = 0; i < 500; i++){
		ptrs[i] =NULL;
	}
}

void add_pointer_to_storage(void* p){
	static int i = 0;
	ptrs[i] = p;
	i++;
}

void free_storage(void){
	for(int i = 500; i > 0; i--){
		free(ptrs[i]);
	}
	free(ptrs);
}
