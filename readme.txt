<문제 2>

1) Purpose of this code.

2개의 linked list A,B를 선언하고 이 안의 data들은 정렬이 되어있다. 이게 이 두개를 합쳐 새로운 리스트 c를 만드는데 오름차순
순서대로 어떻게 만드는지에 대한 코드

2) Input and Output 

Input 으로는 정렬된 A,B 리스트 Output으로는 A,B의 element들이 정렬된 리스트 C 출력

3) variables I used

가장 중요하게 생각한 변수는 구조체 변수들이다. 노드를 표현한 구조체에는 data와 다음 node를 가리킬 포인터 link를 포함했다.
또한 리스트 전체를 담을 구조체도 선언했는데 head,cur,tail,newNode를 선언하여 용이하게 코딩이 될 수 있도록 하였다.

<문제 3>

1) Purpose of this code.
linked list의 모든 adt를 직접 표현한다. 단 tail도 포함하는 list를 활용해 adt를 구성하였다.

2)Input and Output
Input으로는 각각 함수에 따른 삽입, 삭제함수를 호출하였고 output으로는 그에 따른 결과를 출력했다.

3) variables I used
ListType에 tail을 가장 중요하게 생각하였다. 리스트 안에서 노드들의 변화가 있을때 head 뿐만 아니라 그에 따라서 tail도 
변할 수 있도록 신경써서 코딩하였다.