/* 3 Logos
https://codeforces.com/problemset/problem/581/D

Idea: Fix one of the rectangles in one specific oriengtation on topleft corner of will-be square.

Difficulty: */

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main(){
    int x1, y1, x2, y2, x3, y3; // lengths and widths of rectangles, no guarantee if x or y is longer
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    // loop thru all possible ways to arrange 3 rectangles when x1,y1 rectange is fixed at top left
    // first, check the cases where all 3 of them can be smacked together in a stack
    
}