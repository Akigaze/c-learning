//
// Created by Akigaze on 11/8/2020.
//
#include<stdio.h>
#include <stdlib.h>

// 链表节点的组成
typedef struct student {
    int id;
    char name[20];
    struct student *next;
} Student;

Student *createStudent() {
    Student *stu;
    stu = (Student *) malloc(sizeof(Student));
    printf("please input the id and name of the next student:");
    scanf("%d %s", &stu->id, stu->name);
    return stu;
}

void link(Student **head, Student *current) {
    if (*head == NULL) {
        *head = current;
        current->next = NULL;
    } else {
        // 声明指针变量时，变量名前的 * 只是表示这是一个指针变量
        Student *pre = *head;
        while (pre->next != NULL) {
            pre = pre->next;
        }
        pre->next = current;
        current->next = NULL;
    }
}

Student *createLinkList() {
    Student *head = NULL, *current = NULL;
    int numOfStudent;
    printf("input number of student:");
    scanf("%d", &numOfStudent);

    for (int i = 0; i < numOfStudent; ++i) {
        current = (Student *) malloc(sizeof(Student));
        printf("please input the id and name of the next student:");
        scanf("%d %s", &current->id, current->name);
        link(&head, current);
        printf("id: %d, name: %s \n", head->id, head->name);
    }
    return head;
}

void printLink(Student *linkHead) {
    Student *current = linkHead;
    while (current != NULL) {
        printf("id: %d, name: %s \n", current->id, current->name);
        current = current->next;
    }
}

void releaseLink(Student **head) {
    Student *current = *head;
    while (current != NULL) {
        *head = (current)->next;
        free(current);
        current = *head;
    }
    current = NULL;
}

Student *findNode(Student *studentLink) {
    Student *current = studentLink;
    int id;
    printf("please input the student id your want to find:");
    scanf("%d", &id);
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void removeNode(Student **head) {
    while (1) {
        int id;
        printf("please input the id you want to remove(0 to exit):");
        scanf("%d", &id);
        if (id <= 0) {
            return;
        }
        if (*head == NULL) {
            printf("link is empty, nothing to remove \n");
            return;
        }
        Student *current = *head, *pre = *head;
        while (current != NULL && current->id != id) {
            pre = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("could not find id = %d to remove \n", id);
        } else {
            if (current == *head) {
                *head = current->next;
            } else {
                pre->next = current->next;
            }
            printf("remove: id [%d] name [%s] \n", current->id, current->name);
            free(current);
        }
        current = NULL;
        pre = NULL;
        printLink(*head);
    }
}

void insertNode(Student **head) {
    while (1) {
        Student *newman = createStudent();
        if (newman->id == 0) {
            free(newman);
            break;
        }
        if (*head == NULL) {
            *head = newman;
            newman->next = NULL;
        } else {
            Student *cur = *head, *pre = NULL;
            // 找到第一个比newmen大的元素
            while (cur != NULL && cur->id < newman->id) {
                pre = cur;
                cur = cur->next;
            }
            if (cur == NULL) {
                pre->next = newman;
                newman->next = NULL;
            } else if (pre == NULL) {
                *head = newman;
                newman->next = cur;
            } else {
                pre->next = newman;
                newman->next = cur;
            }
            cur = NULL;
            pre = NULL;
        }
        printLink(*head);
    }
}

void bubbleSort(Student *studentLink) {
    if (studentLink == NULL) {
        printf("link is empty, no need to sort \n");
        return;
    }
    if (studentLink->next == NULL) {
        printf("the link only one node, no need to sort \n");
        return;
    }
    Student temp, *cur, *pre = studentLink;
    while (pre->next != NULL) {
        cur = pre->next;
        while (cur != NULL) {
            if (cur->id < pre->id) {
                temp = *cur;
                // 使用指针对结构体变量进行赋值，只时修改结构体中属性的值，并不会改变指针指向的地址
                *cur = *pre;
                *pre = temp;

                //由于指针记录的是地址，所有交换完属性之后，还需要交换保存下一个节点的指针
                temp.next = cur->next;
                cur->next = pre->next;
                pre->next = temp.next;
            }
            cur = cur->next;
        }
        pre = pre->next;
    }
}

void reverse(Student **head) {
    if (*head == NULL) {
        printf("link is empty, can not reverse \n");
        return;
    }
    if ((*head)->next == NULL) {
        printf("the link only one node, can not reverse \n");
        return;
    }
    Student *cur, *pre, *r;
    pre = *head;
    cur = pre->next;
    while (cur != NULL) {
        r = cur->next;
        cur->next = pre;
        pre = cur;
        cur = r;
    }
    (*head)->next = NULL;
    *head = pre;
}

int main(int args, char *argv[]) {
    printf("------------------ 1. create a link list ------------------- \n");
    Student *studentLink = createLinkList();
    printf("------------------ 2. iterate a link list ------------------- \n");
    printLink(studentLink);
    printf("------------------ 1.1. bubble sort a link list ------------------- \n");
    bubbleSort(studentLink);
    printLink(studentLink);
    printf("------------------ 2.1. reverse a link list ------------------- \n");
    reverse(&studentLink);
    printLink(studentLink);
    printf("------------------ 3. search a link list ------------------- \n");
    Student *stu = findNode(studentLink);
    stu == NULL
    ? printf("not found \n")
    : printf("find student: id [%d], name [%s] \n", stu->id, stu->name);
    printf("------------------ 4. remove node ------------------- \n");
    removeNode(&studentLink);
    printf("------------------ 5. insert node ------------------- \n");
    insertNode(&studentLink);
    printf("------------------ n. release a link list ------------------- \n");
    releaseLink(&studentLink);
}
