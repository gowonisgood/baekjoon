**치킨 배달 (BOJ #15686)**

## 문제 요약

1. N×N 격자 도시가 주어지며 각 칸은 빈 칸(0), 집(1), 치킨집(2)으로 구분됩
2. 치킨집 중 최대 M개를 선택하여 나머지는 폐업시키고 모든 집의 치킨 거리를 계산한 뒤 그 합의 최솟값을 구하기

## 해결 전략

1. 치킨집 조합 선택

    1. DFS를 사용해 치킨집 C개 중에서 M개를 선택하는 조합을 생성
    2. 시작 인덱스를 관리하여 중복 없이 C개 중 M개를 선택 하는 경우를 탐색
2. 거리 계산

    1. 모든 집과 치킨집 사이의 맨해튼 거리를 사전 계산하여 테이블에 저장합니다.
    2. 선택된 치킨집들에서 각 집까지의 거리 중 최솟값을 찾아 합산합니다.
    3. 각 조합마다 계산한 거리 합의 최솟값을 갱신합니다.

## 시간 복잡도

1. 조합 생성: O(\binom{C}{M})
2. 거리 계산: 한 조합당 $O(H \times M)$, H는 집의 수
3. 전체: $O(\binom{C}{M} \times H \times M)$

BOJ 제약(N ≤ 50, C ≤ 13, M ≤ C) 하에서 충분히 빠르게 동작

## next_permutation 사용 하는 것도 좀 더 공부해보기 !!


