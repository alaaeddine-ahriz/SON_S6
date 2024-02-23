# VOCODER

## Table des matières

1. Introduction
2. Installation
3. Utilisation

## Introduction

Les vocoders sont des outils utilisés pour modifier et transmettre des signaux vocaux. Ils ont plusieurs applications principales :
- Sécuriser les communications téléphoniques et anonymiser les appels pour protéger la vie privée.
- Modifier de manière créative la voix dans la production musicale pour obtenir des effets artistiques.
- Transformer la voix générée par ordinateur pour la rendre plus humaine, améliorant ainsi les interactions avec l'utilisateur.

## Installation

Pour commencer, téléchargez le dossier "new_pitchshift". À l'intérieur, vous trouverez quatre fichiers :
- `new_pitchshifter.cpp` - Fichier source C++ contenant la fonctionnalité principale.
- `new_pitchshifter.h` - Fichier d'en-tête pour le fichier source C++, déclarant les fonctions et variables.
- `new_pitchshifter.dsp` - Fichier DSP, probablement destiné à définir des routines de traitement de signal numérique.
- `new_pitchshifter.ino` - Le code source à téléverser sur un microcontrôleur Teensy pour l'utilisation.

## Utilisation

Une fois le code téléversé dans le Teensy, vous utiliserez trois contrôleurs pour manipuler le son :
- Deux potentiomètres rotatifs : l'un pour le gain (le volume) et l'autre pour la réverbération.
- Un potentiomètre linéaire (slider) : pour ajuster la hauteur du son.

Ces contrôles vous permettent de personnaliser en temps réel l'effet appliqué à la voix, offrant une large gamme de possibilités créatives et pratiques.
