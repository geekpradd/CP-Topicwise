#include <bits/stdc++.h>
#include <complex>
using namespace std;
typedef complex<int> point;
#define x real
#define y imag

point pivot;

int dot(point a, point b){
	return (conj(a) * b).x();
}
int cross(point a, point b){
	return (conj(a) * b).y();
}

int orientation(point a, point b, point pivot){
	// 0: collinaear with pivot as origin 
	// 1: a-pivot-b is clockwise
	// 2: anticlockwise
	int val = cross(a-pivot, b-pivot);
	if (val==0) return val;
	
	return (val > 0) ? 2 : 1;
}
bool comparator(const point &first, const point &second){
	int ori = orientation(first, second, pivot);
	if (ori==2)
		return true;
	else if (ori==1)
		return false;
	else {
		return (abs(first-pivot) < abs(second-pivot));
	}
}

point secondElem(stack<point> &s){
	point cur = s.top();
	s.pop();
	point fin = s.top();
	s.push(cur);
	return fin;
}
int main(){
	int n; cin >> n;
	vector<point> points(n);
	for (int j=0; j<n; ++j){
		int real, imag; cin >> real >> imag;
		points[j] = complex<int>(real, imag);
	}
	point pivot = points[0];
	int index = 0;
	for (int i=1; i<n; ++i){
		if (points[i].x()<pivot.x()){
			pivot = points[i];
			index = i;
		}
		else if (points[i].x() == pivot.x() && points[i].y() < pivot.y()){
			pivot = points[i];
			index = i;
		}
	}
	point temp = points[0];
	points[0] = pivot;
	points[index] = temp;
	sort(points.begin()+1, points.end(), comparator);
	vector<point> fpoints;
	for (int i=1; i<n; ++i){
		while (i<n-1 && orientation(points[i], points[i+1], pivot) == 0)
			i++;
		fpoints.push_back(points[i]);
	}
	

	stack<point> mainstack;
	mainstack.push(pivot);
	mainstack.push(fpoints[0]);
	int count = 2;
	for (int i=1; i<fpoints.size(); ++i){
		point candidate = fpoints[i];

		while (count >=2 && orientation(candidate, secondElem(mainstack), mainstack.top()) == 1){
			mainstack.pop();
			count--;
		}
		count++;
		mainstack.push(candidate);
	}

	while (!mainstack.empty()){
		point cur = mainstack.top();
		cout << "got " << cur << " in convex hull " << endl;
		mainstack.pop();
	}

	return 0;
}
	
