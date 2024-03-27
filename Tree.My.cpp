#include<iostream>
#include<string>
using namespace std;

template<typename T>
class ListNode
{
public:
    T Data;
    ListNode* Next;
    ListNode(T data) : Data(data), Next(nullptr){}
    ~ListNode(){}
};
template<typename T>
class TreeNode
{
public:
    T TreeData;
    ListNode<TreeNode<T>*>* ChildHead;
    TreeNode() : ChildHead(nullptr){}
    ~TreeNode(){}
    void AddChild(TreeNode<T>* Node)
    {
        ListNode<TreeNode<T>*>* ChildNode = new ListNode<TreeNode<T>*>(Node);
        if(ChildHead == NULL)
        {
            ChildHead = ChildNode;//ÿ���ڵ��ChildHead��ʼ����Ϊnull��������ӽڵ�󣬲Ų�Ϊ��
        }else
        {
            ChildNode ->Next = ChildHead;//�����ڵ������ӽڵ���ڼ�������ӽڵ�ʱ���µ��ӽڵ��nextָ��ɵ��ӽڵ㼴ChildHead��
                                        //Ȼ���ٰ��µ��ӽڵ㸳ΪChildHead,�Դ����Ƽ�������µ��ӽڵ㡣
            ChildHead = ChildNode;
            //delete ChildNode;ǧ���ܻ���ָ��ChildNode����ΪChildNode���ڣ�����������������ڵ㣬����ָ��ͬһ����ֵܽڵ�
        } 
    }

};
template<typename T>
class Tree
{
private:
    TreeNode<T>* Root;
    TreeNode<T>* Nodes;
public:
    Tree(int MaxNodes)
    {
        Nodes = new TreeNode<T>[MaxNodes]; 
    }
    ~Tree()
    {
        delete[] Nodes;
    }
    TreeNode<T>* GetTreeNode(int id)
    {
        return &Nodes[id];
    }
    void SetRoot(int id)
    {
        Root = &Nodes[id];
    }
    void AddChild(int ParaNodeId, int SonNodeId)
    {
        TreeNode<T>* ParaNode = GetTreeNode(ParaNodeId);
        TreeNode<T>* SonNode = GetTreeNode(SonNodeId);
        ParaNode ->AddChild(SonNode);
        //SonNode ->ChildHead ->Next = ParaNode ->ChildHead
    }
    void AssignData(int id, T data)
    {
        
        (&Nodes[id]) ->TreeData = data;//GetTreeNode(id) ->TreeData = data
    }
    void Print(TreeNode<T>* node)
    {
        if(node == NULL)
        {
            node = Root;
        }
        cout << node ->TreeData;
        ListNode<TreeNode<T>*>* tmp = node ->ChildHead;//ChildHeadָ��ָ��������һ��ڵ㣡����
        while (tmp)
        {
            Print(tmp ->Data);
            tmp = tmp ->Next;//Nextָ����ָ��ͬһ������ڵ㣡����������һ�㣬Ҳ������һ��
            //���￿while�ĵ���ѭ��������һ�����ڵ㣬��ײ������󷵻���һ��Next��Ϊ�յļ�������
        }
        
    }
    
};
int main()
{
    Tree<char> T(9);
    T.SetRoot(0);
    T.AssignData(0,'a');
    T.AssignData(1,'b');
    T.AssignData(2,'c');
    T.AssignData(3,'d');
    T.AssignData(4,'e');
    T.AssignData(5,'f');
    T.AssignData(6,'g');
    T.AssignData(7,'h');
    T.AssignData(8,'i');

    T.AddChild(0,2);
    T.AddChild(0,1);
    T.AddChild(1,3);
    T.AddChild(2,5);
    T.AddChild(2,4);
    T.AddChild(3,8);
    T.AddChild(3,7);
    T.AddChild(3,6);
    T.Print(NULL);

    system("pause");
    return 0;
}