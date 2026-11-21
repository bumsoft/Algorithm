#define _CRT_SECURE_NO_WARNINGS
/* 백준 10845 큐(실버IV)  #큐 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct person
{
	char name[101];
	int age;
	struct person *next;
}Person;

void MakeNodes(Person **head, Person **tail)
{
	
	if (*head != NULL) {
		(*tail)->next = (Person *)malloc(sizeof(Person));
		*tail = (*tail)->next;
	}
	else {
		*head = (Person *)malloc(sizeof(Person));
		(*head)->next = NULL;
		*tail = *head;
	}
	scanf("%d %s", &((*tail)->age), &((*tail)->name));

}
int main()
{
	Person *head = NULL, *tail = NULL,*p;
	int N,i,j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		MakeNodes(&head, &tail);
	}
	p = head;
	for (i = 1; i <= 200; i++) {
		head = p;
		for (j = 0; j < N; j++) {
			if (head->age == i) printf("%d %s\n", head->age, head->name);
			head = head->next;
		}
	}
}