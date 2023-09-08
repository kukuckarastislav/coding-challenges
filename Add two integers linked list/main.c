#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node node;

node* newNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node* createList(int arr[], int n){
    node *head = newNode(arr[0]);
    node *temp = head;
    node *next = NULL;
    for (int i = 1; i < n; i++){
        next = newNode(arr[i]);
        temp->next = next;
        temp = next;
    }
    return head;
}

void printList(node* head){
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* sumTwoList(node* head1, node* head2){
    node *temp1 = head1;
    node *temp2 = head2;
    node *resultHead = newNode((temp1->data + temp2->data)%10);
    int over = (temp1->data + temp2->data)/10;
    node *temp3 = resultHead;
    temp1 = temp1->next;
    temp2 = temp2->next;
    while(temp1 != NULL || temp2 != NULL || over){

        int data1 = temp1 == NULL ? 0 : temp1->data;
        int data2 = temp2 == NULL ? 0 : temp2->data;

        int sum = (data1 + data2 + over);
        over = sum / 10;

        temp3->next = newNode(sum % 10);

        temp3 = temp3->next;
        temp1 = temp1 == NULL ? NULL : temp1->next;
        temp2 = temp2 == NULL ? NULL : temp2->next;
    }

    return resultHead;
}


int main(){

    int arr1[] = {1, 0, 9, 9};
    int arr2[] = {7, 3, 2};
    node *head1 = createList(arr1, 4);
    node *head2 = createList(arr2, 3);
    node *head3 = sumTwoList(head1, head2);

    printList(head1);
    printList(head2);
    printList(head3);

    return 0;
}