template <class T>
TreeT<T>::TreeT()
{
    root = nullptr;
    numNodes = 0;
}

template <class T>
TreeT<T>::TreeT(const TreeT& otherTree)
{
    numNodes = otherTree.numNodes;
    CopyHelper(root, otherTree.root);
}

template <class T>
TreeT<T>& TreeT<T>::operator=(const TreeT& otherTree)
{
    // Check to make sure we are not setting treeA = TreeA
    if (this != &otherTree)
    {
    // if (root == otherTree.root)
    // {
        //Get rid of old tree before copying over otherTree
        DestroyTree(root);
        numNodes = otherTree.numNodes;
        CopyHelper(root, otherTree.root);
    }
}

template <class T>
void TreeT<T>::CopyHelper(Node*& thisTree, Node* otherTree)
{
    if (otherTree == nullptr)
    {
        thisTree = nullptr;
        return;
    }
    thisTree = new Node;
    thisTree->value = otherTree->value;
    CopyHelper(thisTree->left, otherTree->left); // copy left subtree
    CopyHelper(thisTree->right, otherTree->right); // copy right subtree
}

template <class T>
TreeT<T>::~TreeT()
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
    root =RemoveHelper(root, value);
}

template <class T>
// Node* TreeT<T>::RemoveHelper(Node*& subtree, T value)
void TreeT<T>::RemoveHelper(Node*& subtree, T value){

// {
//     // Base Case
//     if (subtree == nullptr)
//     {
//         return subtree;
//     }
//     if (value < subtree->value)
//     {
//         subtree  = RemoveHelper(subtree->left, value);
//     }
//     else if (value > subtree->value)
//     {
//         subtree = RemoveHelper(subtree->right, value);
//     }
//     else
//     {
//         if (subtree->left == nullptr && subtree->right == nullptr)
//         {
//             delete subtree;
//         }
//         else if (subtree->left != nullptr)
//         {
//             Node* tmp = subtree->right;
//             delete subtree;
//             return tmp;
//         }
//         else if (subtree->right != nullptr)
//         {
//             Node* tmp = subtree->left;
//             delete subtree;
//             return tmp;
//         }
//         else
//         {
//             T data;
//             GetPredecessor(subtree->left, data);
//             subtree->value = data;
//             subtree->right = RemoveHelper(subtree->left, data);
//         }
//     }
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
    if (traverseOrder == IN_ORDER)
    {
        PlaceInOrder(root);

    }
}

template <class T>
T TreeT<T>::GetNextItem()
{
    T nextItem = iterQue.front(); // front value of queue
    iterQue.pop();
    return nextItem;
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
    if (node == nullptr)
    {
        return;
    }
    PlaceInOrder(node->left); // Put the left subtree in queue
    iterQue.push(node->value); // Put the value in the queue
    PlaceInOrder(node->right); // Put the right subtree in the queue

}
