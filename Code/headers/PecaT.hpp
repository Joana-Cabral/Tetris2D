// Garante que ficheiro atual apenas � inclu�do uma vez durante o processo de compila��o
#pragma once 

#include "headers/Peca.hpp"

#define GLEW_STATIC
#include <GL/glew.h>

#include <chrono>
#include <vector>
using namespace std;

// GLM header file
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
using namespace glm;

class PecaT : public Peca
{
	private:
		// Vari�veis da pe�a
		float xCR;
		float yCR;
		int iPieceWidth;
		int iPieceHeight;

		int yPos;
		int xPosE;
		int xPosD;

		// Vari�veis de tabuleiro
		int** gameGrid;
		int xPosInicial;
		int yPosInicial;
		int iHeight;
		int iWidth;

		// Vari�veis de interacao com user
		int iNumberRotate;
		int iNumberTranslation;
		int iNumberDown;

		std::chrono::time_point<std::chrono::steady_clock> t_start;

	public:
		PecaT();
		PecaT(int, int, int, int, int**);

		void preencheRealVertex(GLfloat, GLfloat);
		void modificaQuadricula(GLfloat, GLfloat);
		void realVertexBuffer();

		bool preencheMatriz(int, int, int, int);
		bool atualizaMatriz();
		bool avaliaColisao();
		void atualizaPos();
		void rotacaoPeca(glm::mat4& rot);
		void translacaoPeca(glm::mat4& trans);

		// Getters
		int** getGameGrid();

		int getNumberRotate();
		int getNumberTranslation();
		int getNumberDown();

		int getXPosD();
		int getXPosE();
		int getYPos();

		// Atualizadores
		void incNumberRotate();
		void incNumberTranslation();
		void decNumberTranslation();
		void incNumberDown();

		// Desenho geom�trico
		void drawObject();

		// Vari�veis de classe
		// Desenho da pe�a
		static std::vector<GLfloat> g_vertex_buffer_data;

		// Cor da pe�a
		static std::vector<GLfloat> g_color_buffer_data;

		static std::vector<GLfloat> g_real_vertex_buffer;
};