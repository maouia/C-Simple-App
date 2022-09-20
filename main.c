#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// scucture livre
typedef struct livre livre ;
	struct livre {
		char Titre [20];
		char auteur [10];
		int nbpage ;
		int disponible;
	
	};
	

//liste bibliothèque
typedef struct biblio {
	livre livre ;
	struct biblio *next;
}biblio;


//initialisation de la liste
struct biblio *l = NULL;





//fonction affiche liste
affiche(){
	system("cls");
	struct biblio *p=l ;
	if(tailleL()==0){
		printf("\nla liste est vide \n\n");
	}
	else{
	while (p != NULL){
		printf("\n________________________________\n");
		printf("|%s                                   \n",p->livre.Titre);
		printf("|%s                                  \n",p->livre.auteur);
		printf("|%d                                  \n",p->livre.nbpage);
		printf("|%d                                  \n",p->livre.disponible);
		printf("|________________________________\n");
		p=p->next;
	}
	}
}





// fonction ajout on tete de la liste
add(){

system("cls");
struct biblio *element = (struct biblio*) malloc(sizeof(struct biblio));
	
	printf("donner le titre de livre : ");
	scanf("%s",&element->livre.Titre);	

	printf("donner le nom d'auteur : ");
	scanf("%s",&element->livre.auteur);
	
	printf("donner le nb page : ");
	scanf("%d",&element->livre.nbpage);
	
	printf("donner l`etat d`un livre  1 pour dire diponible et 0 pour non diponible :");
    scanf("%d",&element->livre.disponible);

	
	element->next=l;
	l=element;
	
	system("cls");
	printf("ajout avec succes\n\n");
}





//fonction ajout on queue de la liste
addQ(){
system("cls");

struct biblio *element = (struct biblio*) malloc(sizeof(struct biblio));

	printf("donner le titre de livre : ");
	scanf("%s",&element->livre.Titre);	

	printf("donner le nom d'auteur : ");
	scanf("%s",&element->livre.auteur);
	
	printf("donner le nb page : ");
	scanf("%d",&element->livre.nbpage);
	
	printf("donner l`etat d`un livre  1 pour dire diponible et 0 pour non diponible :");
    scanf("%d",&element->livre.disponible);
	

	element->next=NULL;
		
	struct biblio *p=l ;
	if(p==NULL){
	element->next=l;
	l=element;
	}
	else{
	while (p->next != NULL){
		p=p->next;
	}
	p->next=element;
	}
	system("cls");
	printf("ajout avec succes\n\n");
}





//fonction ajout au milieu de la liste
addM(){
	system("cls");
	
	int n=tailleL();
	int j;
	printf("\nla liste est de taille %d\n",n);
	do
	{
	printf("donner l`indice de la nouvelle case");
	scanf("%d",&j);}
	while((0>j)||(j>n));
	
	if (j==0){
	add();	
	}
	else if(j==n){
	addQ();
	}
	else{
		struct biblio *element = (struct biblio*) malloc(sizeof(struct biblio));
		
		printf("donner le titre de livre : ");
		scanf("%s",&element->livre.Titre);	

		printf("donner le nom d'auteur : ");
		scanf("%s",&element->livre.auteur);
	
		printf("donner le nb page : ");
		scanf("%d",&element->livre.nbpage);
		printf("donner l`etat d`un livre  1 pour dire diponible et 0 pour non diponible :");
        scanf("%d",&element->livre.disponible);
		

		
		int i =0 ;
		struct biblio *q=l;
		while(q!=NULL && i<j-1 ){	
		q=q->next;
		i++;	
		}
		element->next=q->next;
		q->next=element;
		
		system("cls");
		printf("ajout avec succes\n\n");
	}	
}




/* la fonction supr() permet de supprimer un élément de la liste avec un indice donner   'soit on tête soit on queue soit au milieu' */
supr(){
	system("cls");
	if(tailleL()>0 ){

	int n=tailleL();
	int c ;
	printf("\nla liste est de taille %d\n",n);
	do
	{
	printf("donner l`indice de la case a supprimer ");
	scanf("%d",&c);}
	while((0>c)||(c>n));
	system("cls");
		
	if(tailleL()==1){
	biblio *a = NULL;
	free(l);	
	l=a;
	}
	
	else if(c==0){
	biblio *a = l->next;
	l->next=l->next->next;
	free(a);
	}
	else{
	
	struct biblio *p = l;
	int i=0;
	while(p!=NULL && i<c-1 ){
		p=p->next;
		i++;
	}
	biblio *a = p->next;
	p->next=p->next->next;
	free(a);
}
}
else{
	printf("\nla liste est vide \n\n");
}
}





//fonction calcule la taille de la liste 
int tailleL(){
	int n =0;
	struct biblio *p=l;
		while(p!=NULL){
		p=p->next;
		n++;
	}
	return n ;
}




