#! /usr/bin/octave -qf

function y = Si_integrand(x)
	y = sin(x)./x;
endfunction

q = quad("Si_integrand", 0, 1);

printf("using quad we get %f\n", q); 

pkg load specfun;

s = Si(1);

printf("using Si(1) we get %f\n", s);

printf("Plotting the integrand of Si...\n");

x = -10:.1:10;
plot(x, Si_integrand(x)), grid
print -dpng si_integrand.png


