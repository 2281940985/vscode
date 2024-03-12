#include <iostream>
using namespace std;
#define eleType int
class ListNode{ //;列表当中的节点
    public:
        eleType data;//访问链表数据
        ListNode *next;//访问链表的指针
        ListNode(eleType x){ //构造函数，初始化成员data
        data = x;
        next = NULL;//初始化链表指针为空，即指向末尾
        }

};
class LinkedList
{
private:
    ListNode* head;//链表第一个元素的头部（即指针），即存储指向下一个节点的地址
    int size;//链表大小
public:
    LinkedList(void){//构造函数，初始化，链表无元素时，头部指向末尾，即为空
        head = nullptr;
        size = 0;
    };
    ~LinkedList(){};//析构函数
    void Insert(int i, eleType value);//成员函数声明，在外部仍需要定义
    void Delete(int i);
    void Updata(int i, eleType value);
    void Print();
    ListNode* Find(eleType value);
    ListNode* Get(int i);

};
void LinkedList :: Insert(int i, eleType value){
    if (i < 0 || i > size){
        cout << "索引异常" << endl;//判断索引是否在链表范围内
    }
    else{
        ListNode* NewNode = new ListNode(value);//用关键字new分配内存空间，返回首地址(即指针)，
        if(i==0){ //并将该地址指向的值赋为value。定义ListNode指针变量NewNode，接收new分配的首地址
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
        cout << "索引异常" << endl;
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
        cout << "索引异常" << endl;
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