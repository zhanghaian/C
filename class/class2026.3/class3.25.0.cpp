#include <stdio.h>
#include <stdlib.h>

#define MAX_MAZE_SIZE 100 //迷宫尺寸最大
#define N 8
#define M 9

int maze[N + 2][M + 2];

int dx[] = {0, 1, 0, -1, 0};
int dy[] = {0, 0, 1, 0, -1};

typedef struct {
    int x, y;
    int di;
} Box;

typedef struct Node {
    Box data;
    struct Node *next;
} Node , *LinkStack;

//初始化
LinkStack InitStack() {
    LinkStack S = (LinkStack)malloc(sizeof(Node));
    if (!S) {
        printf("Error: Malloc failed for stack initialization.\n"); //报错
        exit(1);
    }
    S->next = NULL;
    return S;
}

//判断
int IsStackEmpty(LinkStack S) {
    return S->next == NULL;
}

//入栈
void Push(LinkStack S, Box e) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (!p) {
        printf("Error: Malloc failed for push operation.\n");
        exit(1);
    }
    p->data = e;
    p->next = S->next;
    S->next = p;
}

//出栈
Box Pop(LinkStack S) {
    if(IsStackEmpty(S)) {
        printf("Error: Stack is empty, cannot pop.\n");
        exit(1);
    }
    Node *p = S->next;
    Box e = p->data;
    S->next = p->next;
    free(p);
    return e;
}

//获取栈顶元素
Box GetTop(LinkStack S) {
    if (IsStackEmpty(S)) {
        printf("Error: Stack is empty, no top element.\n");
        exit(1);
    }
    return S->next->data;
}

void DestoryStack(LinkStack S) {
    while (!IsStackEmpty(S)) {
        Pop(S);
    }
    free(S);
}

typedef struct {
    int x, y;
    int pre;
} QNode;

QNode queue[MAX_MAZE_SIZE * MAX_MAZE_SIZE];
int front = 0, rear = 0;

void EnQueue(QNode e) {
    if (rear >= MAX_MAZE_SIZE * MAX_MAZE_SIZE) {
        printf("Error;=: Queue is full.\n");
        exit(1);
    }
    queue[rear++] = e;
}

QNode DeQueue() {
    if (front == rear) {
        printf("Error: Aueue is empty.\n");
        exit(1);
    }
    return queue[front++];
}

int IsQueueEmpty() {
    return front == rear;
}

void InitMaze() {
    int i, j;
    for (i = 0; i < N + 2; i++) {
        for (j = 0; j < M + 2; j++) {
            maze[i][j] = 1;
        }
    }

    int temp_maze[N + 2][M + 2] = {
        {1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,0,0,0,1,0,1,1},
        {1,0,0,1,0,0,0,1,0,1,1},
        {1,0,0,0,0,1,1,0,0,1,1},
        {1,0,1,1,1,0,0,0,0,1,1},
        {1,0,0,0,1,0,0,0,0,1,1},
        {1,0,1,0,0,0,1,0,0,1,1},
        {1,0,1,1,1,0,1,1,0,1,1},
        {1,1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1}
    };

    for (i = 0; i < N + 2; i++) {
        for (j = 0; j < M + 2; j++) {
            maze[i][j] = temp_maze[i][j];
        }
    }
}

void PrintMaze() {
    int i, j;
    for (i = 0; i < N + 2; i++) {
        for (j = 0; j < M + 2; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
}

void MazePath(int startX, int startY, int endX, int endY) {
    LinkStack S = InitStack();
    Box currentPos;
    int visited[N + 2][M + 2];
    int i, j;

    for (i = 0; i < N + 2; i++) {
        for (j = 0; j < M + 2; j++) {
            visited[i][j] = 0;
        }
    }

    currentPos.x = startX;
    currentPos.y = startY;
    currentPos.di = i;
    Push(S, currentPos);
    visited[startX][startY] = 1;

    printf("非递归路径：\n");

    while (!IsStackEmpty(S)) {
        currentPos = GetTop(S);
        int x = currentPos.x;
        int y = currentPos.y;
        int di = currentPos.di;

        if (x == endX && y == endY) {
            LinkStack tempS = InitStack();
            while(!IsStackEmpty(S)) {
                Push(tempS, Pop(S));
            }
            while (!IsStackEmpty(tempS)) {
                Box p = Pop(tempS);
                printf("(%d,%d,%d) ", p.x, p.y, p.di);
            }
            printf("\n");
            DestoryStack(tempS);
            DestoryStack(S);
            return;
        }

        while (di <= 4) {
            int nextX = x + dx[di];
            int nextY = y + dy[di];

            if (maze[nextX][nextY] == 0 && visited[nextX][nextY] == 0) {
                S->next->data.di = di;

                currentPos.x = next;
                currentPos.y = next;
                currentPos.di = 1;
                break;
            }
            di++;
        }

        if (di > 4) {
            Pop(S);
            if (!IsStackEmpty(S)) {
                S->next->data.di++;
            }
        }
    }

    printf("没有通路。\n");
    DestoryStack(S);
}

void MazeShortestPath(int startX, int startY, int endX, int endY) {
    int visited[N + 2][M + 2];
    int i, j;

    for (i = 0; i < N + 2; i++) {
        for (j = 0; j < M + 2; j++) {
            visited[i][j] = 0;
        }
    }

    front = 0;
    rear = 0;

    QNode startNode = {startX, staetY, -1};
    EnQueue(startNode);
    visited[startX][startY] = 1;

    int found = 0;
    int endNodeIndex = -1;

    while (!IsQueueEmpty()) {
        QNode current = DeQueue();
        int current_index= front - 1;

        if (current.x == endX && current.y == endY) {
            found = 1;
            endNodeIndex = current_index;
            break;
        }

        for (int di = 1; di <= 4; di++) {
            int nextX = current.x + dx[di];
            int nextY = current.y + dy[di];

            if (maze[next][nextY] == 0 && visited[nextX][nextY] == 0) {
                QNode nextNode = {nextX, nextY, current_index};
                EnQueue(nextNode);
                visited[nextX][nextY] = 1;
            }
        }
    }

    printf("\n最短路径：\n");
    if (found) {
        int path[MAX_MAZE_SIZE * MAX_MAZE_SIZE][2];
        int path_len = 0;
        int idx = endNodeIndex;
        while (idx != -1) {
            path[path_len][0] = queue[idx].x;
            path[path_len][1] = queue[idx].y;
            path_len++;
            idx = queue[idx].pre;
        }

        for (i = path_len - 1; i >= 0; i--) {
            printf("(%d,%d) ", path[i][0], path[i][1]);
        }
        printf("\n");
    } else {
        printf("没有通路。\n");
    }
}

int main() {
    InitMaze();
    printf("初始迷宫：\n");
    PrintMaze();
    
    int startX = 1, startY = 1;
    int endX = 8, endY = 0;

    MazePath(startX, startY, endX, endY);
    MazeShortestPath(startX, startY, endX, endY);

    return 0;
}