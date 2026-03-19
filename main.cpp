#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};

void Insert(node** pointertohead,int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = *pointertohead;
    *pointertohead = temp;


}
void Print(node* temp)
{

    cout<<"all numbers are followings"<<endl;
    while (temp !=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    node* head= NULL;//head pointer
    cout<<"how many numbers in list"<<endl;
    int num,x;
    cin>>num;
    for (int i=0;i<num;i++)
    {
        cout<<"enter the number"<<endl;
        cin>>x;//new number
        Insert(&head,x);
        Print(head);
    }

}
