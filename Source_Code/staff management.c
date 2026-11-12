#include "globals.h"

int errorChk(char *str1, char *str2){ 
    int check=strcmp(str1, str2); 
    if (check==0) {return 1;}
	else {return 0;} 
} 

int passchk(char *regpass) { 
    int i, fl=0, fn=0, fc=0; 
    if (strlen(regpass)<8){
        return 0;
    }
    for (i=0; i<strlen(regpass); i++) { 
        if(regpass[i]>='0' && regpass[i]<='9'){fn = 1;} 
        if ((regpass[i]>='a' && regpass[i]<='z') || (regpass[i]>='A' && regpass[i]<='Z')) {fl=1;} 
        if (regpass[i]=='!' || regpass[i]=='@' || regpass[i]=='#' || regpass[i]=='$' || regpass[i]=='%' || regpass[i]=='^' || regpass[i]=='&' || regpass[i]=='*' || regpass[i]=='?') {fc = 1;}       
        if (fl==1 && fn==1 && fc==1) {return 1;} 
    } 
    return 0; 
} 

int staffReg() { 
    char regid[61]; 
    char regpass[21]; 
    printf("\n========REGISTRATION PAGE==========\n");
    printf("ID\nEnter your name: "); 
    scanf("%60s",regid);
    int edit = pcount + 1;
    staff_floor = (struct staff *)realloc(staff_floor, edit * sizeof(struct staff));

    
    strcpy(staff_floor[pcount].regid, regid);

    do {
        printf("\nEnter password\nPassword must be 8 characters long\nMust have a numeric value and at least one special character\n"); 
        scanf("%20s",regpass);
        if (passchk(regpass)==1) { 
            strcpy(staff_floor[pcount].regpass, regpass);
            printf("\nRegistered Successfully\n"); 
            break;
        } else { 
            printf("\nInvalid Password! Try again.\n"); 
        } 
    } while (1);
    pcount++; 
    return 1;
}

int staffLogin(void){
    while (1) {
        printf("\nEnter login username: ");
        char loginid[61];
        char loginpass[21];
        scanf("%60s", loginid);
        printf("\nEnter password: ");
        scanf("%20s", loginpass);  
        int i;
        int found=0;
        for(i=0;i<pcount;i++){
            if((errorChk(staff_floor[i].regid, loginid) == 1) && (errorChk(staff_floor[i].regpass, loginpass) == 1)){
                printf("\nLogin Successful\n");
                return 1;
            }
        }
        printf("\nInvalid username or password. Try again.");
        int flag=0;
        do{
            int choice=0;
            printf("\nChoose an action:\n1. Retry\n2. Go to Staff Home Page\nEnter choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    flag=0;
                    break;
                case 2:
                    return 0;
                default:
                    printf("\nInvalid choice");
                    flag=1;
                    break;
            }
        }while(flag==1);
    } 
}

void staffMenu(void) { 
	int menu;
	while(1){
		printf("\nGo to:\n1. Registration Page\n2. Login Page\n3. Exit Program"); 
		printf("\nEnter your choice: ");
		scanf("%d",&menu);
	switch(menu){
		case 1:
			printf("\nRedirecting to registration page");
			staffReg();
			break;
		case 2:
			printf("\nRedirecting to login page");
			staffLogin();
			break;
        case 3: 
            printf("\nWARNING: Exiting will completely delete all records entered!");
            printf("\nAre you sure you want to exit? (1 for Yes / 0 for No): ");
            int confirm;
            scanf("%d", &confirm);
            if (confirm == 1) { 
                free(staff_floor); 
                printf("\nSystem cleared. Goodbye!\n");
                return;
            }
            break;
		default:
			printf("\nInvalid choice.");
			continue;
	} 
    }
}
