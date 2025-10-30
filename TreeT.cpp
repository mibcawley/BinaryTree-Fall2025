template <class T>
TreeT<T>::TreeT()
{
    root = nullptr;
    numNodes = 0;
}

template <class T>
TreeT<T>::~TreeT()
{
}

template <class T>
TreeT<T>& TreeT<T>::operator=(const TreeT& otherTree)
{
}

template <class T>
void TreeT<T>::Add(T value)
{
    Node *newNode = new Node;
    newNode->value = value;\

    if (root == nullptr)
    {
        root = new Node;
        numNodes++;
        return;
    }

    Node *currN = root;
    Node *prevN = nullptr;
    while (currN != nullptr)
    {
        prevN = currN;
        if (value < currN->value)
        {
            currN = currN->left;
        }
        else if (value > currN->value)
         {
            currN = currN->right;
        }
        else
        {
            delete newNode;
            return;
        }
    }
    if (value < prevN->value)
    {
        prevN->left = newNode;
    }
    else
    {
        prevN->right = newNode;
    }
    numNodes++;
}

template <class T>
void TreeT<T>::Remove(T value)
{
    // Remove is a grabber function for RemoveHelper
    RemoveHelper(root, value);
}

template <class T>
void TreeT<T>::RemoveHelper(Node*& subtree, T value)
{
}

template <class T>
bool TreeT<T>::Contains(T value)
{
    Node *currN = root;
    while (currN != nullptr)
    {
        if (value < currN->value)
        {
            currN = currN->left;
        }
        else if (value > currN->value)
        {
            currN = currN->right;
        }
        else
        {
            return true; // Found it
        }
    }
    // Just finished the loop without finding the value
    // Must not exist
    return false;
}

template <class T>
int TreeT<T>::Size()
{
    return numNodes;
}

template <class T>
void TreeT<T>::ResetIterator(Order traverseOrder)
{
}

template <class T>
T TreeT<T>::GetNextItem()
{
}

template <class T>
void TreeT<T>::DestroyTree(Node* node)
{
}



template <class T>
void TreeT<T>::DeleteNode(Node*& subtree)
{
}

template <class T>
void TreeT<T>::GetPredecessor(Node* curr, T& value)
{
}

template <class T>
void TreeT<T>::CopyHelper(Node*& thisTree, Node* otherTree)
{
}

template <class T>
void TreeT<T>::PlacePreOrder(Node* node)
{
}

template <class T>
void TreeT<T>::PlacePostOrder(Node* node)
{
}

template <class T>
void TreeT<T>::PlaceInOrder(Node* node)
{
}
