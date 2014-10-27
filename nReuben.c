#include	<os.h>
#include	"tiles.h"
#include	"map.h"
#include	"n2DLib/n2DLib.h"

#define		TILE_WIDTH	16
#define		TILE_HEIGHT	16

#define		K_ESC		isKeyPressed(KEY_NSPIRE_ESC)
#define		K_ENTER		isKeyPressed(KEY_NSPIRE_ENTER)
#define		K_TAB		isKeyPressed(KEY_NSPIRE_TAB)
#define		K_A			isKeyPressed(KEY_NSPIRE_A)
#define		K_7			isKeyPressed(KEY_NSPIRE_7)
#define		K_9			isKeyPressed(KEY_NSPIRE_9)
#define		K_8			isKeyPressed(KEY_NSPIRE_8)
#define		K_5			isKeyPressed(KEY_NSPIRE_5)
#define		K_4			isKeyPressed(KEY_NSPIRE_4)
#define		K_6			isKeyPressed(KEY_NSPIRE_6)

Rect src_rect;

void draw_tile(unsigned short *tileset, int tile_num, int x, int y)
{
    src_rect.x = tile_num % 32 * 10;
    src_rect.y = tile_num / 32 * 10;
    drawSpritePart(tileset, x, y, &src_rect);
}

void draw_tile_map(void)
{
    int i, j;
    for(i = 0; i < MAP_HEIGHT; ++i)
        for(j = 0; j < MAP_WIDTH; ++j)
            draw_tile(tiles, map[i][j], (j + 4) * TILE_WIDTH, (i + 3) * TILE_HEIGHT);
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
	}
	deinitBuffering();
}