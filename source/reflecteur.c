#include "reflecteur.h"
#include "graphic.h"

static int nb_element_r = 0;
static int nb_expected_r = 0;

struct Reflecteur
{
	VECTEUR deb, fin;
};

static REFLECTEUR* tab_r;

int verifier_fin_reflecteur()
{
	if((nb_element_r) < nb_expected_r)
	{
		error_lecture_elements(ERR_REFLECTEUR, ERR_PAS_ASSEZ);
		return 1;
	}
	else if((nb_element_r) > nb_expected_r)
	{
		error_lecture_elements(ERR_REFLECTEUR, ERR_TROP);
		return 1;
	}
	return 0;
}


int reflecteur_load(char * tab)
{
	char *deb = tab; 
	REFLECTEUR r;
	
	if(tab_r == NULL)
	{
		if((sscanf(deb,"%d",&nb_expected_r)) != 1)
		{
			error_lect_nb_elements(ERR_REFLECTEUR);
			return 1;
		}
			
		if(nb_expected_r < 0)
		{
			error_lect_nb_elements(ERR_REFLECTEUR);
			return 1;
		}
		
		if(!(tab_r = malloc(nb_expected_r*sizeof(REFLECTEUR))))
		{
			error_msg("Erreur dans allocation mémoire de l'reflecteur");
			return 1;
		}
	}
	else
	{
		if(sscanf(deb,"%lf %lf %lf %lf", &r.deb.x, &r.deb.y,&r.fin.x,&r.fin.y) != 4)
		{
			error_lecture_elements(ERR_REFLECTEUR, ERR_PAS_ASSEZ);
			return 1;
		}
		if(utilitaire_calculate_distance(r.deb, r.fin) < EPSIL_CREATION)
		{
			error_lecture_point_trop_proche(ERR_REFLECTEUR, nb_element_r);
			return 1;
		}
		reflecteur_add_r(r);
	}
	
	return 0;	
}

void reflecteur_free()
{
	free(tab_r);
	tab_r = NULL;
	nb_element_r = 0;
	nb_expected_r = 0;
}

void reflecteur_retirer(int id)
{
	REFLECTEUR* temp = malloc((nb_element_r-1)*sizeof(REFLECTEUR));
	int i, j = 0;
	
	for (i = 0; i < nb_element_r; i++)
	{
		if (i == id)	
			continue;
				
		*(temp+j) = *(tab_r+i);
		j++; 
	}
	nb_element_r --;
	free(tab_r);
	tab_r = temp;
}

//method pour accéder aux éléments
int reflecteur_get_nombre()	
{
	return nb_element_r;
}

SEGMENT reflecteur_dectection_collision(SEGMENT s)
{
	int i;
	for(i = 0; i < nb_element_r; i++)
	{
		SEGMENT s_r = {(tab_r + i)->deb, (tab_r + i)->fin};
		if(utilitaire_detection_parallelisme(s, s_r) == 1)
			return s_r;
	}
	SEGMENT s_null;
	s_null.deb.x = 0;
	s_null.deb.y = 0;
	s_null.fin.x = 0;
	s_null.fin.y = 0;
	return s_null;
}

int reflecteur_plus_proche_selection(VECTEUR vect_coordonne)
{
	VECTEUR point = vect_coordonne;
	VECTEUR vect = {(tab_r->deb).x, (tab_r->deb).y};
	double min_distance = utilitaire_calculate_distance(point, vect);
	double min_temporaire = 0;
	int min_i = 0;
	int i;
	for(i = 0; i < nb_element_r; i++)
	{	
		vect.x = ((tab_r+i)->deb).x;
		vect.y = ((tab_r+i)->deb).y;			
		min_temporaire = utilitaire_calculate_distance(point, (tab_r+i)->deb);
		if(min_temporaire < min_distance)
		{
			min_distance = min_temporaire;
			min_i = i;
		}
	}
	
	for(i = 0; i < nb_element_r; i++)
	{		
		vect.x = ((tab_r+i)->fin).x;
		vect.y = ((tab_r+i)->fin).y;		
		min_temporaire = utilitaire_calculate_distance(point, (tab_r+i)->fin);
		if(min_temporaire < min_distance)
		{
			min_distance = min_temporaire;
			min_i = i;
		}
	}
	return min_i;
}

void reflecteur_print_file(FILE* file)
{
	fprintf(file, "#reflecteur\n");
	fprintf(file, "%d\n", nb_element_r);
	int i;
	for(i = 0; i < nb_element_r; i++)
	{
		fprintf(file, "%f %f %f %f ", ((tab_r+i)->deb).x, ((tab_r+i)->deb).y, 
										((tab_r+i)->fin).x, ((tab_r+i)->fin).y);
		fprintf(file, "\n");
	}
	fprintf(file, "FIN_LISTE\n\n");
}

int reflecteur_add_r(REFLECTEUR r)
{
	if(tab_r == NULL)
	{
		if(!(tab_r = malloc(sizeof(REFLECTEUR))))
			return 1;
	}
	else if(nb_element_r >= nb_expected_r)
	{
		if(!(tab_r = realloc(tab_r, sizeof(REFLECTEUR)*(nb_element_r+1))))
			return 1;
	}
	*(tab_r+nb_element_r) = r;
	nb_element_r++;

	return 0;
}

void reflecteur_creation(VECTEUR deb, VECTEUR fin)
{
	REFLECTEUR r;
	r.deb = deb;
	r.fin = fin;
	
	reflecteur_add_r(r);
}


SEGMENT reflecteur_get_segment(int id)
{
	VECTEUR v1 = (tab_r + id)->deb;
	VECTEUR v2 = (tab_r + id)->fin;
	
	SEGMENT s;
	s.deb = v1;
	s.fin = v2;
	
	return s;
}

//methode pour dessiner réflecteur
void reflecteur_drawing()
{
	int i;
	for(i = 0; i < nb_element_r; i++)
		reflecteur_draw_obj(i);
}

void reflecteur_draw_obj(int id_r)
{
	graphic_set_line_width(2.);
	graphic_set_color3f(1,0,0);
	
	graphic_draw_segment((tab_r+id_r)->deb.x, (tab_r+id_r)->deb.y,
	                     (tab_r+id_r)->fin.x,(tab_r+id_r)->fin.y);
}

void reflecteur_draw_selection(int id)
{
	graphic_set_line_width(4.);
	graphic_set_color3f(1,1,0);

	graphic_draw_segment((tab_r+id)->deb.x, (tab_r+id)->deb.y,
						 (tab_r+id)->fin.x,(tab_r+id)->fin.y);
}

