#include <iostream>
using namespace std;
#define eleType int
class ListNode{ //;�б��еĽڵ�
    public:
        eleType data;//������������
        ListNode *next;//���������ָ��
        ListNode(eleType x){ //���캯������ʼ����Աdata
        data = x;
        next = NULL;//��ʼ������ָ��Ϊ�գ���ָ��ĩβ
        }

};
class LinkedList
{
private:
    ListNode* head;//�����һ��Ԫ�ص�ͷ������ָ�룩�����洢ָ����һ���ڵ�ĵ�ַ
    int size;//�����С
public:
    LinkedList(void){//���캯������ʼ����������Ԫ��ʱ��ͷ��ָ��ĩβ����Ϊ��
        head = nullptr;
        size = 0;
    };
    ~LinkedList(){};//��������
    void Insert(int i, eleType value);//��Ա�������������ⲿ����Ҫ����
    void Delete(int i);
    void Updata(int i, eleType value);
    void Print();
    ListNode* Find(eleType value);
    ListNode* Get(int i);

};
void LinkedList :: Insert(int i, eleType value){
    if (i < 0 || i > size){
        cout << "�����쳣" << endl;//�ж������Ƿ�������Χ��
    }
    else{
        ListNode* NewNode = new ListNode(value);//�ùؼ���new�����ڴ�ռ䣬�����׵�ַ(��ָ��)��
        if(i==0){ //�����õ�ַָ���ֵ��Ϊvalue������ListNodeָ�����NewNode������new������׵�ַ
            NewNode->next = head;
            head = NewNode;
        }else{
            ListNode* curr = head;
            for (int j = 0; j < i-1; ++j){
                curr = curr->next;
            }
            NewNode -> next = curr -> next;
            curr -> next = NewNode;

        }
    }
    size++;

}
void LinkedList :: Delete(int i){
    if (i < 0 || i > size){
        cout << "�����쳣" << endl;
    }
    if (i == 0){
        ListNode* temp = head;
        head = head ->next;
        delete temp;
    }else{
        ListNode* curr = head;
        for (int j = 0; j < i-1; ++j){
            curr = curr ->next;
        }
        ListNode* temp = curr->next;
        curr ->next = temp ->next;
        delete temp;
    }
    --size;
}
ListNode* LinkedList :: Find(eleType value){
    ListNode* curr = head;
    while(curr && curr ->data != value){
        curr = curr->next;
    }
    return curr;
} 
ListNode* LinkedList :: Get(int i){
    if (i < 0 || i >= size){
        cout << "�����쳣" << endl;
    }
    ListNode* curr = head;
    for (int j = 0; j < i; ++j){
        curr = curr->next;
    }
    return curr;
}

void LinkedList :: Updata(int i, eleType value){
    Get(i) ->data = value;
}
void LinkedList :: Print(){
    ListNode* curr = head;
    while (curr)
    {
        cout << curr ->data << " ";
        curr = curr ->next;
        //cout << endl;   
    }
     
} 

int main(){
    LinkedList list;
    list.Insert(0,10);
    list.Insert(1,20);
    list.Insert(2,30);
    list.Insert(3,40);
    list.Insert(4,50);
    list.Print();
    list.Delete(1);
    cout << endl;
    list.Print();
    list.Updata(2,60);
    cout << endl;
    list.Print();
    cout<<endl;
    ListNode* tmp = list.Find(30);
    cout << tmp ->data << endl;
    cout << list.Get(3) ->data << endl;

    system("pause");
    return 0; 
}