#include <iostream>
#include <cmath>
using namespace std;

typedef struct lat_long_pair{
	float latitude;
	float longitude;
}lat_long;

float shorter_detour(lat_long *a, lat_long *b,lat_long *c, lat_long *d);
float shorter_detour_with_diagonal(lat_long *a, lat_long *b,lat_long *c, lat_long *d);
float total_distance(lat_long* start, lat_long* end);
float total_distance_with_diagonal(lat_long* start, lat_long* end);
float distance(float start, float end);

int main(){
	lat_long a, b, c, d;

	a.latitude = 0;
	a.longitude = 0;
	b.latitude = 0;
	b.longitude = 5;
	c.latitude = 5;
	c.longitude = 5;
	d.latitude = 0;
	d.longitude = 7;

	cout<<shorter_detour(&a,&b,&c,&d)<<endl;
	cout<<shorter_detour_with_diagonal(&a, &b, &c, &d)<<endl;
	return 0;
}

// assumes no diagonal roads
float shorter_detour(lat_long *a, lat_long *b,lat_long *c, lat_long *d){
	float driver1 = 0;
	float driver2 = 0; 

	float ab = total_distance(a,b);
	float ac = total_distance(a,c);
	float cd = total_distance(c,d);
	float bd = total_distance(b,d);

	//driver 1 route with detour : A->C->D->B
	driver1 = ac + cd + bd;

	//driver 2 route with detour : C->A->B->D
	driver2 = ac + ab + bd;

	if(driver1 < driver2){
		return driver1;
	}
	return driver2; 
}

// assumes diagonal roads
float shorter_detour_with_diagonal(lat_long *a, lat_long *b,lat_long *c, lat_long *d){
	float driver1 = 0;
	float driver2 = 0;

	float ab = total_distance_with_diagonal(a,b);
	float ac = total_distance_with_diagonal(a,c);
	float cd = total_distance_with_diagonal(c,d);
	float bd = total_distance_with_diagonal(b,d);
	
	//driver 1 route with detour : A->C->D->B
	driver1 = ac + cd + bd;

	//driver 2 route with detour : C->A->B->D
	driver2 = ac + ab + bd;

	if(driver1 < driver2){
		return driver1;
	}
	return driver2; 
}

float total_distance_with_diagonal(lat_long* start, lat_long* end){
	return sqrt(pow(distance(start->latitude, end->latitude),2) + pow(distance(start->longitude, end->longitude),2));
}

float total_distance(lat_long* start, lat_long* end){
	return distance(start->latitude, end->latitude) + distance(start->longitude, end->longitude);
}

float distance(float start, float end){
	float diff = start - end;
	if(diff < 0){
		return diff * -1;
	}
	return diff;
}