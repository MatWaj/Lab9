#include "gauss.h"

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

		// Pełne pivotowanie

		int maxRow = k, maxCol = k;
		for (i = k; i < n; i++)
		{
			for (j = k; j < n; j++)
			{
				if (fabs(mat->data[i][j]) > fabs(mat->data[maxRow][maxCol]))
				{
					maxRow = i;
					maxCol = j;
				}
			}
		}

		// Zamiana wierszy

		if (maxRow != k)
		{
			for (j = 0; j < mat->c; j++)
			{
				double temp = mat->data[k][j];
				mat->data[k][j] = mat->data[maxRow][j];
				mat->data[maxRow][j] = temp;
			}


			double temp = b->data[k][0];
			b->data[k][0] = b->data[maxRow][0];
			b->data[maxRow][0] = temp;
		}


		if (maxCol != k)
		{
			for (i = 0; i < n; i++)
			{
				double temp = mat->data[i][k];
				mat->data[i][k] = mat->data[i][maxCol];
				mat->data[i][maxCol] = temp;
			}
		}


		if (mat->data[k][k] == 0.0)
		{
			return 1;
		}

		// Eliminacja Gaussa
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
