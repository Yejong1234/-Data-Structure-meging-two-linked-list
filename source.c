#include <stdio.h>
#include <stdlib.h>

typedef struct _node//node의 구조를 담은 구조체
{
	int data;
	struct _node * next;
} Node;

typedef int LData;

typedef struct _linkedList//Linkedlist를 담은 구조체
{
	Node * head;
	Node * cur;
	Node * tail;
	Node * newNode;

} LinkedList;

typedef LinkedList List;

int main(void) {
	List a;//a 리스트 선언
	List b;//b 리스트 선언
	int readData;

	printf("a 리스트에 들어갈 자연수를 입력하세요\n");

	a.head = (Node*)malloc(sizeof(Node));//
	a.tail = a.head;

	while (1) {
		printf("자연수 입력: ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		/*** 노드의 추가과정 ***/
		a.newNode = (Node*)malloc(sizeof(Node));//a.newNode에 새로운 메모리 동적할당 해서 주솟값 저장
		a.newNode->data = readData;//a.newNode의 주솟값이 가리키는 곳의 data에 입력받은 데이터 값 저장
		a.newNode->next = NULL;//next값은 아직 없으니 null

		a.tail->next = a.newNode;//a.tail이 가르키는 next값에 새로운 노드 주솟값, 즉 newNode 이전 노드next에 newNode값 저장

		a.tail = a.newNode;//이제 tail주소값은 newNode의 주솟값을 가르킴.
	}
	printf("\n");

	printf("b 리스트에 들어갈 자연수를 입력하세요\n");

	b.head = (Node*)malloc(sizeof(Node));//더미노드 선언해서 head 에 주솟값
	b.tail = b.head;

	while (1) {
		printf("자연수 입력: ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		/*** 노드의 추가과정 ***/
		b.newNode = (Node*)malloc(sizeof(Node));//a.newNode에 새로운 메모리 동적할당 해서 주솟값 저장
		b.newNode->data = readData;//a.newNode의 주솟값이 가리키는 곳의 data에 입력받은 데이터 값 저장
		b.newNode->next = NULL;//next값은 아직 없으니 null


		b.tail->next = b.newNode;//a.tail이 가르키는 next값에 새로운 노드 주솟값, 즉 newNode 이전 노드next에 newNode값 저장

		b.tail = b.newNode;//이제 tail주소값은 newNode의 주솟값을 가르킴.
	}
	printf("\n");

	List c;

	c.head = (Node*)malloc(sizeof(Node));//더미노드 선언해서 head 에 주솟값
	c.tail = c.head;
	c.cur = c.head;
	a.cur = a.head->next;//a.cur에 첫번째 노드 주소 저장
	b.cur = b.head->next;//b.cur에 첫번째 노드 주소 저장

	while ((a.cur->next != NULL) || (b.cur->next != NULL)) {//둘다 null이 될 때 까지 비교 실행

		c.newNode = (Node*)malloc(sizeof(Node));
		c.cur->next = c.newNode;
		c.cur = c.newNode;

		if ((a.cur->data) <= (b.cur->data)) {

			c.cur->data = a.cur->data;/*c의 첫번째 노드 데이터에다가 a의 데이터가 담긴 노드의 주솟값을 저장. 예를 들어 data 1이 담긴 노드의
								주소값이 100인 경우 c의 첫번째 노드 데이터에 100을 저장*/
			a.cur = a.cur->next;//a.cur의 값을 다음 노드 주소 값으로 바꿔줌.
		}

		else {
			c.cur->data = b.cur->data;
			b.cur = b.cur->next;
		}

	}
	/*남아있는 데이터들 정리*/
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
	/*c 리스트 출력하기*/
	c.cur = c.head;
	int i = 0;
	while (c.cur->next != NULL) {
		printf("%d ", c.cur->next->data);
		c.cur = c.cur->next;

	}

	return 0;
}

