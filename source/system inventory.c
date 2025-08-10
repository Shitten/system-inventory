#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_TABLE 4096
typedef struct item{
char id[100];
char name[100];
char quantity[100];
float price;
char file[100];
unsigned int hash;
struct item *next;

} item;
item *hashtable[HASH_TABLE] = {NULL};

void bucket(item **ptr, int **cnt){
    
    if (**cnt > 0) {
   unsigned int index = (*ptr)[**cnt].hash;
   (*ptr)[**cnt].next = hashtable[index];
    hashtable[index] = &(*ptr)[**cnt];
} else {
   printf("nothing to hash\n");
   
};

}



void read_clean(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Strip newline
}
void add(int **capacity, int **count, item **items);
 void show_options(item **ptr, int **cpt, int **cnt); 
 void edit(item **ptr, int **cpt, int **cnt); 
 void storeItem(item **ptr, int **cpt, int **cnt);
void hash(const char *str,item **ptr);
void search(item **ptr);




void save(item **ptr){
   char again[50];
    
    

    while(1){
        printf("enter the file name:");
    read_clean(again, sizeof(again));

    sprintf((*ptr)->file, "%s.txt", again);
    FILE *fp =fopen((*ptr)->file, "a");
     if(again[0] == '\0' || (*ptr)->file[0] == '\n'){
        printf("Eroor: cant name an empty file :(\n");
        int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        
     }if(fp == NULL){
    printf("ERROR: File not saved\n");
     int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
     }else{
         fprintf(fp,"%-10s|%-10s|%-10s|%-10s\n", "ID","Name","Quantity","Price");
      fprintf(fp, "%-10s|%-10s|%-10s|%-10.2f\n", (*ptr)->id, (*ptr)->name, (*ptr)->quantity, (*ptr)->price);
      printf("=======================END====================\n");
      getchar();

    fclose(fp);
    printf("Item saved to file\n"); 
 
        break;
     }
            
    }
     
}

void delete(){

}
void edit(item **ptr,int **cpt,int **cnt){
    char again[50];
    
        printf("Edit Item [2]: ");
        read_clean(again, sizeof(again));


        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
do{

}while(tolower(again[0]) == '2');



};
void search(item **ptr){
    char buffer[50];
    item temp;
    item *temp_ptr = &temp;
printf("Enter ID:");
read_clean(buffer, sizeof(buffer));
hash(buffer,&temp_ptr);
printf("%X",temp_ptr->hash);

};

void storeItem (item **ptr,int **cpt,int **cnt){
char tempstr[100];

 if(*cpt == NULL){
    *cpt = realloc(*cpt,sizeof(int));
**cpt = 4;
 };
 if(*cnt == NULL){
 *cnt =realloc(*cnt,sizeof(int));
**cnt = 0;
 }



item items;

for(int i = 0;i<**cnt;i++){
printf("%-10s|%-10s|%-10s|%-10s|%-10s\n", "ID","Name","Quantity","Price","Hash");
printf("%-10s|%-10s|%-10s|%-10.2f|%-10u\n", 
    
(*ptr)[i].id,
(*ptr)[i].name,
(*ptr)[i].quantity,
(*ptr)[i].price,
(*ptr)[i].hash
);

} 
if (**cnt > 0) {
    item *lastItem = &(*ptr)[**cnt - 1];
    hash(lastItem->id, &lastItem);
}else{
    item *lastItem = &(*ptr)[**cnt];
    hash(lastItem->id, &lastItem);
}
}
 void hash(const char *str, item **ptr) {
    if (str == NULL || *ptr == NULL) {
        return;
    }
    const char *original = str;
    unsigned int hashs = 5381; 
    int c;

   
    while ((c = *str++)) {
        hashs= ((hashs << 5) + hashs) + c;
    }

  
    unsigned int hashed = hashs % 0xFFF;
    if(*ptr != NULL){
    (*ptr)->hash = hashed;
    }
    printf("%X:%s\n", (*ptr)->hash, original); 
}

void add(int **capacity, int **count, item **items) {
    char again[10];
    char tempstr[100];
    

    do {
        
        if(**count >= **capacity){
            **capacity *= 2;
        *items  = realloc(*items, sizeof(item)* (**capacity));
        
        }
       item *p1 = &(*items)[**count];

        char input[50];
        char buffer[50];

        printf("Enter ID:\n");
read_clean(p1->id, sizeof(p1->id));

printf("Enter name:\n");
read_clean(p1->name, sizeof(p1->name));

printf("Enter quantity:\n");
read_clean(p1->quantity, sizeof(p1->quantity));

printf("Enter price:\n");
read_clean(buffer, sizeof(buffer));

hash(p1->id, &p1);

(**count)++;
p1->price = strtof(buffer, NULL);
       
        
storeItem(items, capacity, count);
        
     
    read_clean(again, sizeof(again));

    if (tolower(again[0]) == '1') {
       printf("Returning to menu... press Enter to continue.");
    getchar();
    } else {
        break;
    }
 
    } while (1);
 
}

void show_options(item **ptr, int **cpt, int **cnt) {
    char input[10];
    int choice;

    do {
        printf("Add Item?:[1]\n");
        printf("Edit Item?:[2]\n");
        printf("Delete Item?:[3]\n");
        printf("Search Item?:[4]\n");
        

        // get input
        read_clean(input, sizeof(input));  
choice = atoi(input);

        switch (choice) {
            case 1:
               #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif
                add(cpt, cnt, ptr);
                break;
            case 2:
                edit(ptr,cnt,cnt);
                break;
            case 3:
                
                break;
            case 4:
              search(ptr);
                break;
                break;
            case 5:
              
                break;
            case 6:
               
                break;
            case 7:
                // exit
                break;
            default:
                // invalid
        }

    } while (choice != 7);
}




void option(int **num,int **capacity,int **count,item **p1){
    switch (**num){
    case 1:{
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
        add(capacity, count,p1);
        show_options(p1, capacity, count);
        break;
    }
    case 2:{

      
    }
    case 3:{

    }
    case 4:{

    }
    case 5:{

    }
    case 6:{

    }
    case 7:{

    }
    case 8:{

    }
    }
}

void checkvalue(int **num,int **capacity,int **count, item **p1){  
    char input[10];  //char for storing the user input before converting it into int
    while(1){
         printf("[1] Add New Item\n");
    printf("[2] Load Inventory\n");
    printf("[3] Exit\n");
        printf("Enter your option(1-3):\n");
        read_clean(input, sizeof(input));  // Instead of fgets + newline strip
**num = atoi(input);
        **num = atoi(input);  //dereferenced it to convert it into int which is stored in num in main()
        if(**num >= 1 && **num <=8){
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif
            option(num,capacity,count,p1);
            break;
        } else {
            printf("invalid input\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
}

int main ( ){
    
    printf("=======================================\n");    
    printf("======🔥SYSTEM INVENTORY V 1.0🔥======\n");
    printf("=======================================\n");
   


   
    
    int *capacity = malloc(sizeof(int));
    *capacity = 4;
    int *count = malloc(sizeof(int));
    *count = 0;
    item *p1 = malloc(sizeof(item)*(*capacity));
    

    int *num = malloc(sizeof(int));
    if (num == NULL){               //allocating dynamic memory for further reusability
        printf("Malloc failed\n");
        return 1;
    }
    while(1){
    checkvalue(&num,&capacity,&count,&p1);  //passed the address
    }
    while (getchar() != '\n');
    free(num);
    
    
    return 0;
}
