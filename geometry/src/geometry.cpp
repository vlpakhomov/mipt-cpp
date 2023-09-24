#include "../include/geometry/geometry.hpp"

#include <algorithm>
#include <iostream>

Vector::Vector(std::int64_t x, std::int64_t y): x_(x), y_(y) {}

Vector& Vector::operator+=(Vector const& vec) {
  x_ += vec.x_;
  y_ += vec.y_;
  return (*this);
}
Vector& Vector::operator-=(Vector const& vec) {
  x_ -= vec.x_;
  y_ -= vec.y_;
  return (*this);
}

Vector Vector::operator-() const {
  return Vector(-x_, -y_);
}

std::int64_t Vector::LenSq() const { return x_ * x_ + y_ * y_; }

std::int64_t Vector::GetX() const { return x_; }
std::int64_t Vector::GetY() const { return y_; }

std::int64_t operator*(Vector const& vec1, Vector const& vec2) {
  return vec1.GetX() * vec2.GetX() + vec1.GetY() * vec2.GetY();
}

std::int64_t operator^(Vector const& vec1, Vector const& vec2) {
  return vec1.GetX() * vec2.GetY() - vec1.GetY() * vec2.GetX();
}

Vector operator+(Vector const& vec1, Vector const& vec2) {
  Vector copy = vec1;
  copy += vec2;
  return copy;
}
Vector operator-(Vector const& vec1, Vector const& vec2) {
  Vector copy = vec1;
  copy -= vec2;
  return copy;
}

Vector operator*(Vector const& vec, std::int64_t num) {
  Vector copy(vec.GetX() * num, vec.GetY() * num);
  return copy;
}

Vector operator*(std::int64_t num, Vector const& vec) {
  return vec * num;
}

bool operator==(Vector const& vec1, Vector const& vec2) {
  return (vec1.GetX() == vec2.GetX() && vec1.GetY() == vec2.GetY());
}

Point::Point(std::int64_t x, std::int64_t y): x_(x), y_(y) {}

std::int64_t Point::GetX() const { return x_; }
std::int64_t Point::GetY() const { return y_; }

void Point::Move(Vector const& vec) {
  x_ += vec.GetX();
  y_ += vec.GetY();
}

bool Point::ContainsPoint(Point const& dot) const { 
  return (x_ == dot.GetX() && y_ == dot.GetY()); 
}

bool Point::CrossSegment(Segment const& seg) const {
  Vector v_a = (*this) - seg.GetA();
  Vector v_b = (*this) - seg.GetB();
  return ((v_a ^ v_b) == 0 && (v_a * v_b) <= 0); 
}

Point* Point::Clone() const { return new Point(*this); }

Vector operator-(Point const& head, Point const& tail) {
  return Vector(head.GetX() - tail.GetX(), head.GetY() - tail.GetY());
}

std::int64_t DistSq(Point const& dot1, Point const& dot2) {
  Vector vec = dot2 - dot1; 
  return vec.LenSq();
}

Segment::Segment(Point const& a, Point const& b): a_(a), b_(b) {}

Point Segment::GetA() const { 
  return a_; 
}
Point Segment::GetB() const { 
  return b_;
}

void Segment::Move(Vector const& vec) {
  a_.Move(vec);
  b_.Move(vec);
}

bool Segment::ContainsPoint(const Point& dot) const { 
  return dot.CrossSegment(*this);
}

bool Segment::CrossSegment(const Segment& seg) const {
  Line a_b(GetA(), GetB());
  Line c_d(seg.GetA(), seg.GetB());

  return Segment::intersect_project(*this, seg) &&
    a_b.CrossSegment(seg) && c_d.CrossSegment(*this);
}

Segment* Segment::Clone() const { return new Segment(*this); }

bool Segment::intersect_project(Segment const& seg1, Segment const& seg2) {
    std::int64_t a_x = seg1.a_.GetX();
    std::int64_t b_x = seg1.b_.GetX();
    std::int64_t c_x = seg2.a_.GetX();
    std::int64_t d_x = seg2.b_.GetX();

    if (a_x > b_x) { std::swap(a_x, b_x); }
    if (c_x > d_x) { std::swap(c_x, d_x); }
   
    std::int64_t a_y = seg1.a_.GetY();
    std::int64_t b_y = seg1.b_.GetY();
    std::int64_t c_y = seg2.a_.GetY();
    std::int64_t d_y = seg2.b_.GetY();

    if (a_y > b_y) { std::swap(a_y, b_y); }
    if (c_y > d_y) { std::swap(c_y, d_y); }
    
    return (std::max(a_x, c_x) <= std::min(b_x, d_x) && 
        std::max(a_y, c_y) <= std::min(b_y, d_y));
}

