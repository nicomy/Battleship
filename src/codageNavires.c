
pNavire* creatNavire(int i_start, int j_start, int i_end, int j_end){
	pNavire* n = malloc(sizeof(navire));

	n->i_deb = i_start;
	n->j_deb = j_start;
	n->i_fin = i_end;
	n->j_fin = j_end;

	return n;
}


