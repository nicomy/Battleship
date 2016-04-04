
typedef struct $navire liste_navire

typedef struct $list
{
	pNavire first;
	pNavire last;
}liste_navire, *pList_navire;

typedef struct $maillon
{
	int i_deb;
	int j_deb;
	int i_fin;
	int j_fin;
	int coule;
	pNavire nextMaillon;
}*pMaillon, maillon;