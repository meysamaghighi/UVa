// Meysam Aghighi
// The final answer is an edge of the convex hull, so check them all O(nlogn)
#include <bits/stdc++.h>
using namespace std;

const double MAX = 80000;

// typedef long long T;
typedef double T;

double INF = 1e100;
double EPS = 1e-12;

struct point { 
  T x, y; 
  point() {}
  point(T x, T y) : x(x), y(y) {}
  point(const point &p) : x(p.x), y(p.y) {}
  point operator + (const point &p) const { return point(x+p.x, y+p.y); }
  point operator - (const point &p) const { return point(x-p.x, y-p.y); }
  point operator * (T c) const { return point(x*c, y*c); }
  point operator / (T c) const { return point(x/c, y/c); }
  bool operator < (const point &p) const { return x < p.x || (x == p.x && y < p.y); }
};

T dot(point p, point q) { return p.x*q.x + p.y*q.y; } // proportional to cos(x)
double dist(point p, point q) { return sqrt(dot(p-q , p-q)); }
T cross(point p, point q) { return p.x*q.y - p.y*q.x; } // proportional to sin(x) - p to q counterclockwise

double dist_point_line(point p, point a, point b){ // dist from point p to line a-b
    if (dist(a,b) < EPS) return dist(p,a);
    double k = dot(p-a,b-a)/dist(a,b); // directed segment from a (projection)
    return dist(p , a + (b-a)*k/dist(a,b));
}

double solve(const vector<point> &p, point a, point b){ // gives sum of dist from points in p to line a-b
    double ans = 0.0;
    int n = p.size();
    for (int i=0;i<n;i++) ans += dist_point_line(p[i],a,b);
    ans /= n;
    return ans;
}

vector<point> convex_hull(vector<point> p){
    int n = p.size() , k = 0;
    vector<point> h(2*n);
    sort(p.begin(),p.end());
    // Lower half
    for (int i=0;i<n;i++){
        while (k >= 2 && cross(h[k-1]-h[k-2] , p[i]-h[k-2]) <= 0) k--;
        h[k++] = p[i];
    }
    int temp = k+1;
    // Upper half
    for (int i=n-2;i>=0;i--){
        while (k >= temp && cross(h[k-1]-h[k-2] , p[i]-h[k-2]) <= 0) k--;
        h[k++] = p[i];
    }
    h.resize(k-1);
    return h;
}

int main(){
    int N,n;
    cin >> N;
    for (int t=1;t<=N;t++) {
        cin >> n;
        vector<point> p(n);
        for (int i=0;i<n;i++) cin >> p[i].x >> p[i].y;
        vector<point> h = convex_hull(p);
        if (h.size() == 2 && dist(h[0],h[1]) < EPS) h.erase(h.begin());
        double ans;
        if (h.size() <= 2) ans = 0.0;
        else {
            ans = 2*MAX;
            for (int i=0;i<h.size();i++){
                ans = min(ans , solve(p , h[i] , h[(i+1)%h.size()]));
            }
        }
        cout << "Case #" << t << ": " << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}
