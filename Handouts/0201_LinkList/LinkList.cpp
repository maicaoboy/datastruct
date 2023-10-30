//
// Created by maicaoboy on 2023/10/29.
//
#include "stdlib.h"
#include "stdio.h"

typedef struct LinkNode {
    int data;
    LinkNode * next;
} LinkNode, *LinkList;



//使用头插法构建带头节点的的单链表
/**
 * 获取一个LinkNode
 * @param data 节点数据
 * @return
 */
LinkNode* getLinkNode(int data) {
    LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * 打印带头结点的链表
 * @param L 要打印的链表
 */
void printLinkList(LinkList L) {
    LinkNode *ptr = L->next;
    while(ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/**
 * 打印带头结点的链表
 * @param L 要打印的链表
 */
void printLinkListWithoutHead(LinkList L) {
    LinkNode *ptr = L->next;
    while(ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeLinkList(LinkList &L) {
    LinkNode *ptr = L;
    while(ptr) {
        free(ptr);
        ptr = ptr->next;
    }
    L = NULL;
}


/**
 * 例题1: 使用头插法构建带头节点的单链表
 * @param L         头节点指针
 * @param array     数据
 * @param length    数据个数
 */
void create_HeadInsert(LinkList &L, int array[], int length) {
    L = (LinkNode*) malloc(sizeof(LinkNode));
    L->next = NULL;
    L->data = -1;

    for(int i = 0; i < length; i++) {
        LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
        node->data = array[i];
        node->next = L->next;
        L->next = node;
    }
}

/**
 * 例题2: 使用尾插法构建带头节点的单链表
 * @param L         头节点指针
 * @param array     数据
 * @param length    数据个数
 */
void create_TailInsert(LinkList &L, int array[], int length) {
    L = (LinkNode*) malloc(sizeof(LinkNode));
    L->next = NULL;
    L->data = -1;

    LinkNode *pTail = L;

    for(int i = 0; i < length; i++) {
        LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
        node->data = array[i];
        node->next = NULL;
        pTail->next = node;
        pTail = node;
    }
}


/**
 * 已知L为带头节点的单链表,,请按照递归的思想完成下列运算:
 * (1) 求链表中的最大整数
 * @param L     待求链表
 * @return      最大值
 */
int MaxOne(LinkNode* L) {
    if(L->next == NULL) {
        return L->data;
    }else {
        int max = MaxOne(L->next);
        return L->data >= max ? L->data : max;
    }
}



/**
 * 已知L为带头节点的单链表,,请按照递归的思想完成下列运算:
 * (2) 求链表中的最大整数
 * @param L     待求链表
 * @return      链表个数
 */
int countLinkList(LinkNode *L) {
    if(L == NULL) {
        return 0;
    }else {
        return 1 + countLinkList(L->next);
    }
}


/**
 * 已知L为带头节点的单链表,,请按照递归的思想完成下列运算:
 * (3) 求链表的平均值
 * @param L     待求链表
 * @param n     链表总个数
 * @return      链表平均值
 */
double averageLinkList(LinkNode *L, int n) {
    if(L == NULL) {
        return (double)0;
    }else {
        return (double)L->data / n + averageLinkList(L->next, n);
    }
}


/**
 * 单链表访问第 ith 个数据节点
 * @param L         待访问链表
 * @param ith       第 ith 个节点
 * @param e         存储访问节点
 */
void accessIth(LinkList L, int ith, int &e) {
    int i = 0;
    LinkNode *ptr = L;

    while(i < ith && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }

    e = ptr->data;
}


/**
 * 例题5: 在第 ith 个数据节点前插入元素 e
 * @param L         待插入链表
 * @param ith       待插入位置
 * @param e         待插入元素
 */
void insertBeforeIth(LinkList L, int ith, int e) {
    if(ith < 1) {
        return;
    }

    LinkNode *ptr = L;
    int i = 0;

    while(i < ith - 1 && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }

    LinkNode *node = getLinkNode(e);
    node->next = ptr->next;
    ptr->next = node;
}


/**
 * 例题6
 * 设计高效算法查找带头节点单链表导数第 m 个位置的节点并输出该结点值
 * @param L         待查找链表
 * @param m         倒数第 m 个
 * @param node      保存查找到的结点
 */
void searchLastMth(LinkList L, int m, LinkNode *&node) {
    LinkNode *fast = L->next;
    LinkNode *slow = L->next;
    int i = 0;

    while(fast != NULL && i < m) {
        fast = fast->next;
        i++;
    }

    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    node = slow;
}



/**
 * 查找 ith 个结点的前驱节点(辅助函数)
 * @param node      带头节点的单链表
 * @param ith       ith
 * @return          返回查找到的结点
 */
LinkNode *preOfIth(LinkList L, int ith) {
    LinkNode *ptr = L;

    for(int i = 0; i < ith - 1 && ptr != NULL ; i++) {
        ptr = ptr->next;
    }

    return ptr;
}


/**
 *例题7
 * 已知指针La Lb分别指向两个无头结点的单链表,编写函数完成从La中删除第j个结点开始的len个结点,并将这些节点插入到L2的第j个元素前
 * !!!当j为1时需要对头节点进行特殊操作,所以操作前先加空头结点
 * @param L1    链表
 * @param L2    链表
 * @param j     删除起始位置
 * @param len   删除长度
 */
void deleteAndMerge(LinkList &L1, LinkList &L2, int j, int len){
    LinkNode *head1 = (LinkNode*) malloc(sizeof(LinkNode));
    LinkNode *head2 = (LinkNode*) malloc(sizeof(LinkNode));
    head1->next = L1;
    head2->next = L2;

    LinkNode *nodeL1 = preOfIth(head1, j);
    LinkNode *nodeL1Len = preOfIth(head1, j + len);
    LinkNode *nodeL2 = preOfIth(head2, j);

    LinkNode *cutDown =  nodeL1->next;
    nodeL1->next = nodeL1Len->next;
    nodeL1Len->next = nodeL2->next;
    nodeL2->next = cutDown;

    L1 = head1->next;
    L2 = head2->next;
}



/**
 * 例题9:从非递减有序的单链表中删除值相同的多余元素
 * 假设带头结点
 * @param L
 */
void removeRepeat(LinkList L) {
    LinkNode *pre = L->next;
    LinkNode *cur = pre->next;

    while(cur) {
        if(pre->data == cur->data) {
            LinkNode *node = cur;
            pre->next = cur->next;
            cur = cur->next;
            free(node);
        }else {
            pre = cur;
            cur = cur->next;
        }
    }
}

/**
 * 例题10:设有一个非递减的正整数单链表(有重复数),设计算法确定比x小的结点数量
 * @param L
 * @param x
 * @return          比x小的数个数
 */
int countLessThanX(LinkList L, int x) {
    LinkNode *pre = L->next;
    LinkNode *cur = pre->next;
    int cnt = 0;

    while(cur) {
        if(pre->data < x) {
            if(pre->data != cur->data) {
                cnt++;
            }
            pre = cur;
            cur = cur->next;
        }else {
            break;
        }
    }
    return cnt;
}



/**
 * 例题11: 删除非递减单链表La中La与Lb相同的元素
 * @param La
 * @param Lb
 */
void removeRepeatInBoth(LinkList La, LinkList Lb) {
    LinkNode *pa = La->next;
    LinkNode *pre = La;
    LinkNode *pb = Lb->next;

    while(pa && pb) {
        if(pa->data < pb->data) {
            pre = pa;
            pa = pa->next;
        }else if(pa->data > pb->data) {
            pb = pb->next;
        }else {
            pre->next = pa->next;
            free(pa);
            pa = pre->next;
        }
    }
}




void repeat(LinkList &L, LinkList La, LinkList Lb) {
    LinkNode *ptrA = La->next;
    LinkNode *ptrB = Lb->next;
    L = (LinkNode*)(malloc(sizeof(LinkNode)));
    L->next = NULL;
    L->data = -1;
    LinkNode *tail = L;


    while(ptrA && ptrB) {
        if(ptrA->data < ptrB->data) {
            ptrA = ptrA->next;
        }else if(ptrA->data > ptrB->data) {
            ptrB = ptrB->next;
        }else {
            LinkNode *node = getLinkNode(ptrA->data);
            tail->next = node;
            tail = node;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
    }
}


/**
 * 例题12 我的版本 (空间复杂度高)
 * 已知La,Lb,Lc是三个链表,且它们已经初始化,其元素按递增顺序排序,每个表中均无重复元素,设计算表在表Lc中删除同时出现在La和Lb中的所有元素
 * @param La
 * @param Lb
 * @param Lc
 */
void removeRepeatInLaLb(LinkList La, LinkList Lb, LinkList Lc) {
    LinkList L;
    repeat(L, La, Lb);
    LinkNode *pre = Lc;
    LinkNode *cur = Lc->next;
    LinkNode *same = L->next;



    while(same && cur) {
        if(cur->data < same->data) {
            pre = cur;
            cur = cur->next;
        }else if(cur->data > same->data) {
            same = same->next;
        }else {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
    }

    freeLinkList(L);
}



void deleteBetween(LinkNode *&pre, LinkNode *&cur, int e) {
    while(cur != NULL && cur -> data < e) {
        pre = cur;
        cur = cur->next;
    }
    if(cur->data == e) {
        pre = cur->next;
        free(cur);
        cur = pre->next;
    }
}

/**
 * 例题12 高效版本
 * 已知La,Lb,Lc是三个链表,且它们已经初始化,其元素按递增顺序排序,每个表中均无重复元素,设计算表在表Lc中删除同时出现在La和Lb中的所有元素
 * !!!每次找出相同元素即从上次删除位置开始继续删除
 * @param La
 * @param Lb
 * @param Lc
 */
void removeRepeatInLaLb_Good(LinkList La, LinkList Lb, LinkList Lc) {
    LinkNode *pa = La->next;
    LinkNode *pb = Lb->next;
    LinkNode *pre = Lc;
    LinkNode *cur = Lc->next;

    while(pa && pb && cur) {
        if(pa->data < pb->data) {
            pa = pa->next;
        }else if(pa->data > pb->data){
            pb = pb->next;
        }else {
            deleteBetween(pre, cur, pa->data);
        }
    }
}


void tailInsert(LinkNode *&tail, LinkNode *node) {
    if(tail->data == node->data) {
        free(node);
    }else {
        tail->next = node;
        tail = node;
        tail->next = NULL;
    }
}


/**
 * La和Lb按值非递减,归并La和Lb,得到新的链表Lc,是的Lc也按值非递减且不含重复元素
 * !!!合并后要处理末尾元素
 * @param L         合并后的新表
 * @param La
 * @param Lb
 */
void merge(LinkList &L, LinkList La, LinkList Lb) {
    LinkNode *ptrA = La->next;
    LinkNode *ptrB = Lb->next;
    L = (LinkNode*)(malloc(sizeof(LinkNode)));
    L->next = NULL;
    L->data = -1;
    LinkNode *tail = L;


    while(ptrA && ptrB) {
        if(ptrA->data < ptrB->data) {
            LinkNode *node = ptrA;
            ptrA = ptrA->next;
            tailInsert(tail, node);
        }else{//在插入函数进行去重操作和重复结点释放
            LinkNode *node = ptrB;
            ptrB = ptrB->next;
            tailInsert(tail, node);
        }
    }

    while(ptrA) {
        LinkNode *node = ptrA;
        ptrA = ptrA->next;
        tailInsert(tail, node);
    }

    while(ptrB) {
        LinkNode *node = ptrB;
        ptrB = ptrB->next;
        tailInsert(tail, node);
    }
}



/**
 * 带头节点单链表中所有元素的数据按递增序列排序,删除链表中大于min且小于max的元素
 * @param L
 * @param min
 * @param max
 */
void deleteBetweenMinMax(LinkList L, int min, int max) {
    LinkNode *pre = L;
    LinkNode *cur = L->next;

    while(cur) {
        if(cur->data > min && cur->data < max) {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }else {
            pre = cur;
            cur = cur->next;
        }
    }

}

























































