# 신입사원 능력치 최소화 문제

## 1. 잘못된 초기 접근

* 배열 두 번 전수 탐색 → `O(number × N)`
* `visited[]` 추적 오버헤드
* 최악 10^9 연산 → TLE

## 2. 우선순위 큐 풀이

* 자료구조: **Min-Heap**
* 복잡도: `O(number × log N)`
* 절차:

    1. 모든 능력치 `push`
    2. `number` 회: `pop`×2 → 합 → `push`×2
    3. 전부 `pop`하며 합산

## 3. `priority_queue<int, vector<int>, greater<int>>`

| 인자             | 의미         |
| -------------- | ---------- |
| `int`          | 데이터 타입     |
| `vector<int>`  | 내부 컨테이너    |
| `greater<int>` | 비교자 → 최소 힙 |

선언 예시:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```
