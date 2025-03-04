#include <stdlib.h>
#include <curses.h>
#include <menu.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

char *choices[] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
                        "Exit",
                  };

int main()
{	ITEM **my_items;
	int c;				
	MENU *my_menu;
        int n_choices, i;
	ITEM *cur_item;
	
	
	initscr();
        cbreak();
        noecho();
	keypad(stdscr, TRUE);
	
        n_choices = ARRAY_SIZE(choices);
        my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

        for(i = 0; i < n_choices; ++i)
                my_items[i] = new_item(choices[i], choices[i]);
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	post_menu(my_menu);
	refresh();

	while((c = getch()) != KEY_F(1))
	{       switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case 10:	/* Enter */
				cur_item = current_item(my_menu);
				move(LINES - 2, 0);
				clrtoeol();
				mvprintw(LINES - 2, 0, "You have chosen %d item with name %s and description %s", 
				item_index(cur_item) + 1,  item_name(cur_item), 
				item_description(cur_item));
				
				refresh();
				pos_menu_cursor(my_menu);
				break;
		}
	}	

	free_item(my_items[0]);
        free_item(my_items[1]);
	free_menu(my_menu);
	endwin();
}
	
