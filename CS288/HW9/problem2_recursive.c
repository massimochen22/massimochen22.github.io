#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

struct Node *start = NULL;
struct Node *head = NULL;
int count = 0;

void listFilesRecursively(char *path);

struct Node{
    char pathName[1024];
    int size;
    struct Node *next;
};

void sortedInsert(struct Node** head_ref,
                  struct Node* new_node)
{
    struct Node* current;
    /* Special case for the head end */
    if (*head_ref == NULL|| (*head_ref)->size >= new_node->size) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        head = new_node;
    }
    else {
        /* Locate the node before 
the point of insertion */
        current = *head_ref;
        while (current->next != NULL
               && current->next->size < new_node->size) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}


int main(int argc, char *argv[])
{
    // Directory path to list files
     char *path = argv[1];
    // Input path from user
    listFilesRecursively(path);
    
    start = head;

    while (start!= NULL){
        count++;
        printf("%d\t%s\n", start->size,start->pathName);
        start = start->next;
	}


    return 0;
}


/**
 * Lists all files and sub-directories recursively 
 * considering path as base path.
 */
void listFilesRecursively(char *basePath)
{
    char path[1024];
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    struct stat buffer;

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            if (dp->d_type!=4){
                count++;
                stat(path,&buffer);
                int size = buffer.st_size;
                //printf("%d\t%s\n", size,path);
                //count++;
                struct Node *pnode=(struct Node *) malloc(sizeof(struct Node));
                strcpy( pnode->pathName,path);
                pnode->size = size;
                if (count == 1 ){
                    head = pnode;
                }
                sortedInsert(&start, pnode);
            }

            listFilesRecursively(path);
        }
    }

    closedir(dir);
}