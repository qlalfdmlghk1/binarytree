#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

typedef struct threadedTree threadedPointer;

typedef struct threadedTree {
    short int leftThread;
    threadedPointer* leftChild;
    char data;
    threadedPointer* rightChild;
    short int rightThread;
} threadedPointer;

threadedPointer* insucc(threadedPointer* tree) {
    threadedPointer* temp = tree->rightChild;
    if (!tree->rightThread) {
        while (!temp->leftThread) {
            temp = temp->leftChild;
        }
    }
    if (temp == NULL) { // temp�� null pointer�� ���
        return tree; // tree�� ��ȯ
    }
    else {
        return temp;
    }
}

void tinorder(threadedPointer* tree) { // tree ����� �ļӳ��temp�ǰ�����ϱ�
    threadedPointer* temp = tree;
    for (; ;) {
        temp = insucc(temp); // �����ļ���ã��
        if (temp == tree) break;
        printf("%3c", temp->data) ; // ã�Ƴ������ļ��ڰ� ���
        if (temp->rightChild == NULL) break ;
        
    }
}

void insert_Right(threadedPointer *parent, threadedPointer *child) {// ������ ���� Ʈ������ child�� parent�� ������ �ڽ����� ����
	threadedPointer *temp;
	child->rightChild = parent->rightChild;
	child->rightThread = parent->rightThread;
	child->leftChild = parent;
	child->leftThread = 1;
	parent->rightChild = child;
	parent->rightThread = 0;
	if ( !child->rightThread ) { // parent�� �������ڽ��� �־��ٸ�
		temp = insucc(child); // child�� �ļ���ã��
		temp->leftChild = child; // �����ļ��ڰ�child�� ����Ŵ
	}
}

int main() {
    // ���� Ʈ�� ����
    threadedPointer* nodeA = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeB = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeC = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeD = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeE = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeF = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeG = (threadedPointer*)malloc(sizeof(threadedPointer));
	threadedPointer* child = (threadedPointer*)malloc(sizeof(threadedPointer));
	
	
    nodeA->data = '1';
    nodeB->data = '2';
    nodeC->data = '3';
    nodeD->data = '4';
    nodeE->data = '5';
    nodeF->data = '6';
    nodeG->data = '7';
	child->data = '8';


    nodeA->leftChild = nodeB;
    nodeA->rightChild = nodeC;
    nodeA->leftThread = 0;
    nodeA->rightThread = 0;

    nodeB->leftChild = nodeD;
    nodeB->rightChild = nodeE;
    nodeB->leftThread = 0;
    nodeB->rightThread = 0;

    nodeC->leftChild = nodeF;
    nodeC->rightChild = nodeG;
    nodeC->leftThread = 0;
    nodeC->rightThread = 0;

    nodeD->leftChild = NULL;
    nodeD->rightChild = nodeB;
    nodeD->leftThread = 1;
    nodeD->rightThread = 1;

    nodeE->leftChild = nodeB;
    nodeE->rightChild = nodeA;
    nodeE->leftThread = 1;
    nodeE->rightThread = 1;

    nodeF->leftChild = nodeA;
    nodeF->rightChild = nodeC;
    nodeF->leftThread = 1;
    nodeF->rightThread = 1;

    nodeG->leftChild = nodeC;
    nodeG->rightChild = NULL;
    nodeG->leftThread = 1;
    nodeG->rightThread = 1;
	
	insert_Right(nodeA, child); // nodeC�� ������ �ڽ����� child ����
	
    // ��ȸ ����
    threadedPointer* startNode = nodeD; // ���� ��� ����
    printf("%3c", startNode->data);
    tinorder(startNode); // ������ȸ �Լ� ȣ��
    return 0;

}


