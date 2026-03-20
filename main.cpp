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
// void Insert_Any(int data,int n )
// /*@数据 @位置
//  *
//  */
// {
//     node* temp1 = new node();
//     temp1->data = data;
//     if (n==1) //改变头指针和temp1的位置
//     {
//         temp1->next = head;
//         head = temp1;
//     }
//     else
//     {
//         node* temp2 =head;//to find the nth node
//         for (int i=0;i<n-2;i++)
//         {
//             temp2 = temp2->next;
//         }
//             temp1->next = temp2->next;
//             temp2->next = temp1;
//     }
// }
// void Delete_Any(int n)
// {
//     node* temp1 = head;
//     if (n>1)
//     {
//         for (int i= 0;i<n-2;i++)
//         {
//             temp1 = temp1 -> next;
//         }
//         node* temp2 = temp1; //temp2是n-1节点
//         temp1 = temp1->next; //temp1是n节点
//         temp2->next = temp1->next;
//         free(temp1);
//     }
//     else
//     {
//         head = temp1->next;
//         free(temp1);
//
//     }
// }
node * Reverse(node* head)
{
    node *curr,*prev,*next;
    curr = head;
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
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
void PrintR(node* temp) //递归
{
    if (temp == NULL)
    {
        cout<<endl;
        return;
    }
    else
    {
        PrintR(temp->next);
        printf("%d",temp->data);
    }
}
node * ReverseR(node * p) //使用递归法实现链表翻转
{
    if (p == NULL || p->next == NULL)
    {
        return p;
    }
    // p = ReverseR(p->next);
    // node *temp = p->next;
    // temp->next = p;
    // p->next = NULL;
    // return p ;
    // 2. 递归：找到翻转后的新头节点（也就是原链表的最后一个节点）
    node* newHead = ReverseR(p->next);

    // 3. 翻转：让“下一个节点”的 next 指向自己
    // 比如 1->2->3，此时 p 是 2，p->next 是 3
    // 下面这行让 3 指向 2
    p->next->next = p;

    // 4. 断开：防止形成环，将原来的 next 置为空
    p->next = NULL;

    // 5. 将新头节点一层层传回去
    return newHead;
}
int main()
{
    node* head;
    head= NULL;//head pointer
    Insert(&head,1);
    Insert(&head,2);
    Insert(&head,3);
    Insert(&head,4);
    Print(head);
    head= ReverseR(head);
    Print(head);
    //PrintR(head);
}
