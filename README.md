[![Licence GPL](http://img.shields.io/badge/license-GPL-green.svg)](http://www.gnu.org/licenses/quick-guide-gplv3.fr.html)

# PLD COMP

Voici le magnifique repo Git pour le code du PLD

## Déployer la solution

On va faire simple, utilisez make (19/03/2019) pour l'instant au lieu de Cmake !
Assurez-vous d'avoir installé CLang (sous ubuntu 18.10 -> 1:7.0-43ubuntu1 minimum) ;)

## Compiler et générer

- [AntLR4](https://github.com/antlr/antlr4) &mdash; Notre analyseur pour la grammaire.

Tuto sur comment générer et installer Antlr sous Ubuntu 18.10 :
- Télécharger le .jar à l'adresse suivante : [Jar Antlr 4.7.2](https://www.antlr.org/download/antlr-4.7.2-complete.jar)
- Placez le .jar dans votre répertoire système "/usr/share/java/"
- Créez les répertoires nécessaire à la racine du système pour obtenir le chemin suivant "/shares/public/tp/"
- Décompressez le .zip intitulé "Antlr4-LOL" dans ce répertoire
- Enjoy \o/

## Contributions

Seuls les membres de l'hexanôme H4213 peuvent commit et push sur le repo ! 

## Licence

[![GNU GPL v3.0](http://www.gnu.org/graphics/gplv3-127x51.png)](http://www.gnu.org/licenses/gpl.html)

```
PLD COMP - Un compilateur C++ du turfu
Copyright (C) 2019 Tifenn Folch
Copyright (C) 2019 Alan Paugois
Copyright (C) 2019 Anatolii Gasiuk
Copyright (C) 2019 Christophe Hirt
Copyright (C) 2019 Clémentine Coquio-Lebresne
Copyright (C) 2019 Matthieu Halunka

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
```