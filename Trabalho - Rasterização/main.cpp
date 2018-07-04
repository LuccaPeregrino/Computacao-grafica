#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    // Laço que escreve uma linha VERMELHA na diagonal apenas com o Putpixel();
    //for(unsigned int x=0; x < 512; x++){
    //int y = x; 
    //pixel p = { x, y, 0, 255, 0, 255};
    //PutPixel(p);
    //
    int x = 0, y = 256, z = 512 , w = 256; 
    pixel p = { x, y, 0, 255, 0, 255};
    pixel b = {z, w, 255, 0,0, 255};
    
    DrawLine(p, b);

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

