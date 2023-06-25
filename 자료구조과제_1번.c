#include <stdlib.h>
#include <stdio.h>

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
    if (temp == NULL) { // temp가 null pointer인 경우
        return tree; // tree를 반환
    }
    else {
        return temp;
    }
}

void tinorder(threadedPointer* tree) { // tree 노드의 후속노드temp의값출력하기
    threadedPointer* temp = tree;
    for (; ;) {
        temp = insucc(temp); // 중위후속자찾기
        if (temp == tree) break;
        printf("%3c", temp->data) ; // 찾아낸중위후속자값 출력
        if (temp->rightChild == NULL) break ;
        
    }
}

int main() {
    // 샘플 트리 생성
    threadedPointer* nodeA = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeB = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeC = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeD = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeE = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeF = (threadedPointer*)malloc(sizeof(threadedPointer));
    threadedPointer* nodeG = (threadedPointer*)malloc(sizeof(threadedPointer));

    nodeA->data = '1';
    nodeB->data = '2';
    nodeC->data = '3';
    nodeD->data = '4';
    nodeE->data = '5';
    nodeF->data = '6';
    nodeG->data = '7';

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

    // 순회 시작
    threadedPointer* startNode = nodeD; // 시작 노드 설정
    printf("%3c", startNode->data);
    tinorder(startNode); // 중위순회 함수 호출
    return 0;

}


