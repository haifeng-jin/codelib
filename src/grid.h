#include "common_header.h"

#ifndef GRID_H
#define GRID_H

class Point {
 public:
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  Point operator+(const Point& a) const { return Point(x + a.x, y + a.y); }
  bool operator==(const Point& a) const { return x == a.x && y == a.y; }
};
vector<Point> directions_4 = {Point(1, 0), Point(0, 1), Point(-1, 0),
                              Point(0, -1)};
vector<Point> directions_8 = {Point(1, 0),   Point(0, 1),  Point(-1, 0),
                              Point(0, -1),  Point(1, -1), Point(-1, 1),
                              Point(-1, -1), Point(1, 1)};
vector<Point> directions_diagonal = {Point(1, -1), Point(-1, 1), Point(-1, -1),
                                     Point(1, 1)};

class Grid {
 public:
  vector<Point> directions;
  int num_rows;
  int num_cols;
  Grid() {}
  Grid(int num_rows, int num_cols, vector<Point> directions = directions_4)
      : num_rows(num_rows), num_cols(num_cols), directions(directions) {
    _visited = Create2DVector<bool>(num_rows, num_cols, false);
  }
  void visit(Point a) { _visited[a.x][a.y] = true; }

  bool out(Point a) {
    return a.x < 0 || a.y < 0 || a.x >= num_rows || a.y >= num_cols;
  }

  bool visited(Point a) { return _visited[a.x][a.y]; }

  vector<Point> neighbours(Point a) {
    vector<Point> _neighbours;
    for (auto v : directions) {
      auto b = a + v;
      if (!out(b)) {
        _neighbours.push_back(b);
      }
    }
    return _neighbours;
  }

 private:
  vector<vector<bool>> _visited;
};

#endif  // GRID_H