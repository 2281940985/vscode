//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
#include <iostream>
using namespace std;

struct Listnode
{
    int val;
    Listnode *next;
    Listnode(int x) : val(x), next(NULL) {}
};
class Soution
{
public:
    int kthToLast(Listnode* head, int k) 
    {
        Listnode* fast = head;
        while(k--)
        {
            fast = fast->next;
        }//让快指针先走k步，慢指针在同步启动
        Listnode* slow = head;
        while(fast)//快指针到达链表尾部，慢指针到达倒数第k个节点
        {
            fast = fast->next;
            slow = slow->next;
        }
    return slow->val;
    }
};
int main()
{
    Soution s;
    Listnode* head = new Listnode(1);
    head->next = new Listnode(2);
    head->next->next = new Listnode(3);
    head->next->next->next = new Listnode(4);
    head->next->next->next->next = new Listnode(5);
    cout<<s.kthToLast(head, 2)<<endl;   
    system("pause");
    return 0;
}