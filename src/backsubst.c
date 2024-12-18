#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
	/**
	 * Tutaj należy umieścić właściwą implemntację.
	 */
	int n = mat->r; // Liczba wierszy (macierz kwadratowa)
	int i, j;

	// Inicjalizacja wyniku w macierzy x
	for (i = 0; i < n; i++)
	{
		x->data[i][0] = 0.0;
	}

	// Algorytm wstecznego podstawienia
	for (i = n - 1; i >= 0; i--)
	{
		double sum = 0.0;

		// Obliczenie sumy dla części Ax = b
		for (j = i + 1; j < n; j++)
		{
			sum += mat->data[i][j] * x->data[j][0];
		}

		// Obliczenie wartości niewiadomej x[i]
		x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
	}

	return 0; // Operacja zakończona sukcesem
}