std::int64_t DistSq(Segment const& seg, Point const& dot) {
  Vector p_q = seg.GetB() - seg.GetA();
  Vector p_a = dot - seg.GetA();
  Vector q_a = dot - seg.GetB();

  if (p_q * p_a <= 0) { return p_a.LenSq(); }
  if ((-p_q) * q_a <= 0) { return q_a.LenSq(); }
 
  return ((p_q ^ p_a) * (p_q ^ p_a)) / p_q.LenSq();
}

Line::Line(Point const& dot1, Point const& dot2):
  a_(dot2.GetY() - dot1.GetY()), 
  b_(dot1.GetX() - dot2.GetX()),
  c_(-dot1.GetX() * dot2.GetY() + dot1.GetY() * dot2.GetX()) {}

std::int64_t Line::GetA() const { return a_; }
std::int64_t Line::GetB() const { return b_; }
std::int64_t Line::GetC() const { return c_; }

void Line::Move(Vector const& vec) {
  c_ -= vec.GetX() * a_ + vec.GetY() * b_; 
}

bool Line::ContainsPoint(Point const& dot) const {
  return (a_ * dot.GetX() + b_ * dot.GetY() + c_ == 0);
}

bool Line::CrossSegment(Segment const& seg) const {
  Point p = seg.GetA();
  Point q = seg.GetB();

  return (a_ * p.GetX() + b_ * p.GetY() + c_) * 
    (a_ * q.GetX() + b_ * q.GetY() + c_) <= 0;
}

Line* Line::Clone() const { return new Line(*this); }

Ray::Ray(Point const& tail, Point const& head):
  a_(tail), vec_(head - tail) {}

Point Ray::GetA() const { return a_; }
Vector Ray::GetVector() const { return vec_; }

void Ray::Move(Vector const& vec) {
  a_.Move(vec); 
}

bool Ray::ContainsPoint(Point const& dot) const {
  Vector v_dot = dot - a_;
  return ((v_dot ^ vec_) == 0) && (v_dot * vec_ >= 0);
}

bool Ray::CrossSegment(Segment const& seg) const {
  if (seg.ContainsPoint(a_)) { return true; }

  Point b_(a_.GetX() + vec_.GetX(), a_.GetY() + vec_.GetY());
  if (!(Line(a_, b_)).CrossSegment(seg)) { return false; }

  std::int64_t cp1 = ((a_ - seg.GetA()) ^ (seg.GetB() - seg.GetA()));
  std::int64_t cp2 = (vec_ ^ (seg.GetB() - seg.GetA())); 
  if (cp1 == 0 && cp2 == 0) { 
    return ContainsPoint(seg.GetA()) || ContainsPoint(seg.GetB());
  } else {
     return cp1 * cp2 < 0;
  }
}

Ray* Ray::Clone() const { return new Ray(*this); }

Circle::Circle(Point const& cntr, std::size_t rad): 
  cntr_(cntr), rad_(rad) {}

Point Circle::GetCentre() const { return cntr_; }
std::size_t Circle::GetRadius() const { return rad_; }

void Circle::Move(Vector const& vec) {
  cntr_.Move(vec);   
}

bool Circle::ContainsPoint(Point const& dot) const {
  Vector v_dot = dot - cntr_;
  return (v_dot.LenSq() <= (rad_* rad_)); 
}

bool Circle::CrossSegment(Segment const& seg) const {
  std::int64_t dist = DistSq(seg, cntr_);
  std::int64_t dist1 = DistSq(seg.GetA(), cntr_);
  std::int64_t dist2 = DistSq(seg.GetB(), cntr_);
  if (dist1 > dist2) { std::swap(dist1, dist2); }

  return (dist <= rad_ * rad_ && !(dist1 < rad_ * rad_ && 
      dist2 < rad_ * rad_)); 
}

Circle* Circle::Clone() const { return new Circle(*this); }
