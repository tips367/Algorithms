/* We are given an array of n points in the plane, and the problem is to find out the closest pair of points in the array. */

#include <iostream>
#include <vector>
#include <algorithm>

class Point
{
public:
    int x, y;
};

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float min(float x, float y)
{
    return (x < y) ? x : y;
}

// Method 1. Time complexity...O(n * log n * log n)
/*
bool compareX(Point a, Point b)
{
    return (a.x < b.x);
}

bool compareY(Point a, Point b)
{
    return (a.y < b.y);
}

float stripClosest(std::vector<Point>& strip, float d)
{
    float min = d; // Initialize the minimum distance as d

    std::sort(strip.begin(), strip.end(), compareY);

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < strip.size(); ++i)
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float closestUtil(Point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);

    // Find the middle point
    int mid = n / 2;
    Point midPoint = P[mid];

    // Consider the vertical line passing through the middle point calculate
    // the smallest distance dl on left of middle point and dr on right side
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);

    // Find the smaller of two distances
    float d = min(dl, dr);

    // Build a vector that contains points close (closer than d)
    // to the line passing through the middle point
    std::vector<Point> strip;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);

    // Find the closest points in strip. Return the minimum of d and closest distance in strip
    return min(d, stripClosest(strip, d));
}

float closest(Point P[], int n)
{
    std::sort(P, P + n, compareX);

    return closestUtil(P, n);
} */

// Method 2: Optimized...Time complexity : O(n log n)
bool compareX(Point a, Point b)
{
    return (a.x != b.x) ? (a.x < b.x) : (a.y < b.y);
}

bool compareY(Point a, Point b)
{
    return (a.y != b.y) ? (a.y < b.y) : (a.x < b.x);
}

float stripClosest(std::vector<Point>& strip, float d)
{
    float min = d; // Initialize the minimum distance as d

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < strip.size(); ++i)
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float bruteForce(std::vector<Point>& P, int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float closestUtil(std::vector<Point>& Px, std::vector<Point>& Py, int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);

    // Find the middle point
    int mid = n / 2;
    Point midPoint = Px[mid];

    // Divide points in y sorted array around the vertical line.
    std::vector<Point> Pyl(mid);      // y sorted points on left of vertical line
    std::vector<Point> Pyr(n - mid);  // y sorted points on right of vertical line
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++)
    {
        if ((Py[i].x < midPoint.x || (Py[i].x == midPoint.x && Py[i].y < midPoint.y)) && li < mid)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }

    // Consider the vertical line passing through the middle point calculate
    // the smallest distance dl on left of middle point and dr on right side
    std::vector<Point> Pxl = std::vector<Point>(Px.begin(), Px.begin() + mid);
    std::vector<Point> Pxr = std::vector<Point>(Px.begin() + mid , Px.end());
    float dl = closestUtil(Pxl, Pyl, mid);
    float dr = closestUtil(Pxr, Pyr, n - mid);

    // Find the smaller of two distances
    float d = min(dl, dr);

    // Build a vector that contains points close (closer than d)
    // to the line passing through the middle point
    std::vector<Point> strip;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip.push_back(Py[i]);

    // Find the closest points in strip. Return the minimum of d and closest distance in strip
    return min(d, stripClosest(strip, d));
}

float closest(Point P[], int n)
{
    std::vector<Point> Px(n);
    std::vector<Point> Py(n);

    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    std::sort(Px.begin(), Px.end(), compareX);
    std::sort(Py.begin(), Py.end(), compareY);

    return closestUtil(Px, Py, n);
}

int main()
{
    Point P[] = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
    int n = sizeof(P) / sizeof(P[0]);
    std::cout << "The smallest distance is " << closest(P, n);
    return 0;
}