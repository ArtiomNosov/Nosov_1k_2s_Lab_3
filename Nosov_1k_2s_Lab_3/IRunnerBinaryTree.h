#pragma once

template<typename T>
class TNode {
public:
    TNode(T value)
        : Value(value)
        , Left(nullptr)
        , Right(nullptr)
        , Parent(nullptr)
    {
    }

    T Value;
    TNode<T>* Left;
    TNode<T>* Right;
    TNode<T>* Parent;
    int Height = -1;
};

template<typename T>
class IRunnerBinaryTree {
public:
    IRunnerBinaryTree()
        : Root(nullptr)
    {
    }

    IRunnerBinaryTree(T* a, long l)
        : Root(nullptr)
    {
        for (long i = 0; i < l; i++) InsertValue(a[i]);
    }

    ~IRunnerBinaryTree() {
        DestroyNode(Root);
    }

    void InsertValue(T x);

    bool DeleteValue(T x);

    int DeleteAllValues(T x);

    int GetTreeHeight();

private:
    static void DestroyNode(TNode<T>* node) {
        if (node) {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }

    TNode<T>* GetRoot() {
        return Root;
    }

    TNode<T>* GetNodeWithValue(T x)
    {
        TNode<T>** cur = &(Root);
        while (*cur) {
            TNode<T>* node = *cur;
            if (x < node->Value) {
                cur = &(node->Left);
            }
            else if (x > node->Value) {
                cur = &(node->Right);
            }
            else {
                return *cur;
            }
        }
        return nullptr;
    }

    void AddTree(TNode<T>* addNode)
    {
        InsertValue(addNode->Value);
        if (addNode->Left != nullptr)
            AddTree(addNode->Left);
        if (addNode->Right != nullptr)
            AddTree(addNode->Right);
    }

    int calcHeight(TNode<T>* node) {
        int hl, hr;
        if (node != nullptr) {
            hl = calcHeight(node->Left);
            hr = calcHeight(node->Right);
            node->Height = ((hl > hr) ? hl : hr) + 1;
            return node->Height;
        }
        else {
            return 0;
        }
    }

        // Обходы дерева TLR (КЛП), LTR (ЛКП), LRT(ЛПК)
     // Обход TLR
    template<typename Ret>
    void TLR(Ret(*p)(TNode<T>*), TNode<T>* node)
    {
        if (node == nullptr) return;
        p(node);
        TLR(p, node->Left);
        TLR(p, node->Right);
    }
     // Обход LTR
    template<typename Ret>
    void LTR(Ret (*p)(TNode<T>*), TNode<T>* node)
    {
        if (node == nullptr) return;
        LTR(p, node->Left);
        p(node);
        LTR(p, node->Right);
    }
     // Обход LRT
    template<typename Ret>
    void LRT(Ret (*p)(TNode<T>*), TNode<T>* node)
    {
        if (node == nullptr) return;
        LRT(p, node->Left);
        LRT(p, node->Right);
        p(node);
    }
    TNode<T>* Root;
};

template<typename T>
inline void IRunnerBinaryTree<T>::InsertValue(T x)
{
    TNode<T>** cur = &(Root);
    TNode<T>* prev = nullptr;
    while (*cur) {
        TNode<T>& node = **cur;
        prev = *cur;
        if (x < node.Value) {
            cur = &node.Left;
        }
        else if (x > node.Value) {
            cur = &node.Right;
        }
        else {
            cur = &node.Right;
        }
    }
    *cur = new TNode<T>(x);
    (*cur)->Parent = prev;
};

// TODO: Рефакторинг.
template<typename T>
bool IRunnerBinaryTree<T>::DeleteValue(T x)
{
    TNode<T>* nodeDel = GetNodeWithValue(x);
    if (nodeDel == nullptr) return false;
    TNode<T>* nodeLeft = nodeDel->Left;
    TNode<T>* nodeRight = nodeDel->Right;
    TNode<T>* nodeParent = nodeDel->Parent;
    TNode<T>** additionalBranch = nullptr;
    auto tmp = Root;
    if (nodeParent != nullptr) additionalBranch = ((nodeParent->Left == nodeDel) ? &(nodeParent->Left) : &(nodeParent->Right));
    if (nodeParent == nullptr)
    {
        if (nodeLeft == nullptr && nodeRight == nullptr)
        {
            delete Root;
            Root = nullptr;
        }
        else if (nodeLeft != nullptr && nodeRight != nullptr)
        {
            Root = nodeLeft;
            Root->Parent = nullptr;
            delete tmp;
            tmp = nullptr;
            AddTree(nodeRight);
        }
        else if (nodeLeft != nullptr)
        {
            Root = nodeLeft;
            Root->Parent = nullptr;
            delete tmp;
            tmp = nullptr;
        }
        else if (nodeRight != nullptr)
        {
            Root = nodeRight;
            Root->Parent = nullptr;
            delete tmp;
            tmp = nullptr;
        }
    }
    else
    {
        if (nodeLeft == nullptr && nodeRight == nullptr)
        {
            delete nodeDel;
            nodeDel = nullptr;
            *additionalBranch = nullptr;
        }
        else if (nodeLeft != nullptr && nodeRight != nullptr)
        {
            *additionalBranch = nodeLeft;
            (*additionalBranch)->Parent = nodeParent;
            delete nodeDel;
            nodeDel = nullptr;
            AddTree(nodeRight);
        }
        else if (nodeLeft != nullptr)
        {
            *additionalBranch = nodeLeft;
            (*additionalBranch)->Parent = nodeParent;
            delete nodeDel;
            nodeDel = nullptr;
        }
        else if (nodeRight != nullptr)
        {
            *additionalBranch = nodeRight;
            (*additionalBranch)->Parent = nodeParent;
            delete nodeDel;
            nodeDel = nullptr;
        }
    }
    /*if (nodeLeft != nullptr && nodeRight != nullptr)
    {
        if (nodeParent == nullptr)
        {
            tmp = Root;
            Root = nodeLeft;
            if (Root != nullptr) Root->Parent = nullptr;
            delete tmp;
        }
        else
        {
            tmp = *additionalBranch;
            *additionalBranch = nodeLeft;
            if (*additionalBranch != nullptr) (*additionalBranch)->Parent = nodeParent;
            delete tmp;
        }
        AddTree(nodeRight);
    }
    else if (nodeParent == nullptr)
    {
        tmp = Root;
        Root = ((nodeLeft != nullptr) ? nodeLeft : nodeRight);
        if (Root != nullptr) Root->Parent = nullptr;
        if (tmp != nullptr) delete tmp;
    }
    else if (nodeLeft != nullptr)
    {
        tmp = *additionalBranch;
        *additionalBranch = (nodeLeft != nullptr) ? nodeLeft : nodeRight;
        if (*additionalBranch != nullptr) (*additionalBranch)->Parent = nodeParent;
        delete tmp;
    }
    else if (nodeRight != nullptr)
    {
        tmp = *additionalBranch;
        *additionalBranch = (nodeLeft != nullptr) ? nodeLeft : nodeRight;
        if (*additionalBranch != nullptr) (*additionalBranch)->Parent = nodeParent;
        delete tmp;
    }
    else if (nodeLeft == nullptr && nodeRight == nullptr)
    {
        delete *additionalBranch;
    }*/
    return true;
};

 // Return number delete values
template<typename T>
int IRunnerBinaryTree<T>::DeleteAllValues(T x)
{
    int numberDeleteValues = 0;
    while (DeleteValue(x)) {
        numberDeleteValues = numberDeleteValues + 1;
    }
    return numberDeleteValues;
};

 // Return -1 if tree root is nullptr
template<typename T>
inline int IRunnerBinaryTree<T>::GetTreeHeight()
{
    if (Root == nullptr) return -1;
    calcHeight(Root);
    return Root->Height;
}
