#ifndef ATAQUE_H
#define ATAQUE_H

#include "territorio.h"
#include <time.h>
#include <stdlib.h>

// ============================================
// PROTÓTIPOS
// ============================================

// Rola um dado de 6 faces
int rolarDado();

// Simula ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor);

// Valida se ataque é possível
int validarAtaque(const Territorio* atacante, const Territorio* defensor);

#endif // ATAQUE_H