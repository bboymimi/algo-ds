#include <stdio.h>
#include <stdlib.h>

int strlength(char *);

enum test {
	FIRST = 1,
	SEC = 4,
	THIRD
};

struct bit {
	unsigned int testa;
	//unsigned int protect:1;
	//char :64;
	//unsigned int mm:1;
	//enum test t;
	unsigned int test;
};

struct list {
	unsigned int i;
	struct list *next;
} *head;

enum return_value {
	OOM_ERROR = -1,
	SUCCESS,
};

void display()
{
	struct list *temp = head;
	if (temp == NULL) {
		printf("The list is empty\n");
		return;
	}
		
	printf("{");
	do {
		printf("%d", temp->i);
		if (temp->next != NULL)
			printf(", ");
		temp = temp->next;
	} while (temp != NULL);
	printf("}\n");
	return;
}

enum return_value insert(int val)
{
	struct list *l = (struct list *) malloc(sizeof(struct list));	
	if (l == NULL)
		return OOM_ERROR;

	l->i = val;

	if (head == NULL) {
		head = l;	
		l->next = NULL;
	} else {
		l->next = head;
		head = l;
	}

	display();
	return SUCCESS;
}

enum return_value delete_item(int val)
{
	struct list *temp = head, *prev = head;
	if (head == NULL) {
		printf("The list is empty\n");
		return SUCCESS;
	} else {
		if (head->i == val) {
			head = head->next;
			free(temp);
			display();
			return;
		}

		prev = head;
		temp = head->next;
		while (temp != NULL) {
			if (temp->i == val) {
				prev->next = temp->next;
				free(temp);
				display();
				return SUCCESS;
			}
			
			prev = temp;
			temp = temp->next;
		}
		printf("can't find the node\n");
		display();
		return SUCCESS;
	}
}

void reverse(struct list *l)
{
	if (l->next == NULL)	
		head = l;
	else {
		reverse(l->next);
		l->next->next = l;
		l->next = NULL;
	}
}

int function_a(int a, int b)
{
	printf("a + b = %d\n", a + b);
	return a + b;
}

void func_throw(int a, int (*func_p)(int a, int b))
{
	printf("a + func_p() = %d\n", a + func_p(1, 2));
}

int main(int argc, char* argv)
{
	char *c = "hello";
	int (*func_p)(int, int);
	//struct bit b;
	//printf("Length of the c = %d\n", strlength(c));
	printf("offset b->test = %d\n", &(((struct bit *)0)->test));
	printf("sizeof struct bit = %d\n", (char *)((struct bit *)0 + 1) - (char *)(struct bit *)0);
	printf("FIRST = %d, SEC = %d, THIRD = %d, SUCCESS = %d\n", FIRST, SEC, THIRD, SUCCESS);

	insert(1);
	insert(2);
	insert(3);
	delete_item(2);
	delete_item(3);
	insert(2);
	insert(3);
	reverse(head);
	display();
	func_p = function_a;
	func_throw(1, func_p);
	
	return 0;
}

int strlength(char *c)
{
	int count = 0;
	while (*c != '\0') {
		count++;
		c++;	
	}
	return count;
}
