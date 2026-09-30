#include<stdio.h>
#include<string.h>
struct user{
	int id;
	char name[100];
	int age;
};
struct user user1;
FILE *fp;
void createUser(){
		fp=fopen("users.txt","a");
	if(fp==NULL){
		printf("Unable to open the file");
		return ;
	}
	printf("File openend successfully\n");
	printf("Enter id:\n");
	scanf("%d",&user1.id);
	printf("Enter name:\n");
	scanf("%s",user1.name);
	printf("Enter age:\n");
	scanf("%d",&user1.age);
	fprintf(fp,"%d %s %d\n",user1.id,user1.name,user1.age);
}
void readUser(){
	fp=fopen("users.txt","r");
   while (fscanf(fp, "%d %s %d", &user1.id, user1.name, &user1.age)!=EOF){
   	printf("%d %s %d\n",user1.id,user1.name,user1.age);
   }
}
void updateUser(){
	FILE *tmp;
	fp=fopen("users.txt","r");
	tmp=fopen("temp.txt","w");
	if(tmp==NULL || fp==NULL){
		printf("Unable to open the file.\n");
		return;
	}
	int i;
	printf("Enter the id of the person to update.");
	scanf("%d",&i);
	while(fscanf(fp,"%d %s %d",&user1.id,user1.name,&user1.age)!=EOF){
		if(user1.id==i){
			printf("Enter new name: ");
            scanf("%s", user1.name);
            printf("Enter new age: ");
            scanf("%d", &user1.age);
		}
		  fprintf(tmp, "%d %s %d\n",
            user1.id, user1.name, user1.age);
	}
	fclose(fp);
	fclose(tmp);
	remove("users.txt");
	rename("temp.txt","users.txt");
}
void deleteUser(){
	FILE *tmp;
	fp=fopen("users.txt","r");
	tmp=fopen("temp.txt","w");
	if(tmp==NULL || fp==NULL){
		printf("Unable to open the file.\n");
		return;
	}
	int i;
	printf("Enter the id of the person to delete.");
	scanf("%d",&i);
	while(fscanf(fp,"%d %s %d",&user1.id,user1.name,&user1.age)!=EOF){
	if(user1.id==i){
		continue;
	}
	else{
		fprintf(tmp, "%d %s %d\n",
            user1.id, user1.name, user1.age);
	}
	}
		fclose(fp);
	fclose(tmp);
	remove("users.txt");
	rename("temp.txt","users.txt");
}
int main(){

//	createUser();
//	updateUser();
//deleteUser();
	readUser();
	
}