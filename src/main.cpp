#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

class Astar {
private:
class Cell {
public:
bool flag; // if flag is true, this cell is visited.
int position[2] = {};
double fScore;
double gScore;
vector<Cell*> neighbor;
Cell(int x, int y) {
this->flag = false;
this->position[0] = x;
this->position[1] = y;
this->fScore = DBL_MAX;
}
void visitCell(Cell* cell) {
cell->flag = true;
return;
}
void clearCell(Cell* cell) {
cell->flag = false;
return;
}
void setfScore(double cost) {
this->fScore = cost;
return;
}
double getfScore() {
return this->fScore;
}
};
queue<Cell*> path;
vector<Cell*> closeSet;
vector<Cell*> openSet; // 초기에는 시작노드만 있음
double gScore[1000000] = {};
public:
Astar() {

}
    void pushCell(Cell* cell) {
        path.push(cell); // if find new cell, push this cell at last position of the path list.
        return;
    }
    void popCell() {
        path.pop();
        return;
    }
    void remove(Cell* cell) {
        // vector안에 있는 선택 cell 지우기
        for (auto i : openSet) {
            if (i == cell) {
            
            }
        }
    }
    Cell* findLowestCell() {
        sort(openSet.begin(), openSet.end(), [](const Cell* a, const Cell* b) {
        return a->fScore < b->fScore;
        });
        return openSet.front();
    }
    double costEstimate(Cell* start, Cell* end) {
        // 계산 과정 g+f 추가 예정
        double cost;
        return cost;
    }
    queue<Cell*> makePath(queue<Cell*> path, Cell* curCell) {
    // 현재 cell이 어디서부터 왔는지(현재 셀의 이전 셀)를 저장 후,
    // 전체 path에 현재 cell의 이전 셀 저장 후 return.
        return path;
    }   
    double distCells(Cell* curCell, Cell* nextCell) {
        double distance = sqrt(pow(curCell->position[0] - nextCell->position[0],2)+pow(curCell->position[1] - nextCell->position[1],2));
        return distance;
    }
    queue<Cell*> astar(Cell* start, Cell* end) {
        gScore[0] = 0; // 처음 노드는 시작노드이므로 gScore은 0이다.
            // 시작 노드로부터의 비용, 목적 노드까지의 비용 두 가지가 합산된 비용
        start->setfScore(costEstimate(start, end));
        while (true) {
        if (openSet.size() == 0) break;
        Cell* curCell = findLowestCell();
        if (curCell == end){
        return makePath(path, curCell);
        }
        openSet.remove(curCell);
        closeSet.push_back(curCell);

        for (auto neighbor : curCell->neighbor) {
            // 현재 closeSet에 neighbor cell이 존재하지 않는다면 다음 차례로
            if (find(closeSet.begin(), closeSet.end(), neighbor) == closeSet.end())continue;
            // 현재 openSet에 neighbor cell이 존재하지 않는다면 추가할 것
            if (find(openSet.begin(), openSet.end(), neighbor) == openSet.end()) openSet.push_back(neighbor);
            double tmpgScore = curCell->gScore + distCells(curCell, neighbor);
            if (tmpgScore >= neighbor->gScore) continue;
            // curCell을 들렸다 가는게 더 효율적이라 판단
            path.push(curCell);
            neighbor->gScore = tmpgScore;
            neighbor->fScore = neighbor->gScore + distCells(curCell, end);
            }

        }
        return queue<Cell*>();
    }
};
int main() {



}
