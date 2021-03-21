/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

bool verificaIgual(const Polygon &lhs, const Polygon &rhs){
    std::vector<Point> v1 = lhs;
    std::vector<Point> v2 = rhs;
    for (const Point &ponto1 : v1){
        bool verifica = false;
        for (const Point &ponto2 : v2)
            if (ponto1.contains(ponto2))
                verifica = true;
        if (verifica == false)
            return false;
    }
    return true;
}

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  return verificaIgual(lhs, rhs) && verificaIgual(rhs, lhs);
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  // TODO: implement this method.
  return false;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
  limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  limits.push_back(*new Point(x0,y0));
  limits.push_back(*new Point(x0,y1));
  limits.push_back(*new Point(x1,y0));
  limits.push_back(*new Point(x1,y1));
}