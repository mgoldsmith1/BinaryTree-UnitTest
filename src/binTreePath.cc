#include "header.h"
#include "gtest/gtest.h"

// C++ program to find count of distinct nodes
// on a path with maximum distinct nodes.
#include "stdc++.h"
 
int largestUinquePathUtil(Node* node, unordered_map<int, int> m)
{
    if (!node)
        return m.size();
 
    // put this node into hash
    m[node->data]++;
 
    int max_path = max(largestUinquePathUtil(node->left, m),
                       largestUinquePathUtil(node->right, m));
 
    // remove current node from path "hash"
    m[node->data]--;
 
    // if we reached a condition where all duplicate value
    // of current node is deleted
    if (m[node->data] == 0)
        m.erase(node->data);
 
    return max_path;
}
 
// A utility function to find long unique value path
int largestUinquePath(Node *node)
{
    if (!node)
        return 0;
 
    // hash that store all node value
    unordered_map<int, int> hash;
 
    // return max length unique value path
    return largestUinquePathUtil(node, hash);
}
 
// A utility function to create a new tree node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node*) malloc(sizeof( struct Node ));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to create a new Queue
struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue*) malloc(sizeof( struct Queue ));
 
    queue->front = queue->rear = -1;
    queue->size = size;
 
    queue->array = (struct Node**) malloc(queue->size * sizeof( struct Node* ));
 
    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;
 
    return queue;
}
 
// Standard Queue Functions
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}
 
int isFull(struct Queue *queue)
{  return queue->rear == queue->size - 1; }
 
int hasOnlyOneItem(struct Queue *queue)
{  return queue->front == queue->rear;  }
 
void Enqueue(struct Node *root, struct Queue *queue)
{
    if (isFull(queue))
        return;
 
    queue->array[++queue->rear] = root;
 
    if (isEmpty(queue))
        ++queue->front;
}
 
struct Node *Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return NULL;
 
    struct Node *temp = queue->array[queue->front];
 
    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;
 
    return temp;
}
 
struct Node *getFront(struct Queue *queue)
{  return queue->array[queue->front]; }
 
// A utility function to check if a tree node has both left and right children
int hasBothChild(struct Node *temp)
{
    return temp && temp->left && temp->right;
}
 
// Function to insert a new node in complete binary tree
void insert(struct Node **root, int data, struct Queue *queue)
{
    // Create a new node for given data
    struct Node *temp = newNode(data);
 
    // If the tree is empty, initialize the root with new node.
    if (!*root)
        *root = temp;
 
    else
    {
        // get the front node of the queue.
        struct Node *front = getFront(queue);
 
        // If the left child of this front node doesn’t exist, set the
        // left child as the new node
        if (!front->left)
            front->left = temp;
 
        // If the right child of this front node doesn’t exist, set the
        // right child as the new node
        else if (!front->right)
            front->right = temp;
 
        // If the front node has both the left child and right child,
        // Dequeue() it.
        if (hasBothChild(front))
            Dequeue(queue);
    }
 
    // Enqueue() the new node for later insertions
    Enqueue(temp, queue);
}
 
// Standard level order traversal to test above function
void levelOrder(struct Node *root)
{
    struct Queue *queue = createQueue(SIZE);
 
    Enqueue(root, queue);
 
    while (!isEmpty(queue))
    {
        struct Node *temp = Dequeue(queue);
 
        printf("%d ", temp->data);
 
        if (temp->left)
            Enqueue(temp->left, queue);
 
        if (temp->right)
            Enqueue(temp->right, queue);
    }
}

int solution(){

    struct Node *root = NULL;
    struct Queue *queue = createQueue(SIZE);
    int i;

    cout << endl;
    cout << "Given an input: ";

    //2^l where l = level thus 2^level0= 1, 2^level1 = 2, ..., 2^leveln
    for(i = 1; i <= 12; ++i)  
        insert(&root, i, queue);
    
    levelOrder(root);
    
    cout << endl;
    cout << endl;
    int max = largestUinquePath(root);
    cout << "Max Distinct Path from Root to Leaf is: " << max << endl;
    return max;

}

int solution2(){

    struct Node *root = NULL;
    struct Queue *queue = createQueue(SIZE);
    int i;

    cout << endl;
    cout << "Given an input: ";

    const int MAX = 7;
    int foo [MAX] = { 4, 5, 6, 4, 1, 6, 5 };
    
    //2^l where l = level thus 2^level0= 1, 2^level1 = 2, ..., 2^leveln
    for(i = 1; i <= MAX; ++i)  
        insert(&root, foo[i], queue);
    
    levelOrder(root);
    
    cout << endl;
    cout << endl;
    int max = largestUinquePath(root);
    cout << "Max Distinct Path from Root to Leaf is: " << max << endl;
    return max;

}

GTEST_API_ int main(int argc, char *argv[]){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
