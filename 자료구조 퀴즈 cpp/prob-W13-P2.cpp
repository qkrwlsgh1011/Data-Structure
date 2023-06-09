#include<iostream>
#include<string>

using namespace std;

#define MappingSize 501

class vertex
{
public:
    vertex* prev;            //vertex를 doublylinkedlist로 구현
    vertex* next;            //이전 vertex와 다음 vertex를 가리키는 포인터
    int degree;               //연결된 edge의 개수 degree
    int data;               //vertex의 고유 값
    vertex(int data)
    {
        this->degree = 0;
        this->data = data;
    }
    void increase_degree()
    {
        this->degree++;
    }
    void decrease_degree()
    {
        this->degree--;
    }
};

class edge {
public:
    edge* prev;                        //edge를 doublylinkedlist로 구현
    edge* next;                        //이전 edge와 다음 edge를 가리키는 포인터
    vertex* source;                     //edge의 시작 vertex 포인터
    vertex* destination;               //edge의 도착 vertex 포인터
    string data;                     //edge의 고유 값
    edge(vertex* a, vertex* b, string data)
    {
        this->source = a;
        this->destination = b;
        this->data = data;
    }
};

class DoublyVertexLinkedList
{
public:
    vertex* head;
    vertex* tail;
    DoublyVertexLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void insert(vertex* insertVertex)      //vertex를 list의 마지막에 삽입
    {
        if (this->head == NULL)
        {
            head = insertVertex;
            tail = insertVertex;
        }
        else
        {
            tail->next = insertVertex;      //tail의 다음 위치에 삽입
            insertVertex->prev = tail;      //삽입된 vertex의 prev 값 할당
            tail = insertVertex;         //tail이동
        }
    }
    void remove(vertex* delVertex)                        //list에서 vertex삭제
    {
        if (delVertex == head || delVertex == tail)            //vertex가 head나 tail일 경우
        {
            if (delVertex == head && delVertex != tail)         //head라면
            {
                vertex* temp = head;                     //현재 head 저장
                head = head->next;                        //head 이동
                head->prev = NULL;                        //새로운 head와 이전 head 연결 끊기
                delete temp;                           //이전 head 삭제
            }
            else if (delVertex == tail && delVertex != head)   //tail이라면
            {
                vertex* temp = tail;                     //현재 tail 저장
                tail = tail->prev;                        //tail 이동
                tail->next = NULL;                        //새로운 tail과 이전 tail 연결 끊기
                delete temp;                           //이전 tail 삭제
            }
            else
            {
                head = tail = NULL;                        //list에 원소가 하나였다면
            }
        }
        else                                       //vertex가 head나 tail 이 아닐 경우
        {
            delVertex->prev->next = delVertex->next;         //삭제하려는 vertex의 이전 vertex와 
            delVertex->next->prev = delVertex->prev;         //다음 vertex 연결
            delete delVertex;                           //vertex 삭제
        }
    }
};

