#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

struct dire *fringe = NULL;
struct Node *start;

struct Node{
    char pathName[1024];
    int size;
    struct Node *next;
};

struct dire{
    char pathName[1024];
    struct dire *next;
};

void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
    struct Node* current;
    /* Special case for the head end */
    if (*head_ref == NULL|| (*head_ref)->size >= new_node->size) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->next != NULL && current->next->size < new_node->size) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}


int main(int argc, char *argv[])
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;
    fringe = (struct dire *) malloc(sizeof(struct dire));
    strcpy(fringe->pathName,argv[1]);
    /////
    struct dire *cur = fringe;
    int c = 0;
    while (fringe != NULL){
  
        // printf("%s\n",fringe->pathName);
        folder = opendir(fringe->pathName);
        struct dire *curr = fringe;
        
        if(folder == NULL)
        {
            break;
        }
        char prev[1024]; 
        strcpy(prev,fringe->pathName);

        while( (entry=readdir(folder)) != NULL)
        {
            
            char path[1024] = "";
            
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
                
                if (entry->d_type!=4){
                    strcat(path, prev);
                    strcat(path, "/");
                    strcat(path, entry->d_name);
                    struct stat buffer;
                    //printf("%s\n",path);
                    stat(path,&buffer);
                    int size = buffer.st_size;
                    //printf("%d\t%s\n", size,path);
                    //count++;
                    struct Node *pnode=(struct Node *) malloc(sizeof(struct Node));
                    strcpy(pnode->pathName,path);
                    pnode->size = size;
                    sortedInsert(&start, pnode);

                }
                else{
                    strcat(path, prev);
                    strcat(path, "/");
                    strcat(path, entry->d_name);
                    // printf("%s\n",path);
                    struct dire *temp = fringe->next; 
                    struct dire  *nextDir = (struct dire *) malloc(sizeof(struct dire));
                    strcpy(nextDir->pathName, path);
                    fringe->next = nextDir;
                    nextDir->next = temp;
                    fringe = fringe->next;
                    
                }
            }
        }
        // printf("%s , %s\n",fringe->pathName,curr->pathName);
        fringe = curr;
        fringe = fringe->next;
        closedir(folder);
    }
    fringe = cur;


    while (start!= NULL){

        printf("%d\t%s\n", start->size,start->pathName);
        start = start->next;
	}
 

    return 0;
}
