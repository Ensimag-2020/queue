#include <stdio.h>
#include <stdlib.h>
#include "shared/queue.h"
#include "shared/panic.c"

struct elt {
	int val;
	link lien;
	int prio;
};

int main(void) {
	printf("hello world!\n");

	link head = LIST_HEAD_INIT(head);
	//LIST_HEAD(head);
	INIT_LIST_HEAD(&head);

	printf("Chaine vide ? %d\n",queue_empty(&head));

	link maillon = {NULL, NULL};
	struct elt e = {1, maillon, 0};
	printf("On ajoute un element\n");
	queue_add(&e, &head, struct elt, lien, prio);

	printf("Chaine vide ? %d\n",queue_empty(&head));

	link maillon2 = {NULL, NULL};
	struct elt e2 = {2, maillon2, 0};
	printf("On ajoute un element\n");
	queue_add(&e2, &head, struct elt, lien, prio);

	link maillon3 = {NULL, NULL};
	struct elt e3 = {3, maillon3, 0};
	printf("On ajoute un element\n");
	queue_add(&e3, &head, struct elt, lien, prio);

	//link itLink;
	struct elt* iterateur;// = {0, itLink, 0};
	queue_for_each(iterateur, &head, struct elt, lien)
		printf("Elt = %d\n", iterateur->val);
}

