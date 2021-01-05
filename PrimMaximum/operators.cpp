#include "operators.h"

bool operator<(ii a, ii b){
	return (a.second)<(b.second);
}

bool operator>=(ii a, ii b){
	return(a.second)>=(b.second);
}

bool operator>(ii a, ii b){
	return (a.second)>(b.second);
}

bool operator<=(ii a, ii b){
	return (a.second)<=(b.second);
}

bool operator==(ii a, ii b){
	return (a.second)==(b.second);
}

bool operator!=(ii a, ii b){
	return (a.second)!=(b.second);
}