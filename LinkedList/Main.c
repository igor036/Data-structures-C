#include <stdio.h>
#include <stdlib.h>
#include  "List.h"
#include <string.h>

struct Person {
	char name[20];
	int idade;
};


int main(){

	struct List* list = newList();
	struct Person* person1 = malloc(sizeof(struct Person));
	struct Person* person2 = malloc(sizeof(struct Person));
	struct Person* person3 = malloc(sizeof(struct Person));
	struct Person* person4 = malloc(sizeof(struct Person));

	printf("lista está %s\n",isEmpty(list) == 1 ? "vazía" : "pre-enchida");

	strcpy(person1->name,"igor");
	person1->idade = 21;

	strcpy(person2->name,"quel");
	person1->idade = 18;

	strcpy(person3->name,"keven");
	person3->idade = 20;

	strcpy(person4->name,"miguel");
		person4->idade = 16;


	add(list,person1);
	add(list,person2);
	add(list,person3);
	add(list,person4);

	printf("%s\n","Imprimindo a lista");
	printl(list);

	printf("lista estás %s\n",isEmpty(list) == 1 ? "vazía" : "pre-enchida");

	printf("\n%s\n","cocnsulta por index");
	struct Person* p = (struct Person*)getByIndex(list,3);
	printf("%s\n",p->name);

	printf("\n%s\n","cocnsulta por valor");
	p = (struct Person*)getByValue(list,person2);
	printf("%s\n",p->name);


	printf("\n%s\n","deletando por index");
	removeByIndex(list,3);
	printl(list);

	printf("\n%s\n","deletando por valor");
	removeByValue(list,person3);
	printl(list);

	return 0;
}
