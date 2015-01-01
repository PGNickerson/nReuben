#include	<os.h>
#include	"RQ1forestisland.h"
#include	"n2DLib/n2DLib.h"

#define		TILE_WIDTH	16
#define		TILE_HEIGHT	16

#define		K_ESC		isKeyPressed(KEY_NSPIRE_ESC)
#define		K_ENTER		isKeyPressed(KEY_NSPIRE_ENTER)
#define		K_TAB		isKeyPressed(KEY_NSPIRE_TAB)
#define		K_UP		isKeyPressed(KEY_NSPIRE_UP)
#define		K_DOWN		isKeyPressed(KEY_NSPIRE_DOWN)
#define		K_LEFT		isKeyPressed(KEY_NSPIRE_LEFT)
#define		K_RIGHT		isKeyPressed(KEY_NSPIRE_RIGHT)

Rect src_rect;
int pos_x = 0;
int pos_y = 0;

void draw_tile(unsigned short *tileset, int tile_num, int x, int y)
{
    src_rect.x = tile_num * TILE_WIDTH;
    src_rect.y = 0;
    drawSpritePart(tileset, x, y, &src_rect);
}

void draw_tile_map(void)
{
    int i, j;
    for(i = pos_y; i < (8 + pos_y); ++i)
        for(j = pos_x; j < (12 + pos_x); ++j)
            draw_tile(RQ1forestisland, RQ1forestisland_map[i][j], (j - pos_x + 4) * TILE_WIDTH, (i - pos_y + 3) * TILE_HEIGHT);
}

void draw_everything()
{
	clearBufferB();
	draw_tile_map();
	updateScreen();
}

int main(void)
{
	int keep_playing = 1;
	
	initBuffering();
	src_rect.w = TILE_WIDTH;
	src_rect.h = TILE_HEIGHT;
	int i;
	int j;
	clearBufferB();
	draw_tile_map();
	updateScreen();
	while(keep_playing)
	{
		if(K_ESC)
			keep_playing = 0;
		if(K_UP)
		{
			if(pos_y > 0)
				pos_y--;
			sleep(250);
			draw_everything();
		}
		if(K_DOWN)
		{
			if(pos_y < MAP_HEIGHT - 8)
				pos_y++;
			sleep(250);
			draw_everything();
		}
		if(K_LEFT)
		{
			if(pos_x > 0)
				pos_x--;
			sleep(250);
			draw_everything();
		}
		if(K_RIGHT)
		{
			if(pos_x < MAP_WIDTH - 12)
				pos_x++;
			sleep(250);
			draw_everything();
		}
	}
	deinitBuffering();
}