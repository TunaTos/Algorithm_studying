#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pos = pair<int,int>; // {cXpos, cYpos, nXpos, nYpos}
using edge = pair<pos,pos>;

set<edge> edges;

pos cur_pos = {0,0};

bool in_the_matrix(const int& xpos, const int& ypos)
{
    return xpos >= -5 && xpos <= 5 && ypos >= -5 && ypos <= 5;
}


int solution(string dirs) {
    
    for (char c: dirs)
    {
        int nx = cur_pos.first;
        int ny = cur_pos.second;
        
        if (c == 'U')
            --ny;
        else if (c == 'D')
            ++ny;
        else if (c == 'L')
            --nx;
        else if (c == 'R')
            ++nx;
        
        if (!in_the_matrix(nx, ny)) continue;
        
        pos a = cur_pos;
        pos b = {nx, ny};
        
        if (a > b)
            swap(a,b);
        
        edge e = {a,b};
        edges.insert(e);
        
    
        cur_pos.first = nx;
        cur_pos.second = ny;
    }
    
    for (edge e: edges)
    {
        cout << e.first.first << " " << e.first.second << " " << e.second.first << " " << e.second.second << endl;
    }
    
    return edges.size();    
}