//operator_overloading

struct Point {
  Point(int xx, int yy) : x(xx), y(yy) {}
  int x = 0;
  int y = 0;
};
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << std::string("{") + std::to_string(p.x) + "," + std::to_string(p.y) + "}";
    return os;
}