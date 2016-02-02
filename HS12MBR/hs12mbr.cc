// Author: József Farkas
// Github: https://github.com/fjozsef

#include <cstdio>
#include <algorithm>

struct RawObject {
	char object_type;
	int object_coordinates[4];
};


class Point {
public:
	int x;
	int y;

	Point(int x, int y) : x(x), y(y) { }
};

class Circle {
public:
	Point center;
	int radius;

	Circle(int x, int y, int radius) : center(Point(x, y)), radius(radius) { }
	Circle(const Point& center, const int radius) : center(center), radius(radius) { }
};

class LineSegment {
public:
	Point points[2];

	LineSegment(const Point& p1, const Point& p2) : points {p1, p2} { }
};

class Rectangle {
public:
	Point lower_left;
	Point upper_right;

	Rectangle(const Point& point) : lower_left(point), upper_right(point) { }
	Rectangle(const Circle& circle) : lower_left(circle.center), upper_right(circle.center) {
		lower_left.x -= circle.radius;
		lower_left.y -= circle.radius;
		upper_right.x += circle.radius;
		upper_right.y += circle.radius;
	}

	Rectangle(const Point& lower_left, Point& upper_right) : lower_left(lower_left), upper_right(upper_right) {	}

	void expand(const RawObject& rawObject) {
		switch (rawObject.object_type) {
		case 'p':
			expand(Point(rawObject.object_coordinates[0], rawObject.object_coordinates[1]));
			break;
		case 'c':
			expand(Circle(rawObject.object_coordinates[0], rawObject.object_coordinates[1], rawObject.object_coordinates[2]));
			break;
		case 'l':
			expand(LineSegment(Point(rawObject.object_coordinates[0], rawObject.object_coordinates[1]), Point(rawObject.object_coordinates[2], rawObject.object_coordinates[3])));
			break;
		default:
			printf("Unknown Object type: %c\n", rawObject.object_type);
			break;
		}
	}

	void expand(const Point& point) {
		lower_left.x = std::min(lower_left.x, point.x);
		lower_left.y = std::min(lower_left.y, point.y);
		upper_right.x = std::max(upper_right.x, point.x);
		upper_right.y = std::max(upper_right.y, point.y);
	}

	void expand(const Circle& circle) {
		expand(Rectangle(circle));
	}

	void expand(const Rectangle& rectangle) {
		expand(rectangle.lower_left);
		expand(rectangle.upper_right);
	}

	void expand(const LineSegment& lineSegment) {
		expand(lineSegment.points[0]);
		expand(lineSegment.points[1]);
	}

};

void readLine(RawObject& rawObject) {
	scanf("%c ", &rawObject.object_type);
	switch (rawObject.object_type) {
	case 'p':
		scanf("%d %d\n", &rawObject.object_coordinates[0], &rawObject.object_coordinates[1]);
		break;
	case 'c':
		scanf("%d %d %d\n", &rawObject.object_coordinates[0], &rawObject.object_coordinates[1], &rawObject.object_coordinates[2]);
		break;
	case 'l':
		scanf("%d %d %d %d\n", &rawObject.object_coordinates[0], &rawObject.object_coordinates[1], &rawObject.object_coordinates[2], &rawObject.object_coordinates[3]);
		break;
	default:
		printf("Unknown Object type: %c\n", rawObject.object_type);
		break;
	}
}


int main() {
	int num_test_cases;
	int num_objects;
	RawObject rawObject;
	Rectangle boundingRectangle(Point(-2000, -2000));

	scanf("%d", &num_test_cases);
	while (num_test_cases--) {
		scanf("%d\n", &num_objects);
		readLine(rawObject);
		boundingRectangle = Rectangle(Point(rawObject.object_coordinates[0], rawObject.object_coordinates[1])); // Initialization of the boundingRectangle
		boundingRectangle.expand(rawObject);
		--num_objects;
		while (num_objects--) {
			readLine(rawObject);
			boundingRectangle.expand(rawObject);
		}
		printf("%d %d %d %d\n", boundingRectangle.lower_left.x, boundingRectangle.lower_left.y, boundingRectangle.upper_right.x, boundingRectangle.upper_right.y);
	}
	return 0;
}
