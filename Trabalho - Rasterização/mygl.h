#ifndef _MYGL_H_
#define _MYGL_H_
#include "definitions.h"
#include "math.h"
#include <vector>
//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

// Struct que recebe a posição x,y e os valores de R,B,G,A.
typedef struct {
int x, y, r, g, b, a;

}pixel;
// Função que pinta um pixel na tela.
void PutPixel (pixel p) {
        FBptr[p.x*4 + 4*p.y*IMAGE_WIDTH + 0] = p.r;
        FBptr[p.x*4 + 4*p.y*IMAGE_WIDTH + 1] = p.g;
        FBptr[p.x*4 + 4*p.y*IMAGE_WIDTH + 2] = p.b;
        FBptr[p.x*4 + 4*p.y*IMAGE_WIDTH + 3] = p.a;
}

void DrawLine(pixel i, pixel f){
    int dx = f.x - i.x;
    int dy = f.y - i.x;
    int d = 2 * dy - dx;
    int incr_e = 2 * dy;
    int incr_ne = 2 * (dy - dx);
    		
    
    PutPixel(i);
    	
	//primeiro octante// 
	if(dx>0 && dy>0 && dx>dy){
		while (i.x < f.x) {
        		if (d <= 0) {
            		d += incr_e;
            		i.x++;
        		} else {
            		d += incr_ne;
            		i.x++;
            		i.y++;
        	}
    		PutPixel(i);
	     }
      }
	 //segundo octante//	
      if(dx>0 && dy>0 && dy>dx){
           while (i.x < f.x) {
        		if (d <= 0) {
            		d += incr_e;
            		i.x++;
        		} else {
            		d += incr_ne;
            		i.x++;
            		i.y++;
        	}
    		PutPixel(i);
	     }
      }
	 //terceiro octante//
	 if(dx<0 && dy>0 && dy>-dx){
		dx = -dx;
		while (i.x > f.x) {
        		if (d <= 0) {
            		d += incr_e;
            		i.x--;
        		} else {
            		d += incr_ne;
            		i.x--;
            		i.y++;
        	}
    		PutPixel(i);
	     }
      }

	 //quarto octante//
      if(dx<0 && dy>0 && -dx>dy){
		dx = -dx;
		while (i.x > f.x) {
        		if (d <= 0) {
            		d += incr_e;
            		i.x--;
        		} else {
            		d += incr_ne;
            		i.x--;
            		i.y++;
        	}
    		PutPixel(i);
	     }
      }

	 //quinto octante//
      if(dx<0 && dy<0 && -dx>-dy){
		dx = -dx;
		dy = -dy;
		while (i.x > f.x) {
        		if (d <= 0) {
            		d += incr_e;
            		i.x--;
        		} else {
            		d += incr_ne;
            		i.x--;
            		i.y--;
        	}
    		PutPixel(i);
	     }
      }

	 //sexto octante//
	 if(dx<0 && dy<0 && -dy>-dx){
		dx = -dx;
		dy = -dy;
		while (i.x > f.x) {
        		if (d <= 0) {
            		d += incr_e;
            		i.x--;
        		} else {
            		d += incr_ne;
            		i.x--;
            		i.y--;
        	}
    		PutPixel(i);
	     }
      }

	 //setimo octante//
	 if(dx>0 && dy<0 && -dy>dx){
		dy = -dy;
		while (i.x < f.x) {
        		if (d <= 0) {
            		d += incr_e;
            		i.x++;
        		} else {
            		d += incr_ne;
            		i.x++;
            		i.y--;
        	}
    		PutPixel(i);
	     }
      }
		
	 //oitavo octante//
	 if(dx>0 && dy<0 && dx>-dy){
		dy = -dy;
		while (i.x > f.x) {
        		if (d <= 0) {
            		d += incr_e;
            		i.x++;
        		} else {
            		d += incr_ne;
            		i.x++;
            		i.y++;
        		}
    			PutPixel(i);
	     	}
      }
	
}	







#endif // _MYGL_H_