//changer l`etat d`un livre a chonger
changeEtat() {
		system("cls");
	
	if(l!=NULL)
	{
		int n=tailleL();
		int c ;
		printf("\nla liste est de taille %d\n",n);
			
		do
		{
		printf("donner l`indice de la case a changer ");
		scanf("%d",&c);
		}
		while((0>c)||(c>n-1));
	system("cls");
		
		struct biblio * p = l ;
		while(p!=NULL && c!=0){
			p=p->next;
			c--;			
		}
		printf("l`etat de livre = %d  \n",p->livre.disponible);
		printf("donner l`etat d`un livre  1 pour dire diponible et 0 pour non diponible :");
        scanf("%d",&p->livre.disponible);
	}
	else
		printf("la liste est vide \n ");	
} 




//tree liste order by Titre 
treeListe(){
		system("cls");
	if(l!=NULL){
	

	int test=0;
	struct biblio * p = l;
	livre val1,val2;  
	while (test==0){
		
		test=1;
		while(p->next!=NULL){
			
			if (p->livre.Titre > p->next->livre.Titre){
				val1=p->livre;
				val2=p->next->livre;
				p->livre=val2;
				p->next->livre=val1;
				test=0;
			}
			p=p->next;
		}
			
	}
	printf("trie avec succes\n\n");
	}
	else{
		printf("la liste est vide\n\n");
	}
}



//convert String to int
int convertInt(const char* str){
    int num = 0;
    int i = 0;
    int isNegetive = 0;
    if(str[i] == '-'){
        isNegetive = 1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9')){
        num = num * 10 + (str[i] - '0');
        i++;
    }
    if(isNegetive==1) num = -1 * num;
    return num;
}




//diviser la chaîne mot par mot et remplir la liste on queue
stringSplite(char chaine [50]){

int i;
struct biblio *element = (struct biblio*) malloc(sizeof(struct biblio));

char  *token ;
token= strtok(chaine, " ");//strtok divise la chaine mot par mot
for(i=0;i<sizeof(token);i++)
element->livre.Titre[i]=token[i];

token = strtok(NULL, " ");//permet d'avancer ver la deuxième mot
for(i=0;i<sizeof(token);i++)
element->livre.auteur[i]=token[i];

token = strtok(NULL, " ");
element->livre.nbpage=convertInt(token);

token = strtok(NULL, " ");
element->livre.disponible=convertInt(token);


element->next=NULL;
		
struct biblio *p=l ;
	if(p==NULL)
	{
		element->next=l;
		l=element;
	}
	else
	{
		while (p->next != NULL)
		{
			p=p->next;
		}
		p->next=element;
	}
} 



//lire un ficher ligne par ligne 
RemplireListeParFicher(){
	char chaine [50];
	FILE* fichier = NULL;
	fichier = fopen("bibliotheque.txt", "r");
	    if (fichier != NULL)
    {
    		
        while (fgets(chaine, 50, fichier) != NULL) 
        {			
        
      		stringSplite(chaine);//une fonction qui prend au parametre un ligne de fichier sous forme d'une chaine
			   	
		}
 
        fclose(fichier);
    }
}




//enregistrer la liste dans un fichier text
saveFile(){
	struct biblio * p =l;
	FILE* fichier = NULL;
	fichier = fopen("bibliotheque.txt", "w");
	while (p!=NULL){
		fputs(p->livre.Titre,fichier);
		fputs(" ",fichier);
		fputs(p->livre.auteur,fichier);
		fputs(" ",fichier);
		fprintf(fichier,"%d",p->livre.nbpage);
		fputs(" ",fichier);
		fprintf(fichier,"%d\n",p->livre.disponible);
		p=p->next;
	}
	fclose(fichier);
}




int main(int argc, char *argv[]) {
	
	
	RemplireListeParFicher();
	
	
char n =10; 
	
	
	//affichage de  menu
	while (n != 0 ){
		
		printf("addTete : 1 \naffiche : 2 \naddQueue : 3 \naddMilieu : 4\nchangeEtat : 5\ntreeListe : 6\nsupprimer : 7 \nquit : 0 \n");
	
		
		printf("doner choix : ");	
		scanf("%d",&n);
		
			if (n==1){
			add();
			}
			
			else if (n==2){
			affiche();
			}
			else if (n==3){
				addQ();
			}
			else if (n==4){
				addM();
			}
			
			else if (n==5){
				changeEtat();
			}	
		
			else if (n==6){
				treeListe();
			}
				
			else if (n==7){
				supr();
			}
			
			else{
				if (n==0){
					printf("bye bye ");
					remove("bibliotheque.txt");
					saveFile();
					break ; 
				}
				else {
					printf("choise unknown \n");
					
				}
			}	
	}

	return 0;
}
