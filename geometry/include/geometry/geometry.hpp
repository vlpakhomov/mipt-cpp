#pragma once

#include <cstddef>
#include <cstdint>
#include <tuple>

class Vector;
class Point;
class Segment;

class IShape {
  public:
    IShape() = default;
    virtual ~IShape() = default;

    virtual void Move(Vector const& vec) = 0;

    virtual bool ContainsPoint(Point const& dot) const = 0;

    virtual bool CrossSegment(Segment const& seg) const = 0;

    virtual IShape* Clone() const = 0;

};

class Vector {
  public:
    Vector() = default;
    Vector(Vector const& vec) = default;
    Vector& operator=(Vector const& vec) = default;
    ~Vector() = default;

    Vector(std::int64_t x, std::int64_t y);
    
    Vector& operator+=(Vector const& vec);
    Vector& operator-=(Vector const& vec);

    Vector operator-() const;

    std::int64_t LenSq() const;

    std::int64_t GetX() const;
    std::int64_t GetY() const;

  private:
    std::int64_t x_;
    std::int64_t y_;
};


std::int64_t operator*(Vector const& vec1, Vector const& vec2);

std::int64_t operator^(Vector const& vec1, Vector const& vec2);

Vector operator+(Vector const& vec1, Vector const& vec2);
Vector operator-(Vector const& vec1, Vector const& vec2);

Vector operator*(Vector const& vec, std::int64_t num);
Vector operator*(std::int64_t num, Vector const& vec);

bool operator==(Vector const& vec1, Vector const& vec2);

class IShape;

class Point: public IShape {
  public:
    Point() = default;
    Point(Point const& dot) = default;
    Point& operator=(Point const& dot);
    ~Point() override = default;

    Point(std::int64_t x, std::int64_t y);

    std::int64_t GetX() const;
    std::int64_t GetY() const;

    void Move(Vector const& vec) override;

    bool ContainsPoint(Point const& dot) const override;

    bool CrossSegment(Segment const& seg) const override;

    Point* Clone() const override;

  private:
    std::int64_t x_;
    std::int64_t y_;
};

Vector operator-(Point const& dot1, Point const& dot2);

std::int64_t DistSq(Point const& dot1, Point const& dot2);

class Segment: public IShape {
  public:
    Segment() = default;
    Segment(Segment const& seg) = default;
    Segment& operator=(Segment const& seg) = default;
    ~Segment() override = default;

    Segment(Point const& p, Point const& q);

    Point GetA() const;
    Point GetB() const;
 
    void Move(Vector const& vec) override;

    bool ContainsPoint(Point const& dot) const override;

    bool CrossSegment(Segment const& seg) const override;

    Segment* Clone() const override; 
    
    static bool intersect_project(Segment const& seg1, Segment const& seg2);

  private:
    Point a_;
    Point b_;
};

std::int64_t DistSq(Segment const& seg, Point const& dot);

class Line: public IShape {
  public:
    Line() = default;
    Line(Line const& line) = default;
    Line& operator=(Line const& line) = default;
    ~Line() override = default;

    Line(Point const& dot1, Point const& dot2);

    std::int64_t GetA() const;
    std::int64_t GetB() const;
    std::int64_t GetC() const;
    
    void Move(Vector const& vec) override;

    bool ContainsPoint(Point const& dot) const override;

    bool CrossSegment(Segment const& seg) const override;

    Line* Clone() const override;
  
  private:
    std::int64_t a_;
    std::int64_t b_;
    std::int64_t c_;
};

class Ray: public IShape {
  public:
    Ray() = default; 
    Ray(Ray const& ray) = default;
    Ray& operator=(Ray const& ray) = default;
    ~Ray() override = default;

    Ray(Point const& head, Point const& tail);

    Point GetA() const;
    Vector GetVector() const;

    void Move(Vector const& vec) override;

    bool ContainsPoint(const Point& dot) const override;

    bool CrossSegment(const Segment& seg) const override;

    Ray* Clone() const override;
  
  private:
    Point a_;
    Vector vec_;
};

class Circle: public IShape {
  public:
    Circle() = default;
    Circle(Circle const& crl) = default;
    Circle& operator=(Circle const& crl) = default;
    ~Circle() override = default;

    Circle(Point const& cntr, std::size_t rad);

    Point GetCentre() const;
    std::size_t GetRadius() const;
 
    void Move(const Vector& vec) override;

    bool ContainsPoint(const Point& dot) const override;

    bool CrossSegment(const Segment& seg) const override;

    Circle* Clone() const override; 
  
  private:
    std::int64_t rad_;
    Point cntr_;
};
