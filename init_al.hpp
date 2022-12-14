#pragma once
#pragma once
/*
* GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS *
* GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS * GLOBALS *
*/
#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include <iostream>
double pi = 3.14159265359;

ALLEGRO_DISPLAY* display;
ALLEGRO_EVENT_QUEUE* event_queue;
ALLEGRO_TIMER* timer;
ALLEGRO_TRANSFORM camera_transform;
ALLEGRO_STATE previous_state;

//calculation variables

void m_setup() {
	//initialize stuff
	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();

	//set up game screen, event queue, and timer
	display = al_create_display(800, 800);
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 1000.0);
	//register stuff
	al_start_timer(timer);
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_store_state(&previous_state, ALLEGRO_STATE_TRANSFORM);

}
/*
*  COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS * COLORS *
*/
ALLEGRO_COLOR white = { 255.f,255.f,255.f,0.f };
ALLEGRO_COLOR blue = { 0.f,0.f,255.f,0.f };
ALLEGRO_COLOR green = { 0.f,255.f,0.f,0.f };
ALLEGRO_COLOR red = { 255.f,0.f,0.f,0.f };


//input function 
void input() {
	//circle_constructor(&first_circle, 0, 10, temp);
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);

	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		printf("you closed the window!\n");
		exit(0);

	}
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		//stuff that happens at the end of event queue


	}


}
