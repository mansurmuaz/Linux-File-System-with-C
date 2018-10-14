#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

enum nodeType {File, Folder};

typedef struct node{
    enum nodeType type;
    char* name;
    int numberOfItems;
    size_t size;
    time_t date;
    char* content;
    struct node* previous;
    struct node* parent;
    struct node* next;
    struct node* child;
}node;

char *getString(){
    size_t size = 10;
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);
    if(!str)return str;
    while(EOF!=(ch=fgetc(stdin)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}

node* getNode(node *currentFolder, char* name, enum nodeType type) {

    if (currentFolder->child != NULL) {

        node *currentNode = currentFolder->child;

        while (currentNode->next != NULL) {

            if (strcmp(name, currentNode->name) == 0 && currentNode->type == type) {
                return currentNode;
            }
            currentNode = currentNode->next;
        }

        if (strcmp(name, currentNode->name) == 0 && currentNode->type == type) {
            return currentNode;
        } else return NULL;

    } else return NULL;
}

node* getNodeTypeless(node *currentFolder, char* name) {

    if (currentFolder->child != NULL) {

        node *currentNode = currentFolder->child;

        while (currentNode->next != NULL) {

            if (strcmp(name, currentNode->name) == 0) {
                return currentNode;
            }
            currentNode = currentNode->next;
        }

        if (strcmp(name, currentNode->name) == 0) {
            return currentNode;
        } else return NULL;

    } else return NULL;
}

void mkdir(node *currentFolder, char *command) {
    if (strtok(command, " ") != NULL) {
        char* folderName = strtok(NULL, " ");
        if (folderName != NULL) {
            if (getNodeTypeless(currentFolder, folderName) == NULL) {

                currentFolder->numberOfItems++;
                node *newFolder = (node*) malloc(sizeof(node));

                if (currentFolder->child == NULL) {
                    currentFolder->child = newFolder;
                    newFolder->previous = NULL;
                    newFolder->parent = currentFolder;
                } else {

                    node *currentNode = currentFolder->child;

                    while (currentNode->next != NULL) {
                        currentNode = currentNode->next;
                    }
                    currentNode->next = newFolder;
                    newFolder->previous = currentNode;
                    newFolder->parent = NULL;
                }

                char* newFolderName = (char*) malloc(sizeof(char)*(strlen(folderName)+1));
                strcpy(newFolderName, folderName);

                newFolder->name = newFolderName;
                newFolder->type = Folder;
                newFolder->numberOfItems = 0;
                newFolder->size = 0;
                newFolder->date = time(NULL);
                newFolder->content = NULL;
                newFolder->next = NULL;
                newFolder->child = NULL;

                printf("Folder '%s' added\n", newFolder->name);
            } else {
                fprintf(stderr, "'%s' is already exist in current directory!\n",  folderName);
            }
        }
    }
}

void touch(node *currentFolder, char *command) {

    if (strtok(command, " ") != NULL) {
        char *fileName = strtok(NULL, " ");
        if (fileName != NULL) {
            if (getNodeTypeless(currentFolder, fileName) == NULL) {

                currentFolder->numberOfItems++;

                node *newFile = (node *) malloc(sizeof(node));

                if (currentFolder->child == NULL) {
                    currentFolder->child = newFile;
                    newFile->previous = NULL;
                    newFile->parent = currentFolder;
                } else {

                    node *currentNode = currentFolder->child;

                    while (currentNode->next != NULL) {
                        currentNode = currentNode->next;
                    }
                    currentNode->next = newFile;
                    newFile->previous = currentNode;
                    newFile->parent = NULL;
                }

                char* newFileName = (char*) malloc(sizeof(char)*(strlen(fileName)+1));
                strcpy(newFileName, fileName);

                newFile->name = newFileName;
                newFile->type = File;
                newFile->numberOfItems = 0;
                newFile->size = 0;
                newFile->date = time(NULL);
                newFile->content = NULL;
                newFile->next = NULL;
                newFile->child = NULL;

                printf("File '%s' added\n", newFile->name);
            } else {
                fprintf(stderr, "'%s' is already exist in current directory!\n", fileName);
            }
        }
    }
}

void ls(node *currentFolder) {
    if (currentFolder->child == NULL) {
        printf("___Empty____\n");
    } else {

        node *currentNode = currentFolder->child;

        while (currentNode->next != NULL) {

            struct tm *date_time = localtime(&currentNode->date);
            char dateString[26];
            strftime(dateString, 26, "%d %b %H:%M", date_time);

            if (currentNode->type == Folder) {
                printf("%d items\t%s\t%s\n", currentNode->numberOfItems, dateString, currentNode->name);
            } else {
                printf("%dB\t%s\t%s\n", (int)currentNode->size, dateString, currentNode->name);
            }

            currentNode = currentNode->next;
        }

        struct tm *date_time = localtime(&currentNode->date);
        char dateString[26];
        strftime(dateString, 26, "%d %b %H:%M", date_time);

        if (currentNode->type == Folder) {
            printf("%d items\t%s\t%s\n", currentNode->numberOfItems, dateString, currentNode->name);
        } else {
            printf("%dB\t%s\t%s\n", (int)currentNode->size, dateString, currentNode->name);
        }
    }
}

void lsrecursive(node *currentFolder, int indentCount) {

    if (currentFolder->child == NULL) {
        for (int i = 0; i < indentCount; ++i) {
            printf("\t");
        }
        if (indentCount != 0 ) {
            printf("|_");
        }
        printf("___Empty____\n");
    } else {

        node *currentNode = currentFolder->child;

        while (currentNode->next != NULL) {

            for (int i = 0; i < indentCount; ++i) {
                printf("\t");
            }
            if (indentCount != 0 ) {
                printf("|_");
            }
            struct tm *date_time = localtime(&currentNode->date);
            char dateString[26];
            strftime(dateString, 26, "%d %b %H:%M", date_time);

            if (currentNode->type == Folder) {
                printf("%d items\t%s\t%s\n", currentNode->numberOfItems, dateString, currentNode->name);
            } else {
                printf("%dB\t%s\t%s\n", (int)currentNode->size, dateString, currentNode->name);
            }
            if (currentNode->type == Folder){
                lsrecursive(currentNode, indentCount+1);
            }
            currentNode = currentNode->next;
        }
        for (int i = 0; i < indentCount; ++i) {
            printf("\t");
        }
        if (indentCount != 0 ) {
            printf("|_");
        }
        struct tm *date_time = localtime(&currentNode->date);
        char dateString[26];
        strftime(dateString, 26, "%d %b %H:%M", date_time);

        if (currentNode->type == Folder) {
            printf("%d items\t%s\t%s\n", currentNode->numberOfItems, dateString, currentNode->name);
        } else {
            printf("%dB\t%s\t%s\n", (int)currentNode->size, dateString, currentNode->name);
        }
        if (currentNode->type == Folder){
            lsrecursive(currentNode, indentCount+1);
        }
    }
}

void edit(node *currentFolder, char *command) {

    if (strtok(command, " ") != NULL) {
        char *fileName = strtok(NULL, " ");
        if (fileName != NULL) {
            node * editingNode = getNode(currentFolder, fileName, File);
            if (editingNode != NULL) {
                printf("%s\n", "Please enter some text to overwrite the file content:");
                if (editingNode->content != NULL){
                    free(editingNode->content);
                }
                char* content = getString();
                if (content != NULL) {
                    editingNode->content = content;
                    editingNode->size = strlen(editingNode->content);
                    editingNode->date = time(NULL);
                }
            }
        }
    }
}

void pwd(char *path) {
    if (strlen(path) != 1){

        for (int i = 0; i < strlen(path)-1 ; ++i) {
            printf("%c", path[i]);
        }
        printf("\n");
    } else {
        printf("%s\n", path);
    }
}

node* cd(node *currentFolder, char *command, char **path) {

    if (strtok(command, " ") != NULL) {
        char* folderName = strtok(NULL, " ");
        if (folderName != NULL) {

            node *destinationFolder = getNode(currentFolder, folderName, Folder);

            if ( destinationFolder != NULL) {

                size_t newPathLength = strlen(*path) + strlen(destinationFolder->name) + 2;

                *path = (char *) realloc(*path, sizeof(char)* newPathLength);

                strcat(strcat(*path, destinationFolder->name), "/");

                return destinationFolder;
            } else {
                fprintf(stderr, "There is no '%s' folder in current directory!\n",  folderName);
                return currentFolder;
            }
        } else {
            return currentFolder;
        }
    } else {
        return currentFolder;
    }
}

node* cdup(node *currentFolder, char **path) {

    size_t newPathLength = strlen(*path) - strlen(currentFolder->name);

    while (currentFolder->previous != NULL) {
        currentFolder = currentFolder->previous;
    }
    if (currentFolder->parent != NULL ) {

        *path = (char *) realloc(*path, sizeof(char)* newPathLength);
        (*path)[newPathLength-1] = '\0';

        currentFolder = currentFolder->parent;
        return currentFolder;
    } else {
        return currentFolder;
    }
}

void freeNode(node *freeingNode) {

    if (freeingNode->child != NULL) {

        node* currentNode = freeingNode->child;

        while (currentNode->next != NULL) {
            node* nextNode = currentNode->next;
            freeNode(currentNode);
            currentNode = nextNode;
        }
        freeNode(currentNode);
    }
    free(freeingNode->name);
    free(freeingNode->content);
    free(freeingNode);

}

void removeNode(node *removingNode) {
    if (removingNode->parent != NULL){
        if (removingNode->next != NULL) {
            removingNode->next->parent = removingNode->parent;
            removingNode->parent->child = removingNode->next;
            removingNode->next->previous = NULL;
        } else {
            removingNode->parent->child = NULL;
        }
    } else {
        if (removingNode->next != NULL) {
            removingNode->previous->next = removingNode->next;
            removingNode->next->previous  = removingNode->previous;
        } else {
            removingNode->previous->next = NULL;
        }
    }
}

void rm(node *currentFolder, char *command) {

    if (strtok(command, " ") != NULL) {
        char *nodeName = strtok(NULL, " ");
        if (nodeName != NULL) {
            node *removingNode = getNodeTypeless(currentFolder, nodeName);

            if (removingNode != NULL) {

                printf("Do you really want to remove %s and all of its content? (y/n)\n", removingNode->name);

                char *answer = getString();
                if (strcmp(answer, "y") == 0 ) {
                    currentFolder->numberOfItems--;
                    removeNode(removingNode);
                    printf("%s and its all content is removed!\n", removingNode->name);
                    freeNode(removingNode);
                }
                free(answer);
            } else {
                fprintf(stderr, "'%s' is not exist in current directory!\n",  nodeName);
            }
        }
    }
}

void moveNode(node *movingNode, node *destinationFolder) {

    if (destinationFolder->child == NULL) {
        destinationFolder->child = movingNode;
        movingNode->previous = NULL;
        movingNode->parent = destinationFolder;
        movingNode->next = NULL;
    } else {

        node *currentNode = destinationFolder->child;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }

        currentNode->next = movingNode;
        movingNode->previous = currentNode;
        movingNode->parent = NULL;
        movingNode->next = NULL;
    }
    destinationFolder->numberOfItems++;
}

