//ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��
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
        }//�ÿ�ָ������k������ָ����ͬ������
        Listnode* slow = head;
        while(fast)//��ָ�뵽������β������ָ�뵽�ﵹ����k���ڵ�
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