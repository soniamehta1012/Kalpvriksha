#include <stdio.h>
#include <ctype.h>

int main() {
    char input[200];
    printf("Enter expression: ");
    fgets(input, sizeof(input), stdin);
    int i=0,result=0,term=0,numberexpected=1;
    char op='+';
    while(input[i]!='\0'){
    	if(isdigit(input[i])){
    		int number=0;
    		while(isdigit(input[i])){
    			number=number*10+(input[i]-'0');
    			i++;
			}
			if(op=='+'){
				result+=term;
				term=number;
			}
			else if(op=='-'){
				result+=term;
				term=-number;
			}	
			else if(op=='*'){
				term=term*number;
			}
			else if(op=='/'){
				if(number==0){
					printf("Division by 0 is not allowed.");
					return 0;
				}
				term=term/number;
			}
			numberexpected=0;
			continue;
		}
    else	if(isspace(input[i])){
    	i++;
		continue;
	     }
    else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
    	if(numberexpected==1){
    		printf("Invalid expression\n");
    		return 0;
		}
    op = input[i];
    numberexpected=1;
    i++;
    continue;
}
else{
   printf("Invalid expression\n");
   return 0;
}
	}
	if(numberexpected==1){
		printf("Invalid expression");
		return 0;
	}
	result=result+term;
	printf("%d",result);
    return 0;
}