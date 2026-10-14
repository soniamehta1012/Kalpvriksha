#include<stdio.h>
struct User{
	char name[50];
	int ticket_quant;
	char choice;
};
int main(){
	const int  standard=150,premium=250,recliner=400;
	int subtotal=0;
	struct User u1;
	scanf("%s %d %c",u1.name,&u1.ticket_quant,&u1.choice);
	if(u1.ticket_quant>20){
		printf("Please enter tickets less than 20.");
		return 0;
	}
    switch(u1.choice){
    	case '1':
    		subtotal=150*u1.ticket_quant;
    		break;	
		case '2':
			subtotal=250*u1.ticket_quant;
			break;
		case '3':
			subtotal=400*u1.ticket_quant;
			break;
		default:
			printf("Please enter a valid category!\n");	 
			return 0;    	
	}
	float final_bill=subtotal;
	float discount=0;
	if(u1.ticket_quant>=5){
	discount=subtotal*0.1;
	final_bill=subtotal*(0.9);
	}
	printf(" Customer Name: %s\n",u1.name);
	printf("Ticket Category: %c\n",u1.choice);
	printf("Tickets: %d\n",u1.ticket_quant);
	printf("Subtotal: %d\n",subtotal);
	printf("Discount: %.2f\n",discount);
	printf("Final bill: %.2f\n",final_bill);
}
