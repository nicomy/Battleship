
typedef struct $navire navire

struct $maillon
{
	pMaillon nextm;
	pNavire liste_navire;
}maillon, *pMaillon;

struct $navire
{
	int i_deb;
	int j_deb;
	int i_fin;
	int j_fin;
	int coulé;
}*pNavire, navire;