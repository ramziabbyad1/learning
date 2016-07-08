function y = H(theta)
	l = 15.3; r = 120; x = 84;
	y = ( (4*l*r)/(r^2 - x^2) ) * sqrt(1 - ( (x/r)^2 )*sin(theta)^2 );
endfunction

expectedH = 1.355661135;

q = quad("H", 0, pi/2);
format long;
printf("Expected = %1.10f\n Computed = %1.10f\n", expectedH, q);
