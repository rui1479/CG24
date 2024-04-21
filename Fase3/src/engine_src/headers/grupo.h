#include "transformacoes.h"
#include "ponto.h"
#include "modelo.h"
#include <vector>

using namespace std;



class Grupo {
	Escala esc;						// escala associada ao group
	Translacao trans;				// transla��o associada ao group
	Rotacao rot;					// rota��o associada ao group
	string ordem;					// ordem das transforma��es do grupo
	vector<Modelo> modelos;			// modelos que cont�m os pontos e a cor associada ao grupo
	vector<Grupo> filhos;			// descendentes do grupo

public:
	Grupo();

	Escala getEscala();
	void setEscala(Escala);

	Translacao getTranslacao();
	void setTranslacao(Translacao);
	

	Rotacao getRotacao();
	void setRotacao(Rotacao);

	vector<Modelo> getModelos();
	void setModelos(vector<Modelo>);
	void addModelo(Modelo);

	string getOrdem();
	void setOrdem(string);

	vector<Grupo> getFilhos();
	void setFilhos(vector<Grupo>);
	void addFilho(Grupo);

};
