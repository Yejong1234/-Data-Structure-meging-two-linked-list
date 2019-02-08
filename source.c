#include <stdio.h>
#include <stdlib.h>

typedef struct _node//node�� ������ ���� ����ü
{
	int data;
	struct _node * next;
} Node;

typedef int LData;

typedef struct _linkedList//Linkedlist�� ���� ����ü
{
	Node * head;
	Node * cur;
	Node * tail;
	Node * newNode;

} LinkedList;

typedef LinkedList List;

int main(void) {
	List a;//a ����Ʈ ����
	List b;//b ����Ʈ ����
	int readData;

	printf("a ����Ʈ�� �� �ڿ����� �Է��ϼ���\n");

	a.head = (Node*)malloc(sizeof(Node));//
	a.tail = a.head;

	while (1) {
		printf("�ڿ��� �Է�: ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		/*** ����� �߰����� ***/
		a.newNode = (Node*)malloc(sizeof(Node));//a.newNode�� ���ο� �޸� �����Ҵ� �ؼ� �ּڰ� ����
		a.newNode->data = readData;//a.newNode�� �ּڰ��� ����Ű�� ���� data�� �Է¹��� ������ �� ����
		a.newNode->next = NULL;//next���� ���� ������ null

		a.tail->next = a.newNode;//a.tail�� ����Ű�� next���� ���ο� ��� �ּڰ�, �� newNode ���� ���next�� newNode�� ����

		a.tail = a.newNode;//���� tail�ּҰ��� newNode�� �ּڰ��� ����Ŵ.
	}
	printf("\n");

	printf("b ����Ʈ�� �� �ڿ����� �Է��ϼ���\n");

	b.head = (Node*)malloc(sizeof(Node));//���̳�� �����ؼ� head �� �ּڰ�
	b.tail = b.head;

	while (1) {
		printf("�ڿ��� �Է�: ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		/*** ����� �߰����� ***/
		b.newNode = (Node*)malloc(sizeof(Node));//a.newNode�� ���ο� �޸� �����Ҵ� �ؼ� �ּڰ� ����
		b.newNode->data = readData;//a.newNode�� �ּڰ��� ����Ű�� ���� data�� �Է¹��� ������ �� ����
		b.newNode->next = NULL;//next���� ���� ������ null


		b.tail->next = b.newNode;//a.tail�� ����Ű�� next���� ���ο� ��� �ּڰ�, �� newNode ���� ���next�� newNode�� ����

		b.tail = b.newNode;//���� tail�ּҰ��� newNode�� �ּڰ��� ����Ŵ.
	}
	printf("\n");

	List c;

	c.head = (Node*)malloc(sizeof(Node));//���̳�� �����ؼ� head �� �ּڰ�
	c.tail = c.head;
	c.cur = c.head;
	a.cur = a.head->next;//a.cur�� ù��° ��� �ּ� ����
	b.cur = b.head->next;//b.cur�� ù��° ��� �ּ� ����

	while ((a.cur->next != NULL) || (b.cur->next != NULL)) {//�Ѵ� null�� �� �� ���� �� ����

		c.newNode = (Node*)malloc(sizeof(Node));
		c.cur->next = c.newNode;
		c.cur = c.newNode;

		if ((a.cur->data) <= (b.cur->data)) {

			c.cur->data = a.cur->data;/*c�� ù��° ��� �����Ϳ��ٰ� a�� �����Ͱ� ��� ����� �ּڰ��� ����. ���� ��� data 1�� ��� �����
								�ּҰ��� 100�� ��� c�� ù��° ��� �����Ϳ� 100�� ����*/
			a.cur = a.cur->next;//a.cur�� ���� ���� ��� �ּ� ������ �ٲ���.
		}

		else {
			c.cur->data = b.cur->data;
			b.cur = b.cur->next;
		}

	}
	/*�����ִ� �����͵� ����*/
	if ((a.cur->next == NULL) && (b.cur->next == NULL)) {
		if (a.cur->data < b.cur->data) {
			c.newNode = (Node*)malloc(sizeof(Node));
			c.cur->next = c.newNode;
			c.cur = c.newNode;
			c.cur->data = a.cur->data;

			c.newNode = (Node*)malloc(sizeof(Node));
			c.cur->next = c.newNode;
			c.cur = c.newNode;
			c.cur->data = b.cur->data;
		}
		else {
			c.newNode = (Node*)malloc(sizeof(Node));
			c.cur->next = c.newNode;
			c.cur = c.newNode;
			c.cur->data = b.cur->data;

			c.newNode = (Node*)malloc(sizeof(Node));
			c.cur->next = c.newNode;
			c.cur = c.newNode;
			c.cur->data = a.cur->data;
		}
	}
	/*c ����Ʈ ����ϱ�*/
	c.cur = c.head;
	int i = 0;
	while (c.cur->next != NULL) {
		printf("%d ", c.cur->next->data);
		c.cur = c.cur->next;

	}

	return 0;
}

