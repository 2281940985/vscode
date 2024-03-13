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
    eleType sum();//������������Ԫ�صĺ�
    int StepCount();

};
void LinkedList :: Insert(int i, eleType value){ //��ΪInsert��LinkedList��Ա���� �����Է���LinkedList
    if (i < 0 || i > size){            //���public����������head
        cout << "�����쳣" << endl;//�ж������Ƿ�������Χ��
    }
    else{
        ListNode* NewNode = new ListNode(value);//�ùؼ���new�����ڴ�ռ䣬�����׵�ַ(��ָ��)��
        if(i==0){//��Ϊ�������LisNodeָ����������Ա��봫��ֵ���г�ʼ��������ListNodeָ�����NewNode������new������׵�ַ
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
    while(curr && curr ->data != value){ //�������������鶼û���֣���ʱcurrΪnull�� �� ���ָ�Ԫ�� ����ѭ��
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
eleType LinkedList :: sum()
{
    eleType sum = 0;
    ListNode* curr = head;
    for (int i = 0; i < size; ++i)
    {
        sum+=curr->data;
        curr = curr->next;
        
    }
    return sum;
} 
int LinkedList :: StepCount()
{
    ListNode* curr = head;
    int ret = 0;
    while (curr)
    {
        ret += (curr -> data +1)/2;
        curr = curr ->next;
    }
    return ret;
    
}
int main()
{
    int n;
    while (cin >> n && n)
    {
        LinkedList l;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            l.Insert(i,x);
        }
        cout << l.StepCount() << endl;
        
    }
    
    system("pause");
    return 0;

}