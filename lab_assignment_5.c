#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int count = 0;
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
    
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    node* temp = head;
    int count = length(head);
    char *toString = (char*) malloc((count+1)*sizeof(char));
    int i = 0;
    for(; i < count; i++){
        toString[i] = head->letter;
        head = head->next;
    }
    toString[i] = '\0';
    
    return toString;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    struct node* newChar = (struct node*) malloc(sizeof(struct node));
    newChar->letter = c;
    newChar->next = NULL;
    if(*pHead == NULL){
        *pHead = newChar;
        return;
    }
    node* temp = *pHead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newChar;
    
    
    
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* temp = *pHead;
    while(temp != NULL){
        free(temp);
        temp = temp->next;
        
    }
    
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}