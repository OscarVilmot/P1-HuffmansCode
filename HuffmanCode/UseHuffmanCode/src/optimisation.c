#include <stdlib.h>
#include "../includes/optimisation.h"
#include "../includes/occurence.h"

//1st PHASE OF OPTIMIZATION NOT INCLUDDED IN THE MAIN CODE
Queue* create_queue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data_queue = NULL;
    return q;
}

int is_empty(Queue* q){
    if(q->data_queue == NULL) return 1;
    else return 0;
}



void enqueue(Queue* q, Node* val){
    //ajout à la fin
    if (val != NULL){
        Element* n_e = (Element*)malloc(sizeof(Element));
        n_e->data = val;
        n_e->next = NULL;
        if (is_empty(q) == 1){
            q->data_queue = n_e;
        }
        else{
            Element* temp = q->data_queue;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = n_e;
        }
    }
}


Node* dequeue(Queue* q){
    //retirer au début
    if (is_empty(q) == 1) return NULL;
    else{
        Element* old = q->data_queue;
        q->data_queue = q->data_queue->next;
        Node* temp = old->data;
        free(old);
        return temp;
    }
}
Node* create_common_node(Node* node1, Node* node2){
    Node* common = (Node*) malloc(sizeof(Node));
    common->right = node2;
    common->left = node1;
    common->letter = '\0';
    common->occurrence = node1->occurrence + node2->occurrence;
}


Node* create_tree(Node** tab, int n){
    if(n==0) return NULL;
    Queue* mainQueue = create_queue();
    Queue* temporaryQueue = create_queue();
    for(int i = 0; i < n; i++){
        enqueue(mainQueue, tab[i]);
    }
    Node* common;
    while(is_empty(mainQueue) != 1){
        Node* newNode = dequeue(mainQueue);
        if(is_empty(mainQueue) != 1 && is_empty(temporaryQueue) != 1){
            if(mainQueue->data_queue->data->occurrence < temporaryQueue->data_queue->data->occurrence){
                Node* binomeOfNewNode = dequeue(mainQueue);
                common = create_common_node(newNode, binomeOfNewNode);
                enqueue(temporaryQueue, common);
            }
            else
            {
                Node* binomeOfNewNode = dequeue(temporaryQueue);
                common = create_common_node(newNode, binomeOfNewNode);
                enqueue(temporaryQueue, common);
            }
        }
        else if(is_empty(temporaryQueue) == 1 ){
            Node* binomeOfNewNode = dequeue(mainQueue);
            common = create_common_node(newNode, binomeOfNewNode);
            enqueue(temporaryQueue, common);
        }
        else if(is_empty(mainQueue) == 1 ){
            enqueue(temporaryQueue, newNode);
        }
    }
    while(is_empty(temporaryQueue) != 1){
        Node* tmp = dequeue(temporaryQueue);
        if(is_empty(temporaryQueue) != 1){
            Node* newNode = dequeue(temporaryQueue);
            common = create_common_node(tmp, newNode);
        }
        else{
            common = create_common_node(tmp, common);
        }
    }
    return common;
}

int add_node(Node*** tab, int n, char caractere)
{
    if(n == 0){
        return ;
    }
    int start = 0;
    int end = n;
    int find = 0;
    while(find != 1 && start < end){
        int middle = (start+end)/2;
        if((*tab)[middle]->OccurenceLetter->letter == caractere ){
            (*tab)[middle]->OccurrenceLetter->occurence++;
            find = 1;
        }
        else if((*tab)[middle]->OccurenceLetter->letter < caractere){
            start = middle + 1;
        }
        else{
            end = middle-1;
        }
    }
    if(find == 1){
        return n;
    }
    else{
        int j = 0;
        Node** newTab = (Node**) malloc((n+1)*sizeof(Node*));
        Node* newElement = (Node*) malloc(sizeof(Node));
        newElement->OccurenceLetter->letter = caractere;
        newElement->OccurenceLetter->occurence = 1;
        newElement->right = NULL;
        newElement->left = NULL;
        int modif = 0;
        for(int i = 0; i < n+1; i++){
            if((j == n || (*tab)[j]->OccurenceLetter->letter > caractere) && modif == 0){
                newTab[i] = newElement;
                modif = 1;
            }
            else{
                newTab[i] = (*tab)[j];
                j++;
            }
        }
        for(int i = 0; i < n; i++){
            free((*tab)[i]);
        }
        free(*tab);
        *tab = newTab;
        return n+1;
    }
}

static void swapElement(ElementOccurrenceLetter* first, ElementOccurrenceLetter* second) {
    OccurrenceLetter* temp = first->data;
    first->data = second->data;
    second->data = temp;
}

void bubbleSortListOccurrences(ElementOccurrenceLetter* occurrences, int sizeListOccurrences) {
    if (occurrences != NULL) {
        int isSwap;
        ElementOccurrenceLetter* current;
        ElementOccurrenceLetter* limit = NULL;

        do {
            isSwap = 0;
            current = occurrences;

            while (current->next != limit) {
                if (current->data->occurrence > current->next->data->occurrence) {
                    swapElement(current, current->next);
                    isSwap = 1;
                }
                current = current->next;
            }
            limit = current;
        } while (isSwap);
    }
}
