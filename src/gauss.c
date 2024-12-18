#include "gauss.h"
#include <stdio.h>


/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	/**
	 * Tutaj należy umieścić właściwą implemntację.
	 */

	int n = mat->r;
	int i, j, k;

	for (k = 0; k < n; k++)
	{
		if (mat->data[k][k] == 0.0)
		{
			return 1;
		}

		double pivot = mat->data[k][k];
		for (j = k; j < mat->c; j++)
		{
			mat->data[k][j] /= pivot;
		}
		b->data[k][0] /= pivot;

		for (i = k + 1; i < n; i++)
		{
			double factor = mat->data[i][k];
			for (j = k; j < mat->c; j++)
			{
				mat->data[i][j] -= factor * mat->data[k][j];
			}
			b->data[i][0] -= factor * b->data[k][0];
		}
	}

	return 0;
}
