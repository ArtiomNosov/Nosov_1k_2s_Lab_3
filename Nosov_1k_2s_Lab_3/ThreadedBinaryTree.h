#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	struct Node* Left, * Right;
	T Info;

	// True if left pointer points to predecessor 
	// in Inorder Traversal
	bool lthread;

	// True if right pointer points to successor 
	// in Inorder Traversal
	bool rthread;
};

template <typename T>
class ThreadedBinaryTree
{
private:
	Node<T>* Root;
	void AddAfterNode(T info, Node<T>* parent, Node<T>* tmp)
	{
		if (tmp == nullptr)
		{
			Node<T>* tmp = new Node<T>;
			tmp->Info = info;
			tmp->Left = nullptr;
			tmp->Right = nullptr;
		}
		else if (info < parent->Info)
		{
			if (!(parent->Left))
			{
				tmp->Left = parent->Left;
				tmp->Right = parent;
				parent->lthread = false;
				parent->Left = tmp;
			}
			else
			{
				AddAfterNode(info, parent->Left, tmp);
			}
		}
		else if (info >= parent->Info)
		{
			if (!(parent->Right))
			{
				tmp->Left = parent;
				tmp->Right = parent->Right;
				parent->rthread = false;
				parent->Right = tmp;
			}
			else
			{
				AddAfterNode(info, parent->Right, tmp);
			}
			
		}
	}

	Node<T>* inorderSuccessor(Node<T>* ptr)
	{
		// If rthread is set, we can quickly find
		if (ptr->rthread == true)
			return ptr->Right;

		// Else return leftmost child of right subtree
		ptr = ptr->Right;
		while (ptr->lthread == false)
			ptr = ptr->Left;
		return ptr;
	}

public:
	ThreadedBinaryTree<T>() { Root = nullptr; };
	Node<T>* Add(T info)
	{
		// Searching for a Node with given value
		Node<T>* ptr = Root;
		Node<T>* par = nullptr; // Parent of key to be inserted
		while (ptr != nullptr)
		{
			par = ptr; // Update parent pointer

			// Moving on left subtree.
			if (info < ptr->Info)
			{
				if (ptr->lthread == false)
					ptr = ptr->Left;
				else
					break;
			}

			// Moving on right subtree.
			else
			{
				if (ptr->rthread == false)
					ptr = ptr->Right;
				else
					break;
			}
		}

		// Create a new node
		Node<T>* tmp = new Node<T>;
		tmp->Info = info;
		tmp->lthread = true;
		tmp->rthread = true;

		if (par == NULL)
		{
			Root = tmp;
			tmp->Left = nullptr;
			tmp->Right = nullptr;
		}
		else if (info < (par->Info))
		{
			tmp->Left = par->Left;
			tmp->Right = par;
			par->lthread = false;
			par->Left = tmp;
		}
		else
		{
			tmp->Left = par;
			tmp->Right = par->Right;
			par->rthread = false;
			par->Right = tmp;
		}

		return Root;
	}
	
	void PrintThreadedBinaryTree()
	{
		if (Root == nullptr)
			cout << "Tree is empty" << endl;

		// Reach leftmost node
		Node<T>* ptr = Root;
		while (ptr->lthread == false)
			ptr = ptr->Left;

		// One by one print successors
		while (ptr != NULL)
		{
			cout<<ptr->Info<<endl;
			ptr = inorderSuccessor(ptr);
		}
	}
};