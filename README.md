# PROJ1 – Conception d’un capteur de radiation avec tube Geiger

Projet réalisé dans le cadre du module **PROJ1 – Projet analogique** en première année à l’**ENSEIRB-MATMECA**.

**Auteurs :** Mattéo BINET  
Quentin MARIE  

**Date :** 30 décembre 2025  

---

## 1. Introduction

Le projet de conception électronique consiste en l'étude et la réalisation d'un capteur de radiation fonctionnel et compact. Ce système repose sur l'utilisation d'un tube Geiger-Müller J315 pour la détection de particules ionisantes.

L'architecture du circuit est une adaptation modernisée du module CAJOE, transposée en technologie de composants montés en surface (CMS) afin de réduire l'encombrement global. La conception a été intégralement réalisée sous le logiciel de CAO **KiCad E.D.A. 9.0.5**.

---

## 2. Cahier des charges (Tube J315)

- **Type de tube :** Halogène à impulsion pour rayonnements beta et gamma.
- **Tension de travail recommandée :** 380 V.
- **Plage du plateau :** 80 V avec une pente maximale de 10 % / 80 V.
- **Tension d'alimentation :** +5 V DC.
- **Protection :** Fusible de 750 mA intégré pour prévenir les courts-circuits.
- **Consommation nominale :** Environ 40 mA.

---

## 3. Conception du circuit

Le circuit est divisé en quatre blocs fonctionnels principaux :

1. **Module d'Alimentation :**
   - Entrée via connecteur JST XH à trois broches (GND, INT, +5 V).
   - Protection par fusible F1 et filtrage par condensateur de découplage C1 (100 nF).
   - Interrupteur bipolaire SW1 pour la mise hors tension complète.

2. **Étage Boost DC-DC :**
   - Oscillateur basé sur un circuit intégré **NE555** (U1) configuré en mode astable.
   - Élévation de tension par découpage via une inductance L2 (10 mH) et un transistor haute tension **MMBTA42** (Q1).
   - Fréquence d'oscillation fixée à 7059 Hz.

3. **Tripleur de tension :**
   - Structure de type Cockcroft-Walton composée de trois diodes **ES1J** (D2, D3, D4) et de condensateurs haute tension (10 nF / 1000 V).
   - Permet d'atteindre la tension de polarisation théorique de 400 V par effet de pompe de charge.

4. **Détecteur d’impulsion :**
   - Le tube V1 génère une avalanche électronique lors du passage d'une particule.
   - Mise en forme du signal par un second **NE555** (U2) configuré en monostable pour produire une impulsion calibrée de 517 us.
   - Signalisation visuelle par une LED rouge D5 à chaque détection.

---

## 4. Résultats expérimentaux

Les mesures effectuées à l'oscilloscope valident le comportement théorique :

- **Sortie Boost :** Observation de pics de tension d'environ 280 V au nœud boost_dc.
- **Sortie Multiplicateur :** Stabilisation de la haute tension après l'étage de filtrage.
- **Plage de réglage :** Tension de sortie ajustable entre 200 V et 550 V via le potentiomètre RV1, permettant un calage précis à 380 V.

---

## 5. Procédure de réglage

Le réglage de la haute tension s'effectue impérativement sans le tube Geiger :

1. **Mise sous tension :** Alimenter la carte en +5 V et vérifier l'allumage de la LED verte D1.
2. **Mesure :** Placer un voltmètre (calibre 1000 V) entre le point de test "tripleur" et la masse.
3. **Ajustement :** Régler RV1 jusqu'à obtenir 380 V.
4. **Alternative :** Une mesure indirecte est possible au point de test TP_Geiger situé après un pont diviseur de 50 MOhm.

---

## 6. Conclusion

Ce projet a permis de valider la conception d'un compteur Geiger CMS performant. L'intégration des étages de puissance et de détection sur un PCB compact répond aux exigences de fiabilité et de sécurité fixées initialement. Le dispositif constitue une base documentée pour toute application de surveillance radiologique.

---

## 7. Contenu du dépôt GitHub

Le dépôt contient l'intégralité des fichiers nécessaires à la reproduction du projet :

- [Datasheet/](./Datasheet) -> Fiches techniques des composants critiques (NE555, MMBTA42, J315)
- [KiCad/](./KiCad) -> Schématics, fichiers de routage PCB et modèles 3D
- [Simulations/](./Simulations) -> Résultats des tests et mesures à l'oscilloscope
- [Code/](./Code) -> Exemple de code Arduino pour le comptage des impulsions (PPS)
- [Rapport/](./Rapport) -> Compte rendu technique détaillé du projet
- [README.md](./README.md) -> Présentation du projet

---

© 2025 — Mattéo BINET, Quentin MARIE
Département Électronique — PROJ1
Enseirb-Matmeca — Capteur de rayonnement beta & gamma
