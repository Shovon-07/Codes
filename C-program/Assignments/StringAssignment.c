#include <stdio.h>

int main()
{
    //=>>> Task 1
    char str[6] = {"shovon"};
    printf("%s\n", str);

    //=>>> Task 2

    //=>>> Task 3

    //=>>> Task 4

    //=>>> Task 5

    return 0;
}

/*
Q1.
A. Construct an Array
time limit per test1 second
memory limit per test256 megabytes
You are given an integer n
. You need to construct an array of integers a1,a2,…,an
 such that the following conditions are satisfied:

1≤ai≤2⋅n
 for all i
 from 1
 to n
.
All elements of the array and the sums of adjacent elements are pairwise distinct. In other words, among the numbers {a1,a2,…,an,a1+a2,a2+a3,…,an−1+an}
, there should not be two equal numbers.
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤100
). The description of the test cases follows.

The only line of each test case contains one integer n
 (1≤n≤500
).

Output
For each test case, output an array of length n
 that satisfies the condition of the problem. It can be shown that such an array always exists under the given constraints.

Example
InputCopy
3
1
3
6
OutputCopy
1
6 2 3
8 1 11 2 3 4
Note
In the second example, all elements and adjacent sums form the set 6,2,3,8,5
, all of whose elements are distinct.

In the third example, all elements and adjacent sums form the set 8,1,11,2,3,4,9,12,13,5,7
, whose elements are also distinct.


Q2.
B. Another Sorting Problem
time limit per test1.5 seconds
memory limit per test256 megabytes

You are given an array a1,a2,…,an
. You can perform the following operation on this array at most once:

Choose a positive integer k
, as well as a subsequence b1,b2,…,bm
 of the array a
∗
 and add k
 to each element of this subsequence, that is, for each i
 perform abi:=abi+k
.
You need to determine whether it is possible to sort the array in nondecreasing order by performing this operation at most once.

∗
A sequence b
 is a subsequence of a sequence a
 if b
 can be obtained from a
 by the deletion of several (possibly, zero or all) element from arbitrary positions.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

In the first line of each test case, one integer n
 is given (1≤n≤2⋅105
) — the length of the array a
.

In the second line of each test case, n
 integers a1,a2,…,an
 are given (1≤ai≤109
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print "Yes" if it is possible to sort the array by performing the operation at most once. Otherwise, print "No". You may print the answer in any case. For example, "YeS", "YES", "NO", "nO" will also be accepted.

Example
InputCopy
8
4
1 2 3 4
5
10 5 9 4 4
7
8 3 9 4 10 5 11
6
5 3 10 5 9 7
3
2 1 1
5
2 1 1 2 1
3
3 1 2
5
2 1 2 3 1
OutputCopy
YES
NO
YES
NO
YES
YES
YES
NO
Note
In the first test case, the array is already sorted, so the operation does not need to be performed at all.

In the second test case, it can be shown that it is impossible to sort the array using such an operation.

In the third test case, choose k=6
 and choose the subsequence [2,4,6]
 as b
. Then after this operation, the array a
 becomes [8,9,9,10,10,11,11]
 (the elements of the chosen subsequence are shown in bold).

Q3.
C. Chipmunk Theo and Equality
time limit per test2 seconds
memory limit per test512 megabytes
While exploring the depths of the Internet, Theodore the chipmunk found a very interesting sequence of positive integers and decided to play with it.

In one operation, he chooses an element of the sequence and performs the following action:

If the chosen element is even, he divides it by 2.
If the chosen element is odd, he increases it by 1.
Theo really loves equality, so he wants to make all numbers in the sequence equal (otherwise, some numbers might feel offended). Since he needs to plan his lunch time, help him determine the minimum number of operations required to make all numbers equal.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤105
) — the length of the sequence.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the elements of the sequence.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
.

Output
For each test case, output a single integer — the minimum number of operations Theo needs to make all numbers in the sequence equal.

Example
InputCopy
5
3
3 2 4
7
3 6 7 16 8 8 7
3
1 4 2
5
10 10 10 10 10
6
1 1 3 1 1 1
OutputCopy
3
11
2
0
3
Note
In the first test case, we have a sequence: [3,2,4]

One possible sequence of operations:
[3,2,4]→[4,2,4]→[2,2,4]→[2,2,2]
(Operations are performed on numbers shown in bold.)

In the second test case, the sequence is: [3,6,7,16,8,8,7]

Possible operations:

Perform the operation once on the 1st element: 3→4
Perform the operation twice on the 2nd element: 6→3→4
Perform the operation twice on the 4th element: 7→8→4
Perform the operation twice on the 5th element: 16→8→4
Perform the operation once on the 6th element: 8→4
Perform the operation once on the 7th element: 8→4
Perform the operation twice on the 8th element: 7→8→4
After these 11
 operations, all elements become 4
.

Q4.
D. Maximum Prefix Sums
time limit per test2 seconds
memory limit per test256 megabytes
521 sounds the same as "I love you" in Chinese. On this special day, Little S wants to give Little A some well-prepared sequences to recall their friendship sealed for years.

Little S has prepared an array a1,a2,…,an
. Let's define its prefix sums array b1,b2,…,bn
, where bi=a1+a2+…+ai
. Also define the prefix maximum array of b
: c1,c2,…,cn
, where ci=max(b1,b2,…,bi)
.

Now array a
 has been partially lost, but luckily Little S still keeps the array c
. Your task is to restore the array a
 and send it to Little A, or report that no such array exists — in this case, the kind and cute Little A won't get mad either.

Formally, you are given a binary string s
, a partially filled array a
, and an array c
, where:

If you remember the value of ai
, then si=1
, and you are given the true value of ai
.
If you do not remember the value of ai
, then si=0
, and you are given ai=0
.
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains an integer n
 (1≤n≤2⋅105
).

The second line of each test case contains a binary string s
 (si∈{0,1}
) of length n
.

The third line of each test case contains n
 integers a1,a2,…,an
 (|ai|≤106
). If si=0
, then it is guaranteed that ai=0
.

The fourth line of each test case contains n
 integers c1,c2,…,cn
 (|ci|≤2⋅1011
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print "Yes" in the first line if the array a
 exists, otherwise print "No". You may print the answer in any case. For example, "YeS", "YES", "NO", "nO" will also be accepted.

If there is at least one solution, print n
 integers a1,a2,…,an
 (|ai|≤1018
) in the second line. If there are multiple suitable arrays, you may print any of them.

Example
InputCopy
10
4
1110
1 2 -1 0
1 3 3 3
5
00001
0 0 0 0 5
-4 -4 -1 -1 -1
1
1
0
1
6
001111
0 0 2 -3 3 -6
-5 -2 0 0 0 0
5
11110
1 2 0 5 0
1 2 2 7 6
2
01
0 1
-1 -1
6
001010
0 0 5 0 3 0
3 3 4 9 13 16
6
000100
0 0 0 4 0 0
2 6 6 7 7 7
2
00
0 0
4 -1
8
11111111
6 1 1 2 0 5 1 9
6 7 8 10 10 15 16 25
OutputCopy
Yes
1 2 -1 0
Yes
-4 0 3 -6 5
No
Yes
-5 3 2 -3 3 -6
No
No
No
Yes
2 4 -3 4 -100 0
No
Yes
6 1 1 2 0 5 1 9
Note
In the first test case, we have:

a=[1,2,−1,0]
.
b=[1,3,2,2]
.
c=[1,3,3,3]
.
In the third test case, the correct array a
 should be equal to [1]
, so no solution exists.

Q5.
E. Graph Cutting
time limit per test2 seconds
memory limit per test256 megabytes
For his birthday, young Fedya was given a tree with n
 vertices. He wants to cut out a connected subgraph from it. Fedya decided to act as follows: he chooses three distinct vertices a,b,c
 (a<b<c
), and cuts out the minimal connected subgraph containing all three vertices. He wants the size of the resulting subgraph to be exactly d
 (that is, the number of vertices in the cut-out subgraph must be equal to d
).

He became interested in how many different such subgraphs he can cut out. Subgraphs are considered different if the chosen triples of vertices are different. Help him solve this problem!

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first line of each test case contains two integers n
 and d
 (3≤d≤n≤2000
) — the number of vertices in the tree and the desired size of the cut-out subgraph.

Then follow n−1
 lines, each containing two integers u
 and v
 (1≤u,v≤n
, u≠v
), meaning the vertices connected by the corresponding edge. It is guaranteed that the given graph is a tree.

It is guaranteed that the sum of n
 over all test cases does not exceed 2000
.

Output
For each test case, output a single number — the number of different subgraphs that Fedya can cut out.

Example
InputCopy
3
4 3
1 2
3 1
4 1
5 5
1 2
2 4
2 3
5 1
7 7
1 2
1 3
2 4
2 5
3 6
3 7
OutputCopy
3
1
0
Note
This is what the tree looks like for the first test case:

Q6.
F. Quadratic Jumps
time limit per test2 seconds
memory limit per test256 megabytes
You are given two integers n
 and q
. Consider a graph with n
 vertices, where vertices i
 and j
 are connected by an edge if and only if |j−i|
 is a perfect square∗
.

You are given q
 pairs of numbers ai,bi
. For each of these q
 pairs, you need to find the shortest distance between vertices ai
 and bi
 in this graph. It can be proved that the graph is connected, so the distance between ai
 and bi
 is not infinite.

∗
An integer x
 is a perfect square if there exists an integer y
 such that x=y2
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The first line of each test case contains two integers n
 and q
 (2≤n≤2⋅105
, 1≤q≤105
) — the number of vertices in the graph and the number of pairs of vertices for which the distance must be found.

Then the following q
 lines describe the pairs of vertices for which the shortest distance must be found. Each pair is described by two numbers a,b
 (1≤a<b≤n
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
, and the sum of q
 over all test cases does not exceed 105
.

Output
For each test case, output the shortest distance between the vertices for each of the q
 pairs.

Example
InputCopy
2
5 4
1 2
1 3
1 4
1 5
8 3
3 7
2 5
1 7
OutputCopy
1
2
2
1
1
2
3
Note
This is what the graph looks like for the first test case:


For the first pair of vertices, the shortest path is 1→2
.
For the second pair of vertices, the shortest path is 1→2→3
.
For the third pair of vertices, the shortest path is 1→5→4
.
For the fourth pair of vertices, the shortest path is 1→5
.
This is what the graph looks like for the second test case:


For the first pair of vertices, the shortest path is 1→2
.
For the second pair of vertices, the shortest path is 2→6→5
.
For the third pair of vertices, the shortest path is 1→2→6→7
.




*/