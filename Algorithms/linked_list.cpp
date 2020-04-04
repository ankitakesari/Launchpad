#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

int length_ll(node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return length;
}

void insert_at_head(node *&head, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        return;
    }

    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insert_at_tail(node *&head, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    node *new_node = new node(data);
    temp->next = new_node;
}

void insert_at_k(node *&head, int data, int k)
{
    if (k == 1)
    {
        insert_at_head(head, data);
    }

    else if (k >= length_ll(head))
    {
        insert_at_tail(head, data);
    }
    else
    {
        int pos = 1;
        node *temp = head;

        while (pos < k - 1)
        {
            pos++;
            temp = temp->next;
        }
        node *new_node = new node(data);
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void print_list(node *head)
{
    //cout<<"A";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void delete_at_head(node *&head)
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;
    head = head->next;
    delete temp;
    return;
}

void delete_at_k(node *&head, int k)
{
    if (k == 1)
    {
        delete_at_head(head);
    }

    node *temp = head;

    int count = 1;
    while (count < k - 1)
    {
        count++;
        temp = temp->next;
    }

    node *old = temp->next;
    temp->next = temp->next->next;
    delete old;
}

void delete_at_tail(node *&head)
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    node *old = temp->next;
    delete old;
    temp->next = NULL;
}

bool search_itr(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }

    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }

    return false;
}

node *mid_ele(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *slow = head;
    node *fast = head;
    //if lower mid in case of even elements then fast=head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// node* mid_ele(node* head) {
// 	if (head == NULL || head->next == NULL) {
// 		return head;
// 	}

// 	node* slow = head;
// 	node* fast = head->next;

// 	while (fast != NULL && fast->next != NULL) {
// 		fast = fast->next->next;
// 		slow = slow->next;
// 	}
// 	return slow;
// }

bool search_recur(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }

    if (head->data == key)
    {
        return true;
    }

    search_recur(head->next, key);
}

void build_ll(node *&head)
{
    int d;
    cin >> d;

    while (d != -1)
    {
        insert_at_tail(head, d);
        cin >> d;
    }
}

istream &operator>>(istream &is, node *&head)
{
    build_ll(head);
    return is;
}

ostream &operator<<(ostream &os, node *&head)
{
    print_list(head);
    return os;
}

void reverse_itr(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *next_node;

    while (curr != NULL)
    {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    head = prev;
}

node *reverse_recur(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *new_head = reverse_recur(head->next);
    node *curr = head;
    curr->next->next = curr;
    curr->next = NULL;
    return new_head;
}

void k_from_last(node *head, int k)
{
    if (head == NULL)
    {
        return;
    }

    node *slow = head;
    node *fast = head;

    int count = 0;

    while (count < k)
    {
        if (fast == NULL)
        {
            cout << " K is greater than the nodes" << endl;
            return;
        }

        count++;
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    cout << "kth node from last: " << slow->data;
}

// node* merge(node* a,node*b){
//     if(b==NULL){
//         return a;
//     }

//     if(a==NULL){
//         return b;
//     }

//     node *c;

//     if(a->data <= b->data){
//         c=a;
//         c->next=merge(a->next ,b);
//     }

//     else{
//         c=b;
//         c->next=merge(a,b->next);
//     }

//     return c;

// }

// node* merge_sort(node* head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     node* mid_node= mid_ele(head);
//     node *a=head;
//     node *b=mid_node->next;
//     mid_node->next=NULL;

//     a=merge_sort(a);
//     b=merge_sort(b);
//     node* c= merge(a,b);

//     return c;
// }
node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }

    node *c;
    if (a->data <= b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}
node *mergeSort(node *head)
{
    cout << "a";
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *midNode = mid_ele(head);
    node *a = head;          //left half linked list
    node *b = midNode->next; //right half linked list

    midNode->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    node *c = merge(a, b);

    return c;
}

int main()
{
    node *head = NULL;
    node *head2 = NULL;

    // insert_at_head(head,5);
    // insert_at_head(head,10);
    // insert_at_head(head,11);
    // insert_at_head(head,15);

    // print_list(head);
    //  cout<<endl;
    // cout<<"length: "<<length_ll(head);
    // cout<<endl;

    // insert_at_tail(head,4);
    // insert_at_tail(head,3);
    // insert_at_tail(head,2);
    // insert_at_k(head,7,5);

    // print_list(head);
    // cout<<endl;
    // cout<<"length: "<<length_ll(head);
    // cout<<endl;

    // delete_at_head(head);
    // print_list(head);
    // cout<<endl;

    // delete_at_k(head,3);
    // print_list(head);
    // cout<<endl;

    //  delete_at_tail(head);
    // print_list(head);
    // cout<<endl;

    // if(search_itr(head,7)){
    //     cout<<"key found"<<endl;
    // }

    // else{
    //     cout<<"key not found"<<endl;
    // }

    //  if(search_recur(head,11)){
    //     cout<<"key found"<<endl;
    // }

    // else{
    //     cout<<"key not found"<<endl;
    // }
    // cout<<endl;
    // node* midd=mid_ele(head);
    // cout<<"middle element: "<<midd->data;

    // build_ll(head);
    // print_list(head);

    cin >> head;
    //cout<<head<<endl;

    //cin>>head2;
    //cout<<head2<<endl;

    // reverse_itr(head);
    // cout<<head;

    // head=reverse_recur(head);
    // cout<<head<<endl;

    //k_from_last(head,3);

    node *c = mergeSort(head);
    print_list(c);
}