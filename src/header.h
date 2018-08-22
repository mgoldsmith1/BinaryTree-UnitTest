#ifndef HEADER_H
#define HEADER_H

#define SIZE 50
#include<unordered_map>

using  namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

// tree creation
// A queue node
struct Queue
{
    int front, rear;
    int size;
    struct Node **array;
};

int largestUinquePathUtil(Node* node, unordered_map<int, int> m);
int largestUinquePath(Node *node);
struct Node *newNode(int data);
struct Queue *createQueue(int size);
int isEmpty(struct Queue *queue);
int isFull(struct Queue *queue);
int hasOnlyOneItem(struct Queue *queue);
void Enqueue(struct Node *root, struct Queue *queue);
struct Node *Dequeue(struct Queue *queue);
struct Node *getFront(struct Queue *queue);
int hasBothChild(struct Node *temp);
void insert(struct Node **root, int data, struct Queue *queue);
void levelOrder(struct Node *root);

int solution();//int solution(int N);

#endif 
