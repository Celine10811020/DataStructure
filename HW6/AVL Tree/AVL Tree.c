#include <stdio.h>

int insertNode(int root, int key);
int rotateLeft(int node);
int rotateRight(int node);
int getBalance(int node);
int getHeight(int node);
int max(int one, int two);

int nodes[100000][3];  //0: key, 1:leftChild, 2:rightChild
int queue[100000];

int main()
{
    int i, temp;
    int root, node;
    int head, tail;

    root = -1;
    node = 0;

    while(scanf("%d", &temp) != EOF)
    {
        root = insertNode(root, temp);
        node++;
    }

    queue[0] = root;
    head = 0;
    tail = 1;

    while(1)
    {
        if(tail >= node)
        {
            break;
        }

        temp = queue[head];

        if(nodes[temp][1] != -1)
        {
            queue[tail] = nodes[temp][1];

            tail++;
        }

        if(nodes[temp][2] != -1)
        {
            queue[tail] = nodes[temp][2];

            tail++;
        }

        head++;
    }

    temp = queue[0];
    printf("%d", nodes[temp][0]);

    for(i=1; i<node; i++)
    {
        temp = queue[i];

        printf(" %d", nodes[temp][0]);
    }
    printf("\n");

    return 0;
}

int insertNode(int root, int key)
{
    int temp;
    int newNode;
    int balance;

    if(root == -1)
    {
        newNode = 0;

        while(nodes[newNode][0] != 0)
        {
            newNode++;
        }

        nodes[newNode][0] = key;
        nodes[newNode][1] = -1;
        nodes[newNode][2] = -1;

        return newNode;
    }

    if(key < nodes[root][0])
    {
        nodes[root][1] = insertNode(nodes[root][1], key);
    }else if(key > nodes[root][0])
    {
        nodes[root][2] = insertNode(nodes[root][2], key);
    }else
    {
        return root;
    }

    balance = getBalance(root);

    //leftSubtree unbalance
    if(balance > 1)
    {
        temp = nodes[root][1];

        if(key < nodes[temp][0])
        {
            root = rotateRight(root);
        }else
        {
            nodes[root][1] = rotateLeft(nodes[root][1]);
            root = rotateRight(root);
        }
    }

    //rightSubtree unbalance
    if(balance < -1)
    {
        temp = nodes[root][2];

        if(key > nodes[temp][0])
        {
            root = rotateLeft(root);
        }else
        {
            nodes[root][2] = rotateRight(nodes[root][2]);
            root = rotateLeft(root);
        }
    }

    return root;
}

int rotateLeft(int node)
{
    int rightChild;

    rightChild = nodes[node][2];
    nodes[node][2] = nodes[rightChild][1];
    nodes[rightChild][1] = node;

    return rightChild;
}

int rotateRight(int node)
{
    int leftChild;

    leftChild = nodes[node][1];
    nodes[node][1] = nodes[leftChild][2];
    nodes[leftChild][2] = node;

    return leftChild;
}

int getBalance(int node)
{
    int balance;

    if(node == -1)
    {
        return 0;
    }

    balance = getHeight(nodes[node][1]) - getHeight(nodes[node][2]);

    return balance;
}

int getHeight(int node)
{
    int leftChild, rightChild;
    int leftHeight, rightHeight, maxHeight;

    if(node == -1)
    {
        return -1;
    }

    leftChild = nodes[node][1];
    rightChild = nodes[node][2];

    leftHeight = getHeight(leftChild);
    rightHeight = getHeight(rightChild);

    maxHeight = max(leftHeight, rightHeight);

    return maxHeight + 1;
}

int max(int one, int two)
{
    if(one > two)
    {
        return one;
    }else
    {
        return two;
    }
}