void mov(node *currentFolder, char *command) {

    char* nodeName;
    char* destinationName;

    if (strtok(command, " ") != NULL) {
        nodeName = strtok(NULL, " ");
        if (nodeName != NULL) {
            destinationName = strtok(NULL, " ");
            if (destinationName != NULL) {
                if (strtok(NULL, " ")) {
                    return;
                } else {

                    node* movingNode = getNodeTypeless(currentFolder, nodeName);
                    node* destinationFolder = getNode(currentFolder, destinationName, Folder);

                    if (destinationFolder != NULL && movingNode != NULL && destinationFolder != movingNode) {

                        removeNode(movingNode);
                        moveNode(movingNode, destinationFolder);
                    } else {
                        fprintf(stderr, "Something you made wrong!\n");
                    }
                }
            }
        }
    }
}

int main() {

    node *root = (node*) malloc(sizeof(node));

    char *rootName = (char *) malloc(sizeof(char)*2);
    strcpy(rootName, "/");
    root->type = Folder;
    root->name = rootName;
    root->numberOfItems = 0;
    root->size = 0;
    root->date = time(NULL);
    root->content =NULL;
    root->previous = NULL;
    root->parent = NULL;
    root->next = NULL;
    root->child = NULL;

    node *currentFolder = root;

    char *path = (char *) malloc(sizeof(char)*2);
    strcpy(path, "/");

    while (1) {

        printf("> ");
        char *command = getString();

        if (strncmp(command, "mkdir", 5) == 0) {
            mkdir(currentFolder, command);
        } else if (strncmp(command, "touch", 5) == 0) {
            touch(currentFolder, command);
        } else if (strcmp(command, "ls") == 0) {
            ls(currentFolder);
        } else if (strcmp(command, "lsrecursive") == 0) {
            lsrecursive(currentFolder, 0);
        } else if (strncmp(command, "edit", 4) == 0 ) {
            edit(currentFolder, command);
        } else if (strcmp(command, "pwd") == 0) {
            pwd(path);
        } else if (strcmp(command, "cdup") == 0) {
            currentFolder = cdup(currentFolder, &path);
        } else if (strncmp(command, "cd", 2) == 0){
            currentFolder = cd(currentFolder, command, &path);
        } else if (strncmp(command, "rm", 2) == 0) {
            rm(currentFolder, command);
        } else if (strncmp(command, "mov", 3) == 0) {
            mov(currentFolder, command);
        } else if (strcmp(command, "exit") == 0){
            free(command);
            freeNode(root);
            free(path);
            break;
        }
        free(command);
    }

    return 0;
}

//==11180== HEAP SUMMARY:
//==11180==     in use at exit: 0 bytes in 0 blocks
//==11180==   total heap usage: 182 allocs, 182 frees, 10,723 bytes allocated
//==11180==
//==11180== All heap blocks were freed -- no leaks are possible
//==11180==
//==11180== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
//==11180== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
