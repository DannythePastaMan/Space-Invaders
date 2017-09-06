// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

int main(int argc, char **argv)
{
	al_init();

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *image = NULL;
	ALLEGRO_FONT *font, *font2;
	ALLEGRO_EVENT_QUEUE *eventqueue = al_create_event_queue();

	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	al_register_event_source(eventqueue, al_get_keyboard_event_source());

	al_create_display(1920, 1080);

	image = al_load_bitmap("Sky2.jpg");

	font = al_load_ttf_font("Alice.ttf", 150, ALLEGRO_ALIGN_CENTER);
	font2 = al_load_ttf_font("ORI.otf", 150, ALLEGRO_ALIGN_CENTER);
	
		//Menu
		bool salir = false, jugar=false;
		int opcion = 0;
		do
		 {
			al_draw_bitmap(image, 0, 0, 0);
			if (!jugar) {
				al_draw_text(font, al_map_rgb(255, 255, 255), 1000.00, 100.00, ALLEGRO_ALIGN_CENTER, "Space Invaders");
				if (opcion == 0&&!jugar) {
				al_draw_text(font2, al_map_rgb(153, 255, 51), 1000.00, 400.00, ALLEGRO_ALIGN_CENTER, "Jugar");
				al_draw_text(font2, al_map_rgb(255, 255, 255), 1000.00, 600.00, ALLEGRO_ALIGN_CENTER, "Salir");
			}
			else if (opcion == 1&&!jugar) {
				al_draw_text(font2, al_map_rgb(255, 255, 255), 1000.00, 400.00, ALLEGRO_ALIGN_CENTER, "Jugar");
				al_draw_text(font2, al_map_rgb(153, 255, 51), 1000.00, 600.00, ALLEGRO_ALIGN_CENTER, "Salir");
				}
			}
			
			ALLEGRO_EVENT events;
			

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_wait_for_event(eventqueue, &events);
			if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (events.keyboard.keycode) {
				case ALLEGRO_KEY_DOWN:
					opcion++;
					if (opcion > 1) {
						opcion = 0;
					}
					break;
				case ALLEGRO_KEY_UP:
					opcion--;
					if (opcion < 0) {
						opcion = 1;
					}
					break;

				case ALLEGRO_KEY_W:
					opcion--;
					if (opcion < 0) {
						opcion = 1;
					}
					break;
					
				case ALLEGRO_KEY_S:
					opcion++;
					if (opcion > 1) {
						opcion = 0;
					}
					break;
				
				case ALLEGRO_KEY_ENTER:
					if (opcion == 1) {
						salir = true;
						al_flip_display();
						al_destroy_display(display);
						break;
					}
					else if(opcion == 0){
						al_clear_to_color(al_map_rgb(0, 0, 0));
						image = al_load_bitmap("back.png");
						opcion = -1;
						jugar = true;
						break;
					}
					break;
				}
			}
		} while (!salir);
		
		do {
			ALLEGRO_BITMAP *sprite = NULL;
			sprite = al_load_bitmap("playerShip2_blue.png");
			al_draw_bitmap(sprite, 0, 900, ALLEGRO_ALIGN_CENTER);
		} while (opcion == 0);
		

	
	return 0;



}

