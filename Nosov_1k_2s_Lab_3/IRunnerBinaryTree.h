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
        for (long i; i < l; i++) InsertValue(a[i]);
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
            TNode<T>& node = **cur;
            if (x < node.Key) {
                cur = &node.Left;
            }
            else if (x > node.Key) {
                cur = &node.Right;
            }
            else {
                return *cur;
            }
        }
        return nullptr;
    }

    void AddTree(TNode<T>* addNode)
    {
        Insert(addNode->Value);
        if (addNode->Left != nullptr)
            AddTree(addNode->Left);
        if (addNode->Right != nullptr)
            AddTree(addNode->Right);
    }

    int calcHeight(TNode<T>* node) {
        int hl, hr;
        if (node != nullptr) {
            hl = calcHeight(node.left);
            hr = calcHeight(node.right);
            return node.Height = ((hl > hr) ? hl : hr) + 1;
        }
        else {
            return -1;
        }
    }

        // Œ·ıÓ‰˚ ‰ÂÂ‚‡ TLR ( Àœ), LTR (À œ), LRT(Àœ )
     // Œ·ıÓ‰ TLR
    void TLR(auto (*p)(TNode<T>*), TNode<T>* node)
    {
        if (node == nullptr) return;
        p(node);
        TLR(node->Left);
        TLR(node->Right);
    }
     // Œ·ıÓ‰ LTR
    void LTR(auto (*p)(TNode<T>*), TNode<T>* node)
    {
        if (node == nullptr) return;
        LTR(node->Left);
        p(node);
        LTR(node->Right);
    }
     // Œ·ıÓ‰ LRT
    void LRT(auto (*p)(TNode<T>*), TNode<T>* node)
    {
        if (node == nullptr) return;
        LRT(node->Left);
        LRT(node->Right);
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
        if (x < node.Key) {
            cur = &node.Left;
        }
        else if (x > node.Key) {
            cur = &node.Right;
        }
        else {
            cur = &node.Right;
        }
    }
    *cur = new TNode<T>(x);
    (*cur)->Parent = prev;
};

template<typename T>
bool IRunnerBinaryTree<T>::DeleteValue(T x)
{
    TNode<T>* nodeDel = GetNodeWithValue(x);
    if (nodeDel == nullptr) return false;
    TNode<T>* nodeLeft = nodeDel->Left;
    TNode<T>* nodeRight = nodeDel->Right;
    TNode<T>* nodeParent = nodeDel->Parent;
    TNode<T>* additionalBranch = nullptr;
    if (nodeParent != nullptr) additionalBranch = (nodeParent->Left == nodeDel) ? nodeParent->Left : nodeParent->Right;
    delete nodeDel;
    if (nodeLeft != nullptr && nodeRight != nullptr)
    {
        if (nodeParent == nullptr)
        {
            Root = nodeLeft;
        }
        else
        {
            additionalBranch = nodeLeft;
        }
        AddTree(nodeRight);

    }
    else if (nodeParent == nullptr)
    {
        Root = (nodeLeft != nullptr) ? nodeLeft : nodeRight;
    }
    else if (nodeLeft != nullptr)
    {
        additionalBranch = (nodeLeft != nullptr) ? nodeLeft : nodeRight;
    }
    else if (nodeRight != nullptr)
    {
        additionalBranch = (nodeLeft != nullptr) ? nodeLeft : nodeRight;
    }
    return true;
};

 // Return number delete values
template<typename T>
int IRunnerBinaryTree<T>::DeleteAllValues(T x)
{
    int numberDeleteValues = 0;
    while (DeleteValue(x))
        numberDeleteValues++;
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
