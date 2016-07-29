/*
	Left Rectangle approximation to integrate x'(t) = f(t, x(t))
	[param] fun RHS of above
*/
int eulerSolver(float x0, float t0, float tMax, float dt, float (*fun) (float, float)) {
	int tN = (int) ( (tMax - tMin) / dt );  //Calculate mesh size
	float * x = (float*) calloc(tN, sizeof(float)); //allocate memory for x(t)
	x[0] = x0;
	float t = t0;
	//Euler's method
	for(int i = 1; i < tN; i++) {
		x[i] = x[i-1] + dt*fun(t, x[i-1]); 
		dt += dt;	
	}
	return 0;
}