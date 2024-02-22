# Réduction de bruit active
#### Projet SON

## 1. Objectif du projet :
Le but du projet est d'implémenter en C++ l'algorithme de traitement audio LMS sur un teensy arduino 4.0 permettant de réduire le bruit ambiant. Pour cela, on fait appel à la librairie MyDsp de teensy qui permet d'échantillonner des signaux audio. Le traitement s'effectuera sur chacun des échantillons et l'algorithme que nous utilisons est une version normalisée de LMS qui est NLMS.

## 2. Etat du code :
La version actuelle fait appel à un bruit blanc généré en interne par le teensy et qu'il va chercher à supprimer avec l'algorithme. En sortie, nous analysons l'erreur qui converge au courant de l'algorithme.

## 3. Perspectives d'amélioration :
Ce programme peut servir de base pour l'implémentation d'un système haut-parleur/microphone en tant que source de bruit. Il peut également être utilisé dans une configuration FxLMS.

## 4. Matériel utilisé :
- Teensy 4.0 (alimentation et branchements)
- Audioshield
- Casque audio
- Breadboard
- Jumper
- Potentiomètre
- Bouton poussoir
- Résistance de tirage (10 kΩ)

## 5. Code :
- ``MyDsp.h`` contient les définitions de fonctions et de variables.
- ``MyDsp.cpp`` contient le code des fonctions et le traitement audio réalisé par le teensy.
- ``active_noise_reduction.ino`` permet de gérer les entrées/sorties du teensy.


## Sources consultées

- Contributors to Wikimedia projects. (2005, 9 juin). Least mean squares filter - Wikipedia. Wikipedia, the free encyclopedia. https://en.wikipedia.org/wiki/Least_mean_squares_filter
- Song, Y. (2022). Active Noise Cancellation and Its Applications. Journal of Physics : Conference Series, 2386(1), 012042. https://doi.org/10.1088/1742-6596/2386/1/012042
- GitHub - zftan0709/Feedback-ANC-Teensy-3.6 : Feedback ANC project based on FxLMS algorithm and Teensy 3.6 microcontroller. (s. d.). GitHub. https://github.com/zftan0709/Feedback-ANC-Teensy-3.6
- Ravinchandra, K. A., Ka Fei, T., & Chee Yong, L. (2019). Active Noise Reduction using LMS and FxLMS Algorithms. Journal of Physics : Conference Series, 1228, 012064. https://doi.org/10.1088/1742-6596/1228/1/012064
- Gomathi, K., Saravanan, V., & Santhiya kumari, N. (2016). Variable Step Size for Improving Convergence of FxLMS Algorithm. Procedia Technology, 25, 420–426. https://doi.org/10.1016/j.protcy.2016.08.127
- Kidner, M. R. F. (2002). Understanding Active Noise Cancellation. Shock and Vibration, 9(3), 151. https://doi.org/10.1155/2002/264984
