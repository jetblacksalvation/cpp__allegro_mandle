// cpp__allegro_mandle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "init_al.hpp"
#include <complex>
using  _Complex = std::complex<double>;
_Complex mandel(_Complex z, _Complex c) {
	//sortof efficient, it doesn't re initialize variables, which is good 
	z = (z * z) + c;


	return z;
}

float iter = 0;

int main()
{
	m_setup();
	bool _exit = false;
	int counter = 0;



	_Complex z(0, 0);
	ALLEGRO_COLOR color = { 0.f,0.f,0.f,10.f};
	

	char buffer[10];
	puts("give me the x pos of mandle brot\n");
	fgets(buffer, 10, stdin);
	float x_start = atof(buffer);
	puts("give me the y pos of mandle brot\n");
	fgets(buffer, 10, stdin);
	float y_start = atof(buffer);
	puts("give me the scale value");
	fgets(buffer, 10, stdin);
	float scale = atof(buffer);


	
		




		//drawing section 
		for (float x = 0; x < 800; x++) {

			for (float y = 0; y < 800; y++) {
				for (iter = 0; iter < 1 and abs(z) <2; iter++) {
					z = mandel(z, { (x / 800) * scale , (y / 800) * scale });
				}
				//printf("%i", iter);
				z = { 0,0 };

				color.r = float(iter);
				color.g = float(iter*8);
				color.b = float(iter*16);
				//system("pause");
				//al_draw_filled_rectangle(100, 100, 200, 200, red);
				//printf("printing at x =%d and y = %d", temp1.x, temp1.y);
				//input();
				std::cout << iter;//stuck at 255
				al_draw_filled_rectangle(x, y, x + 1, y + 1,color);
				al_flip_display();//actuall draws stuff
			}
		}

	
}