[![Licence GPL](http://img.shields.io/badge/license-GPL-green.svg)](http://www.gnu.org/licenses/quick-guide-gplv3.fr.html)

# PLD COMP

Voici le code du PLD COMP de l'hexanôme H4213.

## Déployer la solution

Pour pouvoir utiliser ce projet, mettez-vous à la racine du dossier et utilisez :
<ul>
<li><code>make</code> pour compiler la solution complétement</li>
<li><code>make OPTIONS="-DGEN_EXE"</code> pour que l'application compilée génére directement un exécutable à la fin de la compilation du fichier par l'application.</li>
<li><code>make mrproper</code> pour nettoyer les fichiers compilés.</li>
<li><code>make test</code> pour compiler la solution complétement et la tester.</li>
</ul>

Assurez-vous d'avoir installé CLang (sous ubuntu 18.10 -> 1:7.0-43ubuntu1 minimum).

## Utiliser la solution

La solution s'utilise par l'exécution du fichier <code>exec</code> généré. 
Un fichier à compiler devra être spécifier pour que l'application fonctionne. 
<br/>Ex : <code>./exec index.c</code><br/>

L'application affiche la représentation en mémoire du code analysé.<br/>
Les options pour utiliser cette solution sont :
<ul>
<li><code>-a</code> pour activer l'affichage des erreurs d'analyse statique.</li>
<li><code>-c</code> pour activer la transformation de la structure en mémoire en ASM x86 dans un fichier de nom identique (index.c génére index.s).</li>
<li><code>-c sortie.s</code> pour activer la transformation vers un nom de fichier spécifié.</li>
<li><code>-o</code> pour activer l'optimisation de la structure.</li>
</ul>

Le script shell <code>ultimate_script.sh</code> permet de compiler la solution, de lancer l'application avec un fichier index.c situé dans le même dossier et d'exécuter l'assembleur obtenu pour obtenir le résultat de son exécution.

## Compiler et générer en dehors de IF - Guide de déploiement Antlr

- [AntLR4](https://github.com/antlr/antlr4) &mdash; Notre analyseur pour la grammaire.

Tuto sur comment générer et installer Antlr sous Ubuntu 18.10 en dehors du département :
- Télécharger le .jar à l'adresse suivante : [Jar Antlr 4.7.2](https://www.antlr.org/download/antlr-4.7.2-complete.jar).
- Placez le .jar dans votre répertoire système "/usr/share/java/".
- Créez les répertoires nécessaire à la racine du système pour obtenir le chemin suivant "/shares/public/tp/".
- Décompressez le .zip du dossier install intitulé "Antlr4-Dump.zip" dans ce répertoire.

## Contributions

Seuls les membres de l'hexanôme H4213 peuvent commit et ouvrir des pull request sur ce repo GIT ! 

## Licence

[![GNU GPL v3.0](http://www.gnu.org/graphics/gplv3-127x51.png)](http://www.gnu.org/licenses/gpl.html)

```
PLD COMP - Un compilateur C++-like
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