class DoublyEdgeLinkedList
{
public:
    edge* head;
    edge* tail;
    DoublyEdgeLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void insert(edge* insertEdge)
    {
        if (this->head == NULL)
        {
            head = insertEdge;
            tail = insertEdge;
        }
        else
        {
            tail->next = insertEdge;
            insertEdge->prev = tail;
            tail = insertEdge;
        }
    }
    void remove(edge* delEdge)
    {
        if (delEdge == head || delEdge == tail)
        {
            if (delEdge == head && delEdge != tail)
            {
                edge* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            else if (delEdge == tail && delEdge != head)
            {
                edge* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            delEdge->prev->next = delEdge->next;
            delEdge->next->prev = delEdge->prev;
            delete delEdge;
        }
    }
};

class graph
{
public:
    edge*** edgeMatrix;                              //Adjacency Matrix
    DoublyVertexLinkedList* VertexList;                  //vertex list
    DoublyEdgeLinkedList* EdgeList;                     //edge list         
    int vertexSize;                                 //vertex 갯수
    int mappingTable[MappingSize];                     //vertex의 입력 순서를 mapping
    int edgeSize;

    graph()
    {
        this->VertexList = new DoublyVertexLinkedList();
        this->EdgeList = new DoublyEdgeLinkedList();
        this->vertexSize = 0;
        this->edgeSize = 0;
        for (int i = 0; i < MappingSize; i++)            //mapping table 초기화
            mappingTable[i] = -1;
        this->edgeMatrix = new edge * *[1];               //edge의 주소를 저장하는 배열의 배열
        this->edgeMatrix[0] = new edge * [1];            //edge의 주소를 저장하는 배열
        this->edgeMatrix[0][0] = NULL;                  //edge의 주소 초기화
    }
    bool isfindVertex(int n)
    {
        bool flag = false;
        vertex* temp = VertexList->head;               //head부터 탐색
        while (temp != NULL)                        //tmp가 tail->next 일 때 까지
        {
            if (temp->data == n)                     //tmp->data가 n일때
            {
                flag = true;                        //탐색 종료
                break;
            }
            temp = temp->next;                        //tmp이동
        }
        return flag;
    }
    vertex* findVertex(int n)
    {
        vertex* temp = VertexList->head;
        while (temp != NULL)
        {
            if (temp->data == n)
            {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    void insert_vertex(int n)                           //vertex 삽입
    {
        if (isfindVertex(n) == true)                     //vertex가 이미 있다면
        {
            return;
        }

        else
        {
            edge*** tempMatrix = new edge * *[vertexSize + 1];  //새로운 행 생성
            for (int i = 0; i < vertexSize + 1; i++)
            {
                tempMatrix[i] = new edge * [vertexSize + 1];   //새로운 열 생성
                for (int j = 0; j < vertexSize + 1; j++)      //원소 초기화
                    tempMatrix[i][j] = NULL;
            }

            for (int i = 0; i < vertexSize; i++)            //행렬 copy
            {
                for (int j = 0; j < vertexSize; j++)
                    tempMatrix[i][j] = this->edgeMatrix[i][j];
            }

            this->edgeMatrix = tempMatrix;                  //행렬 바꾸기

            vertex* newVertex = new vertex(n);               //새로운 vertex 생성
            VertexList->insert(newVertex);                  //새로운 vertex 삽입
            this->vertexSize++;
            mappingTable[vertexSize - 1] = n;
        }
    }


    void erase_vertex(int n)
    {
        if (isfindVertex(n) == false || vertexSize == 0)            //삭제하려는 vertex가 없다면
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            edge*** tempMatrix = new edge * *[vertexSize - 1];         //새로운 행 생성
            for (int i = 0; i < vertexSize - 1; i++)
            {
                tempMatrix[i] = new edge * [vertexSize - 1];         //새로운 열 생성
                for (int j = 0; j < vertexSize - 1; j++)            //원소 초기화
                    tempMatrix[i][j] = NULL;
            }

            int middleIdx = 0;                                 //mapping table에서 vertex삭제
            for (int i = 0; i < vertexSize; i++)
            {
                if (mappingTable[i] == n)
                    middleIdx = i;
            }
            for (int i = middleIdx; i < vertexSize; i++)
                mappingTable[i] = mappingTable[i + 1];


            for (int i = 0; i < vertexSize; i++)                  //edgeList에서 edge삭제
            {
                if (this->edgeMatrix[middleIdx][i] != NULL)
                {
                    EdgeList->remove(this->edgeMatrix[middleIdx][i]);
                    this->edgeSize--;
                }
            }

            for (int i = 0; i < vertexSize; i++)                  //matrix에서 edge주소 삭제
            {
                for (int j = 0; j < vertexSize; j++)
                {
                    if (i < middleIdx && j < middleIdx)
                        tempMatrix[i][j] = this->edgeMatrix[i][j];

                    else if (i > middleIdx&& j > middleIdx)
                        tempMatrix[i - 1][j - 1] = this->edgeMatrix[i][j];

                    else if (j > middleIdx)
                        tempMatrix[i][j - 1] = this->edgeMatrix[i][j];

                    else if (i > middleIdx)
                        tempMatrix[i - 1][j] = this->edgeMatrix[i][j];
                }
            }
            this->edgeMatrix = tempMatrix;                        //행렬 바꾸기
            VertexList->remove(findVertex(n));                     //vertex 삭제
            this->vertexSize--;

            cout << this->edgeSize << " ";

            edge* tmp = EdgeList->head;
            while (tmp != NULL)
            {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    void insert_edge(int indirectSource, int IndirectDestination, string data)
    {
        if (isfindVertex(indirectSource) == false || isfindVertex(IndirectDestination) == false)         //출발과 도착 vertex가 없다면
        {
            cout << -1 << endl;
            return;
        }

        int destination = -1;
        int source = -1;
        for (int i = 0; i <= vertexSize; i++)                                                //mapping table에서 출발과 도착 vertex의 삽입 순서 탐색
        {
            if (mappingTable[i] == IndirectDestination)
                destination = i;
            if (mappingTable[i] == indirectSource)
                source = i;
            if (source != -1 && destination != -1)
                break;
        }

        if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL)            //삽입하려는 edge가 이미 있다면
        {
            cout << -1 << endl;
            return;
        }

        edge* newEdge = new edge(findVertex(indirectSource), findVertex(IndirectDestination), data);      //새로운 edge 생성
        edgeMatrix[source][destination] = newEdge;                                             //행렬에 edge의 주소값 할당
        edgeMatrix[destination][source] = newEdge;

        findVertex(indirectSource)->increase_degree();                                          //출발과 도착 vertex의 degree 증가
        findVertex(IndirectDestination)->increase_degree();

        EdgeList->insert(newEdge);                                                         //edgeList에 edge 삽입
        this->edgeSize++;
    }

    void erase_edge(int indirectSource, int IndirectDestination)
    {
        int destination = -1;
        int source = -1;
        for (int i = 0; i <= vertexSize; i++)                                                //mapping table에서 출발과 도착 vertex의 삽입 순서 탐색
        {
            if (mappingTable[i] == IndirectDestination)
                destination = i;
            if (mappingTable[i] == indirectSource)
                source = i;
            if (source != -1 && destination != -1)
                break;
        }

        if (edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL)            //삭제하려는 edge가 없다면
            return;
        findVertex(indirectSource)->decrease_degree();                                          //출발과 도착 vertex의 degree 감소
        findVertex(IndirectDestination)->decrease_degree();

        edge* delEdge = edgeMatrix[source][destination];                                       //edgeList에서 edge 삭제
        EdgeList->remove(delEdge);

        edgeMatrix[source][destination] = NULL;                                                //행렬에서 edge의 주솟값 삭제
        edgeMatrix[destination][source] = NULL;
        this->edgeSize--;
    }

    void isAdjacentTo(int indirectSource, int IndirectDestination)
    {
        if (isfindVertex(indirectSource) == false || isfindVertex(IndirectDestination) == false)         //탐색하려는 vertex가 없다면
        {
            cout << -1 << endl;
            return;
        }

        int destination = -1;
        int source = -1;
        for (int i = 0; i <= vertexSize; i++)                                                //mapping table에서 출발과 도착 vertex의 삽입 순서 탐색
        {
            if (mappingTable[i] == IndirectDestination)
                destination = i;
            if (mappingTable[i] == indirectSource)
                source = i;
            if (source != -1 && destination != -1)
                break;
        }

        if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
};

int main()
{
    graph* newGraph = new graph();

    int n, m, k;
    cin >> n >> m >> k;

    while (n--)
    {
        int i;
        cin >> i;
        newGraph->insert_vertex(i);
    }

    while (m--)
    {
        int s, d;
        string u;
        cin >> s >> d >> u;
        newGraph->insert_edge(s, d, u);
    }

    cout << newGraph->vertexSize << " " << newGraph->edgeSize << endl;

    while (k--)
    {
        int l;
        cin >> l;
        newGraph->erase_vertex(l);
    }


    return 0;
}