#include <bits/stdc++.h>
using namespace std;
int N, K;
int seg_tree[262144]; //세그먼트 트리의 크기는? 주어진 N보다 큰 가장 가까운 2의 제곱수의 두배임. N이 100'000이기에 N보다 큰 2의 제곱수는 2^17 = 131'072이므로 이의 두배인 2^18 = 262144

//N의 개수만큼 리프(자식없는노드)를 생성하고, 리프는 1로 설정
//부모노드는 자식 노드들의 합이다.

int init_tree(int node, int start, int end) //루트노드, 시작, 끝
{
	//리프노드에 도달했는지 확인. 도달했다면 1로 설정함
	if (start==end) return seg_tree[node] = 1;

	int mid = (start + end) / 2;
	return seg_tree[node] = init_tree(node * 2, start, mid) + init_tree(node * 2 + 1, mid+1, end); // 부모노드 = 왼쪽 자식노드 + 오른쪽 자식노드

	//1부터 10까지가 범위라면 mid는 5가 됨. 
	//재귀호출시, 왼쪽자식은 1~5 오른쪽자식은 6~10의 범위를 가지게 된다!!
	//3 : 1~3,     4~5           | 8 : 6~8,      9~10
	//2 : 1~2 3~3 | 5 : 4~4, 5~5 | 7 : 6~7, 8~8 | 9: 9~9, 10~10
    //1~1, 2~2, [3]       [4] [5]   6~6, 7~7 [8]     [9]  [10]
	// [1]   [2]                    [6]  [7]
}
//초기화가 끝나게 되면 각 노드의 값은, 해당 노드아래에 있는 노드개수를 가지게 된다. => segment


//세그트리의 연산

// 10일때
// 세그트리의 루트는 10임. 왼쪽자식은 5, 오른쪽 자식도 5
// 만약 제거할 번호가 3이라면?
// 3번째이므로, 1~5가 있는 왼쪽으로 이동해야한다.

// 만약 제거할 번호가 7이라면?
// 7번째이므로, 5번째까지를 가지는 왼쪽자식이 아닌 6~10인 오른쪽으로 이동해야한다. 이 과정에서 당연히, 제거할 인덱스는 왼쪽 자식의 크기만큼 제거해줘야지.


int query(int node, int start, int end, int index)// 현재, 시작, 끝, 제거할 번호   => 초기화할때 처럼  (1,1,N)은 그대로 받아온다.
{
    if (start == end) return start; //시작과 끝이 같다면, 즉 리프라면 번호 반환
    
    int mid = (start + end) / 2;

    //제거할 인덱스가 현재노드의 왼쪽자식값 이하라면? ([node*2] : 왼쪽자식이 나타내는 구간의 크기)
    if (index <= seg_tree[node * 2]) return query(node * 2, start, mid, index); //왼쪽자식으로 이동!

    //제거할 인덱스가 현재노드의 왼쪽자식값보다 크다면?
    else return query(node * 2 + 1, mid + 1, end, index - seg_tree[node * 2]);  //오른쪽자식으로 이동! 범위 바꿔주고, 인덱스도 왼쪽자식크기만큼 빼준다.
}

//세그트리의 수정
void update(int node, int start, int end, int del)
{
    seg_tree[node]--; //구간의 크기를 감소시킴(한 명이 제거되는 것이기에)
    
    if (start == end) return;

    //해당 구간을 찾아가면서, 그 구간에서 제거할 것이기에 [node]를 -1씩 해줄거임
    else
    {
        int mid = (start + end) / 2;
        if (del <= mid)
        {
            return update(2 * node, start, mid, del);
        }
        else
        {
            return update(2 * node + 1, mid + 1, end, del);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    init_tree(1, 1, N); //루트, 시작, 끝

    int index = 1;

    cout << "<";

    for (int i = 0; i < N; i++) //query => update
    {
        // 다음 순서 구하기
        //모듈러연산부분!!!!!
        int size = N - i; // 반복할때마다 한명씩 제거됨. 즉, i번 반복에서 남은 사람수는 N-i임.
        index += K - 1;   //다음 제거할 인덱스를 계산한다 :
                          //K=3이라면, 3번째 사람을 제거한 다음, 그 다음사람부터 3번째를 제거해야한다.
                          // 그렇기에, 제거할 index는 index + 3인데, 다음을 보면...
                          // 1 2 3 4 5 6 7 이 있을때, 3을 제거하고 그 다음은 6이다. 3의 인덱스는 3,  6의 인덱스는 6인데, 제거돼서 땡겨지므로 1을 빼주는 것임
                          // 
        //제거할 인덱스가 배열을 벗어날 수 있기에, 인덱스가 더 크다면, 남은 사람수를 이용해 인덱스를 수정해주는 부분이다.
        if (index % size == 0) index = size;    // index를 남은 사람수로 나눈 나머지가 0이라면? 즉 index가 사람수의 배수라면? index = 남은사람수
        // 즉, 인덱스가 10인데 남은 사람수가 5명이라면, 결국 5번째 사람이기에 인덱스는 5가 된다.

        //인덱스가 사람보다 크다면, 배수부분은 잘라버리고 나머지를 취함.
        else if (index > size) index %= size;
        // else :  정상적인 범위이므로 따로 하는 것 X

        // 다음 순서에 해당하는 번호 받아오기
        int num = query(1, 1, N, index);

        // 해당 번호 제거 하기
        update(1, 1, N, num);

        if (i == N - 1) cout << num;  // 가장 마지막 사람인 경우 ','는 필요하지 않기에 num만 출력한다.
        else cout << num << ", ";
    }
    cout << ">";
	return 0;
}