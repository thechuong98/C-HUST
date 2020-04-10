#include "stack.h"


typedef struct stackNode{
	union{
		int ival;
		float fval;
		char cval;
		char *sval;
		void *pval;
		double dval;
	} data;
	stack_type type;
	struct stackNode *next;
} stackNode;



void stack_init(stackNode **stack, stack_type type){
	(*stack)->type = type;
	(*stack)->next = NULL;
}

void push(stackNode **top, ...){
	stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
	if(newNode == NULL) printf("Out of memory!\n");
	va_list ap;
	va_start(ap, top);
	switch((*top)->type){
		case STACK_CHAR:
			newNode->data.cval = (char) va_arg(ap, int);
			break;
		case STACK_INT:
			newNode->data.ival = va_arg(ap, int);
			break;
		case STACK_STRING:
			newNode->data.sval = (char *) va_arg(ap, char *);
			break;
		case STACK_DOUBLE:
			newNode->data.dval = va_arg(ap, double);
			break;
		case STACK_POINTER:
			newNode->data.pval = va_arg(ap, void *);  
			break;
		case STACK_FLOAT:
			newNode->data.fval = va_arg(ap, double);
			break;
		default:
		 	printf("Unknown type\n");
		 	break;
	}
	va_end(ap);
	newNode->next = *top;
	*top = newNode;
}

void *pop(stackNode **top, void *p){
	if(*top == NULL){
		printf("Stack underflow!\n");
		return NULL;
	}
	switch((*top)->type){
		case STACK_CHAR:
			*((char *) p) = (*top)->data.cval;
			break;
		case STACK_INT:
			*((int *) p) = (*top)->data.ival;
			break;
		case STACK_STRING:
			*((char **) p) = (*top)->data.sval;
			break;
		case STACK_FLOAT:
			*((float *) p ) = (*top)->data.fval;
			break;
		case STACK_DOUBLE:
			*((double *) p) = (*top)->data.dval;
			break;
		case STACK_POINTER:
			*((void **) p) = (*top)->data.pval;
			break;
		default:
			printf("Unknown type\n");
			return NULL;
	}
	stackNode *ptr = *top;
	*top = (*top)->next;
	free(ptr);
	return p;
}

void *peek(stackNode **top, void *p){
	if(*top == NULL){
		printf("Stack underflow!\n");
		return NULL;
	}
	switch((*top)->type){
		case STACK_CHAR:
			*((char *) p) = (*top)->data.cval;
			break;
		case STACK_INT:
			*((int *) p) = (*top)->data.ival;
			break;
		case STACK_STRING:
			*((char **) p) = (*top)->data.sval;
			break;
		case STACK_FLOAT:
			*((float *) p ) = (*top)->data.fval;
			break;
		case STACK_DOUBLE:
			*((double *) p) = (*top)->data.dval;
			break;
		case STACK_POINTER:
			*((void **) p) = (*top)->data.pval;
			break;
		default:
			printf("Unknown type\n");
			return NULL;
	}
	return p;
}

int isEmpty(stackNode **top){
	return(*top == NULL);
}

void freeStack(stackNode **top){
	stackNode *cur = *top;
	stackNode *temp;
	while(cur != NULL){
		temp = cur;
		cur = cur->next;
		free(temp);
	}

	*top = NULL;
	return;
}