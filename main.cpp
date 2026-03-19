#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* head;//global viarient
void Insert(node** pointertohead,int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = *pointertohead;
    *pointertohead = temp;
}
void Insert_Any(int data,int n )
/*@数据 @位置
 *
 */
{
    node* temp1 = new node();
    temp1->data = data;
    if (n==1) //改变头指针和temp1的位置
    {
        temp1->next = head;
        head = temp1;
    }
    else
    {
        node* temp2 =head;//to find the nth node
        for (int i=0;i<n-2;i++)
        {
            temp2 = temp2->next;
        }
            temp1->next = temp2->next;
            temp2->next = temp1;
    }
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
    head= NULL;//head pointer
    Insert_Any(7,1);//7
    Insert_Any(6,1);//67
    Insert_Any(2,2);//627
    Print(head);


}
