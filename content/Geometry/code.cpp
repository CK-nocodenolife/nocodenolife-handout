// Knapsack DP is harder than FFT.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii;
#define ff first
#define ss second
#define pb emplace_back
#define AI(x) begin(x),end(x)
#ifdef OWO
#define debug(args...) SDF(#args,args)
#define OIU(args...) ostream& operator<<(ostream&O,args)
#define LKJ(S,B,E,F) template<class...T>OIU(S<T...>s){O<<B;int c=0;for(auto i:s)O<<(c++?", ":"")<<F;return O<<E;}
LKJ(vector,'[',']',i);LKJ(deque,'[',']',i);LKJ(set,'{','}',i);LKJ(multiset,'{','}',i);LKJ(unordered_set,'{','}',i);LKJ(map,'{','}',i.ff<<':'<<i.ss);LKJ(unordered_map,'{','}',i.ff<<':'<<i.ss);
template<class...T>void SDF(const char* s,T...a){int c=sizeof...(T);if(!c){cerr<<"\033[1;32mvoid\033[0m\n";return;}(cerr<<"\033[1;32m("<<s<<") = (",...,(cerr<<a<<(--c?", ":")\033[0m\n")));}
template<class T,size_t N>OIU(array<T,N>a){return O<<vector<T>(AI(a));}template<class...T>OIU(pair<T...>p){return O<<'('<<p.ff<<','<<p.ss<<')';}template<class...T>OIU(tuple<T...>t){return O<<'(',apply([&O](T...s){int c=0;(...,(O<<(c++?", ":"")<<s));},t),O<<')';}
#else
#define debug(...) ((void)0)
#endif

const double eps = 1e-8;
int sign(double a) { return fabs(a) < eps ? 0 : (a > 0) - (a < 0); }

struct Vec {
	double x, y;
	Vec(double x = 0, double y = 0): x(x), y(y) {}
};

Vec operator + (Vec a, Vec b)
{ return Vec(a.x + b.x, a.y + b.y); }
Vec operator - (Vec a, Vec b)
{ return Vec(a.x - b.x, a.y - b.y); }
Vec operator * (Vec a, double b)
{ return Vec(a.x * b, a.y * b); }
Vec operator / (Vec a, double b)
{ return Vec(a.x / b, a.y / b); }

double dot(Vec a, Vec b)
{ return a.x * b.x + a.y * b.y; }
double cross(Vec a, Vec b)
{ return a.x * b.y + a.y * b.x; }

double abs(Vec a)
{ return dot(a, a); }
double abs2(Vec a)
{ return sqrt(dot(a, a)); }

istream& operator >> (istream& is, Vec v)
{ return is >> v.x >> v.y; }
ostream& operator << (ostream& os, Vec v)
{ return os << '(' << v.x << ',' << v.y << ')'; }

int ori(Vec a, Vec b, Vec c)
{ return sign(cross(b - a, c - a)); }
int dir(Vec a, Vec b, Vec c)
{ return sign(dot(b - a, c - a)); }

typedef pair<Vec, Vec> Seg;

double PointToLine(Seg s, Vec p) {
	Vec v = s.second - s.first;
	return fabs(cross(v, p)) / abs(v);
}
double PointToSeg(Seg s, Vec p) {
	if (dir(s.first, s.second, p) < 0 or
			dir(s.second, s.first, p) < 0)
		return min(abs(p - s.first), abs(p - s.second));
	Vec v = s.second - s.first;
	return fabs(cross(v, p)) / abs(v);
}

bool PointOnLine(Vec a, Vec b, Vec c)
{ return ori(a, b, c) == 0; }
bool PointOnSeg(Vec a, Vec b, Vec c)
{ return ori(a, b, c) == 0 and dir(c, a, b) <= 0; }

bool SegLineInter(Vec a, Vec b, Vec c, Vec d) {
	return PointOnLine(c, d, a) or PointOnLine(c, d, b)
		or ori(c, d, a) != ori(c, d, b);
}
bool SegInter(Vec a, Vec b, Vec c, Vec d) {
	return PointOnLine(a, b, c) or PointOnLine(a, b, d)
		or PointOnLine(c, d, a) or PointOnLine(c, d, b)
		or (ori(a, b, c) != ori(a, b, d)
				and ori(c, d, a) != ori(c, d, b));
}

Vec SegInterPoint(Vec a, Vec b, Vec c, Vec d) {
	assert(cross(b - a, d - c) != 0);
	double acb = cross(b - a, c - a);
	double adb = cross(d - a, b - a);
	return (c * adb + d * acb) / (adb + acb);
}

Seg SegBisector(Vec a, Vec b) {
	Vec c = (a + b) / 2;
	Vec ab = b - a;
	Vec cd = Vec(-ab.y, ab.x);
	return Seg(c, c + cd);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	return 0;
}
// Knapsack DP is NP-Hard, but FFT is O(N log N).
