/*
 * Ce programme est un jeu d'échec comportant 3 pièces differentes : le roi, le fou et la tour.
 * Ce jeu comprend 3 modes de jeu et donc une interface graphique afin de jouer au jeu.
 *\file   main.cpp
* \author Jeremy Vong et Tan Tommy Rin
* \date   3 mai 2024
* Créé le 21 avril 2024
* Description : L'interface graphique du jeu d'échec est creé avec Qt creator. Divers classe représentant
* les differentes pieces du jeu, une exception survient s'il y a trop de roi, une classe pour le jeu d'échec (les cases)
* et pour l'interface graphique. Il y a un namespace pour le back et front end du code. Nous avons aussi
* des images représentant chaque pièce que nous avons implémentés.
*/

#include "ChessWindow.hpp"
#include "ChessBoardArray.hpp"

#include <QApplication>

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.

	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char* argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);
	frontend::ChessWindow chessWindow;
	chessWindow.show();
	return app.exec();
}
