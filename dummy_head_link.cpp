#include <iostream>
#include<vector>

using namespace std;

class MyLinkedList {
    class ListNode
    {
    public:
        int val;
        ListNode *next;
        ListNode(int v) : val(v), next(nullptr){}
    };
    ListNode *dummyHead = new ListNode(0);
    int Size;
public:
    MyLinkedList() {
        Size = 0;
    }
    
    int get(int index) {
        if(index >= Size || index < 0)
        {
            return -1;
        }
        ListNode *cur = dummyHead;
        for(int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur->next->val;


    }
    
    void addAtHead(int val) {
        ListNode *Head = new ListNode(val);
        Head ->next = dummyHead ->next;
        dummyHead -> next = Head;
        Size++;
    }
    
    void addAtTail(int val) {
        ListNode *cur = dummyHead;
        while(cur->next)
        {
            cur = cur->next;
        }
        ListNode *TailNode = new ListNode(val);
        cur->next = TailNode;
        Size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > Size || index < 0)
        {
            return;
        }
        ListNode *NewNode = new ListNode(val);
        ListNode *cur = dummyHead;
        for(int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        NewNode->next = cur->next;
        cur->next = NewNode;
        Size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= Size || index < 0)
        {
            return;
        }
        ListNode *cur = dummyHead;
        for(int i = 0; i < index; ++i)
        {
            cur = cur ->next;
        }
        ListNode *tmp = cur ->next; 
        cur ->next = cur ->next ->next;
        delete tmp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(2);
    obj ->deleteAtIndex(1);
    obj->addAtTail(5);
    obj->addAtIndex(1,2);
    obj->addAtIndex(2,3);
    obj->addAtIndex(3,4);
    obj ->deleteAtIndex(2);

    return 0;

}